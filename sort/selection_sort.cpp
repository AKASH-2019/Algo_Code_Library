#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	vector<int>nums={5,2,3,8,4,1};
	for(auto it:nums){
	    cout<<it<<endl;
	}
	int ln = nums.size();
	for(int i=0; i<ln-1; i++){
	    int minValue = i;
	    for(int j=i; j<ln; j++){
	        if(nums[j]<nums[minValue]){
	            minValue = j;
	        }
	    }
	    swap(nums[i],nums[minValue]);
	}
	
	for(auto it:nums){
	    cout<<it<<" ";
	}
	cout<<endl;
	
	return 0;
}


/*
worst Case:
   ** Total count of comparison operations = Total count of loop iterations = O(n^2)
   ** We are performing one swap on each iteration of the outer loop. Total count of swapping 
   operations = n * O(1) = O(n)
   ** Total update operation of the minIndex  = Total count of loop operations = O(n^2)
*/
/*
Best Case:
    When the input is already sorted, then comparison if (X[j] < X[minIndex]) becomes false 
    every time, and the value of minIndex will not get updated every time. So, a reverse 
    sorted array is a best-case input for selection sort. 
    
    ** Total count of comparison operations = Total count of loop iterations = O(n^2)
    ** Total count of swap operations = O(n)
    ** Total update operation of the minIndex  = O(1)
    ** So the time complexity of selection sort in the best case  = O(n^2) +O(n) + O(1) = O(n^2)
*/
/*
Think.................
    Same as Bubble sort.
*/