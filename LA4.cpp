#include <iostream>
#include <cstring>
using namespace std;

struct node
{
    char word[10];
    string meaning;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void adWord()
{
    struct node *temp = new node;
    cout << "\nENTER WORD : ";
    cin >> temp->word;
    cout << "\nENTER MEANING : ";
    cin.get();
    getline(cin, temp->meaning);

    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p = root;
        struct node *q;
        while (p != NULL)
        {
            q = p;
            if (strcmp(temp->word, p->word) < 0) // compares string lexographically
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        if (strcmp(temp->word, q->word) < 0)
        {
            q->left = temp;
        }
        else
        {
            q->right = temp;
        }
    }
}

void displayWord(struct node *p)
{
    if (p->left != NULL)
    {
        displayWord(p->left);
    }
    cout << "\nWORD : " << p->word << "   "
         << "MEANING : " << p->meaning;
    if (p->right != NULL)
    {
        displayWord(p->right);
    }
}

void searchAndUpdate(struct node *p, char word[10])
{
    string newMeaning;
    // searching the first
    if (strcmp(word, p->word) < 0)
    {
        searchAndUpdate(p->left, word);
    }
    if (strcmp(word, p->word) > 0)
    {
        searchAndUpdate(p->right, word);
    }

    if (strcmp(word, p->word) == 0) // updating the word
    {
        cout << "\nENTER NEW MEANING OF WORD : ";
        cin.get();
        getline(cin, newMeaning);

        p->meaning = newMeaning;    
    }
}

int count = 0;
void noOfComparisons(struct node *p, char word[10])
{
    count++;
    if (strcmp(word, p->word) == 0)  // == 0 states word and p->word are same
    {
        cout << "\nTOTAL COMPARISONS : " << count;
        count = 0;
    }
    if (strcmp(word, p->word) < 0)
    {
        noOfComparisons(p->left, word);
    }
    if (strcmp(word, p->word) > 0)
    {
        noOfComparisons(p->right, word);
    }
}
int main()
{
    int ch, words;
    char newWord[10];
    while (true)
    {
        cout << "\n1.Insert The Data:" << endl;
        cout << "2.Display the Data" << endl;
        cout << "3.Search and Update" << endl;
        cout << "4.Find the Number of Comparisons" << endl;

        cout << "\nEnter the Choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nHow many words you want to add : ";
            cin >> words;
            for (int i = 1; i <= words; i++)
            {
                adWord();
            }
            break;
        case 2:
            displayWord(root);
            cout << endl;
            break;
        case 3:
            cout << "\nEnter word to search and update : ";
            cin >> newWord;
            searchAndUpdate(root, newWord);
            break;
        case 4:
            cout << "\nEnter word to check no of comparisons : ";
            cin >> newWord;
            noOfComparisons(root, newWord);
            break;
    }
    return 0;
}
