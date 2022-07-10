/*Given a non-empty array of integers, find the top k elements which have the highest frequency in the array. 
If two numbers have the same frequency then the larger number should be given preference. 
Note: Print the elements according to the frequency count (from highest to lowest) and if the 
frequency is equal then larger number will be given preference.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> topK(vector<int> &a, int k)
{   
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    map<int, int> m;
    vector<int> v;

    for (int i = 0; i < a.size(); i++)
        m[a[i]]++;

  
    for (auto i : m)
    {
        q.push(make_pair(i.second, i.first));
        if (q.size() > k)
            q.pop();
    }
  
    for (int i = 0; i < k; i++)
    {
        pair<int, int> top = q.top();
        v.push_back(top.second);
        q.pop();
    }

    reverse(v.begin(), v.end());
    return v;
}

int main()
{
    int n, k;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }

    cin >> k ;
    vector<int> v = topK(a, k);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    
    return 0;
}
