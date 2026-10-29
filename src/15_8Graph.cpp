#include<bits/stdc++.h>
using namespace std;


//kosaraju Algorithm help us find the Strongly connected components(SCC's) in the graph.
//a maximal subset of vertices where every vertex can reach every other vertex through a directed path
//it is based on topo sort.
//we find the topo sort then we reverse the graph.
//after revering the grph edges we go no applying the dfs again for finding SCC's.
//watch striver video to get complete idea.
//here i will use dfs to find topo sort .
stack<int> topo;
void dfs(vector<int> adj[],int node,vector<int> &visited){
    visited[node] = 1;

    for(auto it: adj[node]){
        if(visited[it]==0){
            dfs(adj,it,visited);
        }
    }

    topo.push(node);
}
void reversedfs(vector<vector<int>>& transpose,int node,vector<int> &visited){
    visited[node] = 1;

    for(auto it:transpose[node]){
        if(visited[it]==0){
            reversedfs(transpose,it,visited);
        }
    }
}
int kosaraju(int V, vector<int> adj[]){

    //step 1 find the topo sort
    vector<int> visited(V,0);
    for(int i=0;i<V;i++){
        if(visited[i]==0){
            dfs(adj,i,visited);
        }
    }

    //now we have find the topo sort.
    //step 2 lets reverse the adjlist. 
    //--> transpose is our new adjlist.
    vector<vector<int>> transpose(V);
    for(int i=0;i<V;i++){
        for(auto it: adj[i]){
            transpose[it].push_back(i);
        }
    }

    //step 3 now lets travel according to the topo sort and find the answer.
    //new visited
    int result=0;
    vector<int> new_visited(V,0);
    
    while(!topo.empty()){
        int i = topo.top();
        topo.pop();
        if(new_visited[i]==0){
            result++;
            //here we are not asked for the vertices but we can also find the SCC set by little change in reversedfs.
            reversedfs(transpose,i,new_visited);
        }
    }

    return result;

}




//leetcode 1192.Critical Connections in a Network.
//Bridges in graph-->a connection that, if removed, will make some nodes unable to reach some other node.it will create a disjoint set.
//we use striver method using low[] and time[] to solve this question.
//time[] => dfs time of insertion
//low[] => min lowest time insertions of all adjacent nodes apart from the parent.
//apart form parent as we need to check if we can remove the parent to child edge.
//as we dont consider the parent we can check if multiple path are present from the parent to the child node
//if multiple path exist then it is not a bridge.
//in this question we need to find all the bridges in graph.
vector<vector<int>> result;
int timer;
vector<int> timez;
vector<int> low;
vector<int> visited;
void bridge_dfs(int cur,int parent,vector<vector<int>>& adj){
    visited[cur] = 1;

    timez[cur] = low[cur] = timer;
    timer++;

    for(auto it:adj[cur]){
        if(it == parent){
            continue;
        }
        if(visited[it] == 1){ //if visted
            low[cur] = min(low[cur],low[it]);
        }
        else{ //if not visited..
            bridge_dfs(it,cur,adj);
            low[cur] = min(low[cur],low[it]);

            // can node--it be bridge??
            if(low[it] > timez[cur]){
                result.push_back({it,cur});
            }
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

    //make the adj list
    vector<vector<int>> adj(n);
    for(int i=0;i<connections.size();i++){
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
    }

    //init
    int timer = 1;
    timez.resize(n,-1);
    low.resize(n,INT_MAX);
    visited.resize(n,0);

    //we will only call one dfs as the graph is connected.
    //any node can reach other node directly or indirectly through the graph.

    bridge_dfs(0,-1,adj);

    return result;
}







int main(){

}