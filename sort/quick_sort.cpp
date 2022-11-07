// quick sort
/* tc:
    Divide part(partition part): O(n)
    Conquer part(recursive part): T(i)+T(n-i-1)         sort left sub-array + sort right sub-array
    Combine part: O(1)
    
    T(n) = O(n)+T(i)+T(n-i-1)+O(1) = T(i)+T(n-i-1)+O(n) = T(i)+T(n-i-1)+cn
    T(n) = c                  n = 1
    T(n) = T(i)+T(n-i-1)+cn   n > 1
     
*/
// sc: O(1)    // constant extra space
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& nums, int l, int r){
    int pivot = nums[r];
    int i = l-1;
    
    for(int j=l; j<r; j++){
        if(nums[j]<pivot){
            i++;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[i+1],nums[r]);
    return i+1;
}

void quickSort(vector<int>& nums, int l, int r){
    if(l>r){         // If we find l>=r  during the recursive calls, the sub-array would be either
        return;      //  empty or have one value left. Our recursion will not go further and 
    }                // return from the base case.
    
    int partitionIndex = partition(nums,l,r);
    quickSort(nums,l, partitionIndex-1);
    quickSort(nums,partitionIndex+1,r);
}


int main() {
	// your code goes here
	vector<int>nums{8,7,3,2,5};
	
	
	quickSort(nums,0,nums.size()-1);
	
	for(auto it:nums){
	    cout<<it<<" ";
	}
	
	return 0;
}

/*
worst case analysis++

The worst-case scenario of quicksort occurs when the partition process always picks the largest 
or smallest element as a pivot. In this scenario, the partition process would be highly unbalanced
i.e. one subproblem with n - 1 element and the other with 0 elements. 
This situation occurs when the array will be sorted in increasing or decreasing order.

Let us assume that unbalanced partitioning arises at each recursive call. 
So for calculating the time complexity in the worst case, we put i = n - 1 
in the above formula of T(n).

            T(n) = T(i)+T(n-i-1)+cn = T(n-1)+T(n-n-1-1)+cn = T(n-1)+cn
    explore:  T(n) = T(n-1)+cn
                   = T(n-2) + c(n-1) +cn
                   = T(n-3) + c(n-2) + c(n-1) +cn
                   ------------
                   = T(1)+2c+3c+......+ c(n-2) + c(n-1) +cn
                   = c+2c+3c+......+ c(n-2) + c(n-1) +cn
                   = c(1+2+3+............n)
                   = c(n(n+1)/2) = c(n^2)
                   

*/
/*
Best case analysis
The best-case behavior for quicksort occurs when we are lucky and the partition process always 
picks the middle element as a pivot. In other words, this is a case of the balanced partition 
where both sub-problems are n/2 size each.
Let us assume that balanced partitioning arises in each recursive call. So for calculating the 
time complexity in the best case, we put i = n/2 in the above formula of T(n).

T(n) = T(n/2)+T(n-n/2-1)+cn
    = T(n/2)+T(n/2-1)+cn
    ~ 2 T(n/2) + cn
     
    https://cdn-images-1.medium.com/max/600/1*A0gj1R2QRBG_mub2Hs6gcg.png

This recurrence is similar to the merge sort for which the solution is O(nlogn). 
We can solve this using the recursion tree or the master method. The best-case time complexity 
of the quick sort  = O(nlogn)
     

*/
/*
Average case: 
In the worst-case scenario, the partition is always unbalanced, and there will be only 1 recursive 
call at each level of recursion. In such a scenario, the generated tree is skewed in nature. 
So the height of the tree = O(n) and recursion requires a call stack of size O(n). 
The worst-case space complexity  of the quick sort = O(n).

The partition is always balanced in the best-case scenario, and there will be 2 recursive calls 
at each recursion level. In such a scenario, the generated tree is balanced in nature. 
So the height of the tree = O(logn), and recursion requires a call stack of size O(logn).
The best-case space complexity  of the quick sort = O(logn).

The worst-case space complexity
 https://cdn-images-1.medium.com/max/600/1*h6C8WodiZvZ04CwgOKOgBA.png
 tc: O(nlogn)
*/

/*
 pivot selection:
 In the above implementation, we have chosen the rightmost element as the pivot element. 
 But this can result in a worst-case situation when the input array is sorted(it is also for left most element). 
 The best idea would be to choose a random pivot that minimizes the chances of worst-case 
 at each level of recursion. Selecting the median element as a pivot would be also acceptable in the majority of cases. 
 */
