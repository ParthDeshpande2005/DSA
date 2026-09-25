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


//leetcode 994
//I am using BFS...as we need level order traversal.
//DFS is not allowed for this que..
int orangesRotting(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
        
    //first we will count the total fresh oranges as well as push the rotton oranges in the queue.
    int fresh=0;
    queue<pair<int,int>> que;
    vector<vector<int>> visited(n,vector(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                fresh++;
            }
            else if(grid[i][j]==2){
                visited[i][j]=1;
                que.push({i,j});
            }
        }
    }

    vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}}; //up,down,right,left

    //I will use BFS->
    int steps=-1;
    while(!que.empty()){
        steps++;
        int cur_size=que.size();

        for(int k=0;k<cur_size;k++){ //we can completely avoid this loop by also storing the number of steps within the queue. we increase the steps while adding in the que...
            pair<int,int> cur=que.front();
            que.pop();

            int i=cur.first;
            int j=cur.second;

            if(grid[i][j]==1){
                fresh--;
            }

            for(auto dire:directions){

                int newi=i+dire[0];
                int newj=j+dire[1];

                if(newi<0 || newj<0 || newi>=n || newj>=m){
                    continue;
                }
                if(grid[newi][newj]==0 ||grid[newi][newj]==2){
                    continue;
                }
                if(visited[newi][newj]==1){
                    continue;
                }
                visited[newi][newj]=1;
                que.push({newi,newj});

            }
        }
    }

    if(fresh>0) return -1;
    if(steps==-1) return 0;
    return steps;
}

//leetcode 733..
//we can use both dfs as well as bfs.
//I have used bfs.
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n=image.size();
    int m=image[0].size();

    vector<vector<int>> visited(n,vector(m,0));

    queue<pair<int,int>> que;
    que.push({sr,sc});
    visited[sr][sc]=1;

    vector<pair<int,int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
    int tempcolour=image[sr][sc];

    while(!que.empty()){
        pair<int,int> cur=que.front();
        que.pop();
        int i=cur.first;
        int j=cur.second;
        image[i][j]=color;

        for(auto dir:directions){
            int newi=i+dir.first;
            int newj=j+dir.second;

            if(newi<0 || newj<0 || newi>=n || newj>=m){
                continue;
            }

            if(visited[newi][newj]==1){
                continue;
            }

            if(image[newi][newj]!=tempcolour){
                continue;
            }

            visited[newi][newj]=1;
            que.push({newi,newj});
        }
    }

    return image;
}


//leetcode 200
//lets use dfs for this problem..
int n,m;
vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
void dfs2(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& visited){
    visited[i][j]=1;

    for(auto dir:directions){
        int newi=i+dir[0];
        int newj=j+dir[1];

        if(newi<0 || newj<0 || newi>=n || newj>=m){
            continue;
        }
        if(visited[newi][newj]==1){
            continue;
        }
        dfs2(newi,newj,grid,visited);
    }
}
int numIslands(vector<vector<char>>& grid) {
    n=grid.size();
    m=grid[0].size();


    // we want all the 1's to get visited hence we will use a visited where all the 0's are allready marked.
    vector<vector<int>> visited(n,vector(m,0));

    // now we will mark all the 0 as visited

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='0'){
                visited[i][j]=1;
            }
        }
    }

    int result=0;

    //now we will implement the dfs->
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==1){
                continue;
            }
            result++;

            dfs2(i,j,grid,visited);
        }
    }

    return result;
}



//leetcode 1020..
int numEnclaves(vector<vector<int>>& grid) {
    //I will use bfs. first i will put all the border elements that are land in the que as well as i need to count the total numbers of 1. so we will make a queue of pair.i will also mark all the zeros as visied.

    int n=grid.size();
    int m=grid[0].size();

    int count=0;
    queue<pair<int,int>> que;
    vector<vector<int>> visited(n,vector(m,0)); 

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                count++;
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    visited[i][j]=1;
                    count--;
                    que.push({i,j});
                }
            }
            else{
                visited[i][j]=1;
            }
        }
    }
        
    vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};

    while(!que.empty()){
        auto cur=que.front();
        que.pop();
        int i=cur.first;
        int j=cur.second;

        for(auto dir:directions){
            int newi=i+dir[0];
            int newj=j+dir[1];

            if(newi>=n || newj>=m || newi<0 || newj<0){
                continue;
            }

            if(visited[newi][newj]==1) continue;

            visited[newi][newj]=1;
            count--;
            que.push({newi,newj});
        }
    }
    return count;
}


//leetcode 542
//different appoarch IMP...

