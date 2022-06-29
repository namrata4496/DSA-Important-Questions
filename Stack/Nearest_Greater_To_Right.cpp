/*Given an array arr[ ] of size N having distinct elements, 
the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1.
For example, next greater of the last element is always -1.
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

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && a[i] > s.top())
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

    reverse(v.begin(), v.end());

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