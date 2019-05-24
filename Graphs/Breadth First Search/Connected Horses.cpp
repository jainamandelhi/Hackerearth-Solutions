#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--){
    ll n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll> >arr(n+1,vector<ll>(m+1,0));
    vector<pair<ll,ll> >v;
    for(ll i=0;i<q;i++)
    {
        ll a,b;
        cin>>a>>b;
        v.pb(mp(a,b));
        arr[a][b]=1;
    }
    ll ans1=1;
    for(ll i=0;i<v.size();i++)
    {
        queue<pair<ll,ll> >qu;
        if(arr[v[i].first][v[i].second]==1)
        {
            ll temp=1,ans=1;
            ll fi=v[i].first;
            ll se=v[i].second;
            arr[fi][se]=0;
            qu.push(mp(fi,se));
            while(!qu.empty())
            {
                ans=ans%(1000000007);
                fi=qu.front().first;
                se=qu.front().second;
                arr[fi][se]=0;
                qu.pop();
                if(fi+2<=n && se-1>0 && arr[fi+2][se-1]==1){
                    qu.push(mp(fi+2,se-1));
                    arr[fi+2][se-1]=0;
                    temp++;
                    ans*=temp;
                    ans=ans%1000000007;
                }
                if(fi+2<=n && se+1<=m && arr[fi+2][se+1]==1){
                    qu.push(mp(fi+2,se+1));
                    arr[fi+2][se+1]=0;
                    temp++;
                    ans*=temp;
                    ans=ans%1000000007;
                }
                if(fi-2>0 && se-1>0 && arr[fi-2][se-1]==1){
                    qu.push(mp(fi-2,se-1));
                    arr[fi-2][se-1]=0;
                    temp++;
                    ans*=temp;
                    ans=ans%1000000007;
                }
                if(fi-2>0 && se+1<=m && arr[fi-2][se+1]==1){
                    qu.push(mp(fi-2,se+1));
                    arr[fi-2][se+1]=0;
                    temp++;
                    ans*=temp;
                    ans=ans%1000000007;
                }
                if(fi-1>0 && se+2<=m && arr[fi-1][se+2]==1){
                    qu.push(mp(fi-1,se+2));
                    arr[fi-1][se+2]=0;
                    temp++;
                    ans*=temp;
                    ans=ans%1000000007;
                }
                if(fi+1<=n && se+2<=m && arr[fi+1][se+2]==1){
                    qu.push(mp(fi+1,se+2));
                    arr[fi+1][se+2]=0;
                    temp++;
                    ans*=temp;
                    ans=ans%1000000007;
                }
                if(fi-1>0 && se-2>0 && arr[fi-1][se-2]==1){
                    qu.push(mp(fi-1,se-2));
                    arr[fi-1][se-2]=0;
                    temp++;
                    ans*=temp;
                    ans=ans%1000000007;
                }
                if(fi+1<=n && se-2>0 && arr[fi+1][se-2]==1){
                    qu.push(mp(fi+1,se-2));
                    arr[fi+1][se-2]=0;
                    temp++;
                    ans*=temp;
                    ans=ans%1000000007;
                }
            }
            ans1*=ans;
            ans1=ans1%1000000007;
        }
    }
    cout<<ans1<<endl;
    }
    return 0;
}
