#include<bits/stdc++.h>
using namespace std;

//IMP cpp also has predefined SLL and DLL
// SLL-->
//#include<forword_list>
//forword_list<int> l={10,20,30,40};
//l.emplace_front(5);
// auto it = l.begin();
// l.insert_after(it, 15);
// reverse,sort,pop back,pop front,remove,merge and many more
//l.unique()-Removes consecutive duplicate elements.

// DLL-->
// #include<list>  
// list<int> l;
// l.push_back(10);     // insert at end
// l.push_front(5);     // insert at beginning
// l.pop_back();        // delete from end
// l.pop_front();       // delete from beginning




//defining struct.with struct you dont get oop
struct Node{//can also use class Node{} to use oop concept with LL.
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    //having multiple constructor for one with next and one with null
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* convertarr2LL(vector<int> &arr){
    Node*head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;//or mover=mover->next;
    }
    return head;
}

int checkinLL(Node* head,int val){
    Node* temp=head;
    while(temp){
        if(temp->data==val)return 1;
        temp=temp->next;
    }
    return 0;
}

Node* deleteHead(Node* head){
    if(head==NULL)return head;
    Node* temp=head;
    head=head->next;
    delete temp;//can also use free(temp)
    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;

    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;

    // return head;//return head in normal cases
    return temp;//returning the tail location to varify
}

Node* deleteKnode(Node* head,int k){
    if(head==NULL) return head;

    //if k is first node->
    if(k==1){
        Node* temp=head;
        head=head->next;
        free(temp);//can use free instead of delete
        return head;
    }

    //if k is not head->
    int count=0;
    Node* temp=head;
    Node* previous=NULL;
    while(temp!=NULL){
        count++;
        if(count==k){
            previous->next=previous->next->next;//can also use temp->next
            free(temp);
            break;
        }
        previous=temp;
        temp=temp->next;
    }
    return head;
}

Node* deleteelementbyvalue(Node* head,int val){
    if(head==NULL) return head;

    //if k is first node->
    if(head->data==val){
        Node* temp=head;
        head=head->next;
        free(temp);//can use free instead of delete
        return head;
    }

    //if k is not head->
    Node* temp=head;
    Node* previous=NULL;
    while(temp!=NULL){
        if(temp->data==val){
            previous->next=previous->next->next;//can also use temp->next
            free(temp);
            break;
        }
        previous=temp;
        temp=temp->next;
    }
    return head;
}

Node* Insertatstart(Node* head,int val){
    Node* temp=new Node(val,head);
    return temp;//temp becomes new head
}

Node* Insertatlast(Node* head,int val){
    if(head==NULL){
        return new Node(val);
    }
    
    Node*temp=head;
    Node* last=new Node(val);//creating new node
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=last;
    return head;
}

Node* InsertatK(Node* head,int val,int k){
    if(head==NULL){
        if(k==1){
            return new Node(val);
        }
        else{
            return head;
        }
    }
    if(k==1){
        return new Node(val,head);
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==(k-1)){
            Node* x=new Node(val,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* insertbeforeval(Node* head,int val,int el){
    if(head==NULL) return NULL;
    
    //if enter before head
    if(head->data==val){
        return new Node(el,head);
    }
    
    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==val){
            Node* x=new Node(el,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;

}


//1D Linked List->
int main(){
    // int x=2;
    // int* y=&x;//y is the pointer of x
    // cout<<y;
    

    // //Methods to declare
    // vector<int> arr={2,5,8,7};
    // Node* y=new Node(arr[0],nullptr);
    // cout<<y<<endl;//gives location of 2 in LL.
    // cout<<y->data<<endl;
    // cout<<y->next;//gives zero as it is pointing to null pointer.
    // //can also define like Node y=Node(arr[0],nullptr);-> 
    // //this create a object not a pointer we use y.data and y.next to get data and next location respectively.

    //converting array to LL->
    vector<int> arr={2,7,4,6};
    Node* head=convertarr2LL(arr);
    cout<<head->data<<endl;
    //Trversal in LL->
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

    // search in LL->
    cout<<checkinLL(head,2)<<endl;

    
    //Delete Head->
    // head=deleteHead(head);
    // cout<<head->data;


    // //Delete tail->
    // Node* tail=deleteTail(head);
    // cout<<tail->data;


    // //deleting K th number of element
    // head=deleteKnode(head,2);
    // Node* temp1=head;
    // while(temp1){
    //     cout<<temp1->data<<" ";
    //     temp1=temp1->next;
    // }
    // cout<<endl;


    // //delete element->
    // head=deleteelementbyvalue(head,7);
    // Node* temp1=head;
    // while(temp1){
    //     cout<<temp1->data<<" ";
    //     temp1=temp1->next;
    // }
    // cout<<endl;
    

    // // insert at start of LL->
    // head=Insertatstart(head,100);
    // cout<<head->data;


    // // insert at last->
    // head=Insertatlast(head,100);
    // Node* temp2=head;
    // while(temp2){
    //     cout<<temp2->data<<" ";
    //     temp2=temp2->next;
    // }
    // cout<<endl;


    // // insert at K place->
    // head=InsertatK(head,100,4);
    // Node* temp3=head;
    // while(temp3){
    //     cout<<temp3->data<<" ";
    //     temp3=temp3->next;
    // }
    // cout<<endl;


    //insert the element before the value in LL->
    // head=insertbeforeval(head,6,99);
    // Node* temp4=head;
    // while(temp4){
    //     cout<<temp4->data<<" ";
    //     temp4=temp4->next;
    // }
    // cout<<endl;



    // return 0; this is not mandatory.
}