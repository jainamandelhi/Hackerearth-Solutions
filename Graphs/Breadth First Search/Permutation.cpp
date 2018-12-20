#include<bits/stdc++.h>
using namespace std;
int solve(string desstr,string orgstr, int n)
{
    if(desstr==orgstr)
        return 0;
    queue<pair<string,int> >q;
    q.push(make_pair(orgstr,0));
    while(!q.empty())
    {
       // cout<<s<<" "<<x<<endl;
        for(int i=2;i<=n;i++)
        {
            string t=q.front().first;
            int y=q.front().second;
            reverse(t.begin(),t.begin()+i);
           // cout<<t<<endl;
            y++;
            if(t==desstr)
                return y;
            q.push(make_pair(t,y));
        }
        q.pop();
    }
}
int main()
{
    int n;
    cin>>n;
    string desstr="",orgstr="";
    for(int i=1;i<=n;i++)
    {
        stringstream ss;
        ss<<i;
        string s2=ss.str();
        desstr+=s2;
        char c;
        cin>>c;
        orgstr+=c;
    }
    cout<<solve(desstr,orgstr,n);
    return 0;
}
Language: C++14
