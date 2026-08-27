#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//leetcode 104
int recursion(TreeNode* node){
    if(node==NULL){
        return 0;
    }
    return 1+max(recursion(node->left),recursion(node->right));
}
int maxDepth(TreeNode* root) {
    //recursive
    return recursion(root);
    // //Level Order traversal-->
    // queue<TreeNode*> que;
    // que.push(root);
    // if(root==nullptr) return 0;
    // int cnt=0;
    // while(!que.empty()){
    //     cnt++;
    //     int size=que.size();
    //     for(int i=0;i<size;i++){
    //         TreeNode* node=que.front();
    //         que.pop();
    //         if(node->left!=nullptr){
    //             que.push(node->left);
    //         }
    //         if(node->right!=nullptr){
    //             que.push(node->right);
    //         }
    //     }
    // }
    // return cnt;
}


//leetcode 110
int  check(TreeNode* node){
    if(node==nullptr) return 0;
    int lh=check(node->left);
    int rh=check(node->right);
    
    if(lh==-1 ||rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    return 1+max(lh,rh);
}
bool isBalanced(TreeNode* root){
    if(check(root)==-1) return false;
    return true;
}


//leetcode 543
int recursion2(TreeNode* node,int &maxi){
    if(node==NULL) {
        return 0;
    }
    
    int lh=recursion2(node->left,maxi);
    int rh=recursion2(node->right,maxi);

    maxi=max(maxi,lh+rh);

    return 1+max(lh,rh);
    
}
int diameterOfBinaryTree(TreeNode* root) {
    //diameter ia longest path between 2 nodes.
    //this path does not need to pass via root.
    
    if(root==nullptr) return 0;
    int maxi=0;
    recursion2(root,maxi);
     
    return maxi;
}


//leetcode 124
int maxpath=INT_MIN;
int recursion3(TreeNode* node){
    if(node==NULL) {
        return 0;
    }

    int leftsum=max(0,recursion3(node->left));
    int rightsum=max(0,recursion3(node->right));

    //Path passing through current node
    int currentpath=node->val+leftsum+rightsum;
    maxpath=max(maxpath,currentpath);

    return node->val+max(leftsum,rightsum);
}
int maxPathSum(TreeNode* root) {
    int ans=recursion3(root);
    maxpath=max(maxpath,ans);
    return maxpath;
}


//leetcode 100
bool recursion4(TreeNode *p,TreeNode* q){
    if(p==NULL && q==NULL) return true;
    if(q==NULL) return false;
    if(p==NULL) return false;

    if(p->val!=q->val) return false;

    bool left=recursion4(p->left,q->left);
    bool right=recursion4(p->right,q->right);

    return left && right;
}
bool isSameTree(TreeNode* p, TreeNode* q) {
    return recursion4(p,q);


    //brute force ->
    //find the preorder or inorder or postorder traversal for both tree
    //then compare the both array and return according to array.
}


//leetcode 103
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(root==NULL) return result;
    queue<TreeNode*> que;
    que.push(root);
    int start=0;
    while(!que.empty()){
        int size=que.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            TreeNode* top=que.front();
            que.pop();
            level.push_back(top->val);
            
            if(top->left!=nullptr){
                que.push(top->left);
            }
            if(top->right!=nullptr){
                que.push(top->right);
            }
        }
        if(start==0){
            start=start^1;
            result.push_back(level);
        }
        else{
            //more optimal will be not using reverse and adding the numbers in the vector level in reverse manner.
            start=start^1;
            reverse(level.begin(),level.end());
            result.push_back(level);
        }
    }
    return result;
}


