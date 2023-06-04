// GRAPH
//  There are flight paths between cities. If there is a flight between city A and city B
//  then there is an edge between the cities. The cost of the edge can be the time that flight
//  take to reach city B from A, or the amount of fuel used for the journey. Represent this
//  as a graph. The node can be represented by airport name or name of the city. Use
//  adjacency list representation of the graph or use adjacency matrix representation of
//  the graph. Check whether the graph is connected or not. Justify the storage
//  representation used.
#include <iostream>
#include <cstring>
using namespace std;

class graph_matrix
{
public:
    int dist[20][20], num;
    char a[7][50], ch;

    graph_matrix()
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                a[i][j] = 0;
            }
        }
    }
    void add()
    {
        cout << "\n\tEnter The Number Of Cities:";
        cin >> num;
        for (int i = 1; i <= num; i++)
        {
            cout << "\n\t\tEnter The Name OF City " << i << ":";
            cin >> a[i];
        }
    }

    void route()
    {
        for (int i = 1; i <= num; i++)
        {
            for (int j = i; j <= num; j++)
            {
                if (i == j)
                {
                    dist[i][j] = 0;
                }
                else
                {
                    cout << "\nIs there flight path between cities " << i << " and " << j << " ?(y/n): ";
                    cin >> ch;
                    if (ch == 'y' || ch == 'Y')
                    {
                        cout << "Enter Distance between City Aiprorts(Kms): "; // time
                        cin >> dist[i][j];                                     // time[i][j]

                        dist[j][i] = dist[i][j];
                    }
                    else
                    {
                        dist[i][j] = dist[j][i] = -1;
                    }
                }
            }
        }
    }

    void display()
    {
        cout << "\nDistance Matrix: \n";
        for (int i = 1; i <= num; i++)
        {
            cout << "\t";
            cout << a[i];
        }
        cout << endl;
        for (int i = 1; i <= num; i++)
        {
            cout << a[i];
            for (int j = 1; j <= num; j++)
            {
                cout << "\t" << dist[i][j]; // time[i][j]
            }
            cout << endl;
        }
    }

} m;
int main()
{
    int ch;
    while (true)
    {

        cout << "\n\t1. Enter Data";
        cout << "\n\t2. Display Routes";
        cout << "\n\t3. Exit";

        cout << "\n\tEnter option no.:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            m.add();
            m.route();
            break;  
        case 2:
            m.display();
            break;
        case 3:
            cout << "End of program";
            break;
        default:
            cout << "Invalid Choice!!!";
        }
    }
    return 0;
}
