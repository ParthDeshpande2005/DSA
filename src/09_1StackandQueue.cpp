#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;

    Node(int val1,Node* next1){
        val=val1;
        next=next1;
    }
    Node(int val1){
        val=val1;
        next=NULL;
    }
};


//implementing Stack using Array.
// we use fixed size as the array cant be dynamic in nature.
//we use a topindex variable to push in array.
// we never delete out iof the array .
// we just reduce the stack, and when the push operation is done we overwrite the allready stored variable in case there is
//TC->O(1)  SC->O(n)
class ImpstackArray{
    public:
    int topidx=-1;
    vector<int> st=vector<int>(10);
    //or use 
    // vector<int> st;
    // ImpstackArray() : st(10) {}
    //as we can not use vector<int> st(10) in class.
    int capacity=10;

    void push(int x){
        if(topidx==capacity-1) {
            cout<< "Stack is Full\n";
            return;
        }
        topidx=topidx+1;
        st[topidx]=x;
    }

    void pop(){
        if(topidx==-1) {
            cout<<"Stack is empty\n";
            return;
        }
        topidx=topidx-1;
    }

    int top(){
        if(topidx==-1){
            cout<<"Stack is empty\n";
            return -1;
        }
        return st[topidx];
    }

    int size(){
        return topidx+1;
    }

    bool empty(){
        return topidx==-1;
    }

};

//again we will be using fixed size array.
//start and end do pointers hai jo array mai ghum raha hai depending apon the size.
//jab start end last mai pauch ta hai tab hm use first pai late hai vapas depending on ki queue full hai ya nahi.
//end pointer push ke time kam atta hai.
//start pointer pop ke time kam atta hai.
//TC->O(1)  SC->O(n)
//watch video to get completew idea->https://www.youtube.com/watch?v=tqQ5fTamIN4
class ImpueueArray{
    public:
    int capacity=10;
    vector<int> que=vector<int> (10);
    int cur_size=0; //cur_size is very imp need to changed in every push,pop.
    int start=-1;
    int end=-1;

    void push(int x){
        if(cur_size==capacity) {
            cout<<"Queue is Full\n";
            return;
        }
        if(cur_size==0){
            start=0;
            end=0;
        }
        else{
            end=(end+1)%capacity;  //we will return to first index when we are at last. because the first one will be empty due to pop.
            //implementing circular array.
        }
        que[end]=x;
        cur_size=cur_size+1;
    }

    void pop(){
        if(cur_size==0){
            cout<<"Queue is Empty\n";
            return;
        }
        if(cur_size==1){ //we can't use the condition start==0 or end==0 as the single element can be any where in the array.
            start=end=-1;
        }
        else{
            start=(start+1)%capacity;
        }
        cur_size=cur_size-1;
    }

    int top(){
        if(cur_size==0){
            cout<<"Queue is Empty.\n";
            return -1;
        }
        else{
            return que[start];
        }
    }

    int size(){
        return cur_size;
    }

    bool empty(){
        return cur_size==0;
    }

};

//every new node is added at the head.
class ImpstackLL{
    public:
    Node* cur_top=NULL;
    int cur_size=0;

    void push(int x){
        //the first node points to the null.
        //every new node is added at the head.
        //so that the Last in first out can be carried out.
        Node* temp=new Node(x);
        temp->next=cur_top;
        cur_top=temp;
        cur_size=cur_size+1;
    }

    void pop(){
        if(cur_top==NULL){//NULL used insted of 0
            cout<<"Stack is empty\n";
            return;
        }
        Node* temp=cur_top;
        cur_top=cur_top->next;
        delete temp;
        cur_size=cur_size-1;
    }

    int top(){
        if(cur_top==NULL){
            cout<<"Stack is empty\n";
            return -1;
        }
        return cur_top->val;
    }

    int size(){
        return cur_size;
    }

};

//every new node is added at the tail.
//we will use two pointers start and end.
//start will allways point at heada of LL and end will point at tail.
//pop will be carried out by start pointer.
//push will be carried out by end pointer.
class ImpQueueLL{
    public:
    Node* start=NULL;
    Node* end=NULL;
    int cur_size=0;

    void push(int x){
        Node* temp=new Node(x);
        if(cur_size==0){
            start=end=temp;
        }
        else{
            end->next=temp;
            end=end->next;
        }
        cur_size=cur_size+1;
    }   

    void pop(){
        if(start==NULL){
            cout<<"Queue is empty\n";
            return;
        }
        Node* temp=start;
        start=start->next;
        delete temp;
        cur_size=cur_size-1;

        if(start==NULL){
            end=NULL;
        }
    }

    int top(){
        if(start==NULL){
            cout<<"Queue is empty\n";
            return -1;
        }
        return start->val;
    }

