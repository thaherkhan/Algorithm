
#include<bits/stdc++.h>
using namespace std;

stack<int> stk;
vector<int> adj[25];
bool vis[25];

void dfs(int s)
{
    vis[s] = true;
    for(int i=0; i<adj[s].size(); i++)
    {
        int to = adj[s][i];
        if(vis[to]==false)
        {
            dfs(to);

        }
    }
    stk.push(s);
}

void init()
{
    for(int i=0; i<25; i++) vis[i] = false;
}

int main()
{
    int n,m;
    int x,y;
    cin>>n>>m;
    init();
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
    }


    for(int i=1; i<=n; i++)
    {
        sort(adj[i].rbegin(),adj[i].rend());
    }



    for(int i=n; i>=1; i--)
    {
        if(vis[i]==false) dfs(i);
    }

    while(!stk.empty())
    {
        int z= stk.top();
        cout<<z<<" ";
        stk.pop();
    }
    return 0;
}
