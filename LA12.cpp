#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void add()
{
    ofstream file("student.txt", ios::app);
        int rollNumber;
        string name, division, address;
        
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cout << "Enter name: ";
        cin.ignore();    //to clear the Buffer
        getline(cin, name);
        cout << "Enter division: ";
        getline(cin, division);
        cout << "Enter address: ";
        getline(cin, address);
        file << rollNumber << " " << name << " " << division << " " << address << endl;
        
    file.close();
    cout << "Student information added successfully!" << endl;
}
void del()
{
    int rollNumbertodelete;
    cout << "Enter the roll number to delete: ";
    cin >> rollNumbertodelete;
    
    ifstream inputFile("student.txt");
    ofstream tempFile("temp.txt", ios::app);
    int flag =0;
    int RollNumber;
    string name, division, address;
    while (inputFile >> RollNumber >> name >> division >> address)
    {
        if (RollNumber != rollNumbertodelete)
        {
            tempFile << RollNumber << " " << name << " " << division << " " << address << endl;
        } else
        {
            flag=1;
        }
    }
    inputFile.close();
    tempFile.close();
    remove("student.txt");
    rename("temp.txt", "student.txt");
    
    if (flag==1)
    {
        cout << "Student information deleted successfully!" << endl;
    }
    else
    {
        cout << "Student record not found!" << endl;
    }
}
void display()
{
    int rollNumber;
    cout << "Enter the roll number to display: ";
    cin >> rollNumber;
    ifstream inputFile("student.txt");
    int flag =0;
    int RollNumber;
    string name, division, address;
    
    while (inputFile >> RollNumber >> name >> division >> address)
    {
        if (RollNumber == rollNumber)
        {
            flag =1;
            cout << "Roll Number: " << RollNumber << endl;
            cout << "Name: " << name << endl;
            cout << "Division: " << division << endl;
            cout << "Address: " << address << endl;
            break;
        }
    }
    inputFile.close();
    if (flag==0)
    {
        cout << "Student record not found!" << endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\n1. Add \n2. Delete\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                add();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
        }
    }while(choice<=3);
    return 0;
}
