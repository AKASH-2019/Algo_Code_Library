// tc: O(n*m)
// st: O(1)

#include <bits/stdc++.h>
using namespace std;

void printSpiralMatrix(int arr[45][55], int m, int n){
    int rowstart = 0, rowend = m-1;
    int colstart = 0, colend = n-1;

    while (rowstart < rowend && colstart < colend)
    {
        for(int i = colstart; i <= colend; i++){
            cout<<arr[rowstart][i]<<" ";
        }
        rowstart += 1;

        for(int i=rowstart; i <= rowend; i++){
            cout<<arr[i][colend]<<" ";
        }
        colend -= 1;

        if(rowstart < rowend){
            for(int i = colend; i >= colstart; i--){
                cout<<arr[rowend][i]<<" ";
            }
            rowend -= 1;
        }

        if(colstart < colend){
            for(int i= rowend; i >= rowstart; i--){
                cout<<arr[i][colstart];
            }
            colstart += 1;
        }
    }
    
}

int main(){
    int arr[10][10];
    int row,col;

    printSpiralMatrix(arr,row, col);
}



/*
// another process: recursive
// https://www.enjoyalgorithms.com/blog/print-matrix-in-spiral-order
*/