///O(nlogn)

#include<bits/stdc++.h>
using namespace std;
int arr[100];
int tree[4*100];

void init(int node,int b,int e)
{
     if(b==e)
     {
        tree[node]=arr[b];
        return;
     }
     int left=node*2;
     int right=node*2+1;
     int mid=(b+e)/2;
     init(left,b,mid);
     init(right,mid+1,e);
     tree[node]=tree[left]+tree[right];
}
///query

int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
       return 0;
    if(b>=i && e<=j)
       return tree[node];

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

void update(int node,int b,int e,int i,int newvalue)
{
   if(i>e || i<b)
   {
        return;        ///out of range
   }
   if(b>=i && e<=i)
   {
        tree[node]=newvalue;
        return;
   }

   int left=node*2;
   int right=node*2+1;
   int mid=(b+e)/2;
   update(left,b,mid,i,newvalue);
   update(right,mid+1,e,i,newvalue);
   tree[node]=tree[left]+tree[right];
}

int main()
{
    //freopen("input.txt","r",stdin);
    int x,n,value;
    cin>>n;
    for(int i=1;i<=n;i++)
       cin>>arr[i];

    init(1,1,7);
    cout<<query(1,1,7,3,6)<<endl;

    cout<<"enter changing position and value: ";
    cin>>x>>value;

    update(1,1,7,x,value);

    cout<<query(1,1,7,2,7)<<endl;

}
