/*
    Problem Link: https://www.spoj.com/problems/PPATH/
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
bool tc=true;
set<ll>prime;
bool isprime(ll n)
{
	for(ll i=2;i<=ceil(sqrt(n));i++)
		if(n%i==0) return false;
	return true;
}
void init()
{
	for(ll i=1000;i<=9999;i++)
		if(isprime(i)) 
			prime.insert(i);
}
void solve()
{
	string s,e; cin>>s>>e;
	queue<pair<string,ll>>q;
	set<string>vis;
	vis.insert(s);
	q.push({s,0});
	while(q.size())
	{
		auto val=q.front();
		q.pop();
		if(val.fi==e)
		{
			cout<<val.se<<endl;
			return;
		}
		for(int j=0;j<4;j++)
			for(char i='0';i<='9';i++)
			{
				string newcur=val.fi;
				newcur[j]=i;
				if(prime.find(stoll(newcur))!=prime.end() and vis.find(newcur)==vis.end())
				{
					q.push({newcur,val.se+1});
					vis.insert(newcur);
				}
			}
	}
}
 
int main() 
{
    FASTIO1;
    FASTIO2;
    init();
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