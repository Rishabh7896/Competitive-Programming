/*
    Problem Link: https://www.spoj.com/problems/PT07Y/
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
 
ll power(ll x,ll y,ll p);
const ll inf=999999999;
const ll mod=1e9+7;
bool tc=false;
 
vector<ll>par(10005);
vector<ll>ran(10005,0);
 
ll findpar(ll a)
{
	while(a!=par[a])
	{
		par[a]=par[par[a]];
		a=par[a];
	}
	return a;
}
 
void take_union(ll a,ll b)
{
	if(ran[a]>ran[b])
		par[b]=a;
	else if(ran[a]<ran[b])
		par[a]=b;
	else
	{
		ran[b]++;
		par[a]=b;
	}
}
void solve()
{
	ll n,m,a,b; cin>>n>>m;
	for(ll i=0;i<=n;i++)
		par[i]=i;
	while(m--)
	{
		cin>>a>>b;
		a=findpar(a);
		b=findpar(b);
		if(findpar(a)==findpar(b))
		{
			cout<<"NO"<<endl;
			return;
		}
		take_union(a,b);
	}
	cout<<"YES"<<endl;
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
 
ll power(ll x,ll y,ll p)  
{  
    ll res=1; x=x%p;
    if(x==0) return 0;
    while(y>0)  
    {
        if(y&1) res=(res*x)%p;
        y=y>>1; x=(x*x)%p;  
    }
    return res;  
}  