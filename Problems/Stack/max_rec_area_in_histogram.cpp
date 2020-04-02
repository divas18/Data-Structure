#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, i;
        cin >> n;
        long arr[n], area, maxArea = 0;
        for(i = 0; i < n; i++)
            cin >> arr[i];

        stack<int> st;
        i = 0;
        while(i <= n)
        {
            if(st.empty() || (i < n && arr[st.top()] <= arr[i]))
                st.push(i++);
            else
            {
                    int top = st.top();
                    st.pop();
                    if(st.empty())
                        area = i * arr[top];
                    else
                        area = (i - st.top() - 1) * arr[top];
                    if(area > maxArea)
                        maxArea = area;
            }
        }
        cout << maxArea << "\n";
    }
}
