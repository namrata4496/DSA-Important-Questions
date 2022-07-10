#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 vector<int> kLargest(int a[], int n, int k) {
	  
	    priority_queue <int, vector<int>, greater<int>> q;
	    for(int i=0;i<n;i++){
	        q.push(a[i]);
	        if(q.size()>k){
	            q.pop();
	        }
	    }
	    vector<int>v;
	    for(int i=0;i<k;i++){
	        v.push_back(q.top());
	        q.pop();
	    }
	    reverse(v.begin(),v.end());
	    return v;
	}
    
    
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    vector<int>v=kLargest(a,n,k);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
