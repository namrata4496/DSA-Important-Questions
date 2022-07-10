/*Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. 
It is given that all array elements are distinct.*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int a[], int r, int k) {
         priority_queue <int> pq;
         for(int i=0;i<r+1;i++){
             pq.push(a[i]);
             if(pq.size()>k){
                 pq.pop();
             }
         }
         return pq.top();
    }

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    cout<<kthSmallest(a,n-1,k)
    return 0;
}
