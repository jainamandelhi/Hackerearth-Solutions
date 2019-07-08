#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(false)
#define ll long long
ll mod=1000000007;
ll gcd(ll a,ll b)
{
    return (b==0)?a:gcd(b,a%b);
}
void dfs(int i,vector<int>&vis,stack<int>&s,vector<vector<ll> >adj)
{
    vis[i]=1;
    for(int j=0;j<adj[i].size();j++)
    {
        if(!vis[adj[i][j]])
            dfs(adj[i][j],vis,s,adj);
    }
    s.push(i);
}
int main()
{
    fast;
    ll V,e;
    cin>>V>>e;
    vector<vector<ll> >adj(V+1);
    for(ll i=0;i<e;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }
    for(ll i=1;i<=V;i++)
    {
        sort(adj[i].rbegin(),adj[i].rend());
    }
    stack<int>s;
    vector<int>vis(V+1);
    for(int i=V;i>=1;i--)
    {
        if(vis[i])
            continue;
        dfs(i,vis,s,adj);
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    // Your code here
}
