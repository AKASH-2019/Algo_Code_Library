#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100];
int vis[100];
stack<int>st;

void topsort(int s)
{
     if(vis[s]==1)
        return;
     vis[s]=1;

     for(int i=0;i<adj[s].size();i++)
     {
         topsort(adj[s][i]);
     }
     //cout<<"in fun: "<<s<<endl;
     st.push(s);
    //cout<<"in top: "<<st.top()<<endl;
}

int main()
{
   int n,e,x,y;
   cin>>n>>e;

   for(int i=0;i<e;i++)
   {
      cin>>x>>y;
      adj[x].push_back(y);
   }

   memset(vis,0,sizeof(vis));

   for(int i=1;i<=n;i++)
   {
          if(vis[i]==0)
            topsort(i);
   }

   //cout<<st.top()<<endl;

   while(!st.empty())
   {
       cout<<st.top()<<endl;
       st.pop();
   }

   return 0;
}
