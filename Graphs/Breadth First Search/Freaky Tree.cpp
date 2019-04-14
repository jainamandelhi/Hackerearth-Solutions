#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;
    vector<vector<pair<ll,ll>> >arr(n+1);
    for(ll i=0;i<n-1;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        arr[a].pb(mp(b,c));
        arr[b].pb(mp(a,c));
    }
    ll root=0;
    vector<ll>v1(n+1);
    for(ll i=1;i<=n;i++)
    {
        queue<ll>q;
        q.push(i);
        ll temp=0;
        while(!q.empty())
        {
            ll a=q.front();
            q.pop();
            v1[a]=1;
            temp++;
            for(ll j=0;j<arr[a].size();j++)
                if(v1[arr[a][j].first]==0)
                    q.push(arr[a][j].first);
        }
        if(temp==n)
        {
            root=i;
            break;
        }
    }
    //cout<<root<<endl;
    queue<pair<ll,ll> >q;
    q.push(mp(root,0));
    ll ans=0;
    ll r=0;
    vector<ll>v(n+1);
    while(!q.empty())
    {
        ll a=q.front().first;
        ll b=q.front().second,flag=0;
        v[a]=1;
        q.pop();
        //cout<<a<<" ";
        for(ll i=0;i<arr[a].size();i++)
        {
            if(v[arr[a][i].first]==0)
            {
                q.push(mp(arr[a][i].first,arr[a][i].second^b));
                flag=1;
            }
        }
        if(flag==0)
        {
            if(b%2==1)
                ans++;
        }
    }
    cout<<ans<<endl;
}
}
