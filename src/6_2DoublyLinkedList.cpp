#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};


Node* arraytoDL(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;//storing replica of head

    int n=arr.size();

    for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
        
    }
    return head;
}

Node* DeleteHead(Node* head){
    if(head==NULL ||head->next==NULL){//first condition allways check if head is null then only check for head->next
        return NULL;
    }
    Node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;

    delete prev;

    return head;
}

Node* Deletetail(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }

    Node* temp=head;

    while(temp->next->next!=NULL){//we can directly go to tail as there is allways back available to get back to last 2 node.
        temp=temp->next;
    }
    Node* tail=temp->next;
    // tail->back=nullptr;  //no need for this line as tail is about to be deleted.
    temp->next=nullptr;

    //better->
    // Node* newTail = tail->back;
    // newTail->next = NULL;


    delete tail;


    return head;

}

Node* DeleteKnode(Node* head,int k){
    //if k is head->
    if(head==NULL){
        return head;
    }
    if(k==1){
        if(head->next==NULL){
            return NULL;
        }
        Node* newhead=head->next;
        newhead->back=nullptr;

        head->next=nullptr;
        delete head;

        return newhead;

    }
    Node* temp=head;
    int i=1;
    while(i<k){
        i++;
        temp=temp->next;
    }
    //if k is tail->
    if(temp->next==NULL){
        Node* tail=temp->back;
        tail->next=nullptr;

        temp->back=nullptr;
        delete temp;

        return head;
    }
    //when k is neither head nor tail->
    Node* before=temp->back;
    Node* after=temp->next;

    before->next=after;
    after->back=before;


    temp->next = nullptr;//for good practice.
    temp->back = nullptr;//for good practice.
    delete temp;

    return  head;
}

void DeleteGivenNode(Node* temp){
    //given->Node!=head
    Node* prev=temp->back;
    Node* front=temp->next;

    if(front==NULL){
        prev->next=nullptr;
        temp->back=nullptr;
        free(temp);
        return;
    }
    prev->next=front;
    front->back=prev;

    temp->next=nullptr;
    temp->back=nullptr;
    delete temp;

}

Node* insertbeforehead(Node* head,int value){
    if(head==NULL){
        return new Node(value);
    }
    Node* newhead=new Node(value,head,nullptr);
    head->back=newhead;

    return newhead;
}

Node* insertbeforetail(Node* head,int value){
    Node* temp=head;
    if(head==NULL){
        Node* newhead=new Node(value);
        return newhead;
    }
    if(head->next==NULL){
        Node* newhead=new Node(value,head,nullptr);
        head->back=newhead;

        return newhead;
    }

    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    Node* front=temp;//as temp is currently tail.
    Node* prev=temp->back;

    Node* newNode=new Node(value,front,prev);
    prev->next=newNode;
    front->back=newNode;

    return head;
}

Node* insertbeforeKthnode(Node* head,int k,int value){
    if(k==1){//if k is head
        Node* newhead=new Node(value,head,nullptr);
        head->back=newhead;

        return newhead;
    }

    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newnode=new Node(value,temp,prev);
    prev->next=newnode;
    temp->back=newnode;
    return head;
}

void insertbeforegiveNode(Node* node,int value){
    //givenNode is never head;
    Node* prev=node->back;
    Node* newnode=new Node(value,node,prev);
    node->back=newnode;
    prev->next=newnode;
    
}

Node* reverseDLL(Node* head){
    // //bruteforce-> TC-O(2n) SC-O(n)
    // Node* temp=head;
    // stack<int> st;
    // while(temp!=NULL){
    //     st.push(temp->data);
    //     temp=temp->next;
    // }
    // temp=head;
    // while(temp!=NULL){
    //     temp->data=st.top();
    //     st.pop();
    //     temp=temp->next;
    // }
    // return head;

    //optimal-> one pass solution  TC-O(n) SC-O(1)
    //need to solve next ans back for all elements->
    if(head==NULL||head->next==NULL) return head;
    Node* curr=head;
    Node* last=NULL;

    while(curr!=NULL){
        last=curr->back;
        curr->back=curr->next;
        curr->next=last;
        curr=curr->back;
    }
    Node* newhead=last->back;

    return newhead;

}   


void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}





int main(){

    vector<int> arr = {10, 20, 30, 40, 50};
    Node* head1 = arraytoDL(arr);
    print(head1);
    cout << endl;


    //Delete->
    vector<int> arr2 = {10, 20, 30, 40, 50};
    Node* head2 = arraytoDL(arr2);
    cout << "Original DLL: ";
    print(head2);
    head2 = DeleteHead(head2);
    cout << "After deleting head: ";
    print(head2);
    cout<<endl;


    vector<int> arr3 = {10, 20, 30, 40, 50};
    Node* head = arraytoDL(arr3);
    cout << "Original DLL: ";
    print(head);
    head = Deletetail(head);
    cout << "After deleting tail: ";
    print(head);
    cout<<endl;


    vector<int> arr4 = {10, 20, 30, 40, 50};
    Node* heady = arraytoDL(arr4);
    cout << "Original Doubly Linked List: ";
    print(heady);
    int k;
    heady = DeleteKnode(heady, 2);
    cout << "Doubly Linked List after deletion: ";
    print(heady);
    cout<<endl;


    DeleteGivenNode(heady->next->next);
    print(heady);
    cout<<endl;


    //Insert->
    vector<int> arr5 = {10, 20, 30, 40, 50};
    Node* headl = arraytoDL(arr5);
    cout << "Original DLL: ";
    print(headl);
    cout << endl;

    headl = insertbeforehead(headl, 5);
    cout << "After inserting before head: ";
    print(headl);
    cout << endl;

    headl = insertbeforetail(headl, 45);
    cout << "After inserting before tail: ";
    print(headl);
    cout << endl;

    headl = insertbeforeKthnode(headl, 4, 25);
    cout << "After inserting before 4th node: ";
    print(headl);
    cout << endl;

    Node* temp = headl;
    while (temp != NULL && temp->data != 40) {
        temp = temp->next;
    }
    if (temp != NULL) {
        insertbeforegiveNode(temp, 35);
        cout << "After inserting before node with value 40: ";
        print(headl);
        cout << endl;
    }



    //reverse DLL->
    vector<int> arr6 = {10, 20, 30, 40, 50};
    Node* headu = arraytoDL(arr6);
    cout << "Original DLL: ";
    print(headu);
    cout << endl;

    headu = reverseDLL(headu);

    cout << "Reversed DLL: ";
    print(headu);
    cout << endl;
    return 0;

    
}



