#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii>adj[100];
int inf=100000;
int parent[1000],n;


void belmen(int s)
{
    int dis[100];
    for(int i=0; i<n; i++)
        dis[i]=inf;

    dis[s]=0;

    for(int i=0; i<n-1; i++)
    {
        for(int u=0; u<n; u++)
        {
            for(int v=0; v<adj[u].size(); v++)
            {
                if(dis[u]+adj[u][v].second < dis[adj[u][v].first])
                {
                    dis[adj[u][v].first]=dis[u]+adj[u][v].second ;
                    parent[adj[u][v].first]=u;
                }
            }
        }
    }
    bool f=true;
    for(int u=0; u<n; u++)
    {
        for(int v=0; v<adj[u].size(); v++)
        {
            if(dis[u]+adj[u][v].second < dis[adj[u][v].first])
            {
                f=false;
                break;
            }
        }
    }

    /**for(int i=1; i<n-1; i++)
    {
        for(int u=1; u<=n; u++)
        {
            for(int v=1; v<=n; v++)
            {
                if(dis[u]+adj[u][v]<dis[v] && adj[u][v]!=0)
                {
                    dis[v]=dis[u]+adj[u][v];
                    par[v]=u;
                }
            }
        }
    }
    bool f=true;
    for(int u=1; u<=n; u++)
    {
        for(int v=1; v<=n; v++)
        {
            if(dis[u]+adj[u][v]<dis[v] && adj[u][v]!=0)
            {
                f=false;
                break;
            }
        }
    }
    */
    if(!f)
        cout<<"Negative cycle detected"<<endl;
    else
        for(int i=0; i<n; i++)
            cout<<dis[i]<<" ";
    cout<<endl<<endl<<"Path"<<endl;

    for(int i=0;i<n;i++)
       cout<<i<<" --> "<<parent[i]<<endl;

}

int main()
{
    //freopen("input.txt","r",stdin);
    int e;
    cin>>n>>e;
    int x,y,w;
    for(int i=0; i<e; i++)
    {
        cin>>x>>y>>w;
        adj[x].push_back(pii(y,w));
    }
   /* for(int i=1;i<=n;i++)
    {
          cout<<i<<endl;
          for(int v=0; v<adj[i].size(); v++)
              cout<<adj[i][v].first<<" "<<adj[i][v].second<<endl;
          cout<<endl;
    }*/

    belmen(0);

    return 0;
}
