def load_json(file_path):
    with open(file_path, 'r') as json_file:
        data_str = json_file.read()
        data = eval(data_str)
    return data

def dump_json(data, file_path):
    with open(file_path, 'w') as json_file:
        json_str = _serialize(data)
        json_file.write(json_str)
        
def _serialize(data, indent_level=0):
    indent = " " * 3 * indent_level
    next_indent = " " * 3 * (indent_level + 1)

    if isinstance(data, dict):
        items = []
        for key, value in data.items():
            serialized_value = _serialize(value, indent_level + 1)
            items.append(f'{next_indent}"{key}": {serialized_value}')
        return "{{\n{items}\n{indent}}}".format(
            items=",\n".join(items),
            indent=indent
        )
    elif isinstance(data, list):
        items = [_serialize(item, indent_level + 1) for item in data]
        return "[\n{items}\n{indent}]".format(
            items=",\n".join(items),
            indent=indent
        )
    elif isinstance(data, str):
        return f'"{data}"'
    else:
        return str(data)
