def load_json(file_path):
    with open(file_path, 'r') as json_file:
        data_str = json_file.read()
        data = eval(data_str)
    return data

def dump_json(data, file_path):
    with open(file_path, 'w') as json_file:
        json_str = _serialize(data)
        json_file.write(json_str)
        
def delete_field(file_path, user_input):
    data = load_json(file_path)
    print("Original data:", data)

    field_to_delete = user_input
    keys = field_to_delete.split('.')
    current_data = data
    for index, key in enumerate(keys):
        if key not in current_data:
            print(f"Key '{key}' not found!")
            break
        if index == len(keys) - 1:
            del current_data[key]
            print(f"Field '{field_to_delete}' removed from JSON.")
        else:
            current_data = current_data[key]

    dump_json(data, file_path)
    print("Data saved.")
    
def add_or_midify_field(user_input, new_value , data, file_path):
    keys = user_input.split('.')
    current_data = data
    for index, key in enumerate(keys):
        if key not in current_data:
            if index == len(keys) - 1:
                new_value = new_value
                current_data[key] = new_value
                print(f"'{user_input}' created with value '{new_value}'.")
            else:
                current_data[key] = {}
                current_data = current_data[key]
                print(f"Created new key '{key}'.")
        else:
            if index == len(keys) - 1:
                new_value = new_value
                current_data[key] = new_value
                print(f"'{user_input}' updated to '{new_value}'.")
            else:
                current_data = current_data[key]
    dump_json(data, file_path)
    print("Data saved.")

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

def genarate_json_files(count):
    i = 1
    file = f"data{i}"
    expansion = ".json"
    
    data = {}
    localcount = 0
    key = "key1"
    value = "value1"
    
    global counter
    counter = 0

    
    while i != count+1:
        data3 = load_json("shablon.json")
        while localcount != count:
            data[key] = value
            key = "key" + str(i)
            value = "value" + str(i)
            file_path = "data" + str(i) + expansion
            dump_json(eval(_serialize(data)), file_path)
            localcount += 1
        if counter < 2:
            data[key] = data3
        key = "key"
        value = "value"
        localcount = 0
        i += 1
        counter += 1

def parse_json_file(file_path):
    data = load_json(file_path)
    print("Original data:", data)
    while True:
        user_input = input("Enter the full key name you want to modify: ")
        operation_input = input("Select Operation 'add' - (add or modify) or 'del' - (delete) or 'exit': ")

        if operation_input == 'add':
            
            add_or_midify_field(user_input, data, file_path)
        elif operation_input == 'del':
            delete_field(file_path, user_input)

        elif operation_input == 'exit':
            break

def test():
    genarate_json_files(2)
    file_path = "data1.json"
    localdata = load_json(file_path)
    add_or_midify_field("key1", "newvalue", localdata, file_path)
    add_or_midify_field("key2", "newvalue2", localdata, file_path)
    if localdata["key1"] != "newvalue" or localdata["key2"] != "newvalue2":
        return False
    delete_field("data1.json", "key2")
    localdata = load_json("data1.json")
    if "key2" in localdata:
        return False
    
    
    file_path = "data2.json"
    localdata = load_json(file_path)
    
    add_or_midify_field("key1.address.street", "newvalue", localdata, file_path)
    if localdata["key1"]["address"]["street"] != "newvalue":
        return False
    delete_field(file_path, "key1")
    localdata = load_json(file_path)
    if "key1" in localdata:
        return False
    
    return True
    
    
# print(test()) # test function
parse_json_file("my_data.json")  #main function
