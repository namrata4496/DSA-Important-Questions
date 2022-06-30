// Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mah(vector<ll> a, ll n)
{
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
    ll maxi = -1;
    ll j = n - 1;
    ll k = 0;
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
        maxi = max((v1[k] - v[j] - 1) * a[j], maxi);
        j--;
        k++;
    }

    return maxi;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll a[n][m];
    vector<ll> v;
    ll maxi;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }

    for (int i = 0; i < m; i++)
        v.push_back(a[0][i]);
    maxi = mah(v, m);

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (a[i][j] == 0)
            {
                v[j] = 0;
            }
            else
            {
                v[j] = v[j] + a[i][j];
            }
        }
        maxi = max(maxi, mah(v, m));
    }

    cout << maxi << endl;
}

int main()
{

    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}