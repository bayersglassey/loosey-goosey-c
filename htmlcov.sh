pytest --cov-report=html --cov loosey/ && (
    cd htmlcov/ && python3 -m http.server
)
