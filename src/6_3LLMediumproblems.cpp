#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* arrayToLL(vector<int> &arr){
    ListNode*head=new ListNode(arr[0]);
    ListNode* mover=head;
    for(int i=1;i<arr.size();i++){
        ListNode* temp=new ListNode(arr[i]);
        mover->next=temp;
        mover=temp;//or mover=mover->next;
    }
    return head;
}


//leetcode 876 ->
//TortoiseHare Methode->
//ek slow aur ek fast node chala na hai.
ListNode* middleNode(ListNode* head) {
    ListNode* slow=head;
    ListNode* fast=head;
    if(head->next==NULL) return head;
    if(head->next->next==NULL) return head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
//har bar fast 2 step chlega aur slow 1 step
//fast pointer har bar odd node pai jayega.
//even length ke liye fast NULL pai jayega
//odd length mai fast last node tak jayega


//leetcode 206->
ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return  head;
    }
    ListNode* newhead=reverseList(head->next);
    ListNode* front=head->next;//front is current tail of reverse.//diagram ke bina nahi samje ga.
    //dry run the code to understand.
    
    front->next=head;
    head->next=NULL;

    return newhead;


//Optimal->
//         ListNode* temp=head;
//         ListNode* prev=NULL;
//         ListNode* front=head;

//         while(temp!=NULL){
//             front=temp->next;
//             temp->next=prev;
//             prev=temp;
//             temp=front;
//         }
//         return prev;


//better-> TC->O(n)  SC->O(n)
//         ListNode* temp=head;
//         stack<int> st;

//         while(temp!=NULL){
//             st.push(temp->val);
//             temp=temp->next;
//         }

//         ListNode* temp2=head;
//         while(temp2!=NULL){
//             temp2->val=st.top();
//             st.pop();
//             temp2=temp2->next;
//         }
//         return head;
}


//leetcode 141->
//optimal solution->
//tortoise and hare algorithm-> one slow pointer one fast pointer.
//if slow and fast meet then there is a loop
bool hasCycle(ListNode *head) {
    ListNode* fast=head;
    ListNode* slow=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast) return true;
    }

    return false;

//Brute Force->
//         //store the node in map not the value
//         map<ListNode*,int> mpp;
//         ListNode* temp=head;
//         while(temp!=NULL){
//             if(mpp.find(temp)!=mpp.end()) return true;
//             mpp[temp]=1;
//             temp=temp->next;
//         }
//         return false;
}


//optimal-> using tortoise and hare algorithm.
//leetcode->142
//watch video to understand. the appoarch
//very different appoarch.
ListNode *detectCycle(ListNode *head) {
    ListNode* slow=head;
    ListNode* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;//this is the starting point of loop.
        }
    }
    return NULL;

//better solution using hashmap->
//         ListNode* temp=head;
//         unordered_map<ListNode*,int> mpp;

//         while(temp!=NULL){
//             if(mpp.find(temp)!=mpp.end()){
//                 return temp;
//             }
//             mpp[temp]=1;
//             temp=temp->next;
//         }
//         return NULL;
}


//similar logic as last que.
int lengthofloopinLL(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            int len=1;
            fast=fast->next;
            //keep one pointer fixed and move the other one around the loop.
            while(fast!=slow){
                len++;
                fast=fast->next;
            }
            return len;
        }
    }
    return 0;



    // //BruteForce-> using map
    // map<ListNode*,int> mpp;
    // ListNode* temp=head;
    // int timer=1;
    // while(temp!=NULL){
    //     if(mpp.find(temp)!=mpp.end()){
    //         int value=mpp[temp];
    //         return (timer-value);
    //     }
    //     mpp[temp]=timer;
    //     timer++;
    //     temp=temp->next;
    // }
    // return 0;

}


