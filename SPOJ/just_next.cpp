/*
    Problem Link: https://www.spoj.com/problems/JNEXT/
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
	ll n; cin>>n;
	ll ar[n];
	for(ll i=0;i<n;i++) cin>>ar[i];
	bool status=next_permutation(ar,ar+n);
	if(status)
		for(ll i=0;i<n;i++)
			cout<<ar[i];
	else
		cout<<-1;
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