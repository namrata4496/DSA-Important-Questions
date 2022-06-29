/*Given an array a of integers of length n, 
find the nearest smaller number for every element such that the smaller element is on left side.
If no small element present on the left print -1.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    stack<ll> s;
    vector<ll> v;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[i] < s.top())
            s.pop();

        if (s.empty())
        {
            v.push_back(-1);
            s.push(a[i]);
        }

        else
        {
            v.push_back(s.top());
            s.push(a[i]);
        }
    }

    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}