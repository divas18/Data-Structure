#include <bits/stdc++.h>
using namespace std;
string minRemoveToMakeValid(string s) {
        string res = "";
        deque<pair<char, int>> dq;
        int len = s.size();
        for(int i = 0; i < len; i++)
        {
            if(s[i] != ')' && s[i] != '(')
                continue;
            if(dq.empty() || s[i] == '(')
            {
                dq.push_back(make_pair(s[i],i));
            }
            else if(s[i] == ')')
            {
                if(dq.back().first == '(')
                    dq.pop_back();
                else
                    dq.push_back(make_pair(s[i],i));
            }
        }
        for(int i = 0; i < len; i++)
        {
            if(i != dq.front().second)
                res += s[i];
            else
                dq.pop_front();
        }
        return res;
    }
int main()
{
	string str;
	cin >> str;
	str = minRemoveToMakeValid(str);
	cout << str << "\n";
}
