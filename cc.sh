#/usr/bin/env bash
#
# A helper for testing C snippets quickly
#
set -euo pipefail

newline='
'

code="$1"
shift
while test "$#" -ge 1
do
    code="$code$newline$1"
    shift
done

fullcode="
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv) {
    $code
    return 0;
}
"

echo "$fullcode" | gcc -x c "$@" - || {
    echo "Code was:"
    echo "$fullcode"
    exit 1
}
./a.out
