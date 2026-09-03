#include <bits/stdc++.h>
using namespace std;



// LeetCode 131 - Palindrome Partitioning
bool isPalindrome131(string s) {
    string temp = s;
    reverse(temp.begin(), temp.end());
    return s == temp;
}
void recursion1(int cur, vector<string> ans, string s, vector<vector<string>> &result) {
    if (cur == s.size()) {
        result.push_back(ans);
        return;
    }

    for (int i = cur; i < s.length(); i++) {
        string sub = s.substr(cur, i - cur + 1);
        if (isPalindrome131(sub)) {
            ans.push_back(sub);
            recursion1(i + 1, ans, s, result);
            ans.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> ans;

    recursion1(0, ans, s, result);

    return result;
}


// LeetCode 79 - Word Search
vector<pair<int, int>> directions = {{1, 0},{0, 1},{-1, 0},{0, -1}};
bool recursion2(pair<int, int> cur, int w,vector<vector<int>> &visited,vector<vector<char>> &board,string word,int row,int col) {
    int i = cur.first;
    int j = cur.second;

    if (w == word.size()) {
        return true;
    }

    if (board[i][j] == word[w]) {
        if (w == word.size() - 1) {
            return true;
        }
        for (auto dir : directions) {
            int ni = i + dir.first;
            int nj = j + dir.second;
            if (ni < 0 || ni >= row || nj < 0 || nj >= col)
                continue;
            if (visited[ni][nj] == 0)
                continue;
            visited[ni][nj] = 0;
            if (recursion2({ni, nj}, w + 1, visited, board, word, row, col))
                return true;
            visited[ni][nj] = -1;
        }
    }
    return false;
}
bool exist(vector<vector<char>> &board, string word) {
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> visited(n, vector<int>(m, -1));
    bool ans = false;
    //finding the first element in board
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == word[0]) {
                visited[i][j] = 0;
                if (recursion2({i, j}, 0, visited, board, word, n, m))
                    ans = true;
                visited[i][j] = -1;
            }
        }
    }
    return ans;
}



