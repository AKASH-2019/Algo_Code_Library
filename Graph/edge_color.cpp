#include<bits/stdc++.h>
using namespace std;

int n,e;
vector<vector<pair<int,int> > >adj;
vector<int>color;
bool vis[1000];

void edge_color(int s)
{
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int c=0;
        int u=q.front();
        q.pop();
        set<int>a;

        if(vis[u]==1)
            return;
        vis[u]=1;

        for(int i=0; i<adj[u].size(); i++)
        {
            if(color[adj[u][i].second]!=-1)
            {
                a.insert(color[adj[u][i].second]);
            }
        }

        for(int i=0; i<adj[u].size(); i++)
        {
            if(!vis[adj[u][i].first])
            {
                q.push(adj[u][i].first);
            }
            if(color[adj[u][i].second]==-1)
            {
                while(a.find(c)!=a.end())
                {
                    c++;
                }
                color[adj[u][i].second]=c;
                a.insert(c);
                c++;
            }
        }
    }
    /*while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        edge_color(temp);
    }*/
    return;
}

int main()
{
    int x,y;
    cout<<"enter the verices and edges: ";
    cin>>n>>e;
    adj.resize(n);
    color.resize(e,-1);
    memset(vis,0,sizeof(vis));
    for(int i=0; i<e; i++)
    {
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(make_pair(y,i));
        adj[y].push_back(make_pair(x,i));
    }
    cout<<endl<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
              cout<<adj[i][j].first<<" "<<adj[i][j].second<<endl;
        }
    }
    edge_color(0);

    for(int i=0; i<e; i++)
    {
        cout<<i+1<<" edge is colored by "<<color[i]+1<<endl;
    }

    return 0;
}

/**
4 6  //n e

1 2
2 3
3 4
1 4
2 4
1 3


output.......

Edge 1 is coloured 1
Edge 2 is coloured 2
Edge 3 is coloured 1
Edge 4 is coloured 2
Edge 5 is coloured 3
Edge 6 is coloured 3

*/

/**
7 6 //n e
1 2
1 4
1 5
2 3
4 6
5 7

output..........

edge 1 color 1
.... 2 ....  2
.... 3 ....  3
.... 4 ....  2
.... 5 ....  1
.... 6 ....  1
*/





