rm -rf dist

# Equivalent to --sdist, then running again with --wheel
python -m build