    int size(){
        return cur_size;
    }


};


class IMPStackQueue{//implementing stack using queue.
    public:
    queue<int> q;
    void push(int x){
        int s=q.size();
        q.push(x);
        for(int i=1;i<=s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    void pop(){
        if(q.empty()){
            cout<<"Stack is empty\n";
            return;
        }
        q.pop();
    }
    int top(){
        if(q.empty()){
            cout<<"Stack is empty\n";
        }
        return q.front();
    }
    int size(){
        return q.size();
    }
    bool empty(){
        return q.empty();
    }
};


class IMPQueueStackM1{//implementing Queue using stack.
    public:
    //using 2 stack.
    //here we apply multiple pop and push on push.
    stack<int> st1;
    stack<int> st2;
    void push(int x){

        //step 1->
        while(st1.size()){
            st2.push(st1.top());
            st1.pop();
        }

        //step 2->
        st1.push(x);

        //step 3->
        while(st2.size()){
            st1.push(st2.top());
            st2.pop();
        }
    }

    void pop(){
        st1.pop();
    }

    int front(){
        return st1.top();
    }

    int size(){
        return st1.size();
    }

    bool empty(){
        return st1.empty();
    }
};


class IMPQueueStackM2{
    public:
    //using 2 stack
    //here we apply multiple pop for pop and top.
    stack<int> st1;
    stack<int> st2;
    void push(int x){
        st1.push(x);
    }
    
    void pop(){
        if(!st2.empty()){
            st2.pop();
        }
        else{
            int s=st1.size();
            for(int i=1;i<=s;i++){
                st2.push(st1.top());
                st1.pop();
            }
            st2.pop();
        }
    }

    int top(){
        if(!st2.empty()){
            return st2.top();
        }
        int s=st1.size();
        for(int i=1;i<=s;i++){
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }

    int size(){
        return st1.size()+st2.size();
    }

    bool empty(){
        return st1.empty() && st2.empty();
    }

};

//leetcode 155->
//method 1 using stack<pair<int,int>> .
//pair first stores element.
//pair second stores the curent min.
class MinstackM1{
    public:
    stack<pair<int,int>> st;
    void push(int x){
        if(st.empty()){
            st.push({x,x});
        }
        else{
            st.push({x,min(x,st.top().second)});
        }
    }
    void pop(){
        st.pop();
    }
    int top(){
        return st.top().first;
    }
    int getMin(){
        return st.top().second;
    }
};

//Method 2 using maths
//using 2*val-prevmin=newval; to push the element smaller than current min.
//using prevmin=2*val-newval;  to get the prev min back.
//also used when pop and top is called.
class MinstackM2{
    public:
    stack<int> st;
    int cur_min;
    void push(int val){
        if(st.empty()){
            cur_min=val;
            st.push(val);
        }
        else{
            if(val>=cur_min) st.push(val);
            else{
                int newval=2*val-cur_min;
                st.push(newval);
                cur_min=val;
            }
        }
    }
    void pop(){
        if(st.empty()) return;
        else{
            if(st.top()>=cur_min){
                st.pop();
            }
            else{
                int prevmin=2*cur_min-st.top();
                cur_min=prevmin;
                st.pop();
            }
        }
    }
    int top(){
        if(st.empty()) return -1;
        else{
            if(st.top()>=cur_min){
                return st.top();
            }
            else{
                return cur_min;
            }
        }
    }
    int getMin(){
        return cur_min;
    }
};



//leetcode 20
bool isValid(string s) {
    stack<int> st;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.empty() ||st.top()!='(') return false;
            st.pop();
        }
        else if(s[i]=='}'){
            if(st.empty() ||st.top()!='{') return false;
            st.pop();
        }
        else if(s[i]==']'){
            if(st.empty() || st.top()!='[') return false;
            st.pop();
        }
    }
    return st.empty();
}



