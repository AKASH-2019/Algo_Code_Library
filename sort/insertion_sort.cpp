#include <bits/stdc++.h>
using namespace std;

int main() {
 	vector<int>nums{0,-3,5,-1,7,-2,-4,1,3};
//    vector<int>nums{1,2,3,10,11,12,13,14,15,13,2,12,1,16,17};
	
	for(int i=1; i<nums.size(); i++){
		int curValue = nums[i];
		int j=i-1;
		while(j>=0 && nums[j]>curValue){
			nums[j+1] = nums[j];
			j--;
		}
		nums[j+1] = curValue;
	}
	
	for(auto it:nums){
		cout<<it<<" ";
	}
	
	return 0;
}

/*
 best case analysis:
    This is the situation of an already sorted array, where the outer loop will run n - 1 time, 
    and the inner loop will run only once. Why? Because every time we enter into the loop, the 
    condition X[j] > currValue will be false, and we exit the inner loop.
      ** Total comparison operations = n - 1 = O(n)
      ** Total shifting operations = 0 = O(1)
      ** So, the best case time complexity of insertion sort = O(n) + O(1) = O(n)  
 */

/*
 worst case analysis:
    This is the situation of a reverse sorted array, where the outer loop will run n - 1 time, 
    and at each iteration of the outer loop, the inner loops run i times. Why? Because the 
    condition X[j] > currValue will be true for every value from j = i - 1 to 0. 
       ** At ith iteration of the outer loop: count of comparison operations = i, count of shifting operations = i
       ** Total comparison operations = 1 + 2 + 3 + ….+ n - 2 + n - 1 = n(n - 1)/2 = O(n²)
       ** Total shifting operations = 1 + 2 + 3 + ….+ n - 2 + n - 1 = n(n - 1)/2 = O(n²)
       ** So the worst-case time complexity of insertion sort = O(n²) + O(n²) = O(n²)    
    
 */
/*
Basically, Insertion sort is efficient for small data values
Insertion sort is adaptive in nature, i.e. it is appropriate for data sets which are already partially sorted.

*/