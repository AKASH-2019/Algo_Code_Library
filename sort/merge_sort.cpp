#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums,int l,int mid,int r){
    int n1 = mid-l+1;
    int n2 = r-mid;
    int x[n1],y[n2];
    for(int i=0; i<n1; i++){
        x[i] = nums[l+i];
    }
    for(int i=0; i<n2; i++){
        y[i] = nums[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(x[i]<=y[j]){
            nums[k] = x[i];
            k++;i++;
        }else{
            nums[k] = y[j];
            k++;j++;
        }
    }
    while(i<n1){
        nums[k] = x[i];
        k++;i++;
    }
    while(j<n2){
        nums[k] = y[j];
        k++;j++;
    }
}

void mergeSort(vector<int>& nums, int l, int r){
    if(l>=r){        // l == r during the recursive calls, then the sub-array has one element left, which is trivially sorted
        //cout<<l<<" "<<r<<endl;
        return;
    }
    int mid = l+(r-l)/2;       // got through this blog: https://ai.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html
    mergeSort(nums,l,mid);
    mergeSort(nums,mid+1,r);
    //cout<<l<<" "<<r<<endl;
    merge(nums,l,mid,r);
}

int main() {
	// your code goes here
	vector<int>nums{5,55,10,6,1,4,2};
	mergeSort(nums,0,nums.size()-1);
	
	for(auto it:nums){
	    cout<<it<<" ";
	}
	return 0;
}

/*
Merge Sort Time Comlexity Analysis

Let's assume that T(n) is the worst-case time complexity of the merge sort for n  integers. 
When n >1 (merge sort on a single element takes constant time), then we can break down the 
time complexities as follows:
Divide part: the time complexity of the divide part is O(1) because calculating the middle index 
takes constant time.
Conquer part: we are recursively solving two sub-problems, each of size n/2. So the time complexity
of each subproblem is T(n/2) and the overall time complexity of the conquer part is 2T(n/2).
Combine part: As calculated above, the worst-case time complexity of the merging process is O(n).

        T(n) = O(1) + 2T(n/2) + O(n) = 2T(n/2) + O(n) = 2T(n/2) + cn
        T(n) = c              if n = 1
        T(n) = 2T(n/2) + cn   if n > 1

Merge Sort Space complexity Analysis
Space complexity of merge sort 
        = space complexity of the merging process + size of recursion call stack 
        = O(n) + O(logn) 
        = O(n)
    **  The size of recursion call stack = height of the merge sort recursion tree = O(logn) 
*/

/*
Think.................
1. For the smaller input, It is slower in comparison to other sorting algorithms. 
Even it goes through the complete process if the array is already or almost sorted.
2. Merge sort is the best choice for sorting a linked list. It is relatively easy to implement 
a merge sort in this situation to require only O(1) extra space. On the other hand, 
a linked list's slow random-access performance makes some other algorithms, 
such as quicksort, perform poorly and others like heap sort completely impossible.
*/

