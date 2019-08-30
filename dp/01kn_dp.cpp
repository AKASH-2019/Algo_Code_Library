#include<bits/stdc++.h>
using namespace std;

int k[105][105];
int kn(int cap,int wt[],int val[],int n)
{
    int i,w;
    ///bottom up manner

    for(i=0;i<=n;i++)
    {
        for(w=0;w<=cap;w++)
        {
            if(i==0 || w==0)
                k[i][w]=0;
            else if(wt[i-1]<=w)
            {
                k[i][w]=max(val[i-1] + k[i-1][w-wt[i-1]],  k[i-1][w]);
            }
            else
                k[i][w]=k[i-1][w];
        }
    }

    return k[n][cap];
}

int main()
{
    int val[10],wt[10],cap,n,r;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    cin>>cap;

    r=kn(cap,wt,val,n);
    cout<<r;

    cout<<"          .............PRINT PATH................. "<<endl<<endl;

    int w=cap;

    for(int i=n;i>0 && r>=0;i--)
    {
        if(r==k[i-1][w])
            continue;

        else
        {
            cout<<wt[i-1];
            r=r-val[i-1];
            w=w-wt[i-1];
        }
    }


    return 0;
}

/**
3
60 10 120
10 20 30
*/
