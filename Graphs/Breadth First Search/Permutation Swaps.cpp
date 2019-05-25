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
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll>p,q;
        for(ll i=0;i<n;i++)
        {
            ll a;
            cin>>a;
            p.pb(a);
        }
        for(ll i=0;i<n;i++)
        {
            ll a;
            cin>>a;
            q.pb(a);
        }
        vector<vector<ll> >v(n+1);
        for(ll i=0;i<m;i++)
        {
            ll a,b;
            cin>>a>>b;
            a--;
            b--;
            a=p[a];
            b=p[b];
            v[a].pb(b);
            v[b].pb(a);
        }
        vector<ll>vis(n+1);
        queue<pair<ll,ll> >qu;
        vector<ll>ans(n+1);
        for(ll i=1;i<=n;i++)
            ans[i]=i;
        for(ll i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                qu.push(mp(i,ans[i]));
                while(!qu.empty())
                {
                    ll fi=qu.front().first;
                    ll se=qu.front().second;
                    qu.pop();
                    vis[fi]=1;
                    for(ll j=0;j<v[fi].size();j++)
                    {
                        if(vis[v[fi][j]]==0)
                        {
                            vis[v[fi][j]]=1;
                            ans[v[fi][j]]=se;
                            qu.push(mp(v[fi][j],se));
                        }
                    }
                }
            }
        }
        int flag=1;
        for(ll i=0;i<n;i++)
        {
            if(ans[p[i]]!=ans[q[i]])
            {
                cout<<"NO"<<endl;
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
    }
    return 0;
}
