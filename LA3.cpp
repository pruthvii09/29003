
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

void addNode()
{
    struct node *temp = new node;
    cout << "\nENTER DATA : ";
    cin >> temp->data;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL) // tree is empty
    {
        root = temp;
    }
    else // when nodes are present
    {
        struct node *p = root;
        struct node *q;
        while (p != NULL)
        {
            q = p;
            if (p->data < temp->data) // comparing data for BST
            {
                p = p->right;
            }
            else
            {
                p = p->left;
            }
        }
        if (q->data < temp->data)
        {
            q->right = temp;
        }
        else
        {
            q->left = temp;
        }
    }
}

void inorderTraversal(struct node *p)
{
    if (p == NULL)
    {
        cout << "\nEMPTY TREE \n";
    }
    else
    {
        if (p->left != NULL)
        {
            inorderTraversal(p->left); // recursive call
        }
        cout << p->data << " ";
        if (p->right != NULL)
        {
            inorderTraversal(p->right);
        }
    }
}

void preorderTraversal(struct node *p)
{
    cout << p->data << " ";
    if (p->left != NULL)
    {
        preorderTraversal(p->left);
    }
    if (p->right != NULL)
    {
        preorderTraversal(p->right);
    }
}

void postorderTraversal(struct node *p)
{
    if (p->left != NULL)
    {
        postorderTraversal(p->left);
    }
    if (p->right != NULL)
    {
        postorderTraversal(p->right);
    }
    cout << p->data << " ";
}

int heightOfTree(struct node *p)
{
    if (p == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = heightOfTree(p->left);
        int rDepth = heightOfTree(p->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

int minValue(struct node *p)
{
    int min = p->data;
    while (p != NULL)
    {
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->left; // min value is found on left side
    }
    return min;
}

int maxValue(struct node *p)
{
    int max = 0;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->right; // max value is found on right side
    }
    return max;
}

void search1(struct node *p, int data)
{
    int flag = 0;
    while (p != NULL)
    {
        if (p->data == data)
        {
            flag = 1;
            break;
        }
        if (p->data < data) 
        {
            p = p->right;
        }

        if (p->data > data)
        {
            p = p->left;
        }
    }
    if (flag == 1)
    {
        cout << "FOUND";
    }
    else
    {
        cout << "NOT FOUND";
    }
}

void mirror(struct node *p)
{
    struct node *temp;
    if (p != NULL)
    {
        mirror(p->left);
        mirror(p->right);
        node *temp = p->left;
        p->left = p->right;
        p->right = temp;
    }
}

int main()
{
    int ch, nodes, value, no;
    while (true)
    {
        cout << "\nENTER YOUR CHOICE\n1]ADD NODES\n2]DISPLAY TRAVERSAL\n3]LARGEST ELEMENT\n4]SMALLEST ELEMENT\n5]HEIGHT OF TREE\n6]SEARCH ELEMENT\n7]SWAP POINTERS\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nHOW MANY NODES YOU WANT TO ADD : ";
            cin >> nodes;
            for (int i = 0; i < nodes; i++)
            {
                addNode();
            }
            break;
        case 2:
            cout << "\nINORDER TRAVERSAL : ";
            inorderTraversal(root);
            cout << "\nPREORDER TRAVERSAL : ";
            preorderTraversal(root);
            cout << "\nPOSTORDER TRAVERSAL : ";
            postorderTraversal(root);
            break;
        case 3:
            cout << "\nLARGEST ELEMENT : " << maxValue(root);
            break;
        case 4:
            cout << "\nSMALLEST ELEMENT : " << minValue(root);
            break;
        case 5:
            cout << "\nHEIGHT OF TREE : " << heightOfTree(root);
            break;
        case 6:
            cout << "\nENTER ELEMENT TO BE SEARCHED : ";
            cin >> value;
            search1(root, value);
            break;
        case 7:
            cout << "\nINORDER TRAVERSAL(BEFORE) : ";
            inorderTraversal(root);
            cout << "\nMIRROR ELEMENTS : ";
            mirror(root);
            cout << "\nINORDER TRAVERSAL(AFTER) : ";
            inorderTraversal(root);
            break;
        default:
            cout << "\nINVALID CHOICE";
        }
    }
    return 0;
}
