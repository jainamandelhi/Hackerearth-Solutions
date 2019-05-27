#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(false)
#define ll long long
ll mod=1000000007;
ll index,total=0,temp=0;
vector<ll>ans;
void dfs(ll f,vector<vector<ll> >v,vector<ll>&vis,ll arr[])
{
    vis[f]=1;
    total+=arr[f-1];
    if(arr[f-1]>temp){
        temp=arr[f-1];
        index=f;
    }
    else if(arr[f-1]==temp)
        index=min(index,f);
    for(ll i=0;i<v[f].size();i++)
    {
        if(vis[v[f][i]]==0)
        {
            dfs(v[f][i],v,vis,arr);
        }
    }
}
ll gcd(ll a,ll b)
{
    return (b==0)?a:gcd(b,a%b);
}
int main()
{
    ll n;
    cin>>n;
    ll m;
    cin>>m;
    queue<pair<ll,ll> >q;
    map<ll,ll>ma;
    ma[n]++;
    q.push(mp(n,0));
    while(!q.empty())
    {
        ll fi=q.front().first;
        ll se=q.front().second;
        q.pop();
        ma[fi]++;
        if(fi==m)
        {
            cout<<se;
            return 0;
        }
        ll temp=fi*2;
        if(temp<10001 && !ma[temp]){
            q.push(mp(temp,se+1));
            ma[temp]++;
        }
        if(fi-1>0 && !ma[fi-1]){
            q.push(mp(fi-1,se+1));
            ma[fi-1]++;
        }
    }
    cout<<-1;
    return 0;
}
