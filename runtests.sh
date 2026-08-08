set -euo pipefail

venv/bin/pytest

./pptests.sh

./minictests.sh
