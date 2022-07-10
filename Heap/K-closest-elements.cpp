/*Given a sorted array, arr[] of N integers, and a value X. Find the K closest elements to X in arr[].
Keep the following points in mind:

If X is present in the array, then it need not be considered.
If there are two elements with the same difference with X, the greater element is given priority.
If sufficient elements are not present on the right side then take elements from left and vice versa.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> printKClosest(int a[], int n, int k, int x)
{

    priority_queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        if (x - a[i] != 0)
            q.push(make_pair(abs(x - a[i]),-1* a[i]));
        if (q.size() > k)
            q.pop();
        
    }
    vector<int> v;
    for (int i = 0; i < k; i++)
    {
        pair<int, int> top = q.top();
        v.push_back(-1*top.second);
        q.pop();
    }
    reverse(v.begin(), v.end());
    return v;
}

int main()
{
    int n, k, x;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> k >> x;
    vector<int> v = printKClosest(a, n, k, x);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
