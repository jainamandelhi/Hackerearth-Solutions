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
ll mini=INT_MAX,index;
void dfs(ll f,vector<ll>&vis,vector<vector<ll> >v,map<ll,ll>m,ll temp)
{
    for(ll i=0;i<v[f].size();i++)
    {
        if(vis[v[f][i]]==0)
        {
            vis[v[f][i]]=1;
            if(m[v[f][i]] && temp<mini)
            {
                mini=temp;
                index=v[f][i];
                return;
            }
            dfs(v[f][i],vis,v,m,temp+1);
        }
    }
}
int main()
{
    fast;
    ll n;
    cin>>n;
    vector<vector<ll> >v(n+1);
    vector<ll>vis(n+1);
    for(ll i=0;i<n-1;i++)
    {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    map<ll,ll>m;
    ll q;
    cin>>q;
    for(ll i=0;i<q;i++)
    {
        ll a;
        cin>>a;
        m[a]++;
    }
    for(ll i=1;i<=n;i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    vis[1]=1;
    dfs(1,vis,v,m,1);
    cout<<index;
    return 0;
}
