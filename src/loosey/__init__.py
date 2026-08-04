import os


def get_data_filename(*parts) -> str:
    return os.path.join(os.path.dirname(__file__), 'data', *parts)
