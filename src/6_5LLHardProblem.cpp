#include<bits/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int data1,ListNode* next1){
        val=data1;
        next=next1;
    }
    ListNode(int data1){
        val=data1;
        next=nullptr;
    }
};


ListNode* arr2LL(vector<int> &arr){
    ListNode* head=new ListNode(arr[0]);
    ListNode* mover=head;
    for(int i=1;i<arr.size();i++){
        ListNode* temp=new ListNode(arr[i]);
        mover->next=temp;
        mover=temp;//or mover=mover->next;
    }
    return head;
}

void printLL(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

//this solution is not optimal as i am using recursive reverse functio.
//if i use iterative reverse function it gets optimal.
//iterative reverse function is using only one extra space and idea is like swap.
ListNode* reverse(ListNode* head){
    if(head==NULL ||head->next==NULL) return head;
    ListNode* newhead=reverse(head->next);
    ListNode* front=head->next;

    front->next=head;
    head->next=NULL;

    return newhead;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    if(k==1) return head;
    ListNode* temp=head;
    ListNode* k_cnt=head;
    ListNode* prev=temp;
    int cnt=1;
    while(k_cnt!=NULL){
        if(cnt==k){
            //broken in k group and reverse
            ListNode* front=k_cnt->next;
            k_cnt->next=nullptr;
            k_cnt=reverse(temp);
            if(prev!=head){
                prev->next=k_cnt;
            }
            //now attach the reverse part to the LL
            if(temp==head){
                head=k_cnt;
            }
            k_cnt=front;
            temp->next=k_cnt;
            prev=temp;
            temp=temp->next;
            cnt=1;
        }
        else{
            k_cnt=k_cnt->next;
            cnt++;
        }
    }
    return head;
}


ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL || head->next==NULL) return head;
    ListNode* tail=head;
    int n=1;
    while(tail!=NULL && tail->next!=NULL){
        tail=tail->next;
        n++;
    }
    tail->next=head;
    k=k%n;
    ListNode* prev=head;
    ListNode* temp=head;
    for(int i=0;i<n-k;i++){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    return temp;
}


//watch striver video to understand the question ->
//we are using recursion as well as a merge function to get ans.
struct Node{
    int data;
    Node* next;
    Node* child;

    Node(int data1,Node* next1,Node* child1){
        data=data1;
        next=next1;
        child=child1;   
    }

    Node(int data1){
        data=data1;
        next=nullptr;
        child=nullptr;
    }
};
Node* mergeflatLL(Node* t1,Node* t2){
    Node* dummy=new Node(-1);
    Node* temp=dummy;
    while(t1->child!=NULL && t2->child!=NULL){
        if(t1->data<t2->data){
            temp->child=t1;
            t1=t1->child;
            temp=temp->child;
        }
        else{
            temp->child=t2;
            t2=t2->child;
            temp=temp->child;
        }
        temp->next=NULL;
    }
    while(t1!=NULL){
        temp->child=t1;
        t1=t1->child;
        temp=temp->child;
        temp->next=NULL;
    }
    while(t2!=NULL){
        temp->child=t2;
        t2=t2->child;
        temp=temp->child;
        temp->next=NULL;
    }

    return dummy->child;
}
Node* flattenLL(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* mergehead=flattenLL(head->next);
    Node* newhead=mergeflatLL(head,mergehead);

    return newhead;
}
void printflattenLL(Node* head){

    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->child;
    }
}




//leetcode 138-> really long to type and write as it uses different type of struct node.


int main(){

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode* head = arr2LL(arr);
    cout << "Original Linked List:\n";
    printLL(head);
    int k = 3;
    head = reverseKGroup(head, k);
    cout << "After reversing in groups of " << k << ":\n";
    printLL(head);
    cout<<endl;

    vector<int> arr2 = {1, 2, 3, 4, 5};
    ListNode* head2 = arr2LL(arr2);
    cout << "Original Linked List:\n";
    printLL(head2);
    int k2 = 2;
    head2 = rotateRight(head2, k2);
    cout << "After rotating right by " << k2 << " positions:\n";
    printLL(head2);
    cout<<endl;



    //creating question LL for flattening que.->
    //looks like this->
    //   1 -> 4 -> 3 -> X
    //   |    |    |
    //   2    5    6     //2,5,6 all next pointing to NULL
    //   |    |    |
    //   X    X    7
    //             |
    //             X
    
    //given -> the LL is vertically sorted.
    Node* heady=new Node(1);
    heady->child=new Node(2);
    Node* heady1=new Node(4);
    heady1->child=new Node(5);
    heady->next=heady1;
    Node* heady2=new Node(3);
    Node* midh2=new Node(6);
    heady2->child=midh2;
    midh2->child=new Node(7);
    heady1->next=heady2;
    heady=flattenLL(heady);
    printflattenLL(heady);
    cout<<endl;







    return 0;
}