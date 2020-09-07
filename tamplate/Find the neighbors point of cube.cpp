///uva 10264

#include<bits/stdc++.h>
#define ll long long
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

/// 1<<n   2^n

inline bool neighbour(int i,int j)    ///  inline Function call overhead doesn’t occur.
{
	int n = i^j;                   /// this two instruction use to find the neighbour corner 
    return ((n & (-n))==n);
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
   
       int n;
       cout<<"Number of Cube Dimension "<<endl;
       cin>>n;
       cout<<(1<<n)<<endl; /// number of corner/point    (000..,001..,100...,......)
       
       for(int i=0;i<(1<<n);i++){
          for(int j=0;j<(1<<n);j++)
          {
			  
			  if(neighbour(i,j))
			  {
				  if(i==j)continue;
				  cout<<i<<" "<<j<<endl;
			  }
			  
		  }
		  cout<<endl;
	  }
    
    return 0;
}
