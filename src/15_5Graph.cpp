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




int main(){


    return 0;
}