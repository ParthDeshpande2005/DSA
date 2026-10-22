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




//leetcode 721 IMP.....
//disjoint set solution but allong with it we use the map to store the string and there parent.
//we identify parent node using its index and not the string 
//the use of parent node is very different.
class disjointset{
public:
    vector<int> parent;
    vector<int> size;
    disjointset(int n){
        size.resize(n,1);
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findUpar(int node){ //finding ultimate parent of node.
        if(parent[node]==node){
            return node;
        }

        return parent[node] =  findUpar(parent[node]);
    }

    void unionbysize(int u,int v){
        int ultu = findUpar(u);
        int ultv = findUpar(v);

        int usize = size[ultu];
        int vsize = size[ultv];

        if(usize < vsize){
            parent[ultu] = ultv;
            size[ultv] += size[ultu];
        }

        else{
            parent[ultv] = ultu;
            size[ultu] += (1LL * size[ultv]) % (1000000007LL);
        }
    }
};
class AccountsSolution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n =  accounts.size();

        disjointset ds(n);

        unordered_map<string,int> mapmailnode;

        for(int i=0;i<n;i++){
            int m = accounts[i].size();
            for(int j=1;j<m;j++){
                if(mapmailnode.find(accounts[i][j])==mapmailnode.end()){ 
                    mapmailnode[accounts[i][j]] = i;
                }
                else{
                    //meaning the user allready exists.
                    //so we will joint the two nodes.
                    int v = mapmailnode[accounts[i][j]];
                    ds.unionbysize(i,v);
                }
            }
        }

        vector<vector<string>> mergedmail(n);
        for(auto it: mapmailnode){
            int cur = it.second;
            int node = ds.findUpar(cur);
            mergedmail[node].push_back(it.first);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedmail[i].empty()){
                continue;
            }

            string name = accounts[i][0];

            vector<string> temp = mergedmail[i];
            sort(temp.begin(),temp.end());

            vector<string> cur_result;
            cur_result.push_back(name);
            for(auto mail:temp){
                cur_result.push_back(mail);
            }

            ans.push_back(cur_result);
        }

        return ans;
    }
};



//we can optimize this solution more by keeping the count as int and updating it according the new find coloumn.
//striver takeUforward 381.Number of island 2.
//we need to find the number of island at each step as we get new island from vector A.
//we will use disjoint set to solve this probelem.
//i am thinking that as i get a new element and if the adjacent element of it is allready filled then we 
//will make is new node as the ultimate parent of the node.
//i will use the parnet arrray very differently like the chess board marking .
//we can also use the parent vector of pair but we will not do that as there is no thrill in that.
//this is my solution.
class disjointislands2{
public:
    //here we are not using size as we will allways make the new node as our ultimate parent.
    vector<int> parent;

    disjointislands2(int n,int m){
        int matrixsize = n*m;

        parent.resize(matrixsize,0);
        for(int i=0;i<matrixsize;i++){
            parent[i] = i;
        }
    }

    int findUpar(int node){
        if(parent[node]==node){
            return node;
        }

        return parent[node] = findUpar(parent[node]);
    }

    void unionbysize(int newnode,int prevnode){
        int ultprev = findUpar(prevnode);
        int ultnew = findUpar(newnode);
    
        parent[ultprev] = ultnew;

    }
};
class IslandsSolution{
public:
vector<int> numOfIslands(int n, int m, vector<vector<int>> &A){
        int matrix = n*m;
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<int> result;
        disjointislands2 ds(n,m);

        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        
        int count =0;

        for(int k =0; k < A.size();k++){
            int i = A[k][0];
            int j = A[k][1];
            if(visited[i][j] == 1){
                result.push_back(count);
                continue;
            }

            int newnode = m*i + j; //this is the logic i used in the chess project;
            visited[i][j] = 1;

            for(auto dir: directions){
                //using prev as this are allready islands.
                int previ = i+dir.first;
                int prevj = j+dir.second;

                if(previ<0 || prevj<0 || previ>=n || prevj>=m){
                    continue;
                }

                if(visited[previ][prevj] == 1){
                    int prevnode = m*previ + prevj;
                    ds.unionbysize(newnode,prevnode);
                }
            }


            count =0;
            for(int row=0;row<n;row++){
                for(int col=0;col<m;col++){
                    if(visited[row][col]==0){
                        continue;
                    }
                    int mat = row*m + col;
                    if(ds.findUpar(mat)==mat){
                        count++;
                    }
                }
            }
            result.push_back(count);
        }
        return result;
    }
};




int main() {
    // LeetCode 1319: Number of Operations to Make Network Connected
    int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {0, 2}, {1, 2}
    };

    cout << "1319 - Make Connected: "
         << makeConnected(n, connections) << "\n";

    // LeetCode 721: Accounts Merge
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };

    AccountsSolution accSol;
    vector<vector<string>> merged = accSol.accountsMerge(accounts);

    cout << "\n721 - Accounts Merge:\n";
    for (auto &account : merged) {
        for (auto &value : account) {
            cout << value << " ";
        }
        cout << "\n";
    }

    // Striver 381: Number of Islands II
    int rows = 3;
    int cols = 3;

    vector<vector<int>> positions = {
        {0, 0}, {0, 1}, {1, 2}, {2, 1}, {1, 1}
    };

    IslandsSolution islandSol;
    vector<int> islands = islandSol.numOfIslands(rows, cols, positions);

    cout << "\n381 - Number of Islands II:\n";
    for (int count : islands) {
        cout << count << " ";
    }
    cout << "\n";

    return 0;
}