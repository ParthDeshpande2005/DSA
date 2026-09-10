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
        left=NULL;
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
//IMP->
//we can even find kth largest->
//we need to find total elements n.
//then use kth smallest for n-k. to get kth largest.


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


//leetcode 235
//Lowest Common Ancestor of a Binary Search Tree->
TreeNode* lca(TreeNode* node,TreeNode* p,TreeNode* q,int mini,int maxi){
    if(node==NULL){
        return NULL;
    }

    if(node->val>=mini && node->val<=maxi){
        return node;
    }

    if(node->val>maxi){
        return lca(node->left,p,q,mini,maxi);
    }

    return lca(node->right,p,q,mini,maxi);

}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int mini=min(p->val,q->val);
    int maxi=max(p->val,q->val);

    return lca(root,p,q,mini,maxi);
}


//leetcode 1008->
//my solution is createBST-> TC->O(n log n)
TreeNode* createBST(int i,int j,vector<int>& preorder){
    if(i>j){
        return NULL;
    }

    TreeNode* parent=new TreeNode(preorder[i]);

    //we will use binary search to find the index greater than and less than current.
    int cur=preorder[i];
    int low=i+1;
    int high=j;
    while(low<=high){
        int mid=(low+high)/2;

        if(preorder[mid]>cur){
            high=mid-1;
        }

        else{
            low=mid+1;
        }
    }
    int x=high;

    parent->left=createBST(i+1,x,preorder);

    parent->right=createBST(x+1,j,preorder);

    return parent;
}
TreeNode* build(int &cur,int bound,vector<int>& preorder){
    if(cur==preorder.size() || preorder[cur]>bound) return NULL;

    TreeNode* root=new TreeNode(preorder[cur]);
    cur++;

    root->left=build(cur,root->val,preorder);

    root->right=build(cur,bound,preorder);
        
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
   //optimal-> O(N)
    int i=0;
    return build(i,INT_MAX,preorder); //->here we are only considering upper bound as we travel complete left tree first hence there is no need of lower bound.

    // //better 1->  tc->O(N log N)
    // //my solution->
    // int n=preorder.size();
    // TreeNode* root=createBST(0,n-1,preorder);

    // return root;


    //better 2->  tc->O(N log N)+O(N)   sc->O(N)
    //striver better->
    // sort the preorder .sorting will give us inorder then use preorder and inorder to make a tree.
}


//Successor of a node in BST->
int result;
void successor_recursion(TreeNode* node,int key){
    if(node==NULL){
        return;
    }

    if(node->val > key){
        result=node->val;
        successor_recursion(node->left,key);
    }

    else{
        successor_recursion(node->right,key);
    }
}
int successor(TreeNode* root,int key){
    result=-1;

    successor_recursion(root,key);
    
    return result;
}


//Predecessor of a node in BST->
TreeNode* predecessor(TreeNode* root,TreeNode* key){
    TreeNode* pre=NULL;

    while(root!=NULL){
        if(root->val<key->val){
            pre=root;
            root=root->right;
        }
        else{
            root=root->left;
        }
    }

    return pre;
}


//leetcode 173->
//using stack to store the node . 
//at a particular time at max we are using O(h) space complexity. where h is the hight of the tree.
//and next() and hasnext() is O(1) time complexity.
class BSTIterator {
public:
    stack<TreeNode*> st;
    void pushall(TreeNode* node){
        while(node!=NULL){
            st.push(node);
            node=node->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
        if(st.empty()) return -1;
        TreeNode* cur=st.top();
        st.pop();

        pushall(cur->right);

        return cur->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};




int main(){

}