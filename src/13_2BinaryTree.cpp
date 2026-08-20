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


int main() {

    /*
            1
           / \
          2   3
         / \
        4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    
    cout << "Maximum Depth: " << maxDepth(root) << endl;

    cout << "Is Balanced: "<< (isBalanced(root) ? "Yes" : "No") << endl;

    cout << "Diameter: " << diameterOfBinaryTree(root) << endl;


    return 0;
}