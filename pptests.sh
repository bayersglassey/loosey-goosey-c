set -euo pipefail

die() {
    echo "*** ERROR: $@"
    exit 1
}

files=
mode="${MODE:-loosey}"
just_input=false
just_output=false
while test "$#" -ge 1; do
    opt="$1"
    case "$opt" in
        -m|--mode) mode="$2"; shift 2;;
        -i|--input) just_input=true; shift;;
        -o|--output) just_output=true; shift;;
        --) shift; break;;
        -*) die "Unexpected option: $opt";;
        *) files="$files $opt"; shift;;
    esac
done

if test -z "$files"; then
    files=pptests/*.c
fi

normalize() (
    sed -E 's/\s+/\n/g'
)

if test "$mode" = cpp; then
    # NOTE: -iquote specifies paths to be used with #include "..."
    pp() ( cpp -P -iquote pptests )
elif test "$mode" = loosey; then
    pp() ( python -m loosey.pp --local-dir pptests )
else
    die "Unrecognized mode: $mode"
fi

input() {
    awk 'BEGIN{x=1} /###+/{x=0} {if(x)print $0}' "$1"
}

actual() {
    input "$1" | pp
}

expected() {
    awk 'BEGIN{x=0} {if(x)print $0} /###+/{x=1}' "$1"
}

if test "$just_input" = true; then
    for file in $files; do
        input "$file"
    done
    exit 0
fi

n_files=0
for file in $files; do
    : $(( n_files++ ))
    echo
    echo "================================================================"
    echo "=== Testing file $n_files: $file"
    echo "=== Input:"
    input "$file"

    if test "$just_output" = true; then
        echo "=== Output:"
        actual "$file"
        continue
    fi

    echo "=== Actual vs expected output:"
    # NOTE: here are diff's whitespace/newline related options:
    #  -Z, --ignore-trailing-space     ignore white space at line end
    #  -b, --ignore-space-change       ignore changes in the amount of white space
    #  -w, --ignore-all-space          ignore all white space
    #  -B, --ignore-blank-lines        ignore changes where lines are all blank
    if diff -ZB "$@" <(actual "$file" | normalize) <(expected "$file" | normalize); then
        echo "OK!"
    else
        echo "*** FAIL"
        exit 1
    fi
done

echo
echo "================================================================"
echo "=== $n_files/$n_files FILES OK"
