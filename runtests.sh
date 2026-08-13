
#/usr/bin/env bash
set -euo pipefail

# Run basic unit tests, including doctests
pytest

# Run preprocessor tests using GCC and loosey
./pptests.sh -m gcc
./pptests.sh -m loosey

# Run mini-C tests using GCC and loosey
./minictests.sh -m gcc
./minictests.sh -m loosey

# Run doctests on various public-facing documentation files
python -m doctest README.md
python -m doctest examples/cpython/reverse_slice.c
python -m doctest examples/regexp-bytecode.c
python -m doctest examples/sqlite/hash.c
