#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<cstring>
#define maxn 200005
using namespace std;

vector<int> a[maxn];
int is_rearrange[maxn];
vector<int> ans;
int value[maxn];
vector<int> temp;
int find_root[maxn];
int vis[maxn];
int first_time=1;

void dfs(int node,bool is_noted)
{
    if (!is_noted)
    {
        ans.push_back(value[node]);
        vis[node] = 1;
        if (a[node].empty())
            return;
        sort(a[node].begin(), a[node].end());

        for (int i = 0; i < a[node].size(); i++)
        {
            if (!vis[a[node][i]])
            {
                dfs(a[node][i],is_rearrange[a[node][i]]);
            }
        }
        return;
    }
    else if(first_time==1){//is_noded == 1
        first_time=0;
        temp.push_back(value[node]);
        vis[node] = 1;
        if (a[node].empty())
        {
            ans.push_back(value[node]);
            temp.clear();
            first_time=1;
            return;
        }
            

        for (int i = 0; i < a[node].size(); i++)
        {
            if (!vis[a[node][i]])
            {
                dfs(a[node][i],1);
            }
        }
        
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++)
        {
            ans.push_back(temp[i]);
        }
        temp.clear();
        first_time=1;
        return;
    }
    else if(first_time==0)
    {
        temp.push_back(value[node]);
        vis[node] = 1;
        if (a[node].empty())
            return;

        for (int i = 0; i < a[node].size(); i++)
        {
            if (!vis[a[node][i]])
            {
                dfs(a[node][i],1);
            }
        }
    }
}



int main()
{
    int n;int root;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&value[i]);

    for(int i=1;i<=n;i++)
        scanf("%d",&is_rearrange[i]);

    for(int i=1;i<n;i++)
    {
        int p,q;
        scanf("%d%d",&p,&q);
        find_root[q]=1;
        a[p].push_back(q);
    }

    for(int i=1;i<=n;i++)
        if(find_root[i]==0){root=i;break;}

    // a[2].push_back(3);
    // a[2].push_back(5);a[2].push_back(4);
    // a[3].push_back(6);a[3].push_back(1);
    // a[5].push_back(7);
    // root=2;

    int i;
    dfs(root,is_rearrange[root]);
    cout<<'[';
    for(i=0;i<ans.size()-1;i++)
        cout<<ans[i]<<',';

    cout<<ans[i]<<']'<<endl;
    
}