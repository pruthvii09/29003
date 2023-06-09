// Read the marks obtained by students of second year in an online examination of
// particular subject. Find out maximum and minimum marks obtained in that subject.
#include <iostream>
using namespace std;
#define max 20
class stud
{
  int mks[max];

public:
  stud()
  {
    for (int i = 0; i < max; i++)
      mks[i] = 0;
  }
  void insertheap(int tot);
  void insertMaxheap(int tot);
  void showmax(int tot);
  void displayheap(int tot);
  void showmin();
};

void stud::insertheap(int tot)
{
  for (int i = 1; i <= tot; i++)
  {
    cout << "enter marks";
    cin >> mks[i];
    int j = i;
    int par = j / 2;
    while (mks[j] <= mks[par] && j != 0)
    {
      int tmp = mks[j];
      mks[j] = mks[par];
      mks[par] = tmp;
      j = par;
      par = j / 2;
    }
  }
}
void stud::insertMaxheap(int tot)
{
  for (int i = 0; i < tot; i++)
  {
    cout << "Enter marks: ";
    cin >> mks[i];

    int child = i;
    int parent = child / 2;

    while (child > 0 && mks[child] > mks[parent])
    {
      int temp = mks[child];
      mks[child] = mks[parent];
      mks[parent] = temp;

      child = parent;
      parent = child / 2;
    }
  }
}

void stud::displayheap(int tot)
{
    for (int i = 1; i <= tot; i++)
    {
      cout << "hii : " << mks[i] << endl;
    }
  int i = 1, level = 1, count = 0, space = 6;
  while (i <= tot)
  {
    if (i == 2 || i == 4 || i == 8 || i == 16 || i == 1)
    {
      cout << endl
           << endl;
      for (int j = 0; j < space; j++)
      {
        cout << " ";
      }
      space -= 2;
    }
    cout << mks[i] << " ";
    // if (count == level)
    // {
    //   cout << endl;
    //   count = 0;
    //   level *= 2;
    // }
    i++;
  }
}

void stud::showmax(int tot)
{
  int max1 = mks[1];
  for (int i = 2; i <= tot; i++)
  {
    if (max1 < mks[i])
      max1 = mks[i];
  }
  cout << "Max marks:" << max1;
}
void stud::showmin()
{
  cout << "Min marks:" << mks[0];
}
int main()
{
  int ch, cont, total, tmp;
  int n;
  stud s1;
  do
  {
    cout << "\nMenu\n1.Read marks of the student\n2.Show Max\n3.Show Min\nEnter Choice";
    cin >> ch;
    switch (ch)
    {
    case 1:
      cout << "how many students";
      cin >> total;
      s1.insertheap(total);
      break;
    case 2:
      s1.showmax(total);
      break;
    case 3:
      s1.showmin();
      break;
    case 4:
      s1.displayheap(total);
      break;
    }
    cout << "\ndo u want to continue?(1 for continue)";
    cin >> cont;
  } while (cont == 1);

  return 0;
}