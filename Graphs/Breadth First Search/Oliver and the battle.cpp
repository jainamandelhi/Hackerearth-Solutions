#include <iostream>
#define ll long long
#define mp make_pair
#define pb push_back
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,cnt=0,maxi=0;
        cin>>n>>m;
        ll arr[n][m];
        vector<vector<ll> >vis(n,vector<ll>(m,0));
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                cin>>arr[i][j];
            }
        }
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                if(arr[i][j]==1 && vis[i][j]==0)
                {
                    cnt++;
                    queue<pair<ll,ll> >q;
                    q.push(mp(i,j));
                    vis[i][j]=1;
                    ll c=0;
                    while(!q.empty())
                    {
                        c++;
                        ll fe=q.front().first;
                        ll se=q.front().second;
                        q.pop();
                        if(fe-1>=0 && arr[fe-1][se]==1 && vis[fe-1][se]==0){
                            q.push(mp(fe-1,se));
                            vis[fe-1][se]=1;
                        }
                        if(fe-1>=0 && se-1>=0 && arr[fe-1][se-1]==1 && vis[fe-1][se-1]==0){
                            q.push(mp(fe-1,se-1));
                            vis[fe-1][se-1]=1;
                        }
                        if(fe-1>=0 && se+1<m && arr[fe-1][se+1]==1 && vis[fe-1][se+1]==0){
                            q.push(mp(fe-1,se+1));
                            vis[fe-1][se+1]=1;
                        }
                        if(se-1>=0 && arr[fe][se-1]==1 && vis[fe][se-1]==0){
                            q.push(mp(fe,se-1));
                            vis[fe][se-1]=1;
                        }
                        if(se+1<m && arr[fe][se+1]==1 && vis[fe][se+1]==0){
                            q.push(mp(fe,se+1));
                            vis[fe][se+1]=1;
                        }
                        if(fe+1<n && arr[fe+1][se]==1 && vis[fe+1][se]==0){
                            q.push(mp(fe+1,se));
                            vis[fe+1][se]=1;
                        }
                        if(fe+1<n && se-1>=0 && arr[fe+1][se-1]==1 && vis[fe+1][se-1]==0){
                            q.push(mp(fe+1,se-1));
                            vis[fe+1][se-1]=1;
                        }
                        if(fe+1<n && se+1<m && arr[fe+1][se+1]==1 && vis[fe+1][se+1]==0){
                            q.push(mp(fe+1,se+1));
                            vis[fe+1][se+1]=1;
                        }
                    }
                    maxi=max(c,maxi);
                }
            }
        }
        cout<<cnt<<" "<<maxi<<endl;
    }
	return 0;
}
