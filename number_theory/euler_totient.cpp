#include<bits/stdc++.h>
using namespace std;

//#define fast ios::sync_with_stdio(0);cin.tie(0);
///.............................blog.........................
///    source-> http://zobayer.blogspot.com/2013/02/euler-totient-function.html
///    source->https://project-algo.blogspot.com/2017/04/eulers-totient-unction-n.html

int MX=5000002;
int phi[5000002];

void euler_phi()
{
    phi[1]=1;

    for(int i=2;i<=MX;i++)
    {
        if(!phi[i])
        {
            phi[i]=i-1;                 /// for prime phi of(prime of a) is = a-1
            for(int j=(i<<1);j<=MX;j+=i)
            {
                if(!phi[j])
                    phi[j]=j;            /// initialization of n;
                phi[j]=(phi[j]/i)*(i-1); /// use the formula   (n* (1-i/d1)*(1-i/d2)-----*(1-i/dm)
            }
        }
    }
}


int main()
{
    //fast

    euler_phi();

    for(int i=1;i<MX;i++)
        cout<<i<<" of phi is "<<phi[i]<<endl;

    return 0;
}
