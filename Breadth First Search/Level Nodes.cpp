#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>adj[n+1];
    vector<vector<int> >v(n+1,vector<int>(n+1,0));
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int x;
    cin>>x;
    queue<int>q;
    q.push(1);
    int temp=1,ans=0;
    for(int j=1;j<x;j++)
    {
        ans=0;
        temp=q.front();
        q.pop();
        for(int i=0;i<adj[temp].size();i++)
        {
            if(v[temp][adj[temp][i]]==0)
            {
                q.push(adj[temp][i]);
                v[temp][adj[temp][i]]++;
                v[adj[temp][i]][temp]++;
                ans++;
            }
        }
    }
    cout<<ans;
}
