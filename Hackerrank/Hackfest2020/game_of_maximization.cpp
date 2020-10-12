/*
    Problem Link: https://www.hackerrank.com/contests/hackerrank-hackfest-2020/challenges/stones-piles
    Author: Rishabh Gautam
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,odd=0,even=0,temp;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        if(i&1) 
            odd+=temp;
        else
            even+=temp;
    }
    cout<<2*min(even,odd);
    return 0;
}
