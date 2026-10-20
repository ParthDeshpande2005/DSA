#include<bits/stdc++.h>
using namespace std;

// Spanning Tree ->
// a tree in which we have N nodes & N-1 edges and all nodes are reachable from each other.
// can only be formed when the graph is connected as starting from any node we must be able to visit all the other nodes.

// Minimum spanning Tree ->
// it is the spanning tree where the sum of the edge weight is minimum.


/*

    normal graph    weights in bracket->

    0---1---2       0<->1(2), 0<->3(6)
    |  /|  /        1<->3(8), 1<->2(3), 1<->4(5)
    | / | /         2<->4(7)
    3   4           

    minimum spanning tree-->

    0---1---2       sum of edges = 16
    |   |         
    |   |         
    3   4  

    spanning tree-->

    0---1---2       sum of edges = 20
       /   /        
      /   /         
    3   4  

*/  

//Prim's Algorithm...used to find the minimum spanning tree.
// we use priority queue(min heap) along with visited array to find the sum of edges of the minimum spanning tree
// also find the edges used in the minimum spanning tree.
// IMP-->>
// we dont add all the edes together to the priority queue as there is chance of making a graph where all nodes cannot be visited from any node.
//we can start from any vertice as we need to visit all.
//here we will start with the 0 vertice to keep it standard.
//T.C-> O(edges * log(edges))
//S.C-> O(V + E)
vector<pair<int,int>> spanningTree(int V, vector<vector<int>> adj[]) {
       
    //priority queue
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq; //{weight{nextnode,parentnode}}

    //visited array 
    vector<int> visited(V,0);

    //all edges in the minimum spanning tree
    vector<pair<int,int>> min_edges;

    pq.push({0,{0,-1}}); // here -1 is the parent of the vertice 0.


    //result sum of all edges ->
    int sum  = 0;

    while(!pq.empty()){
        int weight = pq.top().first;
        int cur_node = pq.top().second.first;
        int parent_node = pq.top().second.second;

        pq.pop();
 
        if(visited[cur_node]==1){ //skip if the node is all ready visited.
            continue;
        }

        sum += weight;

        //mark cur_node as visited
        visited[cur_node]=1;

        if(parent_node!=-1){ //adding to min_edges. just not adding the initial node whose parent is -1.
            min_edges.push_back({parent_node,cur_node});
        }

        for(auto it : adj[cur_node]){

            int next_node = it[0];
            int edge_weight = it[1];

            if(visited[next_node]==1){
                continue;
            }

            pq.push({edge_weight,{next_node,cur_node}});

        }
    }
    return min_edges;
} 



//IMP --->
//Disjoint Set is a complex datastucture used to tell if the 2 nodes belong to same set in graph in O(1)
//as we know a graph can have multiple disjoint set.
//for complete understanding of this datastructure watch striver video.
//we also implement the graph compression to find in faster time complexity.
//2 ways we make the graph in this one is by unionbyrank and one is unionbysize.
//this is not like normal graph as we focus on conuction of node to ultimate parent and not original parent.
//this graph can't tell if 2 nodes are connected to each other or not.
//it is only used to tell if they belong to same disjoint set.
//all member of one disjoint set will have same ultimate parent.
class DisjointSet {
    vector<int> rank;
    vector<int> size;
    vector<int> parent; 
public:
    DisjointSet(int n) {
        rank.resize(n+1,0); //we take n+1 as sometime the graph can be 1 based indexing.
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUpar(int node){ // to find the ultimate parent.
        if(parent[node] == node){
            return node;
        }
        //here we are also doing the path comprasion.
        return parent[node] = findUpar(parent[node]); 
    }

    bool find(int u, int v) {
        //we will check if ultimate parent are the same.
        return findUpar(u) == findUpar(v); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        //we need not to do any thing if they allready belong to same disjoint set.
        if(ulp_u == ulp_v){ 
            return;
        }

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        //when the rank are equal. i am makeing v parent.we can even do other way around.
        else{ 
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        //we need not to do any thing if they allready belong to same disjoint set.
        if(ulp_u == ulp_v){ 
            return;
        }

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else if(size[ulp_v] < size[ulp_u]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        //when the rank are equal. i am makeing v parent.we can even do other way around.
        else{ 
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};





int main() {
    int V = 5;

    vector<vector<int>> adj[V];

    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});

    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});

    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});

    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});

    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    vector<pair<int, int>> min_edges = spanningTree(V, adj);

    cout << "Edges in the Minimum Spanning Tree:\n";

    int sum = 0;

    for (auto edge : min_edges) {
        cout << edge.first << " - " << edge.second << '\n';
    }

    return 0;





    
}