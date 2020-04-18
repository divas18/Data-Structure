#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> ppi;

vector<int> kWayMerge(vector<vector<int>> &list)
{
    int k = list.size();
    priority_queue<ppi, vector<ppi>, greater<ppi>> minHeap;

    for(int i = 0; i < k; i++)
    {
        minHeap.push({list[i][0],{i,0}});
    }

    vector<int> merged_list;
    while(!minHeap.empty())
    {
        auto el = minHeap.top();
        merged_list.push_back(el.first);
        minHeap.pop();

        auto x = el.second.first, y = el.second.second;
        if(list[x].size() > y+1)
        {
            minHeap.push({list[x][y+1],{x,y+1}});
        }
    }
    return merged_list;
}

int main()
{
    vector<vector<int>> list;
    cout << "Number of sorted list : ";
    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cout << "Number of element list " << i + 1 << "\n";
        int n;
        cin >> n;
        vector<int> temp(n);
        for(int i = 0; i < n; i++)
            cin >> temp[i];
        list.push_back(temp);
    }
    cout << "Merged list : ";
    auto merged_list = kWayMerge(list);
    for(auto x : merged_list)
        cout << x << " ";
    cout << "\n";
}
