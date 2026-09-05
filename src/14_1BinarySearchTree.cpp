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
 
//Binary Search Tree property.
// left child < parent < right child
// where leftsubtree is a BST and right subtree is also a BST.
//          8
//         / \
//        3   10
//       / \    \
//      1   6    14
//         / \   /
//        4   7 13

//everything on right of node should be greater and everything left of node should be smaller.

//normally duplicates are not allowed.
//but we can implement duplicates using count or even adding one more node.

//in most case the height of BST is logN.
//we try to minimize the maxheight of the tree in BST.


//Search in a Binary Search Tree->
//leetcode 700
TreeNode* recursivesearchBST(TreeNode* node,int val){
    if(node==NULL){
        return NULL;
    }
    if(node->val==val){
        return node;
    }
    if(val>node->val){
        return recursivesearchBST(node->right,val);
    }
    else{
        return recursivesearchBST(node->left,val);
    }
    
}
TreeNode* searchBST(TreeNode* root, int val) {
    return recursivesearchBST(root,val);

    // //Iterative-->
    // while(root!=NULL && root->val!=val){
    //     root=val<root->val? root->left:root->right;
    // }
    // return root;
}


//find MIN/Max in BST-->
vector<int> minmaxBST(TreeNode* root){
    if(root==NULL) return {};

    TreeNode* mini=root;
    TreeNode* maxi=root;

    while(mini->left!=NULL){
        mini=mini->left;
    }

    while(maxi->right!=NULL){
        maxi=maxi->right;
    }

    return {mini->val,maxi->val};
}


int main(){

}