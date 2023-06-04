class Hashing:
    def __init__(self):
        self.size = int(input("Enter size of HASH TABLE: "))
        self.count = 0
        self.hashTable = [None for i in range(self.size)]

    def hashFunction(self, ele):
        return (ele % self.size)

    def isFull(self):
        if (self.count == self.size):
            return True
        else:
            return False

    def inserting(self, ele):
        if (self.isFull()):
            print("\nHASH TABLE is full...")
        else:
            if (self.hashTable[self.hashFunction(ele)] == None):
                self.hashTable[self.hashFunction(ele)] = ele
                self.count += 1
                print(self.hashTable)
            else:
                self.collision(ele)

    def search(self, ele):
        hash_key = self.hashFunction(ele)
        flag = 0
        if (self.hashTable[hash_key] == ele):
            print("Found!!")
            flag = 1
        else:
            for i in range(hash_key, self.size):
                if (self.hashTable[i] == ele):
                    print("Found")
                    flag = 1
                    break
            else:
                for i in range(hash_key):
                    if (self.hashTable[i] == ele):
                        print("Found")
                        flag = 1
                        break
        if (flag == 0):
            print("Not Found")

    def collision(self, ele):
        print("\n1-Linear Probing\n2-Quadratic Probing\n")
        ch = int(input("Enter your choice: "))
        match(ch):
            case 1:
                self.linear(ele)
            case 2:
                self.quadratic(ele)

    def linear(self, ele):
        hk = self.hashFunction(ele)
        flag = 0
        for i in range(hk, self.size):
            if (self.hashTable[i] == None):
                self.hashTable[i] = ele
                self.count += 1
                flag = 1
                print("\nElement placed successfully!!\n")
                print(self.hashTable)
                break

        if (flag == 0):
            for i in range(hk):
                if (self.hashTable[i] == None):
                    self.hashTable[i] = ele
                    self.count += 1
                    flag = 1
                    print("\nElement placed successfully!!\n")
                    print(self.hashTable)
                    break

    def quadratic(self, ele):
        y = self.hashFunction(ele)
        flag = 0
        for i in range(self.size):
            h1 = (y + (i**2)) % self.size
            if (self.hashTable[h1] == None):
                self.hashTable[h1] = ele
                flag = 1
                self.count += 1
                print("\nElement placed successfully!!\n")
                print(self.hashTable)
                break
        if (flag == 0):
            print("\nThis element cannot be placed!")


obj = Hashing()
n = int(input("Enter how many numbers you want to add: "))
for i in range(n):
    ele1 = int(input("\nEnter Phone No. to insert: "))
    obj.inserting(ele1)

qwerty = int(input("\nEnter Search: "))
obj.search(qwerty)
asd = int(input("\nEnter Search: "))
obj.search(asd)
