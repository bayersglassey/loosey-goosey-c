
#/usr/bin/env bash
set -euo pipefail

# Run basic unit tests, including doctests
pytest

# Run preprocessor tests using GCC, TCC, and loosey
./pptests.sh -m gcc
./pptests.sh -m tcc
./pptests.sh -m loosey

# Run mini-C tests using GCC, TCC, and loosey
./minictests.sh -m gcc
./minictests.sh -m tcc
./minictests.sh -m loosey

# Run doctests on various public-facing documentation files
python -m doctest -f README.md
python -m doctest -f examples/cpython/reverse_slice.c
python -m doctest -f examples/regexp-bytecode.c
python -m doctest -f examples/sqlite/hash.c
