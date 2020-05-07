/**
 * @Author: ADITYA KUMAR SINGH <the__martian>
 * @Filename: quick-find.cpp
 * @Last modified by:   the__martian
 * @Github: ADITYA-CS
 */

// N A I V E - I M P L E M E N T A T I O N
// Array representation

#include <iostream>
#include <algorithm>
using namespace std;

class UnionFind{
private:
    int *arr_;
    int size_;
public:
    UnionFind(int n);
    void makeSet(int n);
    int Find(int n);
    void Union(int a, int b);
};

int main()
{
    cout << "Set(s)\n";
    cout << "{0}, {9,3,2,4,7}, {5}, {6,1,8}\n";
    int n = 10;
    UnionFind uf(n);
    for(int i = 0; i < n; i++)
        uf.makeSet(i);
    uf.Union(9,3);
    uf.Union(2,4);
    uf.Union(9,7);
    uf.Union(2,9);
    uf.Union(6,8);
    uf.Union(1,8);

    if(uf.Find(9) == uf.Find(2))
        cout << 9 << " and " << 2 << " are in same set.\n";
    else
        cout << 9 << " and " << 2 << " are not in same set.\n";

    if(uf.Find(7) == uf.Find(5))
        cout << 7 << " and " << 5 << " are in same set.\n";
    else
        cout << 7 << " and " << 5 << " are not in same set.\n";

    if(uf.Find(1) == uf.Find(8))
        cout << 1 << " and " << 8  << " are in same set.\n";
    else
        cout << 1 << " and " << 8  << " are not in same set.\n";

    if(uf.Find(5) == uf.Find(0))
        cout << 5 << " and " << 0 << " are in same set.\n";
    else
        cout << 5 << " and " << 0 << " are not in same set.\n";
}

UnionFind :: UnionFind(int n)
{
    size_ = n;
    arr_ = new int[size_];
}

void UnionFind :: makeSet(int n)
{
    if(n < 0 || n >= size_)
        return;
    arr_[n] = n;
}

int UnionFind :: Find(int n)
{
    if(n < 0 || n >= size_)
        return -1;
    return arr_[n];
}

void UnionFind :: Union(int a, int b)
{
    int a_id = Find(a);
    int b_id = Find(b);
    if(a_id == b_id)
        return;
    int m = min(a_id,b_id);
    for(int i = 0; i < size_; i++)
        if(arr_[i] == a_id || arr_[i] == b_id)
            arr_[i] = m;
}
