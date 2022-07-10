/*Given an array A[] of integers, sort the array according to frequency of elements. 
That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n;
    cin >> n;
    map<int, int> m;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }

    priority_queue<pair<int, int>> q;
    for (auto i : m)
       q.push(make_pair(i.second, -1 * i.first));
    
    for (int i = 0; i < m.size(); i++)
    {
        pair<int, int> top = q.top();
        for (int i = 0; i < top.first; i++)
            cout << -1 * top.second << " ";
        
        q.pop();
    }

    cout << endl;
}

int main()
{
  
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}