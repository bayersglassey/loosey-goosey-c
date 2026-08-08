#/usr/bin/env bash
#
# Uploads our Python packages to pypi
# NOTE: this script assumes the packages have already been built!
# See: ./build.sh
#
set -euo pipefail

twine upload --verbose dist/*
