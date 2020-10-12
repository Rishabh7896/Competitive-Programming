/*
    Problem Link: https://www.spoj.com/problems/BRCKTS/
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
string s;
 
ll construct(pair<ll,ll> seg[],ll front,ll back,ll index)
{
	if(front==back)
	{
		seg[index].fi=seg[index].se=(s[front]=='('?1:-1);
		return seg[index].fi;
	}
	ll mid=(front+back)/2;
	seg[index].fi=construct(seg,front,mid,2*index+1)+construct(seg,mid+1,back,2*index+2);
	seg[index].se=min(seg[2*index+1].se,seg[2*index+1].fi+seg[2*index+2].se);
	return seg[index].fi;
}
 
void update(pair<ll,ll> seg[],ll front,ll back,ll ref,ll diff,ll index)
{
	if(ref<front || ref>back) return;
	seg[index].fi+=diff;
	if(front==back) 
		seg[index].se=-seg[index].se;
	if(front!=back)
	{
		ll mid=(front+back)/2;
		update(seg,front,mid,ref,diff,2*index+1);
		update(seg,mid+1,back,ref,diff,2*index+2);
		seg[index].se=min(seg[2*index+1].se,seg[2*index+1].fi+seg[2*index+2].se);
	}
}
void solve()
{
	ll n; cin>>n>>s;
	ll tsize=(1<<((ll)ceil(log2(n))+1))-1;
	pair<ll,ll> seg[tsize];
	construct(seg,0,n-1,0);
	ll m,k,diff; cin>>m;
	while(m--)
	{
		cin>>k;
		if(k==0)
		{
			if(!seg[0].fi && !seg[0].se) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else
		{
			diff=(s[k-1]=='('?-2:2);
			update(seg,0,n-1,k-1,diff,0);
			s[k-1]=(s[k-1]=='('?')':'(');\
		}
	}
}
 
int main() 
{
    FASTIO1;
    FASTIO2;
    clock_t start=clock();
    ll t=10;
    for(ll i=1;i<=t;i++)
    {
    	cout<<"Test "<<i<<":"<<endl;
        solve();
    }
    cerr<<fixed<<setprecision(6);
    cerr<<(double)(clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}