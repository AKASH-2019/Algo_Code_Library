// tc : O(n)
// sc : O(1)

#include <bits/stdc++.h>

using namespace std;

int rmvDuplicate(int arr[], int n){
    if(n==0 || n==1){
        return n;
    }
    int j=0;
    for(int i=0; i<n-1; i++){
        if(arr[i] != arr[i+1]){
            arr[j] = arr[i];
            j++;
        }
    }
    arr[j] = arr[n-1];
    
    return (j+1);
}

int main()
{
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    n = rmvDuplicate(arr,n);
    cout<<n<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}

/*
// brute force approach
// tc: O(n)+O(n) = O(n)
// sc: O(n)

voie rmvDuplicate(int arr[], int n){
    int unique[n], j=0;

    for(int i=0; i<n-1; i++){
        if(arr[i] != arr[i+1]){
            unique[j] = arr[i];
            j++;
        }
    }
    unique[j]= arr[n-1];
    j++;
    cout<<"unique array element"<<endl;
    for(auto it:unique){
        cout<<it<<" ";
    }

}

*/ 