int main(){

    ImpstackArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top: " << s.top() << endl;
    cout << "Size: " << s.size() << endl;
    s.pop();
    cout << "Top: " << s.top() << endl;
    cout << "Size: " << s.size() << endl;
    while (s.size()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    s.pop();   // Stack is empty
    if(s.empty()==true){
        cout<<"empty stack\n";
    }
    else{cout<< "stack not empty\n";}
    cout<<endl;




    ImpueueArray q;
    // Push elements
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Front: " << q.top() << endl;
    cout << "Size: " << q.size() << endl;
    // Pop one element
    q.pop();
    cout << "After one pop:\n";
    cout << "Front: " << q.top() << endl;
    cout << "Size: " << q.size();
    // Push more elements
    q.push(40);
    q.push(50);
    q.push(60);
    cout << "\nCurrent Queue (Front to Rear): ";
    while (q.size() > 0) {
        cout << q.top() << " ";
        q.pop();
    }
    // Try popping from an empty queue
    q.pop();
    // Try accessing front of an empty queue
    cout << q.top()<<endl;
    if(q.empty()==true){
        cout<<"empty queue";
    }
    else{cout<< "queue not empty";}
    // Fill the queue completely
    cout << "\nTesting Queue Overflow:\n";
    for (int i = 1; i <= 11; i++) {
        q.push(i * 10);
    }
    cout<<endl;




    ImpstackLL st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.top() << endl;
    cout << "Size: " << st.size();
    st.pop();
    cout << "\nAfter one pop:\n";
    cout << "Top: " << st.top() << endl;
    cout << "Size: " << st.size();
    cout << "\nCurrent Stack (Top to Bottom): ";
    while (st.size() > 0) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    st.pop();
    cout << "Top after empty: " << st.top() << endl;
    cout<<endl;




    ImpQueueLL qLL;
    qLL.push(10);
    qLL.push(20);
    qLL.push(30);
    cout << "Front: " << qLL.top() << endl;
    cout << "Size: " << qLL.size();
    qLL.pop();
    cout << "\nAfter one pop:\n";
    cout << "Front: " << qLL.top() << endl;
    cout << "Size: " << qLL.size();
    qLL.push(40);
    qLL.push(50);
    cout << "\nCurrent Queue (Front to Rear): ";
    while (qLL.size() > 0) {
        cout << qLL.top() << " ";
        qLL.pop();
    }
    cout << endl;
    qLL.pop();
    cout << "Front after empty: " << qLL.top() << endl;
    cout<<endl;



    
        //================ Stack using Queue ==================
    cout << "\n\n===== Stack using Queue =====\n";
    IMPStackQueue sq;
    sq.push(10);
    sq.push(20);
    sq.push(30);
    cout << "Top: " << sq.top() << endl;
    cout << "Size: " << sq.size() << endl;
    sq.pop();
    cout << "After one pop:\n";
    cout << "Top: " << sq.top() << endl;
    cout << "Size: " << sq.size() << endl;
    cout << "Current Stack (Top to Bottom): ";
    while (!sq.empty()) {
        cout << sq.top() << " ";
        sq.pop();
    }
    cout << endl;
    sq.pop();    // Underflow test
    cout << endl;
    

    
    //================ Queue using Stack (Method 1) ==================
    cout << "===== Queue using Two Stacks (Method 1) =====\n";
    IMPQueueStackM1 q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    cout << "Front: " << q1.front() << endl;
    cout << "Size: " << q1.size() << endl;
    q1.pop();
    cout << "After one pop:\n";
    cout << "Front: " << q1.front() << endl;
    cout << "Size: " << q1.size() << endl;
    cout << "Current Queue: ";
    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl << endl;


    
    //================ Queue using Stack (Method 2) ==================
    cout << "===== Queue using Two Stacks (Method 2) =====\n";
    IMPQueueStackM2 q2; 
    q2.push(10);
    q2.push(20);
    q2.push(30);
    cout << "Front: " << q2.top() << endl;
    cout << "Size: " << q2.size() << endl;
    q2.pop();
    cout << "After one pop:\n";
    cout << "Front: " << q2.top() << endl;
    cout << "Size: " << q2.size() << endl;
    q2.push(40);
    q2.push(50);
    cout << "Current Queue: ";
    while (!q2.empty()) {
        cout << q2.top() << " ";
        q2.pop();
    }
    cout << endl;
    
    

    vector<string> testCases = {"()","()[]{}","(]","([)]","{[]}","","(","((()))","[{()}]","{[(])}"};
    for (string s : testCases) {
        cout << "Input: \"" << s << "\" -> ";
        if (isValid(s))
            cout << "Valid\n";
        else
            cout << "Invalid\n";
    }



    cout << "\n===== Min Stack Method 1 =====\n";
    MinstackM1 ms1;
    ms1.push(5);
    ms1.push(3);
    ms1.push(7);
    ms1.push(2);
    cout << "Top: " << ms1.top() << endl;
    cout << "Min: " << ms1.getMin() << endl;
    ms1.pop();
    cout << "After pop\n";
    cout << "Top: " << ms1.top() << endl;
    cout << "Min: " << ms1.getMin() << endl;
    

    

    cout << "\n===== Min Stack Method 2 =====\n";
    MinstackM2 ms2;
    ms2.push(5);
    ms2.push(3);
    ms2.push(7);
    ms2.push(2);
    cout << "Top: " << ms2.top() << endl;
    cout << "Min: " << ms2.getMin() << endl;
    ms2.pop();
    cout << "After pop\n";
    cout << "Top: " << ms2.top() << endl;
    cout << "Min: " << ms2.getMin() << endl;




    return 0;
}