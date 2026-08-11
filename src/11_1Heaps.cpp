#include<bits/stdc++.h>
using namespace std;

//Heap or priority queue-->
//A Priority Queue is a special type of queue where each element is assigned a priority, 
//and instead of being processed in the order they arrive (like a normal queue), 
//the element with the highest priority is always processed first.
//If two elements have the same priority, they are handled based on their insertion order.

// https://takeuforward.org/data-structure/introduction-to-priority-queues-using-binary-heaps

//in this link there is no mention of left being smaller than right...



class BinaryHeap{
    public:
    int capacity; //max element that can be stored.
    int size=0; //curent number of elements in heap.
    //creating dynamic array 
    int* arr;

    BinaryHeap(int cap){
        capacity=cap;
        size=0;
        arr=new int[capacity];
    }

    //return parent of the node 
    int parent(int i){
        return (i-1)/2;
    }

    //return left child 
    int left(int i){
        return  2*i+1;
    }

    //return right child
    int right(int i){
        return 2*i+2;
    }

    //TC-O(logN)
    void Insert(int x){
        if(size==capacity){
            cout<<"Binary Heap Overflow"<<endl;
            return;
        }
        arr[size]=x;
        int k=size;
        size++;

        //fix the min heap property
        while(k!=0 && arr[parent(k)]>arr[k]){
            swap(&arr[parent(k)],&arr[k]);
            k=parent(k);
        }
    }

    //TC-O(logN)
    void Heapify(int ind){
        int ri=right(ind);
        int li=left(ind);
        int smallest=ind;


        if(li<size && arr[li]<arr[smallest]) smallest=li;
        if(ri<size && arr[ri]<arr[smallest]) smallest=ri;

        //if the minimum among the three nodes is not parent itself,
        //then swap and call heapify recursively
        if(smallest!=ind){
            swap(&arr[ind],&arr[smallest]);
            Heapify(smallest);
        }
    }

    //TC-O(1)
    int getMin(){
        return arr[0];
    }

    //TC-O(logN)
    int ExtractMin(){
        if(size<=0) return INT_MAX;

        if(size==1){
            size--;
            return arr[0];
        }

        int mini=arr[0];
        //copy last node value to root node
        arr[0]=arr[size];
        size--;
        //call heapify on root node
        Heapify(0);

        return mini;
    }

    //TC-O(logN)
    void Decreasekey(int i,int val){
        //updating new value.
        arr[i]=val;

        //fixing min heap
        while(i!=0 && arr[parent(i)]>arr[i]){
            swap(&arr[parent(i)],&arr[i]);
            i=parent(i);
        }
    }

    //TC-O(logN)
    void Delete(int i){
        Decreasekey(i,INT_MIN);
        ExtractMin();
    }

    void swap(int *x,int *y){
        int temp=*x;
        *x=*y;
        *y=temp;
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};


//check if the array represents binary heap
class Solution {
public:
    // Function to check if the given array is a min-heap
    bool isMinHeap(vector<int>& nums) {
        int n = nums.size();
        // Iterate through all non-leaf nodes
        for (int i = 0; i <= (n / 2) - 1; i++) {
            // Calculate the left child index
            int left = 2 * i + 1;
            // If left child exists and is smaller than parent, not a min-heap
            if (left < n && nums[i] > nums[left]) {
                return false;
            }
            // Calculate the right child index
            int right = 2 * i + 2;
            // If right child exists and is smaller than parent, not a min-heap
            if (right < n && nums[i] > nums[right]) {
                return false;
            }
        }
        // If no violations found, it is a min-heap
        return true;
    }
};


//convert min heap to max heap..
void Heapify(vector<int>&arr,int n,int i){
    int largest=i;
    int li=2*i+1;
    int ri=2*i+2;

    if(li<n && arr[li]>arr[largest]) largest=li;
    if(ri<n && arr[ri]>arr[largest]) largest=ri;
    //if the minimum among the three nodes is not parent itself,
    //then swap and call heapify recursively
    if(largest!=i){
        swap(arr[i],arr[largest]);
        Heapify(arr,n,largest);
    }
}
void convertMinToMaxHeap(vector<int>&arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        Heapify(arr,n,i);
    }

}




int main(){

    BinaryHeap h(20);
    h.Insert(4);
    h.Insert(1);
    h.Insert(2);
    h.Insert(6);
    h.Insert(7);
    h.Insert(3);
    h.Insert(8);
    h.Insert(5);
    cout << "Min value is " << h.getMin() << endl;
    h.Insert(-1);
    cout << "Min value is " << h.getMin() << endl;
    h.Decreasekey(3, -2);
    cout << "Min value is " << h.getMin() << endl;
    h.ExtractMin();
    cout << "Min value is " << h.getMin() << endl;
    h.Delete(0);
    cout << "Min value is " << h.getMin() << endl;
    cout<<endl;
    
    Solution obj;
    vector<int> nums = {10, 20, 30, 21, 23};
    // Output result
    cout << (obj.isMinHeap(nums) ? "true" : "false") << endl;
    cout<<endl;
    

    vector<int> heapData = {1, 3, 5, 7, 9, 8, 10};
    cout << "Min Heap (Array): ";
    for (int value : heapData)
        cout << value << " ";
    cout << "\n";
    convertMinToMaxHeap(heapData);
    cout << "Max Heap (Array): ";
    for (int value : heapData)
        cout << value << " ";
    cout << "\n";



    return 0;

}