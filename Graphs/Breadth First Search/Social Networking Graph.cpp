#include <iostream>
#define ll long long
#define mp make_pair
#define pb push_back
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ll v,e;
    cin>>v>>e;
    vector<vector<ll> >adj(v+1);
    for(ll i=0;i<e;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll t;
    cin>>t;
    while(t--)
    {
        vector<ll>vis(v+1);
        ll cnt=0;
        ll n,k;
        cin>>n>>k;
        queue<pair<ll,ll> >q;
        q.push(mp(n,0));
        vis[n]=1;
        while(!q.empty())
        {
            ll fi=q.front().first;
            ll se=q.front().second;
            q.pop();
            if(se==k)
            {
                cnt++;
                continue;
            }
            if(se>k)
                continue;
            for(ll i=0;i<adj[fi].size();i++)
            {
                if(vis[adj[fi][i]]==0){
                    vis[adj[fi][i]]=1;
                    q.push(mp(adj[fi][i],se+1));
                }
            }
        }
        cout<<cnt<<endl;
    }
	return 0;
}
