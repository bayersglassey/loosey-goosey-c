#!/usr/bin/env bash
set -euo pipefail

die() {
    echo "*** ERROR: $@"
    exit 1
}

files=
mode="${MODE:-loosey}"
testtype=cc # for C compiler, or 'pp' for preprocessor
just_output=false
while test "$#" -ge 1; do
    opt="$1"
    case "$opt" in
        -t|--testtype) testtype="$2"; shift 2;;
        -m|--mode) mode="$2"; shift 2;;
        -o|--output) just_output=true; shift;;
        --) shift; break;;
        -*) die "Unexpected option: $opt";;
        *) files="$files $opt"; shift;;
    esac
done

if test "$testtype" = pp; then
    testdir=pptests

    # NOTE: here are diff's whitespace/newline related options:
    #  -Z, --ignore-trailing-space     ignore white space at line end
    #  -b, --ignore-space-change       ignore changes in the amount of white space
    #  -w, --ignore-all-space          ignore all white space
    #  -B, --ignore-blank-lines        ignore changes where lines are all blank
    diffopts=-ZB

    normalize() (
        sed -E 's/\s+/\n/g'
    )
elif test "$testtype" = cc; then
    testdir=minictests
    diffopts=-ZB
    normalize() (
        cat -
    )
else
    die "Unrecognized test type: $testtype"
fi

if test -z "$files"; then
    files="$testdir"/*.c
fi

if test "$mode" = gcc; then
    # NOTE: -iquote specifies paths to be used with #include "..."
    if test "$testtype" = pp; then
        prog() ( cpp -P -iquote pptests "$1" )
    elif test "$testtype" = cc; then
        prog() (
            filename="$1"
            shift
            gcc -iquote minictests "$filename" && ./a.out "$@"
        )
    else
        die "Unrecognized test type: $testtype"
    fi
elif test "$mode" = loosey; then
    if test "$testtype" = pp; then
        prog() ( python -m loosey.pp --local-dir pptests -f "$1" )
    elif test "$testtype" = cc; then
        prog() (
            filename="$1"
            shift
            python -m loosey.mini --local-dir minictests -f "$filename" -- "$@"
        )
    else
        die "Unrecognized test type: $testtype"
    fi
else
    die "Unrecognized mode: $mode"
fi

actual() (
    prog "$@" || die "Non-zero exit code: $?"
)

n_tests=0
given() {
    : $(( n_tests++ ))
    test_name="Shell test $n_tests"
    echo "=== $test_name:"

    if test "$1" = "args"; then
        args="$2"
        shift 2
    else
        args=
    fi
    if test "$1" = "input"; then
        input="$2"
        shift 2
    else
        input=
    fi
    if test "$1" = "expect"; then
        expected="$2"
        shift 2
    else
        expected=
    fi

    echo "--- Args: $args"
    echo "--- Input:"
    printf "%s\n" "$input"
    if test "$just_output" = true; then
        echo "--- Output:"
        printf %s "$input" | actual "$file" $args
    else
        echo "--- Actual vs expected output:"
        if diff $diffopts <(printf %s "$input" | actual "$file" $args | normalize) <(printf %s "$expected" | normalize); then
            echo "$file: OK!"
        else
            echo "*** $file: FAIL"
            exit 1
        fi
    fi
}

n_files=0
for file in $files; do
    : $(( n_files++ ))
    echo
    echo "================================================================"
    echo "=== Testing file $n_files: $file"
    echo "=== Input:"
    cat "$file"

    if test -f "$file.out"; then
        if test "$just_output" = true; then
            echo "=== Output:"
            actual "$file"
        else
            echo "=== Actual vs expected output:"
            if diff $diffopts "$@" <(actual "$file" | normalize) <(cat "$file.out" | normalize); then
                echo "$file: OK!"
            else
                echo "*** $file: FAIL"
                exit 1
            fi
        fi
    fi

    if test -f "$file.sh"; then
        . "$file.sh"
    fi
done

echo
echo "================================================================"
echo "=== $n_files/$n_files FILES OK"
