The `myparser` program is a console application in Python that provides functionality for parsing and manipulating JSON files. It allows users to add or delete fields in a JSON file through a command-line interface. The program consists of two main functions: `add_field` and `delete_field`.

## Functions

### 1. `add_field(file_path, user_input, new_value)`

This function adds a new field to a JSON file.

**Parameters:**
- `file_path` (string): The path to the JSON file.
- `user_input` (string): The full key name of the field to be added.
- `new_value` (any): The value to assign to the field.

**Example:**
```python
myparser.add_field("data.json", "key1", "newvalue")
```

### 2. `delete_field(file_path, user_input)`

This function deletes a field from a JSON file.

**Parameters:**
- `file_path` (string): The path to the JSON file.
- `user_input` (string): The full key name of the field to be deleted.

**Example:**
```python
myparser.delete_field("data.json", "key1")
```

## Usage

1. Import the `myparser` module in your Python script:
```python
import myparser
```

2. Run the `parse_json_file` function from the `myparser` module to start the command-line interface for interacting with the JSON file:
```python
myparser.parse_json_file("data.json")
```

3. The program will prompt the user to enter commands. The supported commands are:
- `add`: Adds a new field to the JSON file. The user will be prompted to enter the field name and the value.
- `del`: Deletes a field from the JSON file. The user will be prompted to enter the field name.

4. To add a new field, enter `add` when prompted for a command, followed by the field name and the value when prompted. For example:
```
Enter command (add/del/exit): add
Enter the full key name you want to add: key1
Enter the value for key1: newvalue
```

5. To delete a field, enter `del` when prompted for a command, followed by the field name when prompted. For example:
```
Enter command (add/del/exit): del
Enter the full key name you want to delete: key1
```

6. Repeat steps 4 and 5 as needed to add or delete more fields.

7. To exit the program, enter `exit` when prompted for a command.

Note: Ensure that the specified JSON file exists in the provided file path before executing the program.

Please refer to the provided example code for additional usage details and examples.
