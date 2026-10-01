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
string findOrder(vector<string> &words) {
        
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


int main(){

    


    return 0;
}