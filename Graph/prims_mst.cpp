#include<bits/stdc++.h>
using namespace std;

struct data
{
    int v,w;
    bool operator <(const data &p)const
    {
        return w>p.w;
    }
};

vector<int>vec[2000];
vector<int>cost[2000];

void mst_prims(int src,int n)
{
    priority_queue<data>pq;

    int visited[2000]={0};
    int sum=0,p;
    cout<<"the path is"<<endl;
    for(int i=1;i<n;i++)
    {
        int u=src;
        visited[u]=1;
        for(int j=0;j<vec[u].size();j++)
        {
            int v=vec[u][j];
            if(visited[v]==0)
            {
                data d;
                d.v=v;
                d.w=cost[u][j];
                pq.push(d);
            }
        }
        data t;
        do
        {
            t=pq.top();
            src=t.v;
            p=t.w;
            pq.pop();
        }while(visited[src]==1);
        cout<<u<<" - "<<t.v<<endl;
        sum+=p;
    }

    cout<<"the mst is "<<sum<<endl;
}

int main()
{
    int n,e;

    cin>>n>>e;

    for(int i=0;i<e;i++)
    {
        int n1,n2,w;
        cin>>n1>>n2>>w;
        vec[n1].push_back(n2);
        vec[n2].push_back(n1);
        cost[n1].push_back(w);
        cost[n2].push_back(w);
    }
    mst_prims(1,n);

    return 0;
}

/**
5 5
1 2 100
1 3 80
3 4 120
1 5 220
5 4 170

output....
470

*/
