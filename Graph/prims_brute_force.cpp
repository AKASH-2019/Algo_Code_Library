// mst prims algorithem
// tc : greater than O(n^2)          outer loop(n)+inner loop(n)+ inner loop/adj edge loop
// sc : n+n+n+n                      adj list+key+parent+mstSet
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,e;
	cin>>n>>e;
	vector<pair<int,int> > adj[n];
	int a,b,w;
	for(int i=0; i<e; i++){
	    cin>>a>>b>>w;
	    adj[a].push_back(make_pair(b,w));
	    adj[b].push_back(make_pair(a,w));
	}
	
	int key[n], mstSet[n], parent[n];
	for(int i=0; i<n; i++){
	    key[i] = INT_MAX;
	    mstSet[i] = 0;
	    parent[i] = -1;
	}
	key[0]=0;
	int miniWeight=0;
	for(int i=0; i<n-1; i++){
	    int mini = INT_MAX,u;
	    
	    for(int i=0; i<n; i++){
	        if(mstSet[i] == 0 && key[i]<mini){
	            mini = key[i];
	            u = i;
	        }
	    }
	    mstSet[u]=1;
	    for(auto it:adj[u]){
	        int v = it.first;
	        int weight = it.second;
	        if(mstSet[v] == 0 && weight < key[v]){
	            key[v] = weight;
	            parent[v] = u;
	        }
	    }
	}
	
	for(int i=0; i<n; i++){
	    cout<<i<<" parent "<<parent[i]<<endl;
	    miniWeight += key[i];
	}
	cout<<"weight of the mst "<<miniWeight<<endl;
	
	return 0;
}

/*
5 6 
0 1 2 
0 3 6 
1 2 3 
1 3 8 
1 4 5 
2 4 7 
++++++++++++++++++++++++++++++++
6 9
0 1 2 
0 4 4 
0 3 1 
3 4 4 
1 3 3 
1 2 3 
1 5 7
5 2 8
3 2 5
*/

/*
mst:
   ** It has exactly n node and n-1 edge
   ** Every node is reachable from every other nodes
   ** spanning tree/ tree can't have a cycle
   ** A graph has multiple spanning trees but you should find out the minimum weight of those trees for mst

In the computation aspect, Prim’s and Dijkstra’s algorithms have three main differences:
      
        ** It differs from the minimum spanning tree because the shortest distance between two 
           vertices might not include all the vertices of the graph.
        ** Dijkstra’s algorithm finds the shortest path, but Prim’s algorithm finds the MST
        ** Dijkstra’s algorithm can work on both directed and undirected graphs, 
           but Prim’s algorithm only works on undirected graphs
        ** Prim’s algorithm can handle negative edge weights, but Dijkstra’s algorithm may fail 
           to accurately compute distances if at least one negative edge weight exists

        In practice, Dijkstra’s algorithm is used when we want to save time and fuel traveling 
        from one point to another. Prim’s algorithm, on the other hand, is used when we want to 
        minimize material costs in constructing roads that connect multiple points to each other.
*/
