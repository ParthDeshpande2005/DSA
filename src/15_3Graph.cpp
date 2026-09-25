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







int main(){



    return 0;
}