/*
    Problem Link: https://www.spoj.com/problems/ONP/
    Author: Rishabh Gautam
*/
#include<bits/stdc++.h>
using namespace std;
 
#define FASTIO1 ios_base::sync_with_stdio(false)
#define FASTIO2 cin.tie(NULL),cout.tie(NULL)
#define count_1(p) __builtin_popcountll(p)
#define count_0(p) __builtin_ctzll(p)
#define all(x) (x).begin(),(x).end()
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
const ll inf=999999999;
const ll mod=1e9+7;
bool tc=true;
 
void solve()
{
	string s; cin>>s;
	stack <char> opt;
	for(ll i=0;s[i]!='\0';i++)
	{
		if(s[i]>='a' && s[i]<='z')
			cout<<s[i];
		else if(s[i]==')')
		{
			cout<<opt.top();
			opt.pop();
		}
		else if(s[i]!='(')
			opt.push(s[i]);
	}
	cout<<endl;
}
 
int main() 
{
    FASTIO1;
    FASTIO2;
    clock_t start=clock();
    ll t=1; 
    if(tc) cin>>t;
    while(t--)
        solve();
    cerr<<fixed<<setprecision(6);
    cerr<<(double)(clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}