/*Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

 bool ispar(string x)
    {
        stack<char>s;
        map<char,char>m;
        m[']'] = '[';
         m['}'] = '{';
          m[')'] = '(';
          for(int i=0;i<x.length();i++){
              if(s.empty()) s.push(x[i]);
              else{
                  if(s.top()==m[x[i]]) s.pop();
                  else s.push(x[i]);
              }
          }
          if(s.empty()) return true;
          else return false;
   
    }

    int main(){
        string s;
        cin>>s;
        cout<<ispar(s);
        return 0;
    }
