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

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* delalloccuranceofK(Node* head,int K){
    Node* temp=head;

    while(temp!=NULL){
        if(temp->data==K){
            if(temp==head){
                head=head->next;
            }
            Node* nextnode=temp->next;
            Node* prevnode=temp->back;

            if(nextnode){
                nextnode->back=prevnode;
            }
            if(prevnode){
                prevnode->next=nextnode;
            }
            delete temp;
            temp=nextnode;
        }
    
        else{
            temp=temp->next;
        }
    }
    return head;
}

//find pairs with given sum in sorted LL.
vector<pair<int,int>> findpairsum(Node* head,int sum){
    //optimal->
    //we will implement BS in DLL
    Node* left=head;
    //taking right to end of list;
    Node* right=head;
    //see the condition of ewhile carefully..
    while(right->next!=NULL){
        right=right->next;
    }
    vector<pair<int,int>> ans;
    while(right->data>left->data){
        int cur_sum=left->data+right->data;
        if(cur_sum>sum){
            right=right->back;
        }
        else if(cur_sum==sum){
            ans.push_back({left->data,right->data});
            left=left->next;
            right=right->back;
        }
        else{
            left=left->next;
        }
    }
    return ans;


    // //bruteforce-> TC-O(n^2)  
    // //we can find all pairs by using two while loops.
    // vector<pair<int,int>> ans;
    // Node* temp1=head;
    // Node* temp2=head;
    // while(temp1!=NULL){
    //     temp2=temp1->next;
    //     while(temp2!=NULL && (temp1->data+temp2->data)<=sum){
    //         if(temp1->data+temp2->data==sum){
    //             ans.push_back({temp1->data,temp2->data});
    //         }
    //         temp2=temp2->next;
    //     }
    //     temp1=temp1->next;
    // }
    // return ans;
}

Node* removeduplicatesinSortedDLL(Node* head){
    //TC-O(N)  SC-O(1)
    if(head == NULL) return NULL;

    Node* prev=head;
    Node* temp=head->next;

    while(temp!=NULL){
        while(temp!=NULL && temp->data==prev->data){
            Node* del=temp;
            temp=temp->next;
            delete del;
        }
        prev->next=temp;
        if(temp!=NULL){
            prev=prev->next;
            temp->back=prev;
            temp=temp->next;
        }
    }
    return head;
}



//Implimanting LRU using DLL--> this is different than other DLL que.
//it has easy DLL logic but idea of implementing using DLL and map is unique.
//watch video to get complete idea.
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


//also see leetcode 460 lfu cache.


int main(){


    vector<int> arr = {1, 2, 3, 2, 4, 2, 5, 2};
    Node* head = arraytoDL(arr);
    cout << "Original Doubly Linked List: ";
    print(head);
    cout << endl;
    int K = 2;
    head = delalloccuranceofK(head, K);
    cout << "After deleting all occurrences of " << K << ": ";
    print(head);
    cout << endl;
    cout << endl;



    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node* head2 = arraytoDL(arr2);
    cout << "Doubly Linked List: ";
    print(head2);
    cout << endl;
    int sum = 10;
    vector<pair<int, int>> ans = findpairsum(head2, sum);
    cout << "Pairs with sum " << sum << ":\n";
    for (auto it : ans) {
        cout << "(" << it.first << ", " << it.second << ")" << endl;
    }
    cout << endl;


    vector<int> arr3 = {1, 1, 2, 2, 2, 3, 4, 4, 5, 5, 6};
    Node* head3 = arraytoDL(arr3);
    cout << "Original Doubly Linked List: ";
    print(head3);
    cout << endl;
    head3 = removeduplicatesinSortedDLL(head3);
    cout << "After Removing Duplicates: ";
    print(head3);
    cout << endl;
    cout<<endl;



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



    return 0;

}