//leetcode 234
ListNode* reverse(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    ListNode* newhead=reverse(head->next);
    ListNode* front=head->next;
    front->next=head;
    head->next=NULL;
    return newhead;
}
bool isPalindrome(ListNode* head) {
    //optimal->
    //solved in three parts->
    //1.find the middle
    //2.reverse the part after middle and return right part head.
    //3.compare the normal first half and reversed second half
    //in the end reverse the second part again.
    if(head->next == NULL) return true;
    //step1->
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    //step 2->
    ListNode* newhead=reverse(slow->next);
    ListNode* first=head;
    ListNode* second=newhead;
    //step 3->
    while(second!=NULL){
        if(first->val!=second->val){
            reverse(newhead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverse(newhead);
    return true;


    // //BruteForce -> using stack
    // ListNode* temp=head;
    // stack<int> st;
    // while(temp!=NULL){
    //     st.push(temp->val);
    //     temp=temp->next;
    // }

    // temp=head;

    // while(temp!=NULL){
    //     if(temp->val!=st.top()){
    //         return false;
    //     }
    //     temp=temp->next;
    //     st.pop();
    // }
    // return true;
}


ListNode* oddEvenList(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;

    ListNode* backhead=head->next;

    ListNode* odd=head;
    ListNode* even=backhead;
    ListNode* prev=odd;
    while(odd!=NULL && even!=NULL){
        if(odd->next==NULL || even->next==NULL){
            break;
        }
        odd->next=odd->next->next;
        prev=odd;
        odd=odd->next;
        even->next=even->next->next;
        even=even->next;
    }
    if(odd==NULL){
        prev->next=backhead;
        even->next=NULL;
        return head;
    }
    odd->next=backhead;
    return head;
    

    //nicley return eay to understand->
    // if (head == NULL || head->next == NULL)
    //     return head;

    // ListNode* odd = head;
    // ListNode* even = head->next;
    // ListNode* evenHead = even;

    // while (even != NULL && even->next != NULL) {
    //     odd->next = even->next;
    //     odd = odd->next;

    //     even->next = odd->next;
    //     even = even->next;
    // }

    // odd->next = evenHead;

    // return head;

}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast=head;
    ListNode* slow=head;

    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    if(fast==NULL){
        return head->next;
    }
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    ListNode* del=slow->next;
    slow->next=slow->next->next;
    del->next=nullptr;
    delete del;

    return head;

}

//using tortoise and hare
ListNode* deleteMiddle(ListNode* head) {
    if(head->next==NULL || head==NULL) return NULL;

    ListNode* prevSlow=NULL;
    ListNode* slow=head;
    ListNode* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        prevSlow=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prevSlow->next=slow->next;
    delete(slow);

    return head;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head;

    if(list1==NULL) return list2;
    if(list2==NULL) return list1;

    if(list1->val<=list2->val){
        head=list1;
        list1=list1->next;
    }
    else{
        head=list2;
        list2=list2->next;
    }

    ListNode* temp=head;
    while(list1!=NULL && list2!=NULL){
        if(list1->val<=list2->val){
            temp->next=list1;
            list1=list1->next;
            temp=temp->next;
        }
        else{
            temp->next=list2;
            list2=list2->next;
            temp=temp->next;
        }
    }

    while(list2!=NULL){
        temp->next=list2;
        list2=list2->next;
        temp=temp->next;
    }

    while(list1!=NULL){
        temp->next=list1;
        list1=list1->next;
        temp=temp->next;
    }

    return head;
}

//implementing Merge sort in LL->
ListNode* Middle(ListNode* head){
    ListNode* slow=head;
    //IMP
    ListNode* fast=head->next;//use this to find the correct middle node->The node before the middle to sort..
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* merge(ListNode* list1,ListNode* list2){
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
    ListNode* head;
    if(list1->val<list2->val){
        head=list1;
        list1=list1->next;
    }
    else{
        head=list2;
        list2=list2->next;
    }
    ListNode* temp=head;
    while(list1!=NULL && list2!=NULL){
        if(list1->val<list2->val){
            temp->next=list1;
            list1=list1->next;
            temp=temp->next;
        }
        else{
            temp->next=list2;
            list2=list2->next;
            temp=temp->next;
        }
    }
    while(list1!=NULL){
        temp->next=list1;
        list1=list1->next;
        temp=temp->next;
    }
    while(list2!=NULL){
        temp->next=list2;
        list2=list2->next;
        temp=temp->next;
    }
    return head;
}
ListNode* MergeSort(ListNode* head){    
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode* middle=Middle(head);
    //breaking in two parts
    ListNode* lefthead=head;
    ListNode* righthead=middle->next;
    middle->next=NULL;
    lefthead=MergeSort(lefthead);
    righthead=MergeSort(righthead);
    //merging two parts
    return merge(lefthead,righthead);
}
ListNode* sortList(ListNode* head) {
    
    return MergeSort(head);
}


ListNode* sortLLof1_2_3(ListNode* head){
    //Optimal apporach-> using 3 dummy nodes
    if(head==NULL || head->next==NULL){
        return head;
    }
    //make 3 dummy Nodes->
    ListNode* zerohead=new ListNode(-1);
    ListNode* onehead=new ListNode(-1);
    ListNode* twohead=new ListNode(-1);

    ListNode* zero=zerohead;
    ListNode* one=onehead;
    ListNode* two=twohead;

    ListNode* temp=head;

    while(temp!=NULL){
        if(temp->val==0){
            zero->next=temp;
            zero=zero->next; //or zero=temp
        }
        else if(temp->val==1){
            one->next=temp;
            one=one->next;  //or one=temp
        }
        else{
            two->next=temp;
            two=two->next;  //or two=temp
        }
        temp=temp->next;
    }
    zero->next=(onehead->next)? onehead->next : twohead->next;
    one->next=twohead->next;
    two->next=NULL;

    ListNode* newhead=zerohead->next;

    delete(zerohead);
    delete(onehead);
    delete(twohead);

    return newhead;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //Optimal Solution-> watch video to understand better.
    //har ek node t1 or t2 dono LL traversal karega to vo head change ke baad parallel a jayega.
    if(headA==NULL || headB==NULL) return NULL;
    ListNode* temp1=headA;
    ListNode* temp2=headB;

    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;

        if(temp1==temp2) return temp1;
        if(temp1==NULL) temp1=headB;
        if(temp2==NULL) temp2=headA;
    }

    return temp1;


    //Better solution-> dono ko length nikal lenge traversal kar ke.
    //fir dono ko equal distance from interction rakh denge.
    //matlab longer ll lo age bade ge
    //themn dono ko sath mai start kare ge
    //jab dono milega to vo hamara interstion hoga.


    //Brute force->
    // map<ListNode*,int> mpp;
    // ListNode* temp=headA;
    // while(temp!=NULL){
    //     mpp[temp]=1;
    //     temp=temp->next;
    // }
    // ListNode* temp2=headB;
    // while(temp2!=NULL){
    //     if(mpp.find(temp2)!=mpp.end()){
    //         return temp2;
    //     }
    //     temp2=temp2->next;
    // }
    // return NULL;
}


//add 1 to a number represented by linkedlist
int helper(ListNode* temp){
    if(temp==NULL){
        return 1;
    }
    int carry=helper(temp->next);
    temp->val=temp->val+carry;
    if(temp->val<10){
        return 0;
    }
    temp->val=0;
    return 1;
}
ListNode* add1toLL(ListNode* head){
    //Recursive solution-> TC-O(N) SC->O(N)
    ListNode* temp=head;
    int carry=helper(temp);
    if(carry==1){
        ListNode* newhead=new ListNode(1,head);
        return newhead;
    }
    return head;


    // //idea is to reverse the link list and go on adding.
    // // Iterative-> TC-O(3N)  SC-O(1)
    // head=reverseList(head);
    // ListNode* temp=head;
    // int carry=1;
    // while(temp!=NULL){
    //     temp->val=temp->val+carry;
    //     if(temp->val<10){
    //         carry=0;
    //         break;
    //     }
    //     else{
    //         temp->val=0;
    //         carry=1;
    //     }
    //     temp=temp->next;
    // }
    // if(carry==1){
    //     ListNode* newhead=new ListNode(1);
    //     head=reverseList(head);
    //     newhead->next=head;
    //     return newhead;
        
    // }
    // head=reverseList(head);
    // return head;



}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //TC-O(max(N, M))
    ListNode* dummy=new ListNode();
    ListNode* temp=dummy;
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry){
        int sum=0;
        if(l1!=NULL){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        ListNode* node=new ListNode(sum%10);
        temp->next=node;
        temp=temp->next;    
    }
    return dummy->next;
}


//leetcode 82 check the question must do.



void printLL(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}




int main(){
    vector<int> arr1 = {1, 2, 3, 4, 5};
    ListNode* head1 = arrayToLL(arr1);
    cout << "Linked List: ";
    printLL(head1);
    ListNode* mid = middleNode(head1);
    cout << "Middle Node: " << mid->val << endl;
    cout<<endl;


    vector<int> arr2 = {1, 2, 3, 4, 5};
    ListNode* head2 = arrayToLL(arr2);
    cout << "Original List: ";
    printLL(head2);
    head2 = reverseList(head2);
    cout << "Reversed List: ";
    printLL(head2);
    cout<<endl;


    vector<int> arr3 = {1, 2, 3, 4, 5};
    ListNode* head3 = arrayToLL(arr3);
    // Create a cycle: last node points to the node with value 3
    ListNode* tail = head3;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = head3->next->next;   // 5 -> 3
    if (hasCycle(head3)) cout << "Cycle Detected" << endl;
    else cout << "No Cycle" << endl;
    cout<<endl;


    vector<int> arr4 = {1, 2, 3, 4, 5};
    ListNode* head4 = arrayToLL(arr4);
    // Create a cycle: last node points to the node with value 3
    ListNode* tail2 = head4;
    while (tail2->next != nullptr) {
        tail2 = tail2->next;
    }
    tail2->next = head4->next->next;   // 5 -> 3
    ListNode* startNode = detectCycle(head4);
    if (startNode != nullptr) cout << "Cycle starts at node with value: " << startNode->val << endl;
    else cout << "No Cycle" << endl;
    cout<<endl;

 
    vector<int> arr = {3, 2, 0, -4};
    ListNode* head = arrayToLL(arr);
    // Create a cycle:
    // Tail -> node with value 2 (index 1)
    ListNode* tail3 = head;
    while (tail3->next != NULL) {
        tail3 = tail3->next;
    }
    ListNode* cycleNode = head->next;   // Node with value 2
    tail3->next = cycleNode;
    cout << "Length of Loop = " << lengthofloopinLL(head) << endl;
    cout<<endl;



    vector<int> arr5 = {1, 2, 3, 2, 1};
    // Convert array to linked list
    ListNode* head5 = arrayToLL(arr5);
    cout << "Original Linked List: ";
    printLL(head5);
    if (isPalindrome(head5)) cout << "The linked list is a Palindrome." << endl;
    else cout << "The linked list is NOT a Palindrome." << endl;
    cout << "Linked List after function call: ";
    printLL(head5);
    cout<<endl;


    vector<int> arr6 = {1, 2, 3, 4, 5, 6};
    // Convert array to linked list
    ListNode* head6 = arrayToLL(arr6);
    cout << "Original Linked List: ";
    printLL(head6);
    head6 = oddEvenList(head6);
    cout << "After Odd-Even Rearrangement: ";
    printLL(head6);
    cout<<endl;


    vector<int> arr7 = {1, 2, 3, 4, 5};
    // Convert array to linked list
    ListNode* head7 = arrayToLL(arr7);
    cout << "Original Linked List: ";
    printLL(head7);
    int n = 2;
    head7 = removeNthFromEnd(head7, n);
    cout << "After removing " << n << "th node from the end: ";
    printLL(head7);
    cout<<endl;


    vector<int> arr8 = {1, 2, 3, 4, 5};
    // Convert array to linked list
    ListNode* head8 = arrayToLL(arr8);
    cout << "Original Linked List: ";
    printLL(head8);
    head8 = deleteMiddle(head8);
    cout << "After deleting the middle node: ";
    printLL(head8);
    cout<<endl;


    vector<int> arr9 = {1, 2, 4};
    vector<int> arr10 = {1, 3, 4};
    // Convert arrays to linked lists
    ListNode* head9 = arrayToLL(arr9);
    ListNode* head10 = arrayToLL(arr10);
    cout << "List 1: ";
    printLL(head9);
    cout << "List 2: ";
    printLL(head10);
    ListNode* mergedHead = mergeTwoLists(head9, head10);
    cout << "Merged Linked List: ";
    printLL(mergedHead);
    cout<<endl;



    vector<int> arr11 = {4, 2, 1, 3, 5};
    // Convert array to linked list
    ListNode* head11 = arrayToLL(arr11);
    cout << "Original Linked List: ";
    printLL(head11);
    head11 = sortList(head11);
    cout << "Sorted Linked List: ";
    printLL(head11);
    cout<<endl;



    vector<int> arr12 = {1, 0, 2, 1, 0, 2, 1, 0};
    // Convert array to linked list
    ListNode* head12 = arrayToLL(arr12);
    cout << "Original Linked List: ";
    printLL(head12);
    head12 = sortLLof1_2_3(head12);
    cout << "Sorted Linked List: ";
    printLL(head12);
    cout<<endl;



    vector<int> arrA = {4, 1};
    vector<int> arrB = {5, 6, 1};
    vector<int> commonArr = {8, 4, 5};
    // Common part (intersection)
    ListNode* common = arrayToLL(commonArr);
    // List A
    ListNode* headA = arrayToLL(arrA);
    ListNode* temp = headA;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = common;
    // List B
    ListNode* headB = arrayToLL(arrB);
    temp = headB;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = common;
    cout << "List A: ";
    printLL(headA);
    cout << "List B: ";
    printLL(headB);
    ListNode* intersection = getIntersectionNode(headA, headB);
    if (intersection != NULL)
        cout << "Intersection Node Value: " << intersection->val << endl;
    else
        cout << "No Intersection Found." << endl;




    vector<int> arr13 = {1, 2, 9};
    // Convert array to linked list
    ListNode* head13 = arrayToLL(arr13);
    cout << "Original Number: ";
    printLL(head13);
    head13 = add1toLL(head13);
    cout << "After Adding 1: ";
    printLL(head13);
    cout<<endl;
   
    
    vector<int> arr14 = {2, 4, 3};
    vector<int> arr15 = {5, 6, 4};
    // Convert arrays to linked lists
    ListNode* head14 = arrayToLL(arr14);
    ListNode* head15 = arrayToLL(arr15);
    cout << "List 1: ";
    printLL(head14);
    cout << "List 2: ";
    printLL(head15);
    ListNode* result = addTwoNumbers(head14, head15);
    cout << "Sum: ";
    printLL(result);





    return 0;
}