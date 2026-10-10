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



//leetcode 1091
//i was first using dijkstra but here weight is constant 1. so there is no need for the priority queue. as the queue will be allready sorted.
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();

    // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq; 
    // --> not using pq

    queue<pair<int,pair<int,int>>> que;

    if(grid[0][0]==1) return -1;

    que.push({1,{0,0}}); //we store dist,{i,j} in the priority queue.

    vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};

    vector<vector<int>> distance(n,vector(n,-1));
    distance[0][0]=1;

    while(!que.empty()){
        auto cur = que.front();
        que.pop();

        int dist = cur.first;
        int i = cur.second.first;
        int j = cur.second.second;

        for(auto dir : directions){
            int newi = dir.first+i;
            int newj = dir.second+j;

            if(newi>=n || newj>=n || newi<0 || newj<0){
                continue;
            }

            if(grid[newi][newj]==1){
                continue;
            }

            if(distance[newi][newj]==-1){
                distance[newi][newj] = dist+1;
                que.push({dist+1,{newi,newj}});
            }
            else if(distance[newi][newj] > dist+1){
                distance[newi][newj] = dist+1;
                que.push({dist+1,{newi,newj}});
            }
        }
    }
    return distance[n-1][n-1];
}



//leetcode 1631
//lets use dijkstra.
int minimumEffortPath(vector<vector<int>>& heights) {
        
    int n = heights.size();
    int m = heights[0].size();

    //effort 
    vector<vector<int>> effort(n,vector<int>(m,-1));
    effort[0][0]=0;

    //priority_queue  --> min heap.
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

    pq.push({0,{0,0}});

    //4 directions up,down,rigth,left.
    vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        
    while(!pq.empty()){
        int dist = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;

        if(i == n-1 && j== m-1){
            break;
        }

        pq.pop();

        for(auto dir:directions){
            int newi = i+dir.first;
            int newj = j+dir.second;

            if(newi<0 || newj<0 || newi>=n || newj>=m){
                continue;
            }

            int dist2 = abs(heights[newi][newj] - heights[i][j]);
            int newdist = max(dist , dist2);

            if(effort[newi][newj]==-1 || newdist < effort[newi][newj]){
                effort[newi][newj]=newdist;
                pq.push({newdist,{newi,newj}});
            }
        }
    }

    return effort[n-1][m-1];
}


//leetcode 787
//IMP...
//here we use modified dikstra.
//very different appoarch compared previous dijkstra implementations
//we use the stops int as the first index in out prioriority queue instead of shortes distance.
//we maintain the distace array where we decrease the distance accordingly.
//we need only queue and not pq as the stop constantly increase by 1 only.
//we can go till max k+1 stop as the distance being the k+1th stop.
//we don't include the stops greater than k+1 in our queue.
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dstination, int k) {
        
    int size = flights.size();

    //first lets create the adj list
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<size;i++){
        adj[flights[i][0]].push_back({flights[i][1],flights[i][2]}); //we store the next and the distance to reach it.
    }

    //queue
    queue<tuple<int,int,int>> que; // stops,node,dist
    que.push({0,src,0});

    //distance vector
    vector<int> dist(n,-1);
    dist[src]=0;


    while(!que.empty()){
        auto cur = que.front();
        int stops = get<0>(cur);
        int node = get<1>(cur);
        int distance = get<2>(cur);

        que.pop();

        for(auto it:adj[node]){
            int nextdist = it.second;
            int next = it.first;
                
            int newdist = nextdist + distance;

            if(stops > k){ //we dont the flite path that take more than k stops.
                continue;
            }

            if(dist[next] ==  -1 || dist[next] > newdist){
                dist[next] = newdist;
                que.push({stops+1,next,newdist});
            }
        }
    }

    return dist[dstination];
}








int main(){


    return 0;
}