// Find the single element in the sorted array. (leetcode: 540. Single Element in a Sorted Array)
/* brute force 
   tc: O(n)
   sc: O(n)  == vector  
*/
/* effecient force 
   tc: O(n)
   sc: O(n)  == vector  
*/
#include<bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
    // brute force approach
    int ln = nums.size(), ans = -1;
    for(int i=0; i<ln-1; i+=2){
        int xr = nums[i]^nums[i+1];
        
        if(xr != 0){
            int ind = (i%2 == 1 ? i+1 : i);
            ans = nums[ind];
            break;
        }
    }
    if(ans == -1){
        ans = nums[ln-1];
    }
    return ans;

    //////////////////////////////////////////////////////////////////////////////////
    // efficient approach(binary search)

    int low=0, high = nums.size()-2;
    
    while(low<=high){
        int  mid = (low+high)>>1;
        if(nums[mid] == nums[mid^1]){    
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return nums[low];
    
}



int main(){
    vector<int>v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);

    cout<<singleNonDuplicate(v);

    return 0;
}