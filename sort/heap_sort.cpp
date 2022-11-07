#include <bits/stdc++.h>

using namespace std;

// heapify -> O(logn)
void heapify(vector<int> &ht, int i){
    int largest = i, ln = ht.size();
    int l = i*2+1;
    int r = i*2+2;
    if(l<ln && ht[l]>ht[largest]){
        largest = l;
    }
    if(r<ln && ht[r]>ht[largest]){
        largest = r;
    }
    
    if(largest != i){
        swap(ht[i],ht[largest]);
        heapify(ht,largest);
    }
}

// buildMaxheap -> O(n/2) -> O(n)
void buildMaxheap(vector<int> &ht){
    int ln = ht.size();
    int st = ln/2-1;
    for(int i=st; i>=0; i--){
        heapify(ht,i);
    }
}

void insert(vector<int> &ht, int value){
    int ln = ht.size();
    
    if(ln==0){
        ht.push_back(value);
    }else{
        ht.push_back(value);
        buildMaxheap(ht);
    }
}

// heapSort -> O(nlogn)
void heapSort(vector<int> &ht){
    int ln = ht.size();
    
    for(int i=ln-1; i>=0; i--){     // n
        swap(ht[i], ht[0]);
        cout<<ht[i]<<" ";
        ht.pop_back();
        // buildMaxheap(ht);
        heapify(ht,0); // logn
    }
}

void printHeapArray(vector<int> &hT)
{
  for (int i = 0; i < hT.size(); ++i)
    cout << hT[i] << " ";
  cout << "\n";
}

int main()
{
    vector<int> heapTree;
    vector<int> temp{35,33,42,10,14,19,27,44,26,31};
    for(auto x:temp){
        insert(heapTree, x);
    }
    // insert(heapTree, 3);
    // insert(heapTree, 4);
    // insert(heapTree, 9);
    // insert(heapTree, 5);
    // insert(heapTree, 2);
    
    cout << "Max-Heap array: ";
    printHeapArray(heapTree);
    
    cout<<endl<<"heap sort"<<endl;
    heapSort(heapTree);

    return 0;
}
