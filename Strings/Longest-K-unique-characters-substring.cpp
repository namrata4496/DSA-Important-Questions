/*Given a string you need to print the size of the longest possible substring that has exactly K unique characters. 
If there is no possible substring then print -1.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k)
{
    int i = 0, j = 0;
    map<char, int> m;
    int maxi = 0;
    while (j < s.length())
    {
        m[s[j]]++;

        if (m.size() < k)
            j++;

        else if (m.size() == k)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }

        else if (m.size() > k)
        {
            while (m.size() > k)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    if (maxi == 0)
        maxi = -1;
    return maxi;
}

int main()
{
    string s;
    int k;
    cin >> s;
    cin >> k;
    cout << longestKSubstr(s, k);
    return 0;
}