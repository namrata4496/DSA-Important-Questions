/*Find the largest rectangular area possible in a given histogram
where the largest rectangle can be made of a number of contiguous bars.
For simplicity, assume that all bars have the same width and the width is 1 unit, 
there will be N bars height of each bar will be given by the array arr.
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
        while (!s.empty() && a[i] < a[s.top()])
            s.pop();

        if (s.empty())
        {
            v.push_back(-1);
            s.push(i);
        }

        else
        {
            v.push_back(s.top());
            s.push(i);
        }
    }

    stack<ll> s1;
    vector<ll> v1;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s1.empty() && a[i] <= a[s1.top()])
            s1.pop();

        if (s1.empty())
        {
            v1.push_back(n);
            s1.push(i);
        }

        else
        {
            v1.push_back(s1.top());
            s1.push(i);
        }
    }

    reverse(v1.begin(), v1.end());
    ll maxi = -1;

    for (int i = 0; i < n; i++)
        maxi = max((v1[i] - v[i] - 1) * a[i], maxi);

    cout << maxi << endl;
}


int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
}