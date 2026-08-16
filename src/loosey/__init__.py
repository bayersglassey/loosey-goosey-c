import os

def bool_env_var(name: str, default: bool = False) -> bool:
    return os.environ.get(name, '1' if default else '0').lower() in ('1', 'true')

def get_data_filepath(*parts) -> str:
    return os.path.join(os.path.dirname(__file__), 'data', *parts)
