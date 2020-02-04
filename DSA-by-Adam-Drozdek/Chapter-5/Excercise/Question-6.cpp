#include <iostream>
using namespace std;

void putCommas(char *s, int n)
{
    static int i = 0, j =0;
    if(n)
    {
        putCommas(s,n/10);
        s[j++] = (char) n%10;
        i = (i+1)%3;
        if(!i)
            s[j++] = ',';
    }
}
int main()
{
    int n = 12345;
    char str[10] = "\0";
    putCommas(str,n);
    for(int i = 0; str[i]; i++)
        cout.put(str[i]);
    cout << "\n";
}
