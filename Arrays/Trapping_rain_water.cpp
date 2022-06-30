//Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    ll n;
    cin>>n;
    ll a[n];
    ll x[n],y[n];
    ll sum=0;
    for(int i=0;i<n;i++)
     cin>>a[i];

    x[0]=a[0];
      
    for(int i=1;i<n;i++)
      x[i]=max(x[i-1],a[i]);
    
    
    y[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
      y[i]=max(y[i+1],a[i]);
    

    for(int i=0;i<n;i++)
        sum+=min(x[i],y[i]) -a[i];
    
    cout<<sum<<endl;
}

int main(){
    ll t;
    cin>>t;
    while(t--)
       solve();
    return 0;
}