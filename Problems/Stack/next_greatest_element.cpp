#include <iostream>
#include <stack>
using namespace std;

void nge(int *arr, int n, int *brr)
{
	int i = n-1;
	stack<int> st;

	brr[i] = -1;
	st.push(arr[i--]);
	while(i >= 0)
	{
		while(!st.empty() && st.top() <= arr[i])
			st.pop();
		if(st.empty())
			brr[i] = -1;
		else
			brr[i] = st.top();
		st.push(arr[i--]);
	}
}

int main()
{
	int n;
	cout << " Number of elements : ";
	cin >> n;
	int arr[n], brr[n];
	cout << " Elements\n";
	for(int i = 0; i < n; i++)
	{
		cout << " :";
		cin >> arr[i];
	}

	nge(arr, n, brr);
	cout << " Next Greatest Elements\n";
	for(int i = 0; i < n; i++)
	{
		cout << " " << arr[i] << "\t--> " << brr[i] << "\n";
	}
}
