#include <bits/stdc++.h>
using namespace std;

int main() {
	long long x=100, y=200, z=6;
	long long r = x%z;
	long long k = (r==0 ? 0 : z-r);
	long long xtemp = x+k;
    
    long long total = (y/z - x/z);
    if(x%z==0) total++;
    if(total <= 0) total = 0;
    cout<<"total number of divisor between "<<x<<" and "<<y<<" "<<total<<endl;
    
    cout<<"divisor are: "<<endl;
	while(xtemp<=y){
	    cout<<xtemp<<endl;
	    xtemp += z;
	}

	
	
	return 0;
}
