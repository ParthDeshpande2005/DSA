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


//Root to node path
bool getpath(TreeNode* cur,int node,vector<int> & arr){
    if(cur==NULL) {
        return false;
    }

    arr.push_back(cur->val);

    if(cur->val==node){
        return true;
    }

    if(getpath(cur->left,node,arr) || getpath(cur->right,node,arr)){
        return true;
    }

    arr.pop_back();
    return false;
}
vector<int> RootNodePath(TreeNode* root,int node){
    vector<int> result;
    if(root==NULL) return result;
    getpath(root,node,result);
    return result;
}   

//leetcode 236
//optimal method thoda alag hai must see
//better appoarch mai last que wala method use hoge getpath wala same to same.
bool getpath2(TreeNode* cur,TreeNode* node,vector<TreeNode*>& arr){
    if(cur==NULL){
        return false;
    }

    arr.push_back(cur);

    if(cur==node){
        return true;
    }

    if(getpath2(cur->left,node,arr) || getpath2(cur->right,node,arr)){
        return true;
    }

    arr.pop_back();
    return false;
}
TreeNode* lca_recursion(TreeNode* cur,TreeNode* p,TreeNode* q){
    if(cur==NULL || cur==p || cur==q) {
        return cur;
    }
    TreeNode* left=lca_recursion(cur->left,p,q);
    TreeNode* right=lca_recursion(cur->right,p,q);

    if(left==NULL){
        return right;
    }
    else if(right==NULL){
        return left;
    }
    else{ //both left and right are not null, we found our result
        return cur;
    }
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //optimal--> improving the space complexity.
    return lca_recursion(root,p,q);

    // //better->
    // //we will find the path for root->p and also the path root->q .
    // //then we will find all the matching in this path the last match in this path will be our answer.
    // //this is not optimal as there will be two array used to store the path.

    // vector<TreeNode*> arrp;
    // vector<TreeNode*> arrq;

    // getpath2(root,p,arrp);
    // getpath2(root,q,arrq);

    // int size=min(arrp.size(),arrq.size());
    // TreeNode* ans=root;
    // for(int i=0;i<size;i++){
    //     if(arrp[i]==arrq[i]){
    //         ans=arrp[i];
    //     }else{
    //         break;
    //     }
    // }
    // return ans;
}


//leetcode 662
// IMP different appoarch (i first thought about the appoarch used for top view like doing -1 for left and +1 for right)
// where different logic to normalze the ans to prevent overflow.
// we use segment tree logic to find the width this indexing is also known as complete binary tree indexing(cbt indexing).
typedef long long ll;
int widthOfBinaryTree(TreeNode* root) {
    if(root==NULL) return 0;

    queue<pair<TreeNode*,ll>> que;
    que.push({root,0});

    int maxwidth=0;
    while(!que.empty()){
        int size=que.size();

        ll mini=que.front().second; //to make the id start from zero.
        int first=0,last=0;

        for(int i=0;i<size;i++){
            ll cur=que.front().second-mini;
            TreeNode* node=que.front().first;
            que.pop();

            if(i==0){
                first=cur;
            }
            if(i==size-1){
                last=cur;
            }
            if(node->left!=NULL) que.push({node->left,2*cur+1});
            if(node->right!=NULL) que.push({node->right,2*cur+2});
        }
        maxwidth=max(maxwidth,(last-first)+1);
    }
    return maxwidth;
}


//Very IMP --> very different appoarch

//watch striver video for most optimal solution.
//Children Sum Property
// we can only increase the value.we can't decrease the problem.
//appoarch-> as we cant decrease if sum of child is smaller than the parent then we assign both the child the value of parent.
// and if the sum is greater then we assign the parent the sum of children.
int subtreeSum(TreeNode* root) {
    //this recursion function is for better appoarch.
    if (root == NULL)
        return 0;

    return root->val+ subtreeSum(root->left)+ subtreeSum(root->right);
}
void childrensum(TreeNode* root){
    //optimal O(N)
    if(root==NULL) return;
    int child=0;
    if(root->left){
        child+=root->left->val;
    }
    if(root->right){
        child+=root->right->val;
    }

    if(child>=root->val){
        root->val=child;
    }
    else{
        if(root->left){
            root->left->val=root->val;
        }
        if(root->right){
            root->right->val=root->val;
        }
    }

    childrensum(root->left);
    childrensum(root->right);

    int tot=0;
    if(root->left) tot+=root->left->val;
    if(root->right) tot+=root->right->val;
    if(root->left || root->right) root->val=tot; //we dont update the root node.


    //better O(N^2)
    // if (root == NULL)
    //     return;

    // // Calculate the sum of the left and right subtrees
    // int leftSum = subtreeSum(root->left);
    // int rightSum = subtreeSum(root->right);

    // int childSum = leftSum + rightSum;

    // // Children sum is greater -> increase root
    // if (childSum > root->val) {
    //     root->val = childSum;
    // }

    // // Root is greater -> increase a child
    // else if (childSum < root->val) {
    //     if (root->left)
    //         root->left->val = root->val;
    //     else if (root->right)
    //         root->right->val = root->val;
    // }

    // // Recursively fix left and right subtrees
    // childrensum(root->left);
    // childrensum(root->right);

    // int newChildSum = 0;
    // if (root->left)
    //     newChildSum += root->left->val;
    // if (root->right)
    //     newChildSum += root->right->val;
    // if (newChildSum > root->val)
    //     root->val = newChildSum;

}


