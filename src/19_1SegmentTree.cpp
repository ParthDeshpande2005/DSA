#include<bits/stdc++.h>
using namespace std;

//leetcode 303-->
// this is not optimal appoarch 
//optimal appoarch uses prefix sum;
class NumArray {
public:
    vector<int> seg;
    int n;
    void build(int cur,int low,int high,vector<int> &arr){
        //leaf node-->
        if(low==high){
            seg[cur]=arr[low];
            return;
        }

        int mid=low+(high-low)/2;

        //build left subtree-->
        build(2*cur+1,low,mid,arr);

        //build right subtree-->
        build(2*cur+2,mid+1,high,arr);

        //assign value to parent index
        seg[cur]=seg[2*cur+1]+seg[2*cur+2];
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        seg.resize(4*n);
        build(0,0,n-1,nums);
    }
    int query(int cur,int low,int high,int l,int r){

        //completely outside
        if(high<l || r<low){
            return 0;
        }

        //completely inside
        if(l<=low && high<=r){
            return seg[cur];
        }

        //partial overlap
        int mid=low+(high-low)/2;

        int leftsum=query(2*cur+1,low,mid,l,r);
        int rightsum=query(2*cur+2,mid+1,high,l,r);

        return leftsum+rightsum;
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};


//leetcode 307-->
class NumArray2 {
public:
    vector<int> seg;
    int n;
    void build(int cur,int low,int high,vector<int>&arr){
        if(low==high){
            seg[cur]=arr[low];
            return;
        }

        int mid=low+(high-low)/2;

        build(2*cur+1,low,mid,arr);

        build(2*cur+2,mid+1,high,arr);

        seg[cur]=seg[2*cur+1]+seg[2*cur+2];

    }
    NumArray2(vector<int>& nums) {
        n=nums.size();
        seg.resize(4*n);   
        build(0,0,n-1,nums);
    }
    
    void updateidx(int cur,int low,int high,int index,int val){
        //we have reached the leaf containing index
        if(low==high){
            seg[cur]=val;
            return;
        }

        int mid=low+(high-low)/2;

        //Index lies in left subtree
        if(index<=mid){
            updateidx(2*cur+1,low,mid,index,val);
        }
        //Index lies in right subtree
        else{
            updateidx(2*cur+2,mid+1,high,index,val);
        }

        seg[cur]=seg[2*cur+1]+seg[2*cur+2];
    }
    void update(int index, int val) {
        updateidx(0,0,n-1,index,val);
    }
    
    int query(int cur,int low,int high,int l,int r){
        if(high<l || r<low){
            return 0;
        }
        if(l<=low && high<=r){
            return seg[cur];
        }

        int mid=low+(high-low)/2;

        int leftsum=query(2*cur+1,low,mid,l,r);
        int rightsum=query(2*cur+2,mid+1,high,l,r);

        return leftsum+rightsum;

    }
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};


// leetcode 2213--> 
class Solution1 {
public:
    struct Node{
        int maxlen=0;
        char rightchar=0;
        char leftchar=0;
        int pre=0;
        int suf=0;
    };

    vector<Node> seg;
    int n;

    Node merge( Node& L,Node& R,int leftlen,int rightlen){
        Node result;
        result.leftchar=L.leftchar;
        result.rightchar=R.rightchar;

        result.pre=L.pre;
        if(L.pre==leftlen && L.rightchar==R.leftchar){
            result.pre=L.pre+R.pre;
        }

        result.suf=R.suf;
        if(R.suf==rightlen && L.rightchar==R.leftchar){
            result.suf=L.suf+R.suf;
        }

        result.maxlen=max(L.maxlen,R.maxlen);
        if(L.rightchar==R.leftchar){
            result.maxlen=max(result.maxlen,L.suf+R.pre);
        }

        return result;
    }

    void build(int cur,int l,int r, string& s){
        if(l==r){
            seg[cur]={1,s[l],s[l],1,1};
            return ;
        }
        int mid=l+(r-l)/2;
        build(2*cur+1,l,mid,s);
        build(2*cur+2,mid+1,r,s);

        seg[cur]=merge(seg[2*cur+1],seg[2*cur+2],mid-l+1,r-mid);
    }

    void update(int cur,int l,int r,int idx,char ch){
        if(l==r){
            seg[cur]={1,ch,ch,1,1};
            return;
        }

        int mid=l+(r-l)/2;

        if(idx<=mid){
            update(2*cur+1,l,mid,idx,ch);
        }
        else{
            update(2*cur+2,mid+1,r,idx,ch);
        }

        seg[cur]=merge(seg[2*cur+1],seg[2*cur+2],mid-l+1,r-mid);
    }


    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        
        n=s.size();
        seg.resize(4*n,Node());

        build(0,0,n-1,s);

        int m=queryCharacters.size();
        vector<int> result(m,0);
        for(int i=0;i<m;i++){
            char ch=queryCharacters[i];
            int idx=queryIndices[i];

            update(0,0,n-1,idx,ch);

            result[i]=seg[0].maxlen;
        }

        return result;
    }
};


