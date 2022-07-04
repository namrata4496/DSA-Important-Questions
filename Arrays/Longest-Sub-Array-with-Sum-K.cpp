/*Given an array containing N integers and an integer K., Your task is to find the length of the longest 
Sub-Array with the sum of the elements equal to the given value K.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(int A[], int N, int K)
{

    unordered_map<int, int> um;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < N; i++)
    {

        sum += A[i];
        if (sum == K)
            maxLen = i + 1;

        if (um.find(sum) == um.end())
            um[sum] = i;

        if (um.find(sum - K) != um.end())
        {
            if (maxLen < (i - um[sum - K]))
                maxLen = i - um[sum - K];
        }
    }

    return maxLen;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << lenOfLongSubarr(a, n, k);

    return 0;
}