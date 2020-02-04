#include <iostream>
using namespace std;

int gcd(int n, int m)
{
    if(m <= n && n%m == 0)
        return m;
    if(n < m)
        return gcd(m,n);
    return gcd(m, n%m);
}
int main()
{
    int n;
    cout << " n = ";
    cin >> n;
    int m;
    cout << " m = ";
    cin >> m;
    cout << " GCD(n,m) : " << gcd(n,m);
    cout << "\n";
}
