/*
    Problem Link: https://www.hackerrank.com/contests/hackerrank-hackfest-2020/challenges/cyclic-binary-string/
    Author: Rishabh Gautam
*/
#include<bits/stdc++.h>
using namespace std;

#define FASTIO1 ios_base::sync_with_stdio(false)
#define FASTIO2 cin.tie(NULL),cout.tie(NULL)
#define ll long long

int main() 
{
    FASTIO1; 
    FASTIO2;
    string s; 
    cin>>s;
    ll n=s.length();
    for(ll i=0;i<n and s[0]!='1' and s[n-1]!='1';i++)
    {
        string ns="";
        ns+=s[n-1];ns+=s.substr(0,n-1);
        s=ns;
    }
    ll ans=0,i,j;
    for(i=0;i<n;i=j)
    {
        j=i+1;
        while(j<n and s[j]==s[i]) 
            j++;
        if(s[i]=='0' and j-i!=n)
            ans=max(ans,j-i);
    }
    if(ans==0 and s[0]=='0') 
        ans=-1;
    cout<<ans<<endl;
    return 0;
}

