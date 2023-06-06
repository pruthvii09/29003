class dictionary:
    def _init_(self):
        self.size = int(input("Enter the Size of Hash Table: "))
        self.word=[-1 for i in range(self.size)]
        self.meaning=[-1 for i in range(self.size)] 
        self.chain=[-1 for i in range(self.size)]
        self.count = 0
	
    def isFull(self):
        if self.count == self.size:
                return True
        else:
                return False
                
    def display_hash():
        for i in range(len(hashTable)):
                print(self.word[i], " --> ",self.meaning[i],end = " ")
                print()

    def inserting(self,ele,mean,key):
        if self.isFull():
	        print("HASH TABLE is FULL")
        else:
	        if(self.word[key] == -1):
		        self.word[key] = ele
		        self.meaning[key]= mean
		        self.count+=1
		        for i in range(len(self.word)):
		            print(self.word[i], "-->", self.meaning[i],end=" ")
		            print()
	        else:
	            self.i =key
	            while self.word[self.i] != -1:
	                self.i+=1
	            self.word[self.i]=ele
	            self.meaning[self.i]=mean
	            self.count+=1
	            self.chain[key]=self.i
	            for i in range(len(self.word)):
		            print(self.word[i], "-->", self.meaning[i],end=" ")
		            print()
   
    def searching(self,ele,key):
        self.k=key
        if(self.word[self.k]==ele):
                print("If Working")
                print("Meaning for Word is", self.meaning[self.k])
        else:
                self.j=self.chain[self.k]
                if(self.word[self.j]==ele):
                    print("Meaning for Word is", self.meaning[self.j])
                    
                else:    
                    while(self.word[self.j]!=ele):
                            self.j=self.chain[self.j]
                    print("Meaning for Word is", self.meaning[self.k])
        
    def deleting(self,ele,key):
        for i in range(self.size):
            if(self.word[i]==ele):
                self.word[i]=-1
                self.meaning[i]=-1
                self.chain[key]=-1
                print("Deleted")
                break
        else:
            print("element Not found")
    
    def display(self):
        for i in range(len(self.word)):
            print(self.word[i], "-->", self.meaning[i],end=" ")
            print()
            
obj = dictionary()
for j in range(1000):
    ch=int(input("\n 1.Insert data \n 2. Find data \n 3 Delete Word \n 4 Display \n 5 Exit \n:-"))
    if(ch==1):
        for i in range(int(input("Enter the Number of Data elements"))): 
                print("For" , i+1, "th")
                key=int(input("Enter the key: " ))
                ele1 =input("Enter the Word: ")	
                mean =input("Enter the Meaning: ") 
                obj.inserting(ele1,mean,key)
    elif(ch==2):        
        ele=input("Enter the Word to Find Meaning: ")
        key=int(input("Enter the key for that word: " ))
        obj.searching(ele,key)     
    
    elif(ch==3):
        ele=input("Enter the Word to Delete Meaning: ")
        key=int(input("Enter the key for that word: " ))
        obj.deleting(ele,key)
        
    elif(ch==4):
        obj.display()
    elif(ch==5):
        print("Exit")
    
    else:
        print("Invalid Choice")
