pytest --cov-report=html --cov lgci/ && (
    cd htmlcov/ && python3 -m http.server
)
