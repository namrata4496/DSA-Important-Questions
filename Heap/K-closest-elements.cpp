#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> printKClosest(int a[], int n, int k, int x)
{

    priority_queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        if (x - a[i] != 0)
            q.push(make_pair(abs(x - a[i]), a[i]));
        if (q.size() > k)
        {
            q.pop();
        }
    }
    vector<int> v;
    for (int i = 0; i < k; i++)
    {
        pair<int, int> top = q.top();
        if (i > 0 && top.first == abs(v[i - 1] - x) && top.second < v[i - 1])
        {
            int temp = v[i - 1];
            v[i - 1] = top.second;
            v.push_back(temp);
        }
        else
            v.push_back(top.second);
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
