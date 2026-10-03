//Hard Problem in Graph...

#include<bits/stdc++.h>
using namespace std;

//IMP...Very different appoarch..
//leetcode 802
//using bfs we will use topo sort..
//we need to start with the node with no outgoing node which is reverse conditon of the normal topo sort or kahn's algo.
//So we will reverse all the directed edge and then implemnt topo sort.
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n=graph.size();

    // create a new adj list with all directed edge reversed.
    vector<vector<int>> adj(n);

    for(int i=0;i<n;i++){
        for(auto it:graph[i]){
            adj[it].push_back(i);
        }
    }

    //now we need to create the indegree vector
    vector<int> indegree(n);
    for(int i=0;i<n;i++){
        for(int it:adj[i]){
            indegree[it]++;
        }
    }

    //now adding all the nodes with indegree zero to queue
    queue<int> que;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            que.push(i);
        }
    }

    //now we will find the topo sort 
    vector<int> result;
    while(!que.empty()){
        int cur=que.front();
        que.pop();
        result.push_back(cur);

        for(auto it: adj[cur]){
            indegree[it]--;
            if(indegree[it]==0){
                que.push(it);
            }
        }
    }

    sort(begin(result),end(result));
    return result;
}

//Method 2 is like using recursion not very much graph concept used.
//leetcode 802 
//using dfs we will use 2 visited a normal and one respect to the current dfs
int dfs_SafeNode(int cur,vector<vector<int>>& graph,vector<int> &visited,vector<int> &dfsvisited,vector<int>& result){
        
    if(dfsvisited[cur]==1){
        result[cur]=0;
        return 0;
    }

    visited[cur]=1;
    dfsvisited[cur]=1;

    for(auto it: graph[cur]){
        if(result[it]==0){
            dfsvisited[cur]=0;
            result[cur]=0;
            return 0;
        }
        if(result[it]==2){
            continue;
        }

        bool z=dfs_SafeNode(it,graph,visited,dfsvisited,result);
        if(!z){
            dfsvisited[cur]=0;
            result[cur]=0;
            return 0;
        }
    }

    dfsvisited[cur]=0;
    result[cur]=2;
    return 2;
}
vector<int> eventualSafeNodesdfs(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int> result(n,1);
    vector<int> visited(n,0);
    vector<int> dfsvisited(n,0);

    for(int i=0;i<n;i++){
        if(visited[i]==1) continue;
        dfs_SafeNode(i,graph,visited,dfsvisited,result);

    }

    //returning ans.
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(result[i]==2){
            ans.push_back(i);
        }
    }

    return ans;
}



//leetcode 207->Course Schedule 1
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



//leetcode 210.Course Schedule 2.
//we will return the topo sort for the graph.
//if the topo sort size is less than num then we will return empty vector.
//we will use the Kahn's Algorithm to solve this.
vector<int> findOrder(int num, vector<vector<int>>& pre) {

    vector<int> result;

    //if pre is empty we add all the course 
    if(pre.empty()){
        for(int i=0;i<num;i++){
            result.push_back(i);
        }
        return result;
    }

    //make adj list
    vector<vector<int>> adj(num);
    for(int i=0;i<pre.size();i++){
        adj[pre[i][1]].push_back(pre[i][0]);
    }

    //lets create the indegree vector for topo sort
    vector<int> indegree(num,0);
    for(int i=0;i<pre.size();i++){
        indegree[pre[i][0]]++;
    }

    //now lets add all the node with indegree 0 to the queue
    queue<int> que;
    for(int i=0;i<num;i++){
        if(indegree[i]==0){
            que.push(i);
        }
    }

    //now lets find the topo sort.
    vector<int> topo;
    while(!que.empty()){
        int cur=que.front();
        que.pop();

        topo.push_back(cur);

        for(auto it:adj[cur]){
            indegree[it]--;
            if(indegree[it]==0){
                que.push(it);
            }
        }
    }

    //return result
    if(topo.size()==num){
        return topo;
    }
    return {};
}


