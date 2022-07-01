#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int max=0,curSum=0;
    for(int i=0;i<n;i++){
        curSum=curSum+a[i];
        if(curSum>max)
            max=curSum;
        if(curSum<0)
            curSum=0;
    }
    if(max==0){
        sort(a,a+n);
        cout<<a[n-1];
    }
    else
    cout<<max;
    return 0;
}