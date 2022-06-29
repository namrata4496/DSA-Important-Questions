/*The stock span problem is a financial problem where we have a series of n daily price quotes for a stock 
and we need to calculate the span of stocks price for all n days. 
The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, 
for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, 
then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    stack<ll> s;
    vector<ll> v;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[i] >= a[s.top()])
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

    for (int i = 0; i < n; i++)
        cout << i - v[i] << " ";
}

int main(){
    ll t;
    cin>>t;
    while(t--)
      solve();
}
