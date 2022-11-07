#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(int A[], int n)
{
    int ans[];
    bool mark[n];
   // We can initialize the boolean array mark[n] by True
   // assuming that all elements are unique
    for (i = 0 to n-1)  
        mark[i] = True;

    for (i = 0 to n-1)
    {
        if (mark[i] == True)
        {
           for(j = i+1 to n-1)
               if (A[i] == A[j])
                  mark[j] = False;
         }
     }
   for(i = 0 to n-1)
        if (mark[i] == True)
            ans.insert(A[i]);
   return ans;
}

//////////////////////////////////////////////////////USING SORT//////////////////////////////////////////////
/*
// Time complexity = O(nlogn)

// Space complexity = O(1) in the case of heapsort and O(n) in case of merge sort.
int rmvDuplicateUnsorted(int arr[], int n){
    sort(arr, arr+n);
    int j=0;
    for(int i=0; i<n-1; i++){
        if(arr[i] != arr[i+1]){
            arr[j] = arr[i];
            j++;
        }
    }
    arr[j] = arr[n-1];
    return j+1;
}

int main()
{
    int arr[] = { 1, 2, 5, 1, 7, 2, 4, 2 };
    int n = sizeof(arr)/sizeof(arr[0]);
    
    n = rmvDuplicateUnsorted(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}*/

//////////////////////////////////////////////USING HASH TABLE////////////////////////////////////////////////
/*
// TC: Traversing the array + Searching element in Hash Table + Inserting elements into ans[] array and Hash Table

// = O(n) + O(n) + O(n) = O(n)

// SC: Storing Hash Table + Storing ans array

// = O(n) + O(n) = O(n)

void rmvDuplicateUnsorted(int arr[], int n){
    unordered_set<int>s;
    // unordered_set<int>::reverse_iterator rit;
    
    for(int i=0; i<n; i++){
        s.insert(arr[i]);
    }
    
    for(auto x:s){
        cout<<x<<" ";
    }
    cout<<endl;
    
}

int main()
{
    int arr[] = { 1, 2, 5, 1, 7, 2, 4, 2 };
    int n = sizeof(arr)/sizeof(arr[0]);
    
    rmvDuplicateUnsorted(arr, n);

    return 0;
}
*/

