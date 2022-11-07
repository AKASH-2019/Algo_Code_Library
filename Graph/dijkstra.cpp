// Dijkstra Algorithm (find the sorhtest path from src to any other node)
// tc:  O(nlogn) = O((e+n)*logn)            n node + e edge + priority queue 
// sc:  O(n) + O(n)                         dis[] + priority queue
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	vector<pair<int,int> >adj[100];
	int e,n,a,b,w;
	cin>>n>>e;
	
	for(int i=0;i<e; i++){
	    cin>>a>>b>>w;
	    adj[a].push_back(make_pair(b,w));
	    adj[b].push_back(make_pair(a,w));
	}
	int src;
	cout<<"enter source ";
	cin>>src;
	
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq; // dist,node
	vector<int> dis(n+1,INT_MAX);
	
	dis[src] = 0;
	pq.push(make_pair(0,src));
	
	while(!pq.empty()){
	    int prevdist = pq.top().first;
	    int prevnode = pq.top().second;
	    cout<<prevnode<<" "<<prevdist<<endl;
	    pq.pop();
	    
	    for(auto it:adj[prevnode]){
	        int next = it.first;
	        int nextdist = it.second;
	        if(dis[next] > dis[prevnode]+nextdist){
	            dis[next] = (dis[prevnode]+nextdist);
	            pq.push(make_pair(dis[next], next));
	        }
	    }
	}
	
	for(int i=1; i<dis.size(); i++){
	    cout<<"src "<<src<<" -> "<<i<<" "<<dis[i]<<endl;
	}
	
	return 0;
}

/*
5 6 
1 2 2 
1 4 1 
2 3 4 
2 5 5 
3 5 1 
4 3 3 
1
*/


/*
note:
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

    Why does Dijkstra’s Algorithm fail on negative weights?
        ** only negative egde:
                   -2
              0 -------- 1
        dis:  0          -2
              -2         -4
              -6         -8
              -------------
              infinite loop 
        ** Infinite Cycles
           https://www.baeldung.com/wp-content/uploads/sites/4/2021/06/Cycles-300x221-1.png

           Let the source node be A. When we run Dijkstra’s algorithm from A, we’ll add C and 
           B to the priority queue, both with a cost equal to -1.

           Next, we’ll pop node B because it has the minimum cost among all nodes in the priority
           queue, and we’ll add nodes A and C, both with a cost equal to -2. In the next step, we
           pop node C and add nodes A and B, both with the cost equal to -3. Then we go back to node A.

           The same scenarios will happen repeatedly; as we can see, we’ll be stuck in an infinite 
           cycle because in each iteration, we’ll get a smaller cost, and we’ll never reach node D 
           using Dijkstra’s algorithm.

           In conclusion, Dijkstra’s algorithm never ends if the graph contains at least one negative cycle.
           By a negative cycle, we mean a cycle that has a negative total weight for its edges.


        ** Wrong Path
           https://www.baeldung.com/wp-content/uploads/sites/4/2021/06/WrongPath-300x287-1.png

           Let A be the source node. When we run Dijkstra’s algorithm from A, we’ll add B and C 
           to the priority queue with costs equal to 5 and 7, respectively.

           Next, we’ll pop node B, since it has the minimum cost among all nodes in the priority queue, 
           and add node C with a cost equal to 1. Finally, we pop node C, and Dijkstra’s algorithm will 
           stop here.

           The cost array will look like this, [0, 5, 1], representing the cost of the shortest path to 
           reach nodes A, B, and C, respectively. However, we can reach node B with a cost equal to 3 
           through the path A \rightarrow C \rightarrow B.

           What happened is that we didn’t go through the Edge(A, C) = 7 because we reached node C with 
           a smaller cost, and we ignore all paths that pass through Edge(A, C) using this greedy approach.

           To conclude this case, Dijkstra’s algorithm can reach an end if the graph contains negative 
           edges, but no negative cycles; however, it might give wrong results.



*/



