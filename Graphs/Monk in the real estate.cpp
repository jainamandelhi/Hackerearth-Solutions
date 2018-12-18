#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        vector<int>arr(10000+1);
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            arr[x]++;
            arr[y]++;
        }
        for(int i=0;i<arr.size();i++)
            if(arr[i]!=0)
                ans++;
        cout<<ans<<endl;
    }
}
