#include <bits/stdc++.h>
using namespace std;

void optimizedBubleSort(vector<int>& nums, int n){
    
    for(int i=0; i<n; i++){
        bool swapStatus = false;    
        for(int j=0; j<n-i-1; j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
                swapStatus = true;
            }
            // sort element decreasing order
            /*
            if(nums[j]<nums[j+1]){
                swap(nums[j],nums[j+1]);
                swapStatus = true;
            }
            */
        }
        if(swapStatus == false){    // If no element gets swapped inside the inner loop, it means the array is sorted
            break;
        }
    }
}

int main() {
	// your code goes here
	vector<int>nums{8,7,3,2,5};
	optimizedBubleSort(nums, nums.size());
	
	for(auto it:nums){
	    cout<<it<<" ";
	}
	
	return 0;
}

/*
worst case analysis:
When the input is sorted in decreasing order, the comparison X[j] > X[j + 1] becomes true 
for each iteration of the outer loop, and the swap operation will execute every time. 
So, a reverse sorted array will be the scenario of worst-case input in bubble sort.
For ith iteration of the outer loop, the inner loop will run (n - i - 1) times. 
So total count of loop iterations = Sum of n - i - 1 from i 
                        = 0 to n - 1 
                        = (n - 1) + (n - 2) + . . . + 2 + 1 = n(n - 1)/2 = O(n^2)
    ** Total count of comparison operations = Total count of loop iterations = O(n^2)
    ** Total count of swapping operations = Total count of comparison operations = O(n^2)
    ** The time complexity of bubble sort in the worst case = O(n^2) + O(n^2) = O(n^2)
*/
/*
best case analysis:
When the input is already sorted in increasing order, then comparison X[j] > X[j+1] becomes false 
for each iteration of the outer loop, and the swap operation will not execute at all. 
So, a sorted array is the scenario of the best case input in bubble sort.
    ** Total count of comparison operations = Total count of loop iterations = O(n^2)
    ** Total count of swapping operations = 0
    ** The time complexity of bubble sort in the best case = O(n^2)
*/
/*
Think.................
    ** What would be the average case time complexity of the bubble sort?
    ** What is the idea of "stability" in the case of sorting algorithms? is bubble sort a stable sorting algorithm?
    ** Can we think to implement the bubble sort recursively?
    ** How can we sort linked lists and strings using bubble sort algorithm?
*/