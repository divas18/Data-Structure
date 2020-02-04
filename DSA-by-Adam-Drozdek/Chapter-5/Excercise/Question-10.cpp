#include <iostream>
using namespace std;

double func(int n)
{
    if(n > 1 && n%2)
    {
        return -1/(double)n + func(n-1);
    }
    if(n > 1 && n%2==0)
    {
        return 1/(double)n + func(n-1);
    }
    return 1.0;
}

int main()
{
    int n;
    cout << " n = ";
    cin >> n;
    double ans = func(n);
    cout << " Sum : " << ans;
    cout << "\n";
}
