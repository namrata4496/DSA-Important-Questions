/*Given an array A[] of size N and a positive integer K, find the first negative
integer for each and every window(contiguous subarray) of size K.*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> printFirstNegativeInteger(ll A[], ll N, ll K)
{
    queue<ll> q;
    vector<ll> v;
    ll j = 0;
    for (ll i = 0; i < N - K + 1; i++)
    {
        while (j < K)
        {
            if (A[j] < 0)
                q.push(A[j]);
            j++;
        }

        if (j > K && A[i - 1] < 0)
            q.pop();

        if (q.empty())
            v.push_back(0);
        else
            v.push_back(q.front());

        if (j < N && A[j] < 0)
            q.push(A[j]);
        j++;
    }
    return v;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> ans = printFirstNegativeInteger(a, n, k);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}