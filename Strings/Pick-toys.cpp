/*Toys are kept in a row, you have to select max toys in such a way that you can pick 
only 2 types of toys and you can pick only those toys which are kept in contiguous positions.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxToys(string s)
{
    map<char, int> m;
    int i = 0;
    int j = 0;
    int maxi = 0;
    while (j < s.length())
    {
        m[s[j]]++;
        if (m.size() <= 2)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }
        else if (m.size() > 2)
        {
            while (m.size() > 2)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return maxi;
}

int main()
{
    string s;
    cin >> s;
    cout << maxToys(s);
    return 0;
}