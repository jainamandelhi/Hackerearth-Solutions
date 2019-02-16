#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
bool check(ll a, ll b, ll m, ll n)
{
    if(a<0 || a>=n || b<0 || b>=m)
        return false;
    else
        return true;
}
int main()
{
    ll n,m,r;
    ll dir[4][4]={{1,0},{-1,0},{0,1},{0,-1}};
    cin>>n>>m;
    ll arr[n][m];
    queue<pair<ll,ll> >q;
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            cin>>arr[i][j];
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
        {
            if(arr[i][j]==2)
                q.push(mp(i,j));
        }
    ll c=0;
    q.push(mp(-1,-1));
    while(!q.empty())
    {
        ll a=q.front().first;
        ll b=q.front().second;
        if(a==-1 && q.size()>1)
        {
            q.push(mp(-1,-1));
            c++;
            q.pop();
            continue;
        }
        q.pop();
        for(ll y=0;y<4;y++)
        {
            ll fi=dir[y][0]+a;
            ll se=dir[y][1]+b;
            if(check(fi,se,m,n) && arr[fi][se]==1)
            {
                arr[fi][se]=2;
                q.push(mp(fi,se));
            }
        }
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(arr[i][j]==1)
            {
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<c;
}
