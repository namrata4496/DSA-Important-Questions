/*There are given N ropes of different lengths, we need to connect these ropes into one rope. 
The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minCost(int a[], int n)
{
    priority_queue<int, vector<int>, greater<int>> q(a, a + n);

    int sum = 0;
    while (q.size() > 1)
    {
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        sum += x + y;
        int z = x + y;
        q.push(z);
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << minCost(a, n);
    return 0;
}
