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






int main(){

}