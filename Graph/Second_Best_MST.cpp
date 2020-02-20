#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int u,v,w;
    bool operator<(const edge&p)const
    {
        return w<p.w;
    }
};

int par[100005];
vector<edge>e;
int p[1000];
vector<int>done;

int path(int r)
{
    //return (par[r]==r)? r : path(par[r]);
    if(par[r]==r)
        return r;
    else
        path(par[r]);
}

int mst_kruskul(int n)
{
    sort(e.begin(),e.end());

    for(int i=0; i<=n; i++)
    {
        par[i]=i;
    }

    int cont=0,s=0;

    cout<<"the edge is...."<<endl;

    for(int i=0; i<e.size(); i++)
    {
        int u=path(e[i].u);
        int v=path(e[i].v);

        if(u!=v)
        {
            cout<<e[i].u<<" - "<<e[i].v<<endl;
            done.push_back(i);
            par[u]=v;
            cont++;
            s+=e[i].w;
            if(cont==n-1)
                break;
        }
    }

    return s;
}

/// ....................SECOND BEST MST.................................

int mst_kruskul_2nd_best(int n)
{
    sort(e.begin(),e.end());
    int sum2=INT_MAX;
    //cout<<"the edge is...."<<endl;
    for(int j=0; j<done.size(); j++)
    {
        int cont=0,s=0;

        for(int i=0; i<=n; i++)
        {
            par[i]=i;
        }

        for(int i=0; i<e.size(); i++)
        {
            if(done[j]==i)
                continue;
            int u=path(e[i].u);
            int v=path(e[i].v);

            if(u!=v)
            {
                par[u]=v;
                cont++;
                s+=e[i].w;
                if(cont==n-1)
                    break;
            }
        }
        if(cont!=n-1)
          s=0;
        else
           sum2>s ? sum2=s : sum2=sum2;
    }

    return sum2;
}




int main()
{
    int n,m;
    cout<<"enter the number of node and edge: ";
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        edge get;

        get.u=u;
        get.v=v;
        get.w=w;

        e.push_back(get);
    }

    cout<<"the mst is : "<<mst_kruskul(n)<<endl<<endl<<endl;

    cout<<"2nd best mst is : "<< mst_kruskul_2nd_best(n)<<endl;

    return 0;
}
