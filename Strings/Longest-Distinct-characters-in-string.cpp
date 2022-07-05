// Given a string S, find length of the longest substring with all distinct characters.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestSubstrDistinctChars(string S)
{
    // your code here
    int i = 0, j = 0;
    map<char, int> m;
    int maxi = 0;

    while (j < S.length())
    {
        m[S[j]]++;

        if (m.size() == j - i + 1)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }

        else if (m.size() < j - i + 1)
        {
            while (m.size() < j - i + 1)
            {
                m[S[i]]--;
                if (m[S[i]] == 0)
                    m.erase(S[i]);
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
    cin >> s;
    cout << longestSubstrDistinctChars(s);
    return 0;
}