// LeetCode 51 - N Queens
bool isSafe51(int row, int col, vector<string> board, int n) {
    int duprow = row;
    int dupcol = col;

    // Upper diagonal
    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    // Lower diagonal
    row = duprow;
    col = dupcol;
    while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    // Left row
    row = duprow;
    col = dupcol;
    while (col >= 0) {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    return true;
}
void solve51(int col,vector<string> &board,vector<vector<string>> &ans,int n) {
    if (col == n) {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++) {
        if (isSafe51(row, col, board, n)) {
            board[row][col] = 'Q';
            solve51(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
        board[i] = s;
    solve51(0, board, ans, n);
    return ans;
}


//the rat start at 0,0--->n-1,n-1. and cant go to same node twice.
//0 is blocked  1 is can go in the maxe matrix.
//we need to return all the possible path in string using direction the rat take.
//ex->"DLRU"-> are directions
//the direction must be added in lexographical order.
//in this problem i will not use bisited array,instead i will set the visited node as 0.
void ratinmaze(pair<int,int> cur,string path,vector<string> &mazepaths,vector<vector<int>> &maze,int n){
    int i=cur.first;
    int j=cur.second;
    if(i==n-1 && j==n-1 && maze[i][j]==1){
        mazepaths.push_back(path);
        return;
    }
    if(maze[i][j]==0) return; //path is blocked

    //down->
    int new_i=i+1;
    int new_j=j;
    if(new_i<n){
        path+='D';
        maze[i][j]=0;
        ratinmaze({new_i,new_j},path,mazepaths,maze,n);
        maze[i][j]=1;
        path.pop_back();
    }

    //Left->
    new_i=i;
    new_j=j-1;
    if(new_j>=0){
        path+='L';
        maze[i][j]=0;
        ratinmaze({new_i,new_j},path,mazepaths,maze,n);
        maze[i][j]=1;
        path.pop_back();
    }

    //right->
    new_i=i;
    new_j=j+1;
    if(new_j<n){
        path+='R';
        maze[i][j]=0;
        ratinmaze({new_i,new_j},path,mazepaths,maze,n);
        maze[i][j]=1;
        path.pop_back();
    }

    //UP->
    new_i=i-1;
    new_j=j;
    if(new_i>=0){
        path+='U';
        maze[i][j]=0;
        ratinmaze({new_i,new_j},path,mazepaths,maze,n);
        maze[i][j]=1;
        path.pop_back();
    }
}


//graph colouring problem->
//m colour problem.
bool ispossible(int cur,int cur_colour,vector<int> &colours,vector<vector<int>> &adj){
    vector<int> search=adj[cur];
    for(int i=0;i<search.size();i++){
        if(colours[search[i]]==cur_colour) return false;
    }
    return true;
}
bool solve(int cur,vector<int> &colours,vector<vector<int>> &adj,int M,int node){
    if(cur==node){
        return true;
    }

    for(int i=1;i<=M;i++){//colours from one to M.
        if(ispossible(cur,i,colours,adj)==false) continue;
        colours[cur]=i;
        if(solve(cur+1,colours,adj,M,node)==true)  return true;
        colours[cur]=0;
    }
    return false;
}



//when using recursion we must use memoization to get ans or time limit gets excited.
//important que for memoization
//leetcode 139
unordered_set<string> st;
//memoization array->
int t[301];
bool recursion(int cur,string s,int n){
    if(cur>=n){
        return true;
    }
    //memoization->
    if(t[cur]!=-1){
        return t[cur];
    }
    if(st.find(s.substr(cur,n-cur+1))!=st.end()){
        return true;
    }
    for(int i=cur;i<n;i++){
        string sub=s.substr(cur,i-cur+1);
        if(st.find(sub)!=st.end()){
            if(recursion(i+1,s,n)==true) return t[cur]=true;
        }
    }
    return t[cur]=false;
}
bool wordBreak(string s, vector<string>& wordDict) {
    int n=s.size();
    memset(t,-1,sizeof(t));
    for(string &word: wordDict){
        st.insert(word);
    }
    return recursion(0,s,n);
}



bool isvalid(vector<vector<char>>&board,int row,int col,char c){
    for(int i=0;i<9;i++){
        if(board[i][col]==c) return false;
    
        if(board[row][i]==c) return false;
        //IMP-> condition for checking in 3x3 matrix
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
    }
    return true;
}
bool solve37(vector<vector<char>> & board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(char k='1';k<='9';k++){
                    if(isvalid(board,i,j,k)==true){
                        board[i][j]=k;
                        if(solve37(board)==true){
                            return true;
                        }
                        else board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board) {
    solve37(board);
}



void dfs(int index,string path,long long value,long long lastoperand,string &num,int target,vector<string>&ans){
    if(index==num.size()){
        if(value==target){
            ans.push_back(path);
        }
        return;
    }

    long long current=0;
    for(int i=index;i<num.size();i++){
        if(i>index && num[index]=='0') break;

        current=current*10+(num[i]-'0');

        string curstr=num.substr(index,i-index+1);

        //first num->
        if(index==0){
            dfs(i+1,curstr,current,current,num,target,ans);
        }

        else{

            // +
            dfs(i+1,path+"+"+curstr,value+current,current,num,target,ans);

            // -
            dfs(i+1,path+"-"+curstr,value-current,-current,num,target,ans);

            // * 
            long long newval=value-lastoperand+(current*lastoperand);//as we need to multiply now we create new val.
            //current*lastoperand -> multiplication that need to be done first.
            //value-lastoperand -> because we remove lastoperand from the value.
            long long newlast=current*lastoperand; //as me need to all ways consider * together.
            dfs(i+1,path+"*"+curstr,newval,newlast,num,target,ans);
        }
    }
}
vector<string> addOperators(string num, int target) {
    vector<string> ans;

    dfs(0,"",0,0,num,target,ans);

    return ans;
}

int main() {


    string s = "aab";
    vector<vector<string>> partitions = partition(s);
    cout << "Palindrome Partitions:\n";
    for (auto &v : partitions) {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
    cout << endl;




    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    cout << "Word Search: ";
    cout << (exist(board, word) ? "True" : "False") << endl;
    cout << endl;

    
   
    int n = 4;
    vector<vector<string>> queens = solveNQueens(n);
    cout << "N-Queens Solutions:\n";
    for (auto &board : queens) {
        for (auto &row : board)
            cout << row << endl;
        cout << endl;
    }
    


    vector<vector<int>> maze={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> mazepaths;
    int n1=maze.size();
    ratinmaze({0,0},"",mazepaths,maze,n1);
    for(auto it:mazepaths){
        cout<<it<<endl;
    }
    cout<<endl;



    int node=4;
    int M=3;  //number of colour;
    int edge=5;
    vector<vector<int>> adj={{1,2,3},{0,2},{0,1,3},{0,2}};
    //     0---1
    //     | \ |
    //     3---2
    //the graph looks like this.
    vector<int> colours(node,0);//will store colours according to the element.
    if(solve(0,colours,adj,M,node)==true){
        cout<<"the graph is possible."<<endl;
    }
    else{
        cout<<"The colours are less"<<endl;
    }
    cout<<endl;



    string str1 = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << wordBreak(str1, wordDict)<<endl;//1 means true in cpp.and  0 means false.
    cout<<endl;


     vector<vector<char>> board3 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    solveSudoku(board3);
    cout << "Solved Sudoku:\n";
    for (auto &row : board3) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << "\n";
    }
    cout<<endl;


    string num = "123";
    int target = 6;
    vector<string> ans = addOperators(num, target);
    cout << "Expressions that evaluate to " << target << ":\n";
    for (string s : ans) {
        cout << s << endl;
    }




    return 0;

}