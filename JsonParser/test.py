import mypareser

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
        data3 = mypareser.myjson.load_json("shablon.json")
        while localcount != count:
            data[key] = value
            key = "key" + str(i)
            value = "value" + str(i)
            file_path = "data" + str(i) + expansion
            mypareser.myjson.dump_json(eval(mypareser.myjson._serialize(data)), file_path)
            localcount += 1
            if counter < 2:
                data[key] = data3
        key = "key"
        value = "value"
        localcount = 0
        i += 1
        counter += 1

def test():
    genarate_json_files(2)
    file_path = "data1.json"
    localdata = mypareser.myjson.load_json(file_path)
    mypareser.add_or_midify_field("key1", "newvalue", localdata, file_path)
    mypareser.add_or_midify_field("key2", "newvalue2", localdata, file_path)
    if localdata["key1"] != "newvalue" or localdata["key2"] != "newvalue2":
        return False
    mypareser.delete_field("data1.json", "key2")
    localdata = mypareser.myjson.load_json("data1.json")
    if "key2" in localdata:
        return False
    
    
    file_path = "data2.json"
    localdata = mypareser.myjson.load_json(file_path)
    
    mypareser.add_or_midify_field("key1.address.street", "newvalue", localdata, file_path)
    if localdata["key1"]["address"]["street"] != "newvalue":
        return False
    mypareser.delete_field(file_path, "key1")
    localdata = mypareser.myjson.load_json(file_path)
    if "key1" in localdata:
        return False
    
    return True
    