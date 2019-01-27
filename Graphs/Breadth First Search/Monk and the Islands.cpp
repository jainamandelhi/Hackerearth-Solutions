#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll>v[n+1];
        for(ll i=0;i<m;i++)
        {
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        queue<ll>q;
        q.push(1);
        int flag=1;
        vector<ll>vis(n+1);
        vector<ll>ans(n+1);
        while(flag==1)
        {
            ll f=q.front();
            q.pop();
            vis[f]=1;
            for(ll i=0;i<v[f].size();i++)
            {
                if(vis[v[f][i]]==1)
                    continue;
                vis[v[f][i]]=1;
                ans[v[f][i]]=f;
                q.push(v[f][i]);
                if(v[f][i]==n)
                {
                    flag=0;
                    break;
                }
            }
        }
        stack<ll>st;
        st.push(n);
        ll temp=n;
        while(1)
        {
            temp=ans[temp];
            st.push(temp);
            if(temp==1)
                break;
        }
        cout<<st.size()-1<<endl;
    }
	return 0;
}
