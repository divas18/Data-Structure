#include <iostream>
using namespace std;

long BinomialCoefficient(int n, int k)
{
    if(k==0 || k == n)
        return 1;
    return BinomialCoefficient(n-1,k-1)  + BinomialCoefficient(n-1, k);
}

int main()
{
    int n, k;
    cout << " n = ";
    cin >> n;
    cout << " k = ";
    cin >> k;
    cout << " nCk : " << BinomialCoefficient(n,k);
    cout << "\n";
}
