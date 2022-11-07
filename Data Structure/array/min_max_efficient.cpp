// tc: O(n)
// st: O(1) as no extra space was needed.

#include <bits/stdc++.h>
using namespace std;

vector<int> findMinMax(vector<int> &arr, int n){
    int min,max,i;
    if(n%2){
        min = arr[0];
        max = arr[0];
        i = 1;
    }else{
        if(arr[0]>arr[1]){
            min = arr[1];
            max = arr[0];
        }else{
            min = arr[0];
            max = arr[1];
        }
        i = 2;
    }
    while(i<n){
        if(arr[i]<arr[i+1]){
            if(arr[i]<min){
                min = arr[i];
            }
            if(arr[i+1]>max){
                max = arr[i+1];
            }
        }
        else{
            if(arr[i+1]<min){
                min = arr[i+1];
            }
            if(arr[i]>max){
                max = arr[i];
            }
        }
        i += 2;
    }
    
    vector<int>res = {min,max};
    return res;
}  

int main() {
	
	vector<int> arr={-8, -3, -10, -32, -1};
// 	vector<int> arr={4, 2, 0, 8, 20, 9, 2};
	int n = arr.size();
	
	vector<int> ans = findMinMax(arr, n);
	cout<<"min element: "<<ans[0]<<endl;
	cout<<"max element: "<<ans[1]<<endl;
	
	
	return 0;
}

/*
Analysis:
For each pair, there are three comparisons: first among the elements of the pair and the other 
two with min and max. Total number of comparisons = 3 * (n-1) / 2 (If n is odd) or 3*(n–2)/2 
(If n is even).
Time complexity = O(n). Here we observe that the total number of comparisons is less than the 
first approach. In other words, comparison in pairs helps us to optimize the first approach further. 
*/

