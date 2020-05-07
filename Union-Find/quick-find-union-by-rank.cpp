/**
 * @Author: ADITYA KUMAR SINGH <the__martian>
 * @Filename: quick-find-union-by-rank.cpp
 * @Last modified by:   the__martian
 */

// Union-by-rank

#include <iostream>
#include <vector>
using namespace std;

struct QuickFind
{
    int par, rank;
};
vector<QuickFind> parent;
int number_of_sets = 0;

void MakeSet(int x)
{
    parent[x].rank = 0;
    parent[x].par = x;
    number_of_sets++;
}

int Find(int x)
{
    while(parent[x].par != x)
        x = parent[x].par;
    return x;
}

void Union(int x, int y)
{
    auto r = Find(x);
    auto s = Find(y);

    if(r == s)
        return;
    if(parent[r].rank > parent[s].rank)
        parent[s].par = r;
    else if(parent[s].rank > parent[r].rank)
        parent[r].par = s;
    else
    {
        parent[r].par = s;
        parent[s].rank++;
    }
}


int main()
{
    cout << "Set(s)\n";
    cout << "{0}, {9,3,2,4,7}, {5}, {6,1,8}\n";
    int n = 10;
    parent.resize(n);
    for(int i = 0; i < n; i++)
        MakeSet(i);

    cout << "Number of sets : " << number_of_sets << "\n";
    Union(9,3);
    Union(2,4);
    Union(9,7);
    cout << "Number of sets : " << number_of_sets << "\n";
    Union(2,9);
    Union(6,8);
    Union(1,8);
    cout << "Number of sets : " << number_of_sets << "\n";
    if(Find(9) == Find(2))
        cout << 9 << " and " << 2 << " are in same set.\n";
    else
        cout << 9 << " and " << 2 << " are not in same set.\n";

    if(Find(7) == Find(5))
        cout << 7 << " and " << 5 << " are in same set.\n";
    else
        cout << 7 << " and " << 5 << " are not in same set.\n";

    if(Find(1) == Find(8))
        cout << 1 << " and " << 8  << " are in same set.\n";
    else
        cout << 1 << " and " << 8  << " are not in same set.\n";

    if(Find(5) == Find(0))
        cout << 5 << " and " << 0 << " are in same set.\n";
    else
        cout << 5 << " and " << 0 << " are not in same set.\n";
}
