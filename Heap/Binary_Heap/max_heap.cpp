#include <iostream>
#include <climits>
using namespace std;


class MaxHeap
{
private:
    int max_size_;
    int size_;
    int *arr;
    void heapifyDown(int index);
    void heapifyUp(int index);
public:
    MaxHeap();
    void insert(int key);
    int Delete();
    int parent(int index);
    int left(int index);
    int right(int index);
    void display();
    int max();
    bool empty();
};

int main()
{
    MaxHeap heap;
    int n;
    while(1)
    {
        cout << " : ";
        cin >> n;
        if(!n)
            break;
        heap.insert(n);
    }
    heap.display();
    cout << " Max value : " << heap.max() << " " << "\n";

    while(!heap.empty())
    {
        cout << " Current Max value  : " << heap.Delete() << "\n";
    }
}

MaxHeap :: MaxHeap()
{
    max_size_ = 1000;
    size_ = 0;
    arr = new int[max_size_];
}

void MaxHeap :: insert(int key)
{
    size_++;
    arr[size_] = key;
    heapifyUp(size_);
}

int MaxHeap :: Delete()
{
    if(size_ == 0)
    {
        cout << " Heap is empty\n";
        return INT_MIN;
    }
    int max = arr[1];
    arr[1] = arr[size_--];
    heapifyDown(1);
    return max;
}

void MaxHeap :: heapifyUp(int index)
{
    int val = arr[index];
    int p = parent(index);

    while(p > 1 && arr[p] < val)
    {
        arr[index] = arr[p];
        index = p;
        p = parent(index);
    }
    arr[index] = val;
}

void MaxHeap :: heapifyDown(int index)
{
    int val = arr[index], l, r;

    while(index <= size_)
    {
         l = left(index);
          r = right(index);

        if(val >= arr[l] && val >= arr[r])
        {
            arr[index] = val;
            return;
        }
        else if(arr[l] > arr[r])
        {
            arr[index] = arr[l];
            index = l;
        }
        else
        {
            arr[index] = arr[r];
            index = r;
        }
    }
    //when there are even numer of nodes
    if(l == size_ && arr[l] > val)
    {
        arr[index] = arr[l];
        index = l;
    }
    arr[index] = val;
}

int MaxHeap :: parent(int index)
{
    if(index <= 1)
        return 0;
    return index/2;
}

int MaxHeap :: left(int index)
{
    int l = index * 2;
    if(index < 1 || l > size_)
        return 0;
    return l;
}

int MaxHeap :: right(int index)
{
    int r = index * 2 + 1;
    if(index < 1 || r > size_)
        return 0;
    return r;
}

void MaxHeap :: display()
{
    if(!size_)
    {
        cout << " Heap is empty\n";
        return;
    }
    cout << " Heap : ";
    for(int i = 1; i <= size_; i++)
        cout << " " << arr[i];
    cout << "\n";
}

int MaxHeap :: max()
{
    if(size_ > 0)
        return arr[1];
    return INT_MIN;
}

bool MaxHeap :: empty()
{
    return size_ == 0;
}
