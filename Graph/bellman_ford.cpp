// Bellman ford algorithm 
// tc : O(n-1)*O(e)
// sc : O(n)                     // dist array

#include <bits/stdc++.h>
using namespace std;

struct node{
    int u,v,w;
    
    node(int a, int b, int c){
        u = a;
        v = b;
        w = c;
    }
};

int main() {
	int n,e;
	cin>>n>>e;
	int u,v,w;
	vector<node>nums;
	for(int i=0; i<e; i++){
	    cin>>u>>v>>w;
	    nums.push_back(node(u,v,w));
	}
	
	int src;
	cin>>src;
	
	vector<int>dist(n,INT_MAX);
	dist[src]=0;
	
	for(int i=1; i<=n-1; i++){
	    for(auto it:nums){
	        if(dist[it.u]+it.w < dist[it.v]){
	            dist[it.v] = dist[it.u]+it.w;
	        }
	    }
	}
	
	int f=0;
	for(auto it:nums){
	    if(dist[it.u]+it.w < dist[it.v]){
	        dist[it.v] = dist[it.u]+it.w;
	        f = 1;
	        break;
	    }
	}
	
	if(f){
	    cout<<"Negative Cycle Detect";
	}else{
	    for(int i=0; i<n; i++){
	        cout<<"for "<<i<<" weight "<<dist[i]<<endl;
	    }
	}
	
	
	return 0;
}

/*
5 7
0 1 5
1 2 -2
1 5 -3
2 4 3
5 3 1 
3 2 6 
3 4 -2
0
*/
/*
    ** Find sorthest path source to other node on postive/negative weight
    ** Detect negative cycle
*/

/*
Condition:
   ** Directed graph
   ** Work on Both +ve and -ve edges  
   ** But Does not contain negative cycle 
*/

/*
why does bellman ford not work on the undirected graph?
   suppose :   
                  -2
               1 ---- 2  it is mean 1->2 => -2 and 2->1 => -2 also which negative cycle.
*/

/*
why n-1?
   a <- b <- c <- d <- e
   ** n = 5 so, the longest path must be less than equal (n-1)
   ** edge -> ed, dc, cb, ba 
   1 iteration => ed -> inf, dc -> inf, cb -> inf, ba -> (src+wt) -> dis[b]
   2 iteration => ed -> inf, dc -> inf, cb -> dis[b] + w, ba -> (src+wt) -> dis[b]
   3 ...
   4 ...
*/

