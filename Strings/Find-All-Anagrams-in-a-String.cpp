/*Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    int count = 0;
    map<char, int> m;

    for (int i = 0; i < p.length(); i++)
        m[p[i]]++;

    int i = 0, j = 0;
    count = m.size();
    vector<int> v;

    while (j < s.length())
    {
        if (m.find(s[j]) != m.end())
        {
            m[s[j]]--;
            if (m[s[j]] == 0)
                count--;
        }
        if (j - i + 1 < p.length())
            j++;
    
        else if (j - i + 1 == p.length())
        {
            if (count == 0)
                v.push_back(i);
        
            j++;
            if (m.find(s[i]) != m.end())
            {
                if (m[s[i]] == 0)
                    count++;
                m[s[i]]++;
            }
            i++;
        }
    }

    return v;
}

int main()
{
    string s, p;
    cin >> s;
    cin >> p;
    vector<int> ans = findAnagrams(s, p);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}