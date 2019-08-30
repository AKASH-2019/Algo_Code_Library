                                 /*** source---> http://shoshikkha.com/archives/4356   */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(ll a,int n)  ///a^n
{
    string bin="";
    int temp;
    while(n>0)
    {
        temp=n%2;
        if(temp==0)
            bin+="0";
        else
            bin+="1";
        n/=2;
    }
    reverse(bin.begin(),bin.end());

    ll res=1;

    for(int i=0;i<bin.size();i++)
    {
        res=res*res;
        if(bin[i]=='1')
            res=a*res;
    }

    return res;
}

int main()
{
    cout<<power(5,20);
}
