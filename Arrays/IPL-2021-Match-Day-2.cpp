/*Due to the rise of covid-19 cases in India, this year BCCI decided to organize knock-out matches in IPL rather than a league.
Today is matchday 2 and it is between the most loved team Chennai Super Kings and the most underrated team - Punjab Kings.
Stephen Fleming, the head coach of CSK, analyzing the batting stats of Punjab.
He has stats of runs scored by all N players in the previous season and he wants to find the maximum score for each and every 
contiguous sub-list of size K to strategize for the game.*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> max_of_subarrays(vector<int> arr, int n, int k)
{
    int s = 0;
    for (int i = 0; i < k; i++)
        s = max(arr[i], s);

    vector<int> v;
    v.push_back(s);

    for (int i = 1; i < n - k + 1; i++)
    {
        if (arr[i - 1] != s)
        {
            s = max(s, arr[i + k - 1]);
            v.push_back(s);
        }
        else if (arr[i + k - 1] >= s)
        {
            s = arr[i + k - 1];
            v.push_back(s);
        }
        else
        {
            s = 0;
            for (int j = i; j < i + k; j++)
                s = max(s, arr[j]);
            
            v.push_back(s);
        }
    }
    return v;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        v.push_back(c);
    }

    vector<int> ans = max_of_subarrays(v, n, k);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
    
}
