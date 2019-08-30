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

    for(int i=0;i<=n;i++){
         par[i]=i;
    }

    int cont=0,s=0;

    cout<<"the edge is...."<<endl;

    for(int i=0;i<e.size();i++)
    {
        int u=path(e[i].u);
        int v=path(e[i].v);

        if(u!=v)
        {
            cout<<e[i].u<<" - "<<e[i].v<<endl;

            par[u]=v;
            cont++;
            s+=e[i].w;
            if(cont==n-1)
                break;
        }
    }

    return s;
}




int main()
{
    int n,m;
    cout<<"enter the number of node and edge: ";
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        edge get;

        get.u=u;
        get.v=v;
        get.w=w;

        e.push_back(get);
    }

    cout<<"the mst is : "<<mst_kruskul(n)<<endl;

    return 0;
}

/**

input......

4 4
1 2 10
2 3 15
2 4 2
3 4 3

output......
15

*/

/**
9 14

0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

output...
37
*/


