import os


def get_data_filepath(*parts) -> str:
    return os.path.join(os.path.dirname(__file__), 'data', *parts)
