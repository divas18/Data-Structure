#include <iostream>
using namespace std;

void cubes(int n) {
  for (int i = 1; i <= n; i++)
       cout << i * i * i << ' ';
}

void RecursiveCubes(int n)
{
    if(n)
    {
        RecursiveCubes(n-1);
        cout << n * n *n << " ";
    }
}

int main()
{
    int n;
    cout << " n = ";
    cin >> n;
    cout << " Interative Method : ";
    cubes(n);
    cout << "\n Recursive Method : ";
    RecursiveCubes(n);
    cout << "\n";
}
