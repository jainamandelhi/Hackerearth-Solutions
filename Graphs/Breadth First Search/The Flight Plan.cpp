#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;

int main()
{
    ll n,m,c,t;
    cin>>n>>m>>c>>t;
    if(n==1){
        cout << "1\n1";
        return 0;
    }
    vector<vector<ll> >v(n+1);
    for(ll i=0;i<m;i++)
    {
        ll a;
        cin>>a;
        ll b;
        cin>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    ll vis[n+1];
    for(ll i=0;i<n+1;i++)
        vis[i]=0;
    queue<ll>q;
    ll s,e;
    cin>>s>>e;
    q.push(s);
    ll ans[n+1];
    int flag=1;
    for(ll i=1;i<=n;i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    while(flag)
    {
        ll f=q.front();
        q.pop();
        vis[f]++;
        for(ll i=0;i<v[f].size();i++)
        {
            if(vis[v[f][i]]==0)
            {
                vis[v[f][i]]=1;
                q.push(v[f][i]);
                ans[v[f][i]]=f;
                if(v[f][i]==e)
                    flag=0;
            }
        }
    }
  //  for(ll i=1;i<n+1;i++)
   //     cout<<ans[i]<<" ";
  //  cout<<endl;
    stack<ll>st;
    st.push(e);
    ll temp=e;
    while(1)
    {
        temp=ans[temp];
        st.push(temp);
        if(temp==s)
            break;
    }
    cout<<st.size()<<endl;
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
	return 0;
}
