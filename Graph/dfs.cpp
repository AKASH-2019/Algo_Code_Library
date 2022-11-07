// dfs
// TC: O(n+e)
// SC: O(n+e)+O(n)+O(n)                adj+vis+queue
#include <bits/stdc++.h>
using namespace std;

void helpDfs(int node, vector<int>& adj[], vector<int>& vis, vector<int>& dfs){
    dfs.push_back(node);
    vis[node]=1;
    
    for(auto it:adj[node]){
        if(!vis[it]){
            helpDfs(it,adj,vis,dfs);
        }
    }
}

vector<int>dfsTraverse(int node, vector<int>& adj[]){
    vector<int>dfs;
    vector<int>vis(node+1,0);
    
    for(int i=1; i<=node; i++){
        if(!vis[i]){
            helpDfs(i,adj,vis,dfs);
        }
    }
    return dfs;
}

int main() {
	// your code goes here
	return 0;
}


/*
            1--2--4  3--5
               |  |
               7--6
               
    helDfs()=>             dfs(1)          dfs(3)
                        dfs(2)           dfs(5)
                    dfs(4)   dfs(7)        x
                dfs(6)          x
            dfs(7)
              x    
            dfs =>  1 2 4 6 7 3 5
                        
*/
/*
Difference between BFS and DFS:

BFS is a traversal approach in which we first walk through all nodes on the same level before moving on 
to the next level.  	
DFS is also a traversal approach in which the traverse begins at the root node and proceeds through the 
nodes as far as possible until we reach the node with no unvisited nearby nodes.
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
BFS can be used to find a single source shortest path in an unweighted graph because, in BFS, we reach 
a vertex with a minimum number of edges from a source vertex. 	
In DFS, we might traverse through more edges to reach a destination vertex from a source.
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
BFS builds the tree level by level.	
DFS builds the tree sub-tree by sub-tree.
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
BFS is more suitable for searching vertices closer to the given source.	
DFS is more suitable when there are solutions away from source.
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
BFS, siblings are visited before the children.	
DFS, children are visited before the siblings.
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
In BFS there is no concept of backtracking. 	
DFS algorithm is a recursive algorithm that uses the idea of backtracking
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
BFS is optimal for finding the shortest path.	
DFS is not optimal for finding the shortest path.
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
BFS is optimal for finding the shortest path.	
DFS is not optimal for finding the shortest path.
*/
