#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll m;                 ///            ........  (a^p)%m ............
ll power(ll a,ll p)
{
    if(p==0)
        return 1;
    if(p%2==0){
        ll ret=power(a,p/2);
        return ( (ret%m) *(ret%m) )%m;
    }
    else
        return ((a%m) * (power(a,p-1)%m))%m;
}

int main()
{
    cin>>m;
    cout<<power(5,20);
}
