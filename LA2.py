class KeyValuePair:
    def __init__(self, key, value):
        self.key = key
        self.value = value


class Dictionary:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]

    def _hash_function(self, key):
        return hash(key) % self.size

    def insert(self, value, key):
        hash_key = self._hash_function(key)
        slot = self.table[hash_key]
        slot.append(KeyValuePair(key, value))

    def display(self):
        for i, slot in enumerate(self.table):
            print(f"\nIndex {i} : ")
            for pair in slot:
                print(f"Key : {pair.key} Value : {pair.value} --> ", end='')

    def find(self, key):
        hash_key = self._hash_function(key)
        slot = self.table[hash_key]
        for pair in slot:
            if pair.key == key:
                return pair.value
        return None

    def delete(self, key):
        hash_key = self._hash_function(key)
        slot = self.table[hash_key]
        for index, pair in enumerate(slot):
            if pair.key == key:
                del slot[index]
                return
        raise KeyError("Key not found in the dictionary.")


dict = Dictionary(10)
while (True):
    print("\n1.Insert Value\n.2.Find\n3.Delete\n4.Display")
    ch = int(input("Enter Your Choice : "))
    match(ch):
        case 1:
            key = int(input("Enter Key : "))
            value = input("Enter Value : ")
            dict.insert(key, value)
        case 2:
            key = int(input("Enter Key to Find: "))
            dict.find(key)
        case 3:
            key = int(input("Enter Key to Find: "))
            dict.delete(key)
        case 4:
            dict.display()
