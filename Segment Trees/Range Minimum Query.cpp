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
void build(ll ans[],ll arr[],ll st,ll en,ll treenode)
{
    if(st==en)
    {
        ans[treenode]=arr[st];
        return;
    }
    ll mid=st+(en-st)/2;
    build(ans,arr,st,mid,2*treenode);
    build(ans,arr,mid+1,en,2*treenode+1);
    ans[treenode]=min(ans[2*treenode],ans[2*treenode+1]);
}
ll query(ll ans[],ll st,ll en,ll treenode,ll l,ll r)
{
    if(st>r || en<l)
        return INT_MAX;
    if(st>=l && en<=r)
        return ans[treenode];
    ll mid=st+(en-st)/2;
    ll ans1=query(ans,st,mid,2*treenode,l,r);
    ll ans2=query(ans,mid+1,en,2*treenode+1,l,r);
    return min(ans1,ans2);
}
void update(ll arr[],ll ans[],ll st,ll en,ll treenode,ll index,ll val)
{
    if(st==en)
    {
        arr[index]=val;
        ans[treenode]=val;
        return;
    }
    ll mid=st+(en-st)/2;
    if(index>mid)
    {
        update(arr,ans,mid+1,en,2*treenode+1,index,val);
    }
    else
    {
        update(arr,ans,st,mid,2*treenode,index,val);
    }
    ans[treenode]=min(ans[2*treenode],ans[2*treenode+1]);
}
int main()
{
    fast;
    ll n,t;
    cin>>n>>t;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    ll ans[4*n];
    build(ans,arr,0,n-1,1);
    while(t--)
    {
        char ch;
        cin>>ch;
        if(ch=='q')
        {
            ll l,r;
            cin>>l>>r;
            ll ans1=query(ans,0,n-1,1,l-1,r-1);
            cout<<ans1<<endl;
        }
        else
        {
            ll index,val;
            cin>>index>>val;
            update(arr,ans,0,n-1,1,index-1,val);
        }
    }
}
