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



int main() {

    /*
            Tree 1
                1
               / \
              2   3
             / \
            4   5

        Maximum Depth = 3
        Balanced = Yes
        Diameter = 3
        Maximum Path Sum = 11  (4 -> 2 -> 5)
    */

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    cout << "Maximum Depth: "
         << maxDepth(root1) << endl;

    cout << "Is Balanced: "
         << (isBalanced(root1) ? "Yes" : "No") << endl;

    cout << "Diameter: "
         << diameterOfBinaryTree(root1) << endl;

    cout << "Maximum Path Sum: "
         << maxPathSum(root1) << endl;


    /*
            Tree 2
                1
               / \
              2   3
             / \
            4   5
    */

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);

    cout << "Same Tree: "
         << (isSameTree(root1, root2) ? "Yes" : "No") << endl;


    /*
            Tree 3
                1
               / \
              2   3
             /
            4

        This tree is different from Tree 1.
    */

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);

    cout << "Root1 and Root3 Same Tree: "
         << (isSameTree(root1, root3) ? "Yes" : "No") << endl;

    return 0;
}