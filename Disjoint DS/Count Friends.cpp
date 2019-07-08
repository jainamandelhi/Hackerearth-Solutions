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
ll root(ll i,ll parent[])
{
    while(i!=parent[i])
        i=parent[i];
    return i;
}
int main()
{
    fast;
    ll n,e;
    cin>>n>>e;
    ll parent[n+1],tsize[n+1];
    for(ll i=1;i<=n;i++)
        parent[i]=i;
    for(int i=1;i<=n;i++)
        tsize[i]=0;
   // cout<<endl;
    for(ll i=0;i<e;i++)
    {
        ll a,b;
        cin>>a>>b;
        ll c=root(a,parent);
        ll d=root(b,parent);
      // cout<<c<<" "<<d<<endl;
       if(c==d)
        continue;
        if(tsize[c]>tsize[d])
        {
            tsize[c]+=tsize[d]+1;
            tsize[d]=0;
            parent[d]=parent[c];
        }
        else
        {
            tsize[d]+=tsize[c]+1;
            tsize[c]=0;
            parent[c]=parent[d];
        }
    }
    for(ll i=1;i<=n;i++)
    {
        ll j=i;
        while(j!=parent[j])
            j=parent[j];
        tsize[i]=tsize[j];
    }
    for(ll i=1;i<=n;i++)
    {
        cout<<tsize[i]<<" ";
    }
}
