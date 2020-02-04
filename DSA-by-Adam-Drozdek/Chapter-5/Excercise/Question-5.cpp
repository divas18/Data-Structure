#include <iostream>
using namespace std;

void oddBetweenOneAndN(int n)
{
    if(n < 1)
        return;
    if(n%2==0)
        oddBetweenOneAndN(n-1);
    if(n%2)
    {
        oddBetweenOneAndN(n-2);
        cout<<" " << n;
    }
}
void oddBetweenNAndOne(int n)
{
    if(n < 1)
        return;
    if(n%2==0)
        oddBetweenNAndOne(n-1);
    if(n%2)
    {
        cout<<" " << n;
        oddBetweenNAndOne(n-2);
    }
}
int main()
{
    int n;
    cout << " n = ";
    cin >> n;
    cout << " Odd Between 1 and N\n";
    oddBetweenOneAndN(n);
    cout << "\n";
    cout << " Odd Between N and 1\n";
    oddBetweenNAndOne(n);
    cout << "\n";
}
