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


//Topological Sort
//this only works for DAG(directed acyclic graph)
//using dfs solution
stack<int> st;
void dfstoposort(int cur,vector<int> adj[],vector<int> &visited){
    visited[cur]=1;

    for(auto it: adj[cur]){
        if(visited[it]==1){
            continue;
        }

        dfstoposort(it,adj,visited);
    }

    st.push(cur);
}
vector<int> topoSort(int V, vector<int> adj[]){
    //M1 using DFS

    vector<int> visited(V,0);

    for(int i=0;i<V;i++){
        if(visited[i]==1) {
            continue;
        }

        dfstoposort(i,adj,visited);
    }

    vector<int> result;
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }

    return result;
}


//Kahn's Algorithm for Topological Sort
//IMP using a new thing Know as Indegree...IMP...
//Watch striver video for better understanding.....

//this only works for DAG(directed acyclic graph)
//using bfs solution
vector<int> topoSort(int V, vector<int> adj[]){
    //M2 using Kahn's Algorithm.

    vector<int> indegree(V,0); // this is the count of how many edges are directed towards ith node.

    for(int i=0;i<V;i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }   

    queue<int> que;

    for(int i=0;i<V;i++){
        if(indegree[i]==0){ //there will be allways someone with indegree 0 as it is a DAG.
            que.push(i);
        }
    }

    vector<int> result;

    while(!que.empty()){
        int node=que.front();
        que.pop();

        result.push_back(node);
            
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                que.push(it);
            }
        }
    }

    return result;
}


//leetcode 207
//Dectect a cycle in directed graph using dfs.
//IMP as the algorith used for the undirected graph will not work for this.
//we will maintain two visited array to solve this .IMP..
bool directed_dfs(vector<vector<int>>& prerequisites, int cur, vector<int> &visited, vector<int> &visitdfs){

    visited[cur]=1;
    visitdfs[cur]=1;

    for(auto it: prerequisites[cur]){
        if(visitdfs[it]==1){
            return false;
        }
        if(visited[it]==1){
            continue;
        }
        if(!directed_dfs(prerequisites,it,visited,visitdfs)){
            return false;
        }
    }

    visitdfs[cur]=0;

    return true;

}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int n=numCourses;

    vector<int> visited(n,0);
    vector<int> visitdfs(n,0);

    //making adj list
    vector<vector<int>> adj(n);
    for(int i=0;i<prerequisites.size();i++){
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    for(int i=0;i<n;i++){
        if(visited[i]==1){
            continue;
        }

        if(!directed_dfs(adj,i,visited,visitdfs)){
            return false;
        }
    }

    return true;
}


//leetcode 207
//Detect loop in directed Graph using BFS
//here we will use kahn's Algorithm(topo sort) IMP...
// if the topo sort has less than n elements we return fasle as there are multiple dependency meaing a loop . 
//if the topo sort is of size n we return true.
bool canFinish(int n, vector<vector<int>>& pre) {
    //lets create adj list first
    vector<vector<int>> adj(n);
    for(int i=0;i<pre.size();i++){
        adj[pre[i][1]].push_back(pre[i][0]);
    }

    //we will find the topo sort for the adj
    vector<int> topo;
    queue<int> que;
    vector<int> indegree(n,0);

    //create the indegree
    for(int i=0;i<pre.size();i++){
        indegree[pre[i][0]]++;
    }

    //we push all the elements with 0 indegree.
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            que.push(i);
        }
    }

    //now we will find the topo sort
    while(!que.empty()){
        int cur=que.front();
        que.pop();
        topo.push_back(cur);
        for(auto it: adj[cur]){
            indegree[it]--;
            if(indegree[it]==0){
                que.push(it);
            }
        }
    }

    if(topo.size()==n){
        return true;
    }
    return false;

}






int main(){



    return 0;
}