#include<bits/stdc++.h>
using namespace std;

// Leetcode 547.
//This que uses the matrix type representation for the graph..
//I have used BFS. we can even use DFS..
int findCircleNum(vector<vector<int>>& isConnected){

    if(isConnected.empty()) return 0;

    int n=isConnected.size();
    vector<int> visited(n,0);
    int cnt=0;

    queue<int>que;

    for(int i=0;i<n;i++){
        if(visited[i]==1) continue; //we will skip if the element is allready visited...

        cnt++;
        que.push(i);
        visited[i]=1;

        while(!que.empty()){
            int cur=que.front();
            que.pop();

            for(int i=0;i<n;i++){
                if(isConnected[cur][i]==1){
                    if(visited[i]==1) continue;

                    visited[i]=1;
                    que.push(i);
                }
            }
        }
    }
    return cnt;
}


//similar to last que 
//but input is the edges.
//this time we will use BFS
void dfs(int cur,vector<vector<int>> &adj,vector<int> &visited){
    visited[cur]=1;

    for(int i:adj[cur]){
        if(visited[i]==0){
            dfs(i,adj,visited);
        }
    }
}
int countComponents(int V,vector<vector<int>> & edges){

    //we will make a adjency list form the edges.
    vector<vector<int>> adj(V);
    for(auto &e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    //visited array
    vector<int> visited(V,0);

    int components=0;

    for(int i=0;i<V;i++){

        if(visited[i]==1) continue;

        components++;
        dfs(i,adj,visited);

    }
    return components;
}




int main(){

    

    return 0;
}