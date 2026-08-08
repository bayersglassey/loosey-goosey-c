#/usr/bin/env bash
#
# A helper for testing C snippets quickly
#
set -euo pipefail

code="$1"
shift

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
}
./a.out
