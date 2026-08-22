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




int main() {

    /*
            Main Tree
                1
               / \
              2   3
             / \
            4   5

        Used for:
        - Maximum Depth
        - Balanced Binary Tree
        - Diameter
        - Maximum Path Sum
        - Zigzag Level Order
        - Boundary Traversal
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);


    cout << "========== Main Tree ==========" << endl;

    cout << "Maximum Depth: "
         << maxDepth(root) << endl;

    cout << "Is Balanced: "
         << (isBalanced(root) ? "Yes" : "No") << endl;

    cout << "Diameter: "
         << diameterOfBinaryTree(root) << endl;

    cout << "Maximum Path Sum: "
         << maxPathSum(root) << endl;


    // Zigzag Level Order
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


    // Boundary Traversal
    vector<int> boundary = boundrytraversal(root);

    cout << "Boundary Traversal: ";

    for(int x : boundary) {
        cout << x << " ";
    }

    cout << endl;


    /*
            Same Tree Test

            Tree 2 is structurally and
            value-wise identical to root.

                1
               / \
              2   3
             / \
            4   5
    */

    TreeNode* sameTree = new TreeNode(1);
    sameTree->left = new TreeNode(2);
    sameTree->right = new TreeNode(3);
    sameTree->left->left = new TreeNode(4);
    sameTree->left->right = new TreeNode(5);

    cout << "\n========== Same Tree Test ==========" << endl;

    cout << "Root and SameTree: "
         << (isSameTree(root, sameTree) ? "Yes" : "No")
         << endl;


    /*
            Different Tree

                1
               / \
              2   3
             /
            4

    */

    TreeNode* differentTree = new TreeNode(1);
    differentTree->left = new TreeNode(2);
    differentTree->right = new TreeNode(3);
    differentTree->left->left = new TreeNode(4);

    cout << "Root and DifferentTree: "
         << (isSameTree(root, differentTree) ? "Yes" : "No")
         << endl;


    /*
            Unbalanced Tree

                1
               /
              2
             /
            3
           /
          4

        Used to test:
        - Maximum Depth
        - Balanced Binary Tree
        - Diameter
        - Maximum Path Sum
        - Boundary Traversal
    */

    TreeNode* unbalanced = new TreeNode(1);
    unbalanced->left = new TreeNode(2);
    unbalanced->left->left = new TreeNode(3);
    unbalanced->left->left->left = new TreeNode(4);

    cout << "\n========== Unbalanced Tree ==========" << endl;

    cout << "Maximum Depth: "
         << maxDepth(unbalanced) << endl;

    cout << "Is Balanced: "
         << (isBalanced(unbalanced) ? "Yes" : "No") << endl;

    cout << "Diameter: "
         << diameterOfBinaryTree(unbalanced) << endl;

    cout << "Maximum Path Sum: "
         << maxPathSum(unbalanced) << endl;

    vector<int> unbalancedBoundary =
        boundrytraversal(unbalanced);

    cout << "Boundary Traversal: ";

    for(int x : unbalancedBoundary) {
        cout << x << " ";
    }

    cout << endl;


    /*
            Negative Value Tree

                -10
                /  \
               9    20
                   /  \
                  15   7

        Used specifically to test
        Maximum Path Sum with negative values.

        Answer = 15 + 20 + 7 = 42
    */

    TreeNode* negativeTree = new TreeNode(-10);
    negativeTree->left = new TreeNode(9);
    negativeTree->right = new TreeNode(20);
    negativeTree->right->left = new TreeNode(15);
    negativeTree->right->right = new TreeNode(7);

    cout << "\n========== Negative Value Tree ==========" << endl;

    cout << "Maximum Path Sum: "
         << maxPathSum(negativeTree) << endl;


    /*
            Empty Tree
    */

    TreeNode* emptyTree = nullptr;

    cout << "\n========== Empty Tree ==========" << endl;

    cout << "Maximum Depth: "
         << maxDepth(emptyTree) << endl;

    cout << "Is Balanced: "
         << (isBalanced(emptyTree) ? "Yes" : "No") << endl;

    cout << "Diameter: "
         << diameterOfBinaryTree(emptyTree) << endl;

    cout << "Maximum Path Sum: "
         << maxPathSum(emptyTree) << endl;

    cout << "Boundary Traversal: ";

    vector<int> emptyBoundary =
        boundrytraversal(emptyTree);

    for(int x : emptyBoundary) {
        cout << x << " ";
    }

    cout << endl;


    return 0;
}