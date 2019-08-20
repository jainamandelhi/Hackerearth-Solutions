#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define fast ios_base::sync_with_stdio(false)
using namespace std;
struct trie
{
    trie *character[26];
    int val=0;
};
trie *newnode()
{
    trie *temp=new trie;
    return temp;
}
void insert(trie *root,string s)
{
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(root->character[s[i]-'a']==NULL){
            root->character[s[i]-'a']=newnode();
        }
        
        root=root->character[s[i]-'a'];
        root->val++;
    }
}
int search(trie *root,string s)
{
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(!root->character[s[i]-'a'])
            return 0;
        
        root=root->character[s[i]-'a'];
    }
    return root->val;
}
int main()
{
    fast;
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    trie *root=newnode();
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        insert(root,s);
    }
    for(int i=0;i<q;i++)
    {
        string s;
        cin>>s;
        cout<<search(root,s)<<endl;
    }
}