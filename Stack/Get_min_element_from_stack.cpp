// You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
stack<ll> s;
ll minEle;

void push(ll x)
{
    if (s.empty())
    {
        minEle = x;
        s.push(x);
    }
    else
    {
        if (x < minEle)
        {
            s.push(2 * x - minEle);
            minEle = x;
        }
        else
            s.push(x);
    }
}

void pop()
{
    if (s.empty())
        cout << "Already empty" << endl;
    else if (s.top() < minEle)
    {
        minEle = 2 * minEle - s.top();
        s.pop();
    }
    else
        s.pop();
}

void getmin()
{
    if (s.empty())
        cout << "no min" << endl;
    else
        cout << minEle << endl;
}

void solve()
{
    ll q;
    cin >> q;
    while (q--)
    {
        ll qt;
        cin >> qt;
        
        if (qt == 1){
            ll x;
            cin >> x;
            push(x);
        }

        else if (qt == 2)
            pop();

        else if (qt == 3)
            getmin();

    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}