//leetcode premium
//Boundry traversal--> need to return all the boundry elements in anticlock-wise direction.
//Left boundry excluding leaf -> go as left as possible and if not go right and avoid root node.
//leaf nodes -> need to perform Inorder traversal 
//Right Boundry excluding leaf in reverse -> use stack to store this as we need in reverse. 
bool isleaf(TreeNode* node){
    if(node==NULL) return false;
    if(node->left==NULL && node->right==NULL) return true;
    return false;
}
void addleft(TreeNode* root,vector<int>&result){
    TreeNode* cur=root->left;
    while(cur){
        if(!isleaf(cur)) result.push_back(cur->val);
        if(cur->left) cur=cur->left;
        else cur=cur->right;
    }
}
void addright(TreeNode* root,vector<int>&result){
    TreeNode* cur=root->right;
    vector<int> tmp;
    while(cur){
        if(!isleaf(cur)) tmp.push_back(cur->val);
        if(cur->right) cur=cur->right;
        else cur=cur->left;
    }
    for(int i=tmp.size()-1;i>=0;i--){
        result.push_back(tmp[i]);
    }
}
void addleaf(TreeNode* root,vector<int>& result){
    if(isleaf(root)){
        result.push_back(root->val);
    }
    if(root->left) addleaf(root->left,result);
    if(root->right) addleaf(root->right,result);
}
vector<int> boundrytraversal(TreeNode* root){
    vector<int> result;
    if(root==nullptr) return result;
    if(!isleaf(root)) result.push_back(root->val);
    addleft(root,result);
    addleaf(root,result);
    addright(root,result);
    return result;
}


//leetcode 987 
//very very different data structure is used .
// IMP..
vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> result;
    if(root==NULL) return result;
    queue<tuple<TreeNode*, int, int>> que; //treenode , vertical level, horizontal level.
    que.push({root,0,0});
   
    map<int,map<int,multiset<int>>> mpp; // map to store the results. 
    //we will perform level order traversal.
    while(!que.empty()){
        auto [node, verlevel, horlevel] = que.front();
        que.pop();
        mpp[verlevel][horlevel].insert(node->val);
        if(node->left!=NULL){
            que.push({node->left,verlevel-1,horlevel+1});
        }
        if(node->right!=NULL){
            que.push({node->right,verlevel+1,horlevel+1});
        }
    }
    for(auto it:mpp){ //vertical level
        vector<int> temp;
        for(auto k:it.second){ //horizontal level
            for(int x:k.second){
                temp.push_back(x);
            }
        }
        result.push_back(temp);
    }
    return result;
}


// in this we dont use a recursion code as the recursion logic does not visit the horizontal level wise node first.
// we need to write more logic to maintain the horizontal logic in the code for recursion as well
// this is the iterative logic for the code --> using the logic as the previous problem.
vector<int> TopviewofBT(TreeNode* root){
    vector<int> result;
    if(root==NULL) return result;

    queue<tuple<TreeNode*,int>> que;
    que.push({root,0});
    map<int,int> mpp; //for each vertical level one ans

    while(!que.empty()){
        auto[node,level]=que.front();
        que.pop();
        
        if(mpp.find(level)==mpp.end()){
            mpp[level]=node->val;
        }

        if(node->left!=NULL){
            que.push({node->left,level-1});  
        }
        if(node->right!=NULL){
            que.push({node->right,level+1});
        }

    }

    for(auto it:mpp){
        result.push_back(it.second);
    }

    return result;
}


vector<int> BottomviewBT(TreeNode* root){
    vector<int> result;
    if(root==NULL) return result;

    queue<tuple<TreeNode*,int>> que;
    que.push({root,0});

    map<int,int> mpp;

    while(!que.empty()){
        auto [node,level]=que.front();
        que.pop();

        mpp[level]=node->val;

        if(node->left!=NULL){
            que.push({node->left,level-1});
        }
        if(node->right!=NULL){
            que.push({node->right,level+1});
        }
    }

    for(auto k:mpp){
        result.push_back(k.second);
    }
    return result;
}


//leetcode 199
void solve(TreeNode* node,int level,vector<int> & result){
    if(node==NULL) return;
    if(result.size()==level) result.push_back(node->val);
    solve(node->right,level+1,result);
    solve(node->left,level+1,result);
}
vector<int> RightviewBT(TreeNode* root){

    //DFS logic--> Recursive. (Preorder,Inorder,Postorder)
    // will have lower space complexity than BFS solution.
    // we will implement the reverse preorder traversal --> (root,right,left)
    vector<int> result;
    solve(root,0,result);
    return result;

    // //BFS logic--> Iterative. (levelorder)
    // vector<int> result;
    // if(root==NULL) return result;

    // queue<tuple<TreeNode*,int>> que;
    // que.push({root,0});

    // map<int,int> mpp;

    // while(!que.empty()){
    //     auto [node,level]=que.front();
    //     que.pop();

    //     mpp[level]=node->val;

    //     if(node->left!=NULL){
    //         que.push({node->left,level+1});
    //     }
    //     if(node->right!=NULL){
    //         que.push({node->right,level+1});
    //     }
    // }
    
    // for(auto it:mpp){
    //     result.push_back(it.second);
    // }
    
    // return result;
}


