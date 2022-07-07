/*Given two strings S and P. Find length of the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  
Return "-1" in case there is no such window present.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int smallestWindow(string s, string p)
{
    map<char, int> m;
    for (int i = 0; i < p.length(); i++)
        m[p[i]]++;
    int j = 0, i = 0;
    int count = m.size();
    int mini = INT_MAX;
    while (j < s.length())
    {

        if (m.find(s[j]) != m.end())
        {
            m[s[j]]--;
            if (m[s[j]] == 0)
                count--;
            j++;
        }
        else if (count > 0)
            j++;
        if (count == 0)
        {
            while (count == 0)
            {
                if (m.find(s[i]) != m.end())
                {
                    m[s[i]]++;
                    if (m[s[i]] > 0)
                        count++;
                }
                if (count == 0)
                    i++;
            }
            mini = min(mini, j - i);
            j++;
        }
    }
    if(min==INT_MAX) return -1;
    else return mini;
}

int main()
{
    string s, p;
    cin >> s >> p;
    cout << smallestWindow(s, p);
    return 0;
}