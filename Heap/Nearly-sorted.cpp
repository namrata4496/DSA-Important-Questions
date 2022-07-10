/*Given an array of n elements, where each element is at most k away from its target position, you need to sort the array optimally.*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

  vector <int> nearlySorted(int a[], int n, int k){
        priority_queue <int, vector<int>, greater<int>> q ;
        int j=0;
        vector<int>v;
        for(int i=0;i<n;i++){
            q.push(a[i]);
            if(q.size()>k){
               v.push_back(q.top());
                q.pop();
            }
        }
        
        for(int i=0;i<k;i++){
             v.push_back(q.top());
                q.pop();
        }
        return v;
        
    }
    
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    vector<int>v=nearlySorted(a,n,k);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
