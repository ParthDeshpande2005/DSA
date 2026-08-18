#include<bits/stdc++.h>
using namespace std;

//Binary Tree --> hierarchical data structure..
//IMP terms-->
// Root, Children, Leaf, Subtree, ancestors

//Full Binary Tree-> either has 0 or 2 children

//Complete Binary Tree-> all levels are completely filled except last level.
//                    -> the last level has all nodes as lefty as possible

//Perfect Binary Tree-> all leaf nodes are at same level.

//Balanced Binary Tree-> height of tree at max log(N)l.

//Deqenerate Binary Tree-> every node has single child node 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//Preorder/Inorder/Postorder Traversal in one traversal..
//TC->O(3*N)  SC->O(4*N)
void PreInPostTraversal(TreeNode* root,vector<int>& preorder,vector<int>& inorder,vector<int>& postorder){
    //we will use stack
    //we store TreeNode and num in stack
    stack<pair<TreeNode*,int>> st;
    st.push({root,1});
    if(root==NULL) return ;
    while(!st.empty()){
        auto it=st.top();
        st.pop();

        //this is part of preorder
        //increment 1 to 2
        //push the left side of the tree
        if(it.second==1){
            preorder.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }
        }

        //this is part for Inorder
        //increment 2 to 3
        //push right
        else if(it.second==2){
            inorder.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first->right!=NULL){
                st.push({it.first->right,1});
            }
        }

        //dont push it again 
        else{
            postorder.push_back(it.first->val);
        }
    }
}


//Preorder Traversal --> Root Left Right
//leetcode 144 check this on leetcode directly not constructing a tree in int main.
//recursive code--> 
void preorder(TreeNode* cur,vector<int>&result){
    if(cur==NULL) return ;

    result.push_back(cur->val);

    //left child
    preorder(cur->left,result);

    //right child
    preorder(cur->right,result);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    preorder(root,result);

    return result;


    // //Iterative--> using stack..
    // vector<int> result;
    // if(root==nullptr) return result;
    // stack<TreeNode*> st;
    // st.push(root);
    // while(!st.empty()){
    //     TreeNode* top=st.top();
    //     st.pop();
    //     if(top->right!=nullptr){
    //         st.push(top->right);
    //     }
    //     if(top->left!=nullptr){
    //         st.push(top->left);
    //     }
    //     result.push_back(top->val);
    // }
    // return result;

}



//Inorder Traversal --> Left Root Right
//leetcode 94 again not writing a int main for this..
void inorder(TreeNode* cur,vector<int>&result){
    if(cur==NULL){
        return ;
    }
    inorder(cur->left,result);
    result.push_back(cur->val);
    inorder(cur->right,result);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    if(root==NULL) return {};
    inorder(root,result);
    return result;

    
    // //Iterative
    // stack<TreeNode*>st;
    // TreeNode* node=root;
    // vector<int> inorder;
    // while(true){
    //     if(node!=NULL){
    //         st.push(node);
    //         node=node->left;
    //     }
    //     else{
    //         if(st.empty()) break;
    //         node=st.top();
    //         st.pop();
    //         inorder.push_back(node->val);
    //         node=node->right;
    //     }
    // }
    // return inorder;

}



//Postorder Traversal --> Left Right Root 
//leetcode 145
void postorder(TreeNode* cur,vector<int>&result){
    if(cur==NULL) return;

    postorder(cur->left,result);
    postorder(cur->right,result);
    result.push_back(cur->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if(root==NULL) return result;
    postorder(root,result);
    return result;
}


//leetcode 102  Binary Tree Level Order Traversal.
// like bfs..
vector<vector<int>> levelOrder(TreeNode* root) {
    
    //Better written->
    vector<vector<int>> result;
    if(root==NULL) return result;

    queue<TreeNode*> que;
    que.push(root);
        
    while(!que.empty()){
        int size=que.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            TreeNode* top=que.front();
            que.pop();

            level.push_back(top->val);

            if(top->left!=nullptr) que.push(top->left);

            if(top->right!=nullptr) que.push(top->right);
        }
        result.push_back(level);
    }

    return result;
    
    
    
    
    
    
    //Using pair queue to store the index for the level..
    // vector<vector<int>> result;

    // if(root==NULL) return result;

    // queue<pair<TreeNode*,int>> que;
    // que.push({root,0});
        
    // while(!que.empty()){
    //     auto it=que.front();
    //     que.pop();
            
    //     if(it.second==result.size()){
    //         result.push_back({});
    //     }
            
    //     result[it.second].push_back(it.first->val);

    //     if(it.first->left!=NULL){
    //         que.push({it.first->left,it.second+1});
    //     }
    //     if(it.first->right!=NULL){
    //         que.push({it.first->right,it.second+1});
    //     }
    // }
    // return result;
}







int main() {
    // Creating the tree:
    //
    //          1
    //        /   \
    //       2     3
    //      / \   / \
    //     4   5 6   7
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
    PreInPostTraversal(root, preorder, inorder, postorder);
    cout << "Preorder: ";
    for (int x : preorder) {
        cout << x << " ";
    }
    cout << "\nInorder: ";
    for (int x : inorder) {
        cout << x << " ";
    }
    cout << "\nPostorder: ";
    for (int x : postorder) {
        cout << x << " ";
    }



    

    
    
    return 0;
}