/*
    Problem Link: https://www.hackerrank.com/contests/hackerrank-hackfest-2020/challenges/strictly-increasing-sequence
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

void solve()
{
    ll n,temp; cin>>n;
    map<ll,ll>mp;
    for(ll i=0;i<n;i++)
    {
        cin>>temp;
        mp[temp]++;
    }
    ll ans=0,uniq=0;
    for(auto val:mp)
    {
        if(val.se==1) 
            uniq++;
        else
            ans+=val.se;
    }
    if(uniq==n)
        cout<<"First"<<endl;
    else if(uniq%2==0)
        cout<<(ans%2!=0?"First":"Second")<<endl;
    else if(uniq%2!=0)
        cout<<(ans%2==0?"First":"Second")<<endl;
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
