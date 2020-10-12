/*
    Problem Link: https://www.spoj.com/problems/CAM5/
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
#define MAX 200005
 
vector <ll> adj[MAX];
ll vis[MAX],visted;
 
void dfs(ll src)
{
    vis[src]=true;
    visted++;
    for(auto node:adj[src])
        if(!vis[node])
            dfs(node);
}
 
void solve()
{
    ll u,v,n,m; cin>>n>>m;
    for(ll i=0;i<n;i++)
        adj[i].clear();
    memset(vis,false,sizeof(vis));
    for(ll i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll ct=0;
    for(ll i=0;i<n;i++)
        if(!vis[i])
        {
            ct++;
            dfs(i);
        }
    cout<<ct<<endl;
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