#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){
        val=0;
        left=NULL;
        right=NULL;
    }
    TreeNode(int val1){
        val=val1;
        left=nullptr;
        right=nullptr;
    }
    TreeNode(int val1,TreeNode* left1,TreeNode* right1){
        val=val1;
        left=left1;
        right=right1;
    }
};


//floor in a BST->
// we need to find maximum value that is smaller than or equal to the key.
int floorinBST(TreeNode* root,int key){
    int floor=-1;
    TreeNode* temp=root;

    while(temp!=NULL){
        if(temp->val==key){
            floor=temp->val;
            return floor;
        }

        if(key>temp->val){
            floor=temp->val;
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
    }
    return floor;
}       


//ceil in BST->
//we need to find the minium value that is greater than or equal to key.
int ceilinBST(TreeNode* root,int key){
    int ceil=-1;
    TreeNode* temp=root;

    while(temp!=NULL){
        if(temp->val==key){
            ceil=temp->val;
            return ceil;
        }

        if(key<temp->val){
            ceil=temp->val;
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return ceil;
}



int main(){

}