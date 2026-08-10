#/usr/bin/env bash
set -euo pipefail

venv/bin/pytest

python -m doctest README.md

# Run preprocessor tests using GCC and loosey
./pptests.sh -m gcc
./pptests.sh -m loosey

# Run mini-C tests using GCC and loosey
./minictests.sh -m gcc
./minictests.sh -m loosey
