#include<bits/stdc++.h>
using namespace std;

//Dijkstra  -> IMP this algo does not work for negative weight and negative cycles


//Method 1 using priority queue.
//we use the priority queue insted of the normal queue.
//normal queue also works perfectly fine.
vector<int> dijkstra1(int V, vector<vector<int>> edges, int S) {

    //lets create the adj list
    vector<vector<pair<int,int>>> adj(V); //where we add the next node and the weight associated to it.

    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }

    //we weill use the min heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(V,1000000000);
        
    pq.push({0,S});
    dist[S]=0;

    while(!pq.empty()){
        pair<int,int> temp=pq.top();
        pq.pop();
        int weight = temp.first;
        int node =  temp.second;

        for(auto it:adj[node]){
            int newdist =  weight + it.second;
            if(dist[it.first]>newdist){
                dist[it.first]=newdist;
                pq.push({newdist,it.first});
            }
        }
    }

    return dist;
}


//Method 2 using set DS
// set help us to erase allready existing paths
//it improves is for some test case. as erase take log(n) 
//so comparing time complexity of priorityqueue vs set is very relative to the test case ,graph considered.
vector<int> dijkstra2(int V, vector<vector<int>> edges, int S) {

    //lets create the adj list
    vector<vector<pair<int,int>>> adj(V); //where we add the next node and the weight associated to it.

    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }

    //we weill use the set
    set<pair<int,int>> st;
    st.insert({0,S}); //again we will store dist first and then the node

    //visited
    vector<int> dist(V,1000000000);
    dist[S]=0;

    while(!st.empty()){
        pair<int,int> cur=*st.begin();
        int node = cur.second;
        int weight = cur.first;

        st.erase(st.begin());

        for(auto it:adj[node]){
            if(dist[it.first] > weight + it.second){

                //using set to erase allready existing paths. 
                if(dist[it.first]!=1000000000){ 
                    st.erase({dist[it.first],it.first});
                }

                dist[it.first] =  weight + it.second;
                st.insert({dist[it.first],it.first});
            }
        }

    }

    return dist;
}


//In this que we need to print the shortestPath unlike the previous problem.
//the graph is 1 indexed undirected graph
//we will try to maintain the previous node 
//we will use parent array that will store where we came from.
//we use dijkstra to find the minium dist 
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {

    //making adj list
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }
        
    vector<int> parent(n+1,0); //we init with the indexitself.
    for(int i=1;i<=n;i++){
        parent[i-1]=i;
    }

    vector<int> dist(n+1,1e9);
    dist[1]=0;

    //we will use dijkstra algo to find the min dist from the source.
    //using priority queue.
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1}); //{dist,index}

    while(!pq.empty()){
        int weight = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        for(auto it:adj[node]){
            int next = it.first;
            int weight_next = it.second;

            int new_weight = weight_next + weight;

            if(new_weight < dist[next]){
                dist[next] = new_weight;
                parent[next] = node;

                pq.push({new_weight,next});
            }
        }
    }

    //now we have the minium dist.
    if(dist[n]==1e9){
        return {-1};
    }

    vector<int> result; //first index of the result is the total distance
    result.push_back({dist[n]});

    //now adding the path to the result;
    result.push_back(n);
    int temp = parent[n];
    while(temp!=1){
        result.push_back(temp);
        temp = parent[temp];
    }
    result.push_back(1);


    return result;
}









int main(){


    return 0;
}