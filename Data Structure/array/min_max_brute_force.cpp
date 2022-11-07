// tc: O(n)
// st: O(1) as no extra space was needed.

#include <bits/stdc++.h>
using namespace std;

int main() {
    
	int arr[]={1,3,5,4,4,5,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<n<<endl;
	int nmax=INT_MIN, nmin=INT_MAX;
	
	if(n == 1){
	    nmax = arr[0];
	    nmin = arr[0];
	}else{
	    if(arr[0]>arr[1]){
    	    nmax = arr[0];
    	    nmin = arr[1];
    	}else{
    	    nmax = arr[1];
    	    nmin = arr[0];
    	}
    	
    	for(int i=2; i<n; i++){
    	    if(arr[i]<nmin){
    	        nmin = arr[i];
    	    }
    	    else if(arr[i]>nmax){
    	        nmax = arr[i];
    	    }
    	}   
	}
	
	cout<<"minimun number "<<nmin<<endl;
	cout<<"maximum number "<<nmax<<endl;
	
	return 0;
}

/*
In this method, the total number of comparisons is 1 + 2(n-2) in the worst case and 
1 + n – 2 in the best case. 
In the above implementation, the worst case occurs when elements are sorted in descending order 
and the best case occurs when elements are sorted in ascending order.

*/
