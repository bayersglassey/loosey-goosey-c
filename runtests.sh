#/usr/bin/env bash
set -euo pipefail

venv/bin/pytest

python -m doctest README.md

./pptests.sh

./minictests.sh