int bfs(int i,int j,vector<vector<int>>& mat){
    queue<vector<int>> que;
    vector<vector<int>> visited(n,vector(m,0));
    visited[i][j]=1;
    que.push({i,j});
    int cnt=0;
    while(!que.empty()){
        cnt++;
        int size=que.size();
        for(int k=0;k<size;k++){
            auto cur=que.front();
            que.pop();
            int i=cur[0];
            int j=cur[1];
            for(auto dir:directions){
                int newi=i+dir[0];
                int newj=j+dir[1];

                if(newi<0 || newj<0 || newi>=n || newj>=m){
                    continue;
                }

                if(visited[newi][newj]==1) continue;

                if(mat[newi][newj]==0){
                    return cnt;
                }

                visited[newi][newj]=1;
                que.push({newi,newj});
            }
        }
    }
    return cnt;
}
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

    //optimal solution from striver..
    // in optimal we start from every zero .and go out form the zero. and find distance for all the non visited elements in the mat.
    n=mat.size();
    m=mat[0].size();

    queue<vector<int>> que;
    vector<vector<int>> visited(n,vector(m,0));
    vector<vector<int>> result(n,vector(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                que.push({i,j,0});
                visited[i][j]=1;
            }
        }
    }

    while(!que.empty()){ //this is optimal way to apply bfs we avoid one extra for loop by maintaing a k variable.
        auto cur=que.front();
        que.pop();
        int i=cur[0];
        int j=cur[1];
        int k=cur[2];
            
        result[i][j]=k;

        for(auto dir: directions){
            int newi=i+dir[0];
            int newj=j+dir[1];

            if(newi<0 || newj<0 || newi>=n|| newj>=m){
                continue;
            }

            if(visited[newi][newj]==1){
                continue;
            }

            visited[newi][newj]=1;
            que.push({newi,newj,k+1});
        }

    }
    return result;



    //bruteforce---> in this I travel all the index and individual check for there distance using bfs
    // n=mat.size();
    // m=mat[0].size();

    // //lets try the brute force first..
    // vector<vector<int>> result(n,vector(m,0));

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(mat[i][j]==0){
    //             continue;
    //         }
    //         else{
    //             //for 1 i will use bfs.. we cant use dfs as we need to travel to all adjacent node at once.
    //             int cur=bfs(i,j,mat);
    //             result[i][j]=cur;
    //         }
    //     }
    // }
    // return result;
}


//leetcode 130
void solve(vector<vector<char>>& board) {
    int n=board.size();
    int m=board[0].size();

    vector<vector<char>> result(n,vector(m,'X'));
    queue<pair<int,int>> que;

    //now just push all the border elements in the queue.
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='X') continue;
            if(i==0 || j==0 || i==n-1 || j==m-1){ //only push the boarder 0.
                result[i][j]='O';
                que.push({i,j});
            }
        }
    }

    vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};

    while(!que.empty()){
        auto cur=que.front();
        que.pop();
        int i=cur.first;
        int j=cur.second;

        for(auto dir:directions){
            int newi=i+dir[0];
            int newj=j+dir[1];

            if(newi<0 || newj<0 || newi>=n || newj>=m) {
                continue;
            }

            if(board[newi][newj]=='X'){
                continue;
            }
            if(result[newi][newj]=='O'){
                continue;
            }

            //we only do O when the board allways have O.
            que.push({newi,newj});
            result[newi][newj]='O';
        }
    }

    board=result;
}


//IMP how we store the distinct insland.
//we store the island in the set of vector of vector.. where vertor is all the cordinate that are in that island.
//we normalize the island before storing them in set.
//we normalize each pair by subtracting the base pair form them base pair is the pair form which we start the dfs.
// in the end we return the size of set.
class Solution
{
public:
    
    int n,m;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    vector<pair<int,int>> dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &visited){
        visited[i][j]=1;

        vector<pair<int,int>> result;
        result.push_back({i,j});

        for(auto d:dir){
            int newi=i+d[0];
            int newj=j+d[1];

            if(newi<0 || newj<0 || newi>=n || newj>=m){
                continue;
            }
            if(visited[newi][newj]==1) continue;

            vector<pair<int,int>> newv=dfs(newi,newj,grid,visited);

            result.reserve(result.size()+newv.size());

            result.insert(result.end(),newv.begin(),newv.end());

        }

        return result;
    }
    int countDistinctIslands(vector<vector<int>> &grid){
        n=grid.size();
        m=grid[0].size();

        set<vector<pair<int,int>>> st;
        queue<pair<int,int>> que;
        vector<vector<int>> visited(n,vector(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){ // I am marking all the 0 as visited.
                    visited[i][j]=1;
                }
                else{
                    que.push({i,j}); // I don't mark 1 as visited i only push them in the queue.
                }
            }
        }

        
        while(!que.empty()){
            auto cur=que.front();
            que.pop();
            int i=cur.first;
            int j=cur.second;

            if(visited[i][j]==1) continue;

            vector<pair<int,int>> temp=dfs(i,j,grid,visited);


            for(auto &a:temp){
                a.first-=i;
                a.second-=j;
            }

            sort(temp.begin(),temp.end());

            st.insert(temp);
        }

        return st.size();
    }
};









int main(){

    

    return 0;
}