#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    int n,m;

    cin>>a>>b;
    n=a.size();
    m=b.size();

    int dp[n+1][m+1];
    string s[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
        s[i][0]="";
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=0;
        s[0][i]="";
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                s[i][j]=s[i-1][j-1]+a[i-1];
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                dp[i][j]=dp[i-1][j];
                s[i][j]=s[i-1][j];
            }
            else if(dp[i-1][j]<dp[i][j-1])
            {
                dp[i][j]=dp[i][j-1];
                s[i][j]=s[i][j-1];
            }
            else
            {
                dp[i][j]=dp[i][j-1];
                ///s[i][j]=min(s[i][j-1],s[i-1][j]);   ///lexicographical order (increasing)  ///if decreasing max instead of min
                s[i][j]=s[i][j-1];
            }
        }
    }
    cout<<"length of the lcs is : "<<dp[n][m]<<endl;

    cout<<"the lcs is : "<<s[n][m]<<endl;

    return 0;
}
