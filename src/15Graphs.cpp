#include<bits/stdc++.h>
using namespace std;

//Graph -->
//there are majorily two types of graph that are Directed and Undiredted Graph

//Graphs Representation-->
//There are two ways to represent the graph 
//using matrix and adjancy list..

//Graph Traversal--> BFS(Breath First Search)(or level wise trversal) 
//                   DFS(Deapth First Search)


//Printing Graph using BFS
vector<int> BFSofGraph(int V,vector<int> adj[]){
    vector<int> bfs;

    int vis[V]={0};  //way to make a V sized array of all 0.
    vis[0]=1;

    queue<int> que;
    que.push(0);
    
    while(!que.empty()){
        int cur=que.front();
        que.pop();

        bfs.push_back(cur);

        for(int it:adj[cur]){
            if(vis[it]==0){
                vis[it]=1;
                que.push(it);
            }
        }
    }
    return bfs;
}

//Printing Graph using DFS
void dfs(int node,vector<int> adj[],int vis[],vector<int> &ls){
    vis[node]=1;
    ls.push_back(node);

    for(auto it: adj[node]){
        if(vis[it]==0){
            dfs(it,adj,vis,ls);
        }
    }
}
vector<int> DFSofGraph(int V,vector<int> adj[]){
    
    int vis[V]={0};
    vector<int> ls;

    dfs(0,adj,vis,ls);

    return ls;

}



int main(){

    //one based indexing..
    vector<int> adj[]={{1,2},{0,4,5},{0,3,6},{2,7},{1},{1},{2,7},{3,6}};

    vector<int> bfs=BFSofGraph(8,adj);
    for(int i:bfs){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> dfs=DFSofGraph(8,adj);
    for(int i:dfs){
        cout<<i<<" ";
    }
    cout<<endl;
    

    return 0;
}