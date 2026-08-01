pytest --cov-report=html --cov src/ && (
    cd htmlcov/ && python3 -m http.server
)
