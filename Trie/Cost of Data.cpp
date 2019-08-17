#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(false)
using namespace std;
struct trie
{
    trie* next[26];
};
int t=0;
trie *newnode()
{
    trie *temp=new trie();
    for(int i=0;i<26;i++)
        temp->next[i]=NULL;
    return temp;
}
void insert(trie *root,string s)
{
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(root->next[s[i]-'a']==NULL)
        {
            root->next[s[i]-'a']=newnode();
            t++;
        }
        root=root->next[s[i]-'a'];
    }
}
int main()
{
    fast;
    cin.tie(NULL);
    int n;
    cin>>n;
    trie *root=newnode();
    while(n--)
    {
        string s;
        cin>>s;
        insert(root,s);
    }
    cout<<t+1;
}