// Disjoint Set | Union By Rank and Path Compression
/* tc : 
        As mentioned before, if we combine both optimizations - path compression with union by 
        size / rank - we will reach nearly constant time queries. It turns out, that the final 
        amortized time complexity is , where  is the inverse Ackermann function, which grows very 
        slowly. In fact it grows so slowly, that it doesn't exceed  for all reasonable  
        (approximately ).

        Amortized complexity is the total time per operation, evaluated over a sequence of multiple
        operations. The idea is to guarantee the total time of the entire sequence, while allowing 
        single operations to be much slower then the amortized time. E.g. in our case a single call 
        might take  in the worst case, but if we do  such calls back to back we will end up with an 
        average time of .

        We will also not present a proof for this time complexity, since it is quite long and 
        complicated.
        
        Also, it's worth mentioning that DSU with union by size / rank, but without path compression 
        works in  time per query. */

#include <bits/stdc++.h>
using namespace std;

int parent[100];
int ranks[100];

int makeSet(int x){
    parent[x] =x;
    ranks[x]=0;
}

int find(int x){
    if(x == parent[x]){
        return parent[x];
    }
    // return find(parent[x])     
    return parent[x] = find(parent[x]);    // path compression    7 <- 6 <- 5  == 7 <- 5   7 <- 6 
}

int unionSet(int x, int y){
    int px = find(x);
    int py = find(y);
    
    if(ranks[px]>ranks[py]){
        parent[py]=px;
    }else if(ranks[px]<ranks[py]){
        parent[px] = py;
    }else{
        parent[py] = px;
        ranks[px]+=1;
    }
}

int main() {
	int n, com;
	cout<<"enter the total num of node ";
	cin>>n;
	
	for(int i=0; i<n; i++){
	    makeSet(i);
	}
	
	cout<<"enter the total num of component ";
	cin>>com;
	
	while(com--){
	    int x,y;
	    cin>>x>>y;
	    unionSet(x,y);
	   // if(find(x) != find(y)){
	   //     unionSet(x,y);
	   // }
	}
	cout<<"enter two node ";
	int f1,f2;
	cin>>f1>>f2;
	if(find(f1) != find(f2)){
	    cout<<"not in same component"<<endl;
	}else{
	    cout<<"same component"<<endl;
	}
	
	return 0;
}

