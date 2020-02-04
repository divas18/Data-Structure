#include <iostream>
using namespace std;

void SyracuseSequence(int n)
{
    if(n > 1)
    {
        if(n%2==0)
        {
            cout << n << " -> ";
            SyracuseSequence(n/2);
        }
        else
        {
            cout << n << " -> ";
            SyracuseSequence(3*n+1);
        }
    }
    if(n == 1)
        cout << 1 ;
}

int main()
{
    int n;
    cout << " n = ";
    cin >> n;
    SyracuseSequence(n);
    cout << "\n";
}
