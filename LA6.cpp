// BFS and DFS
#include <iostream>
using namespace std;

class BfsDfs
{
    int cost[10][10], n, qu[10], front, rear, visit[10];
     int stk[10], top, visit1[10], m;

public:
    void init();
    void create();
    void display();
    void dfs();
    void bfs();
};

void BfsDfs::init()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cost[i][j] = 0;
            visit1[i] = 0;
            visit[i] = 0;
            qu[i] = 0;
            stk[i] = 0;
        }
    }
}
void BfsDfs::create()
{
    init();
    int i, j;
    cout << "Enter number of vertices : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> m;
    cout << "\n Enter EDGES :\n";
    for (int k = 0; k < m; k++)
    {
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1;
    }
}

void BfsDfs::display()
{
    cout << "The adjacency matrix of the graph is : \n"
         << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }
}

void BfsDfs::bfs()
{
    front = 0;
    rear = 0;
    int v;
    cout << "Enter initial vertex for bfs: ";
    cin >> v;
    cout << "The BFS of the Graph is\n";
    cout << v << " ";
    visit[v] = 1;
    int k = 1;
    while (k < n)
    {
        for (int j = 0; j < n; j++)
        {
            if (cost[v][j] == 1 && visit[j] != 1)
            {
                visit[j] = 1;
                qu[rear++] = j;
            }
        }
        v = qu[front++];
        cout << v << " ";
        k++;
    }
}

void BfsDfs::dfs()
{
    top = 0;
    int v;
    cout << endl
         << "Enter initial vertex for dfs: ";
    cin >> v;
    cout << "The DFS of the Graph is\n";
    cout << v << " ";
    visit1[v] = 1;
    int k = 1;
    while (k < n)
    {
        for (int j = n - 1; j >= 0; j--)
            if (cost[v][j] == 1 && visit1[j] != 1)
            {
                visit1[j] = 1;
                stk[top] = j;
                top++;
            }
        v = stk[--top];
        cout << v << " ";
        k++;
    }
}
int main()
{
    int choice;
    BfsDfs obj;
    do
    {
        cout << "\n\t1-Create\n\t2-Display\n\t3-BFS\n\t4-DFS\n\t5-Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.create();
            break;

        case 2:
            obj.display();
            break;

        case 3:
            obj.bfs();
            break;

        case 4:
            obj.dfs();
            break;

        case 5:
            cout << "\n---THANK YOU---";
            break;

        default:
            cout << "\nInvalid choice!!";
            break;
        }
    } while (choice != 5);
    return 0;
}