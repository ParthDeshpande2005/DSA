#include<bits/stdc++.h>
using namespace std;





//leetcode 1319...IMP...Disjoint set question.
//very interestin que.
//we need to find the number of extra edges as well as the number of components(disjoint set).
//we will use disjoint set datastructure
//we will find the extra edges by checking when the ultimate parent is same.
//we will find the number of components when the node is pointing to itself in the parent array.
//at the end we know we will need componts-1 extra edges to solve. which will be the minimum num of edges.
//very diff appoarch...
vector<int> parent;
vector<int> elements;
int extra;
int findUpar(int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node] = findUpar(parent[node]);
}
void unionbysize(int u,int v){
    int par_u = findUpar(u);
    int par_v = findUpar(v);

    if(par_u == par_v){
        extra++;
        return;
    }

    if(elements[par_u] > elements[par_v]){
        parent[par_v] = par_u;
        elements[par_u] += elements[par_v];
    }

    else{
        parent[par_u] = par_v;
        elements[par_v] += elements[par_u];
    }
}
int makeConnected(int n, vector<vector<int>>& connections) {
    elements.resize(n,1);
    parent.resize(n);
    extra = 0;
    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    int m = connections.size();
    for(int i = 0;i < m;i++){
        int u = connections[i][0];
        int v = connections[i][1];
        unionbysize(u,v);
    }

    int component=0;
    for(int i=0;i<n;i++){
        if(parent[i] == i){
            component++;
        }
    }

    int ans = component-1;
    if(extra >= ans){
        return ans;
    }
    return -1;
}








int main(){


    return 0;
}