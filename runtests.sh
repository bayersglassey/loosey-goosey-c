#/usr/bin/env bash
set -euo pipefail

venv/bin/pytest

# Run preprocessor tests using GCC and loosey
./pptests.sh -m gcc
./pptests.sh -m loosey

# Run mini-C tests using GCC and loosey
./minictests.sh -m gcc
./minictests.sh -m loosey

# Run doctests on various public-facing documentation files
python -m doctest README.md
python -m doctest examples/reverse_slice.c