//leetcode 863
// new idea of making a map for mapping parent of each node.
// IMP 
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> result;

    if(root==NULL) return result;

    unordered_map<TreeNode*,TreeNode*> parent; //we will store all the mpp[children]=parent. 
    queue<TreeNode*> que;
    que.push(root);

    //updating the parent map.
    while(!que.empty()){
        TreeNode* node=que.front();
        que.pop();

        if(node->left){
            parent[node->left]=node;
            que.push(node->left);
        }
        if(node->right){
            parent[node->right]=node;
            que.push(node->right);
        }
    }

    //now we will start from the target node.
    //we will move in all posible direction from the target node.
    //like we use bfs in graph que.
    //we will also maintain a visited map to check if the node is visited before.

    queue<TreeNode*> q;
    unordered_map<TreeNode*,int> visited;

    q.push(target);
    visited[target]++;

    for(int i=0;i<k;i++){
        if(q.empty()) return result;

        int size=q.size();
        for(int j=0;j<size;j++){
            TreeNode* cur=q.front();
            q.pop();
                
            visited[cur]++;

            if(cur->left){
                if(visited.find(cur->left)==visited.end()){
                    q.push(cur->left);
                }
            }
            if(cur->right){
                if(visited.find(cur->right)==visited.end()){
                    q.push(cur->right);
                }
            }
            if(parent.find(cur)!=parent.end()){
                if(visited.find(parent[cur])==visited.end()){
                    q.push(parent[cur]);
                }
            }
        }
    }

    while(!q.empty()){
        result.push_back(q.front()->val);
        q.pop();
    }

    return result;
}






int main() {

    /*
              10
             /  \
            5    3
           / \    \
          2   4    1
    */

    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(1);


    // --------------------------------------------------
    // 1. Root to Node Path
    // --------------------------------------------------

    int node = 4;

    vector<int> path = RootNodePath(root, node);

    cout << "Root to node " << node << " path: ";

    for(int x : path) {
        cout << x << " ";
    }

    cout << "\n\n";


    // --------------------------------------------------
    // 2. LCA
    // --------------------------------------------------

    TreeNode* p = root->left->left;   // 2
    TreeNode* q = root->left->right;  // 4

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    cout << "LCA of " << p->val << " and " << q->val << ": ";

    if(lca)
        cout << lca->val;

    cout << "\n\n";


    // --------------------------------------------------
    // 3. Maximum Width
    // --------------------------------------------------

    cout << "Maximum width of binary tree: "
         << widthOfBinaryTree(root) << "\n\n";


    // --------------------------------------------------
    // 4. Children Sum Property
    // --------------------------------------------------

    cout << "Before Children Sum Property:\n";
    cout << "Root = " << root->val << "\n";

    childrensum(root);

    cout << "After Children Sum Property:\n";
    cout << "Root = " << root->val << "\n";


    // --------------------------------------------------
    // 5. Distance K
    // --------------------------------------------------

    /*
              After children sum modification,
              the structure is still the same.

              Target = node 5
              k = 1

              Nodes at distance 1:
              10, 2, 4
    */
    /* now the tree is ->

              30
             /  \
            20   10
           / \    \
          10  10   10
    */

    TreeNode* target = root->left;

    int k = 1;

    vector<int> distanceNodes = distanceK(root, target, k);

    cout << "\nNodes at distance " << k
         << " from target " << target->val << ": ";

    for(int x : distanceNodes) {
        cout << x << " ";
    }

    cout << "\n";


    return 0;
}