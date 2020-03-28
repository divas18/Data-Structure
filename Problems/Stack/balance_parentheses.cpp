#include <iostream>
#include <stack>
using namespace std;

bool balance(string str)
{
	stack<char> st;
	int i = 0;

	while(str[i])
	{
		if(st.empty() || str[i] == '[' || str[i] == '{' || str[i] == '(')
			st.push(str[i]);
		else if(str[i] == ')' && st.top() == '(')
			st.pop();
		else if(str[i] == '}' && st.top() == '{')
			st.pop();
		else if(str[i] == ']' && st.top() == '[')
			st.pop();
		else
			return false;
		i++;
	}
	return st.empty();
}

int main()
{
	string str;
	cout << " Expression : ";
	cin >> str;
	balance(str) ? cout << " Balanced Expression\n" : cout << " Unbalanced Expression\n";
}
