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
    fast;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        int flag=0;
        vector<vector<pair<ll,ll> >>arr(n+1);
        for(ll i=0;i<n-1;i++)
        {
            ll a,b,w;
            cin>>a>>b>>w;
            arr[a].pb(mp(b,w));
            arr[b].pb(mp(a,w));
        }
        ll maxi=-1;
        ll i=1,max_index;
        while(1)
        {
            ll maxil=-1;
            queue<ll>q;
            q.push(i);
            vector<ll>ans(n+1,INT_MAX);
            vector<ll>vis(n+1);
            ans[i]=0;
            vis[i]=1;
            while(!q.empty())
            {
                ll a=q.front();
                vis[a]=1;
                q.pop();
                for(ll j=0;j<arr[a].size();j++)
                {
                    if(vis[arr[a][j].first]==1)
                        continue;
                    if(arr[a][j].second+ans[a]<ans[arr[a][j].first])
                        ans[arr[a][j].first]=arr[a][j].second+ans[a];
                    q.push(arr[a][j].first);
                }
            }
            for(ll j=1;j<=n;j++)
                if(ans[j]>maxil && ans[j]<INT_MAX){
                    maxil=ans[j];
                    max_index=j;
                }
            if(maxil>maxi)
                maxi=maxil;
            i=max_index;
            if(flag==1)
                break;
            flag=1;
        }
        if(maxi<100)
            cout<<0<<" ";
        else if(maxi<1000)
            cout<<100<<" ";
        else if(maxi<10000)
            cout<<1000<<" ";
        else
            cout<<10000<<" ";
        cout<<maxi<<endl;
    }
    return 0;
}
