#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')')
        return false;
    return true;
}

int precedence(char c)
{
    if(c == '+' || c == '-')
        return 1;
    if(c == '*' || c == '/')
        return 2;
    return 3;
}

string infixToPostfix(string str)
{
    string ans = "\0";
    stack<char> st;
    for(int i = 0; i < str.size(); i++)
    {
        if(isOperand(str[i]))
            ans += str[i];
        else if(str[i] == ')')
        {
            while(st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if(st.empty() || str[i] == '(' || (str[i] == '^' && st.top() == '^') || precedence(str[i]) > precedence(st.top()))
            {
                st.push(str[i]);
            }
            else
            {
                while(!st.empty() && st.top() != '(' && precedence(st.top()) >= precedence(str[i]))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(str[i]);
            }
        }
    }
    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;
    cout << " Postfix : " << infixToPostfix(str) << "\n";
}
