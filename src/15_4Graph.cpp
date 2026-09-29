//Hard Problem in Graph...

#include<bits/stdc++.h>
using namespace std;



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




int main(){

    


    return 0;
}