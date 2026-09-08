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


//leetcode 701
//Insert node in BST->
//we try to solve it in a easy way we allways insert at a leaf root.
//as the val given is not present in the binary tree allready.
TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* insert=new TreeNode(val);
    if(root==NULL) return insert;

    TreeNode* temp=root;
    TreeNode* prev=root;

    while(temp!=NULL){
        if(val>temp->val){
            prev=temp;
            temp=temp->right;
        }
        else{
            prev=temp;
            temp=temp->left;
        }
    }
    if(val>prev->val){
        prev->right=insert;
    }
    else{
        prev->left=insert;
    }
    return root;
}


//delete a node in BST->
//leetcode 450
TreeNode* deleteNode(TreeNode* root, int key) {
    //my solution-> I am trying to move to the node where the val is equal to key
    //then i connect the prev to the left of the node if it exits.
    //if node->left does not exitst then i connect the prev to right.
    // when i connect the prev->left then i connect the left------>node->right 
    //so that the node gets removed 
    //i move the node->right to---> left->right.
    //we can even do the reverse like attach the left subtree to right.
    if(root==NULL) return root;
    TreeNode* node=root;
    TreeNode* prev=root;
    while(node!=NULL){
        if(node->val==key){
            if(node->left){
                if(root==node){
                    root=node->left;
                }
                else{
                    if(prev->val<node->val){
                        prev->right=node->left;
                    }
                    else{prev->left=node->left;}
                }
                TreeNode* lefty=node->left;
                while(lefty->right!=NULL){
                    lefty=lefty->right;
                }
                lefty->right=node->right;
            }
            else{
                if(root==node){
                    root=node->right;
                }
                else{
                    if(prev->val<node->val){
                        prev->right=node->right;
                    }
                    else{
                        prev->left=node->right;
                    }
                }
            }
        }
        if(node->val>key){
            prev=node;
            node=node->left;
        }
        else{
            prev=node;
            node=node->right;
        }
    }
    return root;
}


//leetcode 230 --> different appoarch must see.IMP..
int cnt=0;
int Inorder(TreeNode* node,int k){
    if(node==NULL) return -1;

    int lefty=Inorder(node->left,k);
    if(lefty!=-1) return lefty;

    cnt++;
         
    if(cnt==k){
        return node->val;
    }

    return Inorder(node->right,k);

}
int kthSmallest(TreeNode* root, int k) {
    return Inorder(root,k);
    //optimal->we use inorder with a counter we don't use a array to store the nodes.
    //as counter reaches k we return the answer.
    //inorder ->left root right.


    //better -> we use Inorder traversal and store in array . inorder will allways give sorted array.
    // so using inorder traversal we avoid extra nlogn to sort.


    //brute force-> we make a array and store all the elements in it.
    //then we sort the array  and return the k th smallest element.
        
}


//leetcode 98 
//Validate Binary Search Tree->
bool solve(TreeNode* node,long mini,long maxi){
    if(node==NULL) return true;
    if(node->val<=mini){
        return false;
    }
    if(node->val>=maxi){
        return false;
    }
        
    //going left only change the maxi
    bool lefty=solve(node->left,mini,node->val);

    //going right only change the mini
    bool righty=solve(node->right,node->val,maxi);

    return lefty && righty;
}
bool isValidBST(TreeNode* root) {
    if(root==NULL) return true;
    return solve(root,LONG_MIN,LONG_MAX);
}



int main(){

}