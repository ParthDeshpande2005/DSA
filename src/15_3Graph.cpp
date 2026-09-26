// Cycle in graph-->

#include<bits/stdc++.h>
using namespace std;


//bfs method to detect the cycle in the graph .
//we we also store the previous in the queue while pushing the next in the graph this way we will skip the node that we are comming from.
bool isCycle(int V, vector<int> adj[]) {
    int n=V;
    queue<pair<int,int>> que;
    vector<int> visited(n,0);

    for(int k=0;k<n;k++){
        if(visited[k]==1){
            continue;
        }

        que.push({k,-1});
        visited[k]=1;
            
        while(!que.empty()){
            pair<int,int> cur=que.front();
            que.pop();

            int i=cur.first;
            int j=cur.second;

            for(auto it: adj[i]){
                if(it==j){
                    continue;
                }

                if(visited[it]==1){
                    return true;
                }

                visited[it]=1;
                que.push({it,i});
            }
        }
    }
    return false;
}



//finding the cycle in grahp using dfs.
int n;
vector<int> visited;
bool dfs(int cur,int prev,vector<int> adj[]){
    bool result=false;
    for(auto it: adj[cur]){
        if(it==prev){
            continue;
        }
        if(visited[it]==1){
            return true;
        }
        visited[it]=1;
        result= result||dfs(it,cur,adj);
    }
    return result;
}
bool isCycle(int V, vector<int> adj[]) {
    n=V;
    visited.resize(n,0);
    bool result=false;
        
    for(int i=0;i<n;i++){
        if(visited[i]==1){
            continue;
        }

        visited[i]=1;
        bool ans=dfs(i,-1,adj);
        result = result|| ans;
    }

    return result;
}


//leetcode 785
// A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
//Return true if and only if it is bipartite.

//striver explains the bipartite graph as the that can be colored using 2 colour and no adjacent node have same colour.

//striver aslo gives observation that only the graph having odd length of loop/cycle will give false.
//the graph that are liner or have even length loop/cycle is bipartite graph.

//lets use dfs.
int n2;
vector<int> visited2;
bool dfs2(int cur,int color,vector<vector<int>>& graph){
    visited2[cur]=color;
    cout<<cur<<" "<<color<<endl;
    for(int it: graph[cur]){
        if(visited2[it]!=-1){
            if(visited2[it]==color){
                return false;
            }
        }
        else{
            if(!dfs2(it,color^1,graph)){
                return false;
            }
        }
    }

    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    n2=graph.size();
    visited2.resize(n2,-1); // initially we start with all color as -1 then we will assign two color as 0,1.

        
    for(int i=0;i<n2;i++){
        if(visited2[i]!=-1) continue;
        if(!dfs2(i,0,graph)){
            return false;
        } 
    }

    return true;
}





int main(){



    return 0;
}