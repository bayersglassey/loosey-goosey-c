#/usr/bin/env bash
#
# Builds Python packages for pypi distribution
#
set -euo pipefail

rm -rf dist

# Equivalent to --sdist, then running again with --wheel
python -m build
