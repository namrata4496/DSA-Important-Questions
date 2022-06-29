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
