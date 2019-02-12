#include <iostream>
#define ll long long
#define mp make_pair
#define pb push_back
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ll l,k;
    cin>>l>>k;
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    queue<pair<ll,ll> >q;
    q.push(mp(l,0));
    vector<ll>vis(100001);
    while(!q.empty())
    {
        ll fi=q.front().first;
        ll se=q.front().second;
        q.pop();
        for(ll i=0;i<n;i++)
        {
            if((fi*arr[i])%100000==k){
                cout<<se+1;
                return 0;
            }
            else if(vis[(fi*arr[i])%100000]==0){
                q.push(mp((fi*arr[i])%100000,se+1));
                vis[(fi*arr[i])%100000]++;
            }
        }
    }
    cout<<-1;
	return 0;
}
