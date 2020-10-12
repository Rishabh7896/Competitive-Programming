/*
    Problem Link: https://www.spoj.com/problems/HISTOGRA/
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
bool tc=false;
 
void solve()
{
	while(1)
	{
		ll n; cin>>n;
		if(n==0) return;
		ll ar[n];
		for(ll i=0;i<n;i++)
			cin>>ar[i];
		vector <ll> ltor(n,-1),rtol(n,-1);
		stack <ll> st1,st2;
		for(ll i=0;i<n;i++)
		{
			if(st1.empty())
				st1.push(i);
			else
			{
				while(!st1.empty() && ar[st1.top()]>ar[i])
				{
					ltor[st1.top()]=i;
					st1.pop();
				}
				st1.push(i);
			}
		}
		for(ll i=n-1;i>=0;i--)
		{
			if(st2.empty())
				st2.push(i);
			else
			{
				while(!st2.empty() && ar[st2.top()]>ar[i])
				{
					rtol[st2.top()]=i;
					st2.pop();
				}
				st2.push(i);
			}
		}
		ll ans=-inf,cur,left,right;
		for(ll i=0;i<n;i++)
		{
			if(ltor[i]==-1) right=n-i;
			else right=ltor[i]-i;
			if(rtol[i]==-1) left=i+1;
			else left=i-rtol[i];
			cur=ar[i]*(left+right-1);
			ans=max(ans,cur);
			//cout<<cur<<" ";
		}
		cout<<ans<<endl;
	}
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