#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,color_num;
    cout<<"enter the node and color_number: ";
    cin>>n>>color_num;

    int adj[100][100];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>adj[i][j];
    }

    int res[100],a[100]={0};
    memset(res,-1,sizeof(res));
    res[0]=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(adj[i][j]>0 && res[j]!=-1)  ///if any color are exist
            {
                a[res[j]]=1;            ///assain the existence color to array a[]
            }
        }

        for(int c=0;c<color_num;c++)
        {
            if(a[c]==0)                 ///if a[index]==0 :  then this color is not used
            {
                res[i]=c;               /// assaign the available color in res[] array
                break;
            }
        }

        for(int j=0;j<n;j++)
        {
            if(adj[i][j]>0 && res[j]!=-1)
            {
                a[res[j]]=0;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<"node "<<i<<" is colored by "<<res[i]<<endl;
    }

    return 0;
}

/**

5 4
0 1 1 0 0
1 0 1 1 0
1 1 0 1 0
0 1 1 0 1
0 0 0 1 0
*/
