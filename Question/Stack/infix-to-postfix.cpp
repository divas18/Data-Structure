#include <iostream>
#include <stack>
using namespace std;

int Precedence(char c)
{
    if(c == '+' || c == '-')
        return 1;
    if(c == '*' || c == '/')
        return 2;
    return 3;
}
int IsOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

string Infix_to_postfix(string str)
{
    stack<char> st;
    string ans;
    for(int i = 0; str[i]; i++)
    {
        if(IsOperand(str[i]))
        {
            ans += str[i];
        }
        else
        {
            if(str[i] == '(' || str[i] == '^')
            {
                st.push(str[i]);
            }
            else if(str[i] == ')')
            {
                while(!st.empty()&&st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(!st.empty() && Precedence(str[i]) > Precedence(st.top()))
            {
                st.push(str[i]);
            }
            else if(!st.empty() && Precedence(str[i]) <= Precedence(st.top()))
            {
                while(!st.empty() && Precedence(str[i]) <= Precedence(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
        }
    }
    return ans;
}

int main()
{
    string s;
    cout << " ";
    cin >> s;
    s = Infix_to_postfix(s);
    cout << " " << s <<"\n";
}
