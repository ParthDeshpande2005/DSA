#include<bits/stdc++.h>
using namespace std;

//monotonic deque approach
//leetcode 239
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n=nums.size();
    deque<int> dq;
    vector<int> result;
    for(int i=0;i<n;i++){
        while(!dq.empty() && nums[i]>=nums[dq.back()]){
            dq.pop_back();
        }
        
        while(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        dq.push_back(i);
        if(i>=k-1){
            result.push_back(nums[dq.front()]);
        }
        
    }
    return result;

    //brute force will be N^2 find max in each subarray.
}

//leetcode 901
//finding previous larger input is coming on time 
//IMP...
class StockSpanner {
public:
    stack<pair<int,int>> st;
    int cur_idx=-1;
    StockSpanner() {
        cur_idx=-1;
        // st={};
    }
    
    int next(int price) {
        cur_idx=cur_idx+1;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int ans=cur_idx-(st.empty() ? -1 :st.top().second);
        st.push({price,cur_idx});
        return ans;
    }
};


//celebrity problem.
//find the celebrity in matrix.
// if matrix[0][1]=1 then 0 knows person 1.
// celbrity--> everone knows him , he knows no one.
int celebrity(vector<vector<int>> &matrix){

    
    //optimal-> TC->O(n) SC->O(1)
    int n=matrix.size();
    int top=0;
    int bottom=n-1;

    while(top<bottom){
        if(matrix[top][bottom]==1){//top know bottom.so top can't be celebrity
            top++;
        }
        else if(matrix[bottom][top]==1){//bottom knows top.so bottom can't be celebrity
            bottom--;
        }
        else{//both dont no each other meaning both can't be celebrity.
            top++;
            bottom--;
        }
    }
    if(top>bottom) return -1;


    //now as top and bottom are the same person.
    //we will check in that row and coloumn to check if every one knows him.and he knows no one.
    for(int i=0;i<n;i++){
        if(top==i) continue;
        if(matrix[top][i]==0 && matrix[i][top]==1){
            continue;
        }
        else{
            return -1;
        }
    }
    return top;


    //same appoarch can be applied using stack-->
    // we will push all element in the stack.
    //then pop two at a time. check for same conditions .
    // stack<int> st;
    // int n=M.size();
    // // Push everyone
    // for (int i = 0; i < n; i++)
    //     st.push(i);
    // // Elimination
    // while (st.size() > 1) {
    //     int a = st.top(); st.pop();
    //     int b = st.top(); st.pop();
    //     if (M[a][b] == 1)
    //         st.push(b);   // a knows b, so a can't be celebrity
    //     else
    //         st.push(a);   // a doesn't know b, so b can't be celebrity
    // }
    // int candidate = st.top();
    // // Verification
    // for (int i = 0; i < n; i++) {
    //     if (i == candidate) continue;

    //     if (M[candidate][i] == 1 || M[i][candidate] == 0)
    //         return -1;
    // }
    // return candidate;



    //brute force TC->O(n^2)  SC->(n)
    // int n=matrix.size(); //number of people.
    // vector<int> knowme(n,0);
    // vector<int> iknow(n,0);

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(matrix[i][j]==1){
    //             iknow[i]++;
    //             knowme[j]++;
    //         }
    //     }
    // }

    // for(int i=0;i<n;i++){
    //     if(iknow[i]==0 && knowme[i]==n-1){
    //         return i;
    //     }
    // }

    // return -1;

}


//optimal using DLL and map.
//all method get and put executein O(1) 
class LRUCache {
public:
    struct Node{
        public:
        int key;
        int val;
        Node* next;
        Node* back;

        public:
        Node(int key1,int val1){
            key=key1;
            val=val1;
            next=nullptr;
            back=nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size;
    unordered_map<int,Node*> mpp;

    LRUCache(int capacity) {
        size=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->back=head;
    }

    int get(int key) {
        //in the map-->
        if(mpp.find(key)!=mpp.end()){
            //if in map move it to after head.
            Node* cur=mpp[key];
            Node* curprev=cur->back;
            Node* curnext=cur->next;

            curprev->next=curnext;
            curnext->back=curprev;

            cur->next=head->next;
            cur->next->back=cur;
            head->next=cur;
            cur->back=head;

            return cur->val;
            
        }
        //not in map-->
        return -1;

    }
    
    void put(int key, int value) {
        //if in map. we will delete that node 
        if(mpp.find(key)!=mpp.end()){
            Node* temp=mpp[key]; // node that is to be deleted.
            Node* tempnext=temp->next;
            tempnext->back=temp->back;
            temp->back->next=tempnext;
            delete temp;
        }

        //if hash map size is full we will delete the element previous to tail.
        else if(mpp.size()==size){
            int keydel=tail->back->key;
            Node* dele=tail->back;
            tail->back=dele->back;
            dele->back->next=tail;
            delete dele;
            mpp.erase(keydel);
        }

        //make new node for the current key,value
        Node* newn=new Node(key,value);
        newn->next=head->next;
        newn->next->back=newn;
        head->next=newn;
        newn->back=head;
        mpp[key]=newn;
    }
};


//not optimal using queue and map--.
class LRUCache2 {
public:
    //this will not pass the test cases for leetcode as time complexity is O(n) for every operation.
    //this que can be solved using deque+map as we can do traversal in map.
    //similarly we can use array to do this as well.
    int cap;
    deque<int>dq; //this will store key in LRU pattern.
    unordered_map<int,int> mpp; //this will store key and value.
    LRUCache2(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        for(auto it=dq.begin();it!=dq.end();it++){ //traversal in deque.
            if(*it==key){ //* before is used for value.
                dq.erase(it);
                break;
            }
        }
        dq.push_front(key);
        return mpp[key];
    }
    
    void put(int key, int value) {

        if(mpp.find(key)!=mpp.end()){//if element allready in mpp.
            for(auto it=dq.begin();it!=dq.end();it++){ //traversal in deque.
                if(*it==key){ //* before is used for value.
                    dq.erase(it);
                    break;
                }
            }
            mpp.erase(key);
        }
        //mpp.size is full-->
        if(mpp.size()==cap){
            int del=dq.back();//this is LRU
            dq.pop_back();
            mpp.erase(del);
        }

        mpp[key]=value;
        dq.push_front(key);
    }
};

//using 2 map and multiple DLL-->
//complex to understand.
//TC->O(1) for all operations. OPTIMAL
class LFUCache {
public:
    struct Node{
        int key;
        int val;
        int cnt; //freq.
        Node* next;
        Node* prev;

        Node(int key1,int val1){
            key=key1;
            val=val1;
            cnt=1;
            next=nullptr;
            prev=nullptr;
        }
    };

    struct List{ //we creat new list for each new frequency.
        //menaing there willbe multiple DLL at same time for differenet frequency.
        int size;
        Node* head;
        Node* tail;
        List(){
            head=new Node(-1,-1);
            tail=new Node(-1,-1);
            head->next=tail;
            tail->prev=head;
            size=0;
        }
        
        void addfront(Node* node){//to add node after head.
            Node* temp=head->next;
            node->next=temp;
            temp->prev=node;
            head->next=node;
            node->prev=head;
            size++;
        }

        void removenode(Node* node){ //to remove certain node.
            Node* tempprev=node->prev;
            Node* tempfront=node->next;
            tempprev->next=tempfront;
            tempfront->prev=tempprev;
            size--;
            //we can't use delete node as we are moving a node from one location to other .
            //we can delete if we will allways create a new node to replace it . or ot will create a data inconsistency.
        }
    };

    map<int,Node*>keynode; //map to store key and its respective value.
    map<int,List*>freqlistmap; //map to store frequency and its respective DLL.
    int maxsizecache;//to compare with cursize.
    int minfreq;//store the minium freq curently.
    int cursize;
    LFUCache(int capacity) {
        maxsizecache=capacity;
        minfreq=0;
        cursize=0; 
    }
    void updatefreqlistmap(Node* node){
        //we will remove this node from our list keynode list as well as from list in freqlist.
        keynode.erase(node->key);
        List* cur=freqlistmap[node->cnt];//we get the list in which node is presnt.
        cur->removenode(node);
        if(node->cnt==minfreq && cur->size==0){
            minfreq++;
        }

        List* nexthigherfreqlist=new List();
        //if list allready exists -->
        if(freqlistmap.find((node->cnt)+1)!=freqlistmap.end()){
            nexthigherfreqlist=freqlistmap[(node->cnt)+1];
        }
        node->cnt+=1; //increasing the freq of node
        nexthigherfreqlist->addfront(node);
        freqlistmap[node->cnt]=nexthigherfreqlist;
        keynode[node->key]=node;
    }
    
    int get(int key) {
        if(keynode.find(key)!=keynode.end()){
            Node* node=keynode[key];
            int val=node->val;
            updatefreqlistmap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //edge case-->
        if(maxsizecache==0){
            return;
        }
        if(keynode.find(key)!=keynode.end()){
            Node* node=keynode[key];
            node->val=value;
            updatefreqlistmap(node);
        }
        else{
            if(cursize==maxsizecache){
                List* minfreqlist=freqlistmap[minfreq];
                keynode.erase(minfreqlist->tail->prev->key);
                minfreqlist->removenode(minfreqlist->tail->prev);
                cursize--;
            }

            minfreq=1;
            Node* node=new Node(key,value);
            List* listfreq=new List();
            if(freqlistmap.find(minfreq)!=freqlistmap.end()){
                listfreq=freqlistmap[minfreq];
            }
            listfreq->addfront(node);
            keynode[key]=node;
            freqlistmap[minfreq]=listfreq;
            cursize++;
        }
    }
};


// implemented using deque and map-->
// time complexity is greater than o(1) .
class LFUCache2 {
    int capacity;

    // key -> {value, frequency}
    unordered_map<int, pair<int,int>> mp;

    deque<int> dq;

    // Rearrange key according to frequency
    void updatePosition(int key){
        dq.erase(find(dq.begin(), dq.end(), key));

        auto it = dq.begin();

        while(it != dq.end() &&
              mp[*it].second <= mp[key].second)
            ++it;

        dq.insert(it, key);
    }

public:
    LFUCache2(int cap){
        capacity = cap;
    }

    int get(int key){
        if(mp.find(key)==mp.end())
            return -1;

        mp[key].second++;

        updatePosition(key);

        return mp[key].first;
    }

    void put(int key,int value){

        if(capacity==0)
            return;

        if(mp.find(key)!=mp.end()){
            mp[key].first=value;
            mp[key].second++;

            updatePosition(key);
            return;
        }

        if(mp.size()==capacity){
            int removeKey=dq.front();
            dq.pop_front();
            mp.erase(removeKey);
        }

        mp[key]={value,1};

        auto it=dq.begin();

        while(it!=dq.end() && mp[*it].second<=1)
            ++it;

        dq.insert(it,key);
    }
};




int main(){


    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);
    cout << "Sliding Window Maximums: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    cout << endl;


    StockSpanner obj;
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    for (int price : prices) {
        cout << "Price: " << price<< " -> Span: " << obj.next(price) << endl;
    }
    cout<<endl;


    vector<vector<int>> matrix={{0,1,1,0},{0,0,0,0},{0,1,0,0},{1,1,0,0}};
    cout<<celebrity(matrix)<<endl;
    cout<<endl;


    //optimal using DLL-->
    LRUCache cache(2);
    cache.put(1, 10);
    cache.put(2, 20);
    cout << cache.get(1) << endl;   // 10
    cache.put(3, 30);               // Evicts key 2
    cout << cache.get(2) << endl;   // -1
    cache.put(4, 40);               // Evicts key 1
    cout << cache.get(1) << endl;   // -1
    cout << cache.get(3) << endl;   // 30
    cout << cache.get(4) << endl;   // 40
    cout<<endl;


    //optimal using DLL-->
    LRUCache2 cache2(2);
    cache2.put(1, 10);
    cache2.put(2, 20);
    cout << cache2.get(1) << endl;   // 10
    cache2.put(3, 30);               // Evicts key 2
    cout << cache2.get(2) << endl;   // -1
    cache2.put(4, 40);               // Evicts key 1
    cout << cache2.get(1) << endl;   // -1
    cout << cache2.get(3) << endl;   // 30
    cout << cache2.get(4) << endl;   // 40
    cout<<endl;


    
    LFUCache cache3(2);
    cache3.put(1, 1);
    cache3.put(2, 2);
    cout << "get(1): " << cache3.get(1) << endl;   // 1
    cache3.put(3, 3);                              // Evicts key 2
    cout << "get(2): " << cache3.get(2) << endl;   // -1
    cout << "get(3): " << cache3.get(3) << endl;   // 3
    cache3.put(4, 4);                              // Evicts key 1
    cout << "get(1): " << cache3.get(1) << endl;   // -1
    cout << "get(3): " << cache3.get(3) << endl;   // 3
    cout << "get(4): " << cache3.get(4) << endl;   // 4



    return 0;
}