void solve2(TreeNode* node,int level,vector<int> & result){
    if(node==NULL) return;
    if(result.size()==level) result.push_back(node->val);
    solve2(node->left,level+1,result);
    solve2(node->right,level+1,result);
}
vector<int> LeftviewBT(TreeNode* root){
    //DFS-->
    vector<int> result;
    solve2(root,0,result);
    return result;
    
    // //BFS-->
    // vector<int> result;
    // if(root==NULL) return result;

    // queue<tuple<TreeNode*,int>> que;
    // que.push({root,0});

    // map<int,int> mpp;

    // while(!que.empty()){
    //     auto [node,level]=que.front();
    //     que.pop();

    //     mpp[level]=node->val;

    //     if(node->right!=NULL){
    //         que.push({node->right,level+1});
    //     }

    //     if(node->left!=NULL){
    //         que.push({node->left,level+1});
    //     }
    // }
    
    // for(auto it:mpp){
    //     result.push_back(it.second);
    // }
    
    // return result;

}


int main() {

    /*
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
              /
             8
    */

    // Creating a single tree
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    root->left->right->left = new TreeNode(8);


    // =====================================================
    // Maximum Depth - Leetcode 104
    // =====================================================

    cout << "Maximum Depth: "
         << maxDepth(root) << endl;


    // =====================================================
    // Balanced Binary Tree - Leetcode 110
    // =====================================================

    cout << "Is Balanced: "
         << (isBalanced(root) ? "Yes" : "No") << endl;


    // =====================================================
    // Diameter - Leetcode 543
    // =====================================================

    cout << "Diameter: "
         << diameterOfBinaryTree(root) << endl;


    // =====================================================
    // Maximum Path Sum - Leetcode 124
    // =====================================================

    maxpath = INT_MIN;

    cout << "Maximum Path Sum: "
         << maxPathSum(root) << endl;


    // =====================================================
    // Same Tree - Leetcode 100
    // =====================================================

    /*
        Comparing root with itself just to test the function.
    */

    cout << "Is Same Tree: "
         << (isSameTree(root, root) ? "Yes" : "No") << endl;


    // =====================================================
    // Zigzag Level Order - Leetcode 103
    // =====================================================

    vector<vector<int>> zigzag = zigzagLevelOrder(root);
    cout << "Zigzag Traversal: ";
    for(auto level : zigzag) {
        cout << "[ ";
        for(int x : level) {
            cout << x << " ";
        }
        cout << "] ";
    }
    cout << endl;


    // =====================================================
    // Boundary Traversal
    // =====================================================

    vector<int> boundary = boundrytraversal(root);
    cout << "Boundary Traversal: ";
    for(int x : boundary) {
        cout << x << " ";
    }
    cout << endl;


    // =====================================================
    // Vertical Traversal - Leetcode 987
    // =====================================================

    vector<vector<int>> vertical = verticalTraversal(root);
    cout << "Vertical Traversal: ";
    for(auto level : vertical) {
        cout << "[ ";
        for(int x : level) {
            cout << x << " ";
        }
        cout << "] ";
    }
    cout << endl;


    // =====================================================
    // Top View
    // =====================================================

    vector<int> top = TopviewofBT(root);
    cout << "Top View: ";
    for(int x : top) {
        cout << x << " ";
    }
    cout << endl;


    // =====================================================
    // Bottom view
    // =====================================================

    vector<int> bottom = BottomviewBT(root);
    cout << "Bottom View: ";
    for(int x : bottom) {
        cout << x << " ";
    }
    cout << endl;

    // =====================================================
    // Right view
    // =====================================================
    
    vector<int> right = RightviewBT(root);
    cout << "Right View: ";
    for(int x : right) {
        cout << x << " ";
    }
    cout << endl;


    // =====================================================
    // Left view
    // =====================================================
    
    vector<int> left = LeftviewBT(root);
    cout << "Left View: ";
    for(int x : left) {
        cout << x << " ";
    }
    cout << endl;




    return 0;
}