//Alien Dictionary--> interesting que check the que on tuf or chatgpt
//the challenge is to create the adj list
//we need to use topo sort on the string.
//ONE IMPROVEMENT I CAN MAKE IS THAT HERE I AM ALSO CONSIDERING DUPLICATE EDGES SO NEED TO AVOID THOSE FOR BETTER SOLUTION.
bool dfstopo(int cur,vector<vector<int>> &adj,vector<int> &visited,vector<int> &dfsvisit,vector<int> &topo){
        
    if(dfsvisit[cur]==1) return false;
        
    visited[cur]=1;
    dfsvisit[cur]=1;
        
    for(auto it: adj[cur]){
        if(visited[it]==0){
            if(!dfstopo(it,adj,visited,dfsvisit,topo)){
                return false;
            }
        }
        else if(dfsvisit[it]==1){
            return false;
        }
    }
        
        
    dfsvisit[cur]=0;
    topo.push_back(cur);
    return true;
}
string Alienlang(vector<string> &words) {
        
    int n=words.size();
        
    //first i need to create a map for the value i will assign to each char
    //so first find all the unique char
        
    int K=0; // K is the number of unique elements.
    vector<int> cnt(26,0);
    for(int i=0;i<n;i++){
        for(char it:words[i]){
            if(cnt[it-'a']==0){
                cnt[it-'a']++;
                K++;
            }
        }
    }
        
    //now we have all the unique so lets make a unordered_map.
    //to see which node is given which charchter.
    //so we will know at which index which character is stored.
    unordered_map<int,char> nodetochar;
    unordered_map<char,int> chartonode;
    int low=0;
    for(int i=0;i<26;i++){
        if(cnt[i]>0){
            chartonode['a'+i]=low;
            nodetochar[low]='a'+i;
            low++;
        }
    }
        
        
        
    //now lets create the adj list.
    //as we know each edge is dependent on the 2 adjcent words in words.
    vector<vector<int>> adj(K);
    for(int i=1;i<n;i++){
            
        int ind=0;
        int len=min(words[i].size(), words[i-1].size());
            
        while(ind<len && words[i][ind]==words[i-1][ind]){
            ind++;
        }
            
        if(ind<len){ //we get a vilid edge.
            int prev=chartonode[words[i-1][ind]];
            int next=chartonode[words[i][ind]];
            adj[prev].push_back(next);
        }
        //we wont consider where ind>len as no valid edge can be formed if all char are same.
    }
        
    //now lets start with making topo sort
    //lets do topo sort with dfs.
    vector<int> visited(K,0);
    vector<int> dfsvisit(K,0);
        
    vector<int> topo;
        
    for(int i=0;i<K;i++){
        if(visited[i]==1){
            continue;
        }
            
        bool truth=dfstopo(i,adj,visited,dfsvisit,topo);
        if(!truth){
            return "";
        }
            
    }
        
    reverse(topo.begin(),topo.end());
        
    if(topo.size()==K){
        string result="";
        for(int i=0;i<K;i++){
            char cur=nodetochar[topo[i]];
            result+=cur;
        }
            
        return result;
    }
    else{
        return "";
    }
        
}



//MY SOLUTION NOT OPTIMAL
//we need to find the shortest Path for each node from the sourse.//we are given a weighted DAG.
//so each edge has given dist. 
//N is the number of nodes and M is the number of edges.
//I will use bfs.
vector < int > shortestPathbfs(int N, int M, vector < vector < int >> & edges) {

    //makeing adj list
    vector<vector<pair<int,int>>> adj(N);
    int n=edges.size();
    for(int i=0;i<n;i++){
        int prev=edges[i][0];
        int next=edges[i][1];
        int dist=edges[i][2];

        adj[prev].push_back({next,dist});
    }

    vector<int> result(N,-1);

    vector<int> visited(N,0);

    queue<pair<int,int>> que; //this store cur node and level(distance form source).

    que.push({0,0}); 
    visited[0]=1;
    result[0]=0;

    while(!que.empty()){
        pair cur=que.front();
        que.pop();
        int val=cur.first;
        int dist=cur.second;

        // result[val]=dist;

        for(auto it: adj[val]){

            int next=it.first;
            int newdist=dist+it.second;

            if(visited[next]==0){
                que.push({next,newdist});
                visited[next]=1;
                result[next]=newdist;
            }
            else{ //meaing it is allready visited so i need to check if current dist is smaller.
                if(newdist<result[next]){
                    que.push({next,newdist});
                    result[next]=newdist;
                }
            }
        }
    }

    return result;
}


//Now lets try the dfs for the prev que.This is also not optimal. but doing it for better understanding of graph and dfs.
void dfsdist(int cur,int cur_dist,vector<int> &result,vector<vector<pair<int,int>>>& adj){
    // result[cur]=cur_dist;

    for(auto it: adj[cur]){
        int next=it.first;
        int newdist=it.second+cur_dist;

        if(result[next]==-1){ //meaning the node is not visiied a single time
            result[next]=newdist;
            dfsdist(next,newdist,result,adj);
        }
        else{
            if(newdist<result[next]){
                result[next]=newdist;
                dfsdist(next,newdist,result,adj);
            }
        }
    }

}
vector < int > shortestPathdfs(int N, int M, vector < vector < int >> & edges) {

    //making adj list
    vector<vector<pair<int,int>>> adj(N);
    int n=edges.size();
    for(int i=0;i<n;i++){
        int prev=edges[i][0];
        int next=edges[i][1];
        int dist=edges[i][2];

        adj[prev].push_back({next,dist});
    }

    vector<int> result(N,-1);

    result[0]=0;

    dfsdist(0,0,result,adj);

    return result;
        
}


//optimal solution using topo sort time complexity is almost same but this is the standard appoarch to solve weitghted DAG.
//we use topo sort and then perform relaxcation on the result array.
void dfstopo(int cur,vector<int> &visited,stack<int>& topo,vector<vector<pair<int,int>>>& adj){
    visited[cur]=1;

    for(auto it:adj[cur]){
        int next=it.first;
        if(visited[next]==1){
            continue;
        }
        dfstopo(next,visited,topo,adj);
    }

    topo.push(cur);
}
vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {

    //making adj list
    vector<vector<pair<int,int>>> adj(N);
    int n=edges.size();
    for(int i=0;i<n;i++){
        int prev=edges[i][0];
        int next=edges[i][1];
        int dist=edges[i][2];

        adj[prev].push_back({next,dist});
    }

    //step 1 we need to find the topo sort 
    //we will use dfs to find the topo sort using the stack method
    stack<int> topo;
    vector<int> visited(N,0);

    for(int i=0;i<N;i++){
        if(visited[i]==1) continue;
        dfstopo(i,visited,topo,adj);
    }

    //now step 1 is completed as we have the topo sort stored in the topo stack.

    //step 2-> we will perform relaxcation we will start form the top of topo sort. 
    //we will create a result array having all the distance form sourse initialize to -1. then we will assign the new distance.
    //we travel in topological sort order so that when we are at a current node we know that all its parent node are visited so we can find the minium path for the current node.
    
    //as we need to start form source which is 0 in this case.
    //we mark the result[0]=0 and other as INT_MAX so that allways we get the min distance form the source.

    vector<int> result(N,INT_MAX);
    result[0]=0;

    while(!topo.empty()){
        int cur=topo.top();
        topo.pop();

        if(result[cur]==INT_MAX) continue; //we skip all the node who are not connected to zero.

        for(auto it: adj[cur]){
            int next=it.first;
            long long nextdist=it.second+result[cur];

            if(nextdist<result[next]){
                result[next]=nextdist;
            }
        }

    }

    //marking all the nodes that can not be visited as -1.
    for(int i=0;i<N;i++){
        if(result[i]==INT_MAX){
            result[i]=-1;
        }
    }

    return result;
}


//we need to find shortest path from source to all node in undirected graph with unit weight. 
//meaning all the edges have a weight of 1.
//one improvement can be done is to avoid visited as we can consider the result vector to check if the index is visited or not
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
    //lets try bfs
    // we only visit one path once as it will be shorted due to bfs

    // lets create the adjancy list
    vector<vector<int>> adj(N);
    for(int i=0;i<M;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> visited (N,0);
    queue<pair<int,int>> que;

    que.push({0,0});
    visited[0]=1;
    vector<int> result(N,-1);
        
    while(!que.empty()){
        pair<int,int> cur=que.front();
        int dist=cur.second;
        int ind=cur.first;
        result[ind]=dist;

        que.pop();

        for(auto it: adj[ind]){
            if(visited[it]==0){
                visited[it]=1;
                que.push({it,dist+1});
            }
        }
    }

    return result;
}




int main(){

    


    return 0;
}