// leetcode 3072-->
// this is very important que for segment tree
// we learn how to compress the segment tree.
//this is used to solve query -> how many element are strictly greater/smaller than nums[i]
//in a growing list/vector/array "without needing so much space."
class SegmentTree{
public:
    int m;
    vector<int> segTree;

    SegmentTree(int size){
        m=size;
        segTree.assign(4*m,0); // initialization with frequency 0.
    }

    void segTreeUpdate(int i,int l,int r,int cv){
        if(l==r){
            segTree[i]++;
            return ;
        }

        int mid=l+(r-l)/2;
        if(cv<=mid){
            segTreeUpdate(2*i+1,l,mid,cv);
        }
        else{
            segTreeUpdate(2*i+2,mid+1,r,cv);
        }

        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }

    void update(int cv){
        //0=index of root
        //0=start range
        //m-1=end range
        //cv-compressed value.
        segTreeUpdate(0,0,m-1,cv);
    }

    int segTreeQueryRangeSum(int start,int end,int i,int l,int r){
        if(l>end || r<start){ //out of range
            return 0; //no overlap
        }
        if(l>=start && r<=end){ //completely inside range.
            return segTree[i]; //return frequency
        }

        int mid=l+(r-l)/2;

        return segTreeQueryRangeSum(start,end,2*i+1,l,mid)+segTreeQueryRangeSum(start,end,2*i+2,mid+1,r);

    }

    int query(int start,int end){
        return segTreeQueryRangeSum(start,end,0,0,m-1);
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> sortednums(begin(nums),end(nums));
        // we are sorting as we need to assign higher value to the larger number 
        // so than order remain maintain and we are able to find the numbers larger than the current easily
        sort(sortednums.begin(),sortednums.end()); // Sort the array

        unordered_map<int,int> mp; //to store nums[i] --> compressed value
        int CompressedValue=0;

        for(int &num:sortednums){ //compressed value given to nums
            if(!mp.count(num)){
                mp[num]=CompressedValue;
                CompressedValue++;
            }
        }

        int m=mp.size(); //compressed values=0,1,2,...m-1

        vector<int> arr1;
        vector<int> arr2;

        SegmentTree segTree1(m);
        SegmentTree segTree2(m);

        //1st operation
        arr1.push_back(nums[0]);
        segTree1.update(mp[nums[0]]);

        //2nd operation
        arr2.push_back(nums[1]);
        segTree2.update(mp[nums[1]]);

        for(int i=2;i<n;i++){
            int cv=mp[nums[i]]; //compressed value.
            int cnt1=segTree1.query(cv+1,m-1);//number of elements > nums[i] in arr1
            int cnt2=segTree2.query(cv+1,m-1);//number of elements > nums[i] in arr2

            bool addtoarr1=false;
            if(cnt1>cnt2){
                addtoarr1=true;
            }
            else if(cnt2>cnt1){
                addtoarr1=false;
            }
            else{
                addtoarr1=(arr1.size()<=arr2.size());
            }

            if(addtoarr1){
                arr1.push_back(nums[i]);
                segTree1.update(cv);
            }
            else{
                arr2.push_back(nums[i]);
                segTree2.update(cv);
            }
        }

        arr1.insert(end(arr1),begin(arr2),end(arr2));
        return arr1;
    }
};




int main(){


    vector<int> nums = {1, 3, 5, 7, 9, 11};
    NumArray obj2(nums);
    cout << "Sum [0,2] = " << obj2.sumRange(0, 2) << endl;
    cout << "Sum [1,4] = " << obj2.sumRange(1, 4) << endl;
    cout << "Sum [2,5] = " << obj2.sumRange(2, 5) << endl;
    cout << "Sum [0,5] = " << obj2.sumRange(0, 5) << endl;
    cout<<endl;



    vector<int> nums2 = {1, 3, 5, 7, 9, 11};
    NumArray2 obj(nums2);
    // Initial range sums
    cout << "Initial sum [0,2] = "<< obj.sumRange(0, 2) << endl;
    cout << "Initial sum [1,4] = " << obj.sumRange(1, 4) << endl;
    cout << "Initial sum [0,5] = " << obj.sumRange(0, 5) ;
    // Update index 2: 5 -> 10
    obj.update(2, 10);
    cout << "\nAfter update(2, 10):" << endl;
    cout << "Sum [0,2] = " << obj.sumRange(0, 2) << endl;
    cout << "Sum [1,4] = "<< obj.sumRange(1, 4) << endl;
    cout << "Sum [0,5] = " << obj.sumRange(0, 5);
    // Another update: index 4: 9 -> 20
    obj.update(4, 20);
    cout << "\nAfter update(4, 20):" << endl;
    cout << "Sum [0,5] = " << obj.sumRange(0, 5);
    cout<<endl<<endl;



    Solution1 sol;
    string s = "aaabbb";
    string queryCharacters = "aaa";
    vector<int> queryIndices = {3, 4, 5};
    vector<int> ans = sol.longestRepeating( s,queryCharacters,queryIndices);
    for(int x : ans) cout << x << " ";
    cout<<endl<<endl;




    return 0;
}