
#include<bits/stdc++.h>
#define ll long long
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    /// FOR INTEGER
    
    int arr[10],n;
    cin>>n;
    
    for(int i=0;i<n;i++)cin>>arr[i];
    bool f=next_permutation(arr,arr+n); ///the function could rearrange the object as a (lexicographically) greater permutation
    
    if(f==false)cout<<"NO PERMUTATION POSSIBLE"<<endl;
    else
      do{
		for(int i=0;i<n;i++) cout<<arr[i]<<" ";
		cout<<endl;
	  }while(next_permutation(arr,arr+n));
    
	
	/// FOR String
	string s;
	cin>>s;
	
	bool ans=next_permutation(s.begin(),s.end());
	
	if(ans==false)cout<<"NO WORD POSSIBLE"<<endl;
	
	else 
	   do{
		//for(int i=0;i<n;i++) cout<<arr[i]<<" ";
		cout<<s;
		cout<<endl;
	   }while(next_permutation(s.begin(),s.end()));
	
	
	
    
    return 0;
}
