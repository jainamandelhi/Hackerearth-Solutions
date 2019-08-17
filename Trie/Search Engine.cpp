#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(false) 
using namespace std;
struct trie
{
    trie* character[26];
    int val;
};
trie *newnode()
{
    trie *temp=new trie();
    for(int  i=0;i<26;i++)
        temp->character[i]=NULL;
    temp->val=0;
    return temp;
}
void insert(trie *root,string s,int val)
{
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(root->character[s[i]-'a']==NULL)
        {
            root->character[s[i]-'a']=newnode();
        }
        root->character[s[i]-'a']->val=max(root->character[s[i]-'a']->val,val);
        root=root->character[s[i]-'a'];
    }
}
int search(trie *root,string s)
{
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(root->character[s[i]-'a']==NULL)
            return -1;
        root=root->character[s[i]-'a'];
    }
    return root->val;
}
int main()
{
    fast;
    cin.tie(NULL);
    int n;
    int q;
    cin>>n>>q;
    trie *root=new trie();
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        int val;
        cin>>val;
        insert(root,s,val);
    }
    while(q--)
    {
        string s;
        cin>>s;
        cout<<search(root,s)<<endl;
    }
}
