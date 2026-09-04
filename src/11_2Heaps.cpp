#include<bits/stdc++.h>
using namespace std;

//leetcode 215-> IMP very different appoarch for the optimal solution.
//for optimal T.C is O(N) if we select the worst node as the node selection is random.
//so in worst case we will travel all the nodes.
int randomIdx(int &left,int &right){
    int len=right-left+1;
    return(rand()%len)+left;
    //rand is used to get a random number between 0 and len.
}
// K largest element in array-->
int placeatrightindex(int pivotidx,int left,int right,vector<int>&nums){
    //we move all the smaller element to right of the pivot and all the larger element left of pivot.
    // here we are implementing a type of max heap.
    int pivot=nums[pivotidx];
    swap(nums[pivotidx],nums[left]);
    int idx=left+1;
    for(int i=left+1;i<=right;i++){
        if(nums[i]>pivot){
            swap(nums[i],nums[idx]);
            idx++; 
        }
    }
    swap(nums[left],nums[idx-1]);

    return idx-1;
}
int Klargestelement(vector<int>& nums,int K){

    //optimal--> TC-O(N) SC-O(1) also known as pivot selection appoarch
    int n=nums.size();
    if(K>n) return -1;
    int left=0;
    int right=n-1;

    while(true){
        //pick a pivot
        int pivotidx=randomIdx(left,right);

        //place pivot at correct location
        int index=placeatrightindex(pivotidx,left,right,nums);

        if(index==K-1) return nums[index];

        else if(index>K-1) right=index-1;
        else left=index+1;

    }
    return -1;

    // //better--> TC-O(N*logN) SC-O(K)
    // int n=nums.size();
    // //we will use a min heap-->
    // priority_queue<int,vector<int>,greater<int>>pq;
    // for(int i=0;i<K;i++){
    //     pq.push(nums[i]);
    // }
    // for(int i=K;i<n;i++){
    //     if(nums[i]>pq.top()){
    //         pq.pop();
    //         pq.push(nums[i]);
    //     }
    // }
    // return pq.top();



    // //bruteforce--> TC- O(N*logN+K*logK)  SC-O(N)
    // //by default priority queue is max heap 
    // priority_queue<int> pq;
    // int n=nums.size();
    // for(int i=0;i<n;i++){
    //     pq.push(nums[i]);
    // } 
    // for(int j=1;j<K;j++){
    //     pq.pop();
    // }
    // return pq.top();

}


// K smallest element in array-->
int placeatrightindex2(int pivotidx,int left,int right,vector<int>&nums){
    //we move all the smaller element to left of the pivot and all the larger element right of pivot.
    // here we are implementing a type of max heap.
    int pivot=nums[pivotidx];
    swap(nums[pivotidx],nums[left]);
    int idx=left+1;
    for(int i=left+1;i<=right;i++){
        if(nums[i]<pivot){
            swap(nums[i],nums[idx]);
            idx++; 
        }
    }
    swap(nums[left],nums[idx-1]);

    return idx-1;
}
int Ksmallestelement(vector<int>& nums,int K){

    //optimal--> TC-O(N) SC-O(1) 
    int n=nums.size();
    if(K>n) return -1;
    int left=0;
    int right=n-1;

    while(true){
        //pick a pivot
        int pivotidx=randomIdx(left,right);

        //place pivot at correct location
        int index=placeatrightindex2(pivotidx,left,right,nums);

        if(index==K-1) return nums[index];

        else if(index>K-1) right=index-1;
        else left=index+1;

    }
    return -1;


    // //better--> TC-O(N*logN) SC-O(K)
    // int n=nums.size();
    // //we will use a max heap-->
    // priority_queue<int>pq;
    // for(int i=0;i<K;i++){
    //     pq.push(nums[i]);
    // }
    // for(int i=K;i<n;i++){
    //     if(nums[i]<pq.top()){
    //         pq.pop();
    //         pq.push(nums[i]);
    //     }
    // }
    // return pq.top();



    // //bruteforce--> TC- O(N*logN+K*logK)  SC-O(N)
    // //by default priority queue is max heap 
    // //min heap-->
    // priority_queue<int,vector<int>,greater<int>> pq;
    // int n=nums.size();
    // for(int i=0;i<n;i++){
    //     pq.push(nums[i]);
    // } 
    // for(int j=1;j<K;j++){
    //     pq.pop();
    // }
    // return pq.top();

}


//sort the K sorted array-->
//where each element is at max k distance away from its sorted position.
//this means the smallest element in the array must exist somewhere in first K+1 element.
vector<int> sortkarray(vector<int> &arr,int k){
    //optimal-->
    //so instead of sorting we can use min heap to efficiently keep track
    //of the smallest elements in a moving window of size K+1
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> result;
    int n=arr.size();
    for(int i=0;i<=k &&i<arr.size();i++){
        pq.push(arr[i]);
    }
    for(int i=k+1;i<n;i++){
        result.push_back(pq.top());
        pq.pop();
        pq.push(arr[i]);
    }
    while(!pq.empty()){
        result.push_back(pq.top());
        pq.pop();
    }
    return result;


    //bruteforce return the sorted array using sort function.
}


//leetcode 23 IMP..


//replace elements by there ranks->
//return the rank of the element in the sorted array.
vector<int> rankinsorted(vector<int>&arr){
    //Pranav Optimal--> This does not ignore the position of equal elements->
    //we will use a pair priority queue.
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int n=arr.size();
    for(int i=0;i<n;i++){
        pq.push({arr[i],i});
    }
    vector<int> result(n);
    int count=1;
    while(!pq.empty()){
        pair<int,int> front=pq.top();
        result[front.second]=count;
        count++;
        pq.pop();
    }
    return result;



    // //striver optimal-> this solution gives same rank to same element and ignore who comes first.
    // vector<int> sortedarr=arr;
    // sort(sortedarr.begin(),sortedarr.end());
    // unordered_map<int,int> rankMap;
    // int rank=1;
    // for(int num:sortedarr){
    //     //if this number is not already assigned a rank
    //     if(rankMap.find(num)==rankMap.end()){
    //         rankMap[num]=rank;
    //         rank++;
    //     }
    // }
    // vector<int> result;
    // for(int num:arr){
    //     result.push_back(rankMap[num]);
    // }
    // return result;



    //brute force-->
    //use two loop to find number all smaller elements than the current element .

}


//leetcode 621
//TC->O(N)
int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26,0);
    int size=tasks.size();
    for(int i=0;i<size;i++){
        freq[tasks[i]-'A']++;
    }
    priority_queue<int> pq;
    for(int num:freq){
        if(num>0) pq.push(num);
    }
    int result=0;
    while(!pq.empty()){
        vector<int> cur; //used to hold tasks in current cycle.
        for(int j=0;j<n+1;j++){
            if(!pq.empty()){
                int pqtop=pq.top();
                pq.pop();
                pqtop--;
                cur.push_back(pqtop);
            }
        }
        for(int i=0;i<cur.size();i++){
            if(cur[i]>0){
                pq.push(cur[i]);
            }
        }
        if(pq.empty()){
            result+=cur.size();
        }
        else{
            result+=n+1;
        }
    }
    return result;
}



//leetcode 846
bool isNStraightHand(vector<int>& hand, int groupSize) {
    
    // //optimal without heap (Greedy solution)-->
    // sort(hand.begin(), hand.end());
    // unordered_map<int,int> freq;
    // for(int x : hand)
    //     freq[x]++;
    // for(int x : hand){
    //     if(freq[x]==0) continue;
    //     for(int i=0;i<groupSize;i++){
    //         if(freq[x+i]==0) return false;
    //         freq[x+i]--;
    //     }
    // }
    // return true;

    
    //optimal using heap--> TC-O(n log n)   SC-O(n)
    if (hand.size() % groupSize != 0) return false;
    unordered_map<int,int> mpp;
    int n=hand.size();
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        if(mpp.find(hand[i])==mpp.end()) pq.push(hand[i]);
        mpp[hand[i]]++;
    }
    while(!pq.empty()){
        vector<int> temp;
        for(int i=0;i<groupSize;i++){
            if(pq.empty()) return false;
            int front=pq.top();
            if(temp.size()>0 && temp.back()!=front-1) return false;
            pq.pop();
            mpp[front]--;
            temp.push_back(front);
        }
        for(int i=0;i<groupSize;i++){
            if(mpp[temp[i]]!=0) pq.push(temp[i]);
        }
    }
    return true;
}




int main(){

    vector<int> arr={6,5,1,2,4,8};
    int K=3;
    int kthlargest=Klargestelement(arr,K);
    cout<<"Kth largest element: "<<kthlargest<<endl;
    cout<<endl;

    int kthsmallest=Ksmallestelement(arr,K);
    cout<<"Kth smallest element: "<<kthsmallest<<endl;
    cout<<endl;

    
    vector<int> arr2={1, 4, 5, 2, 3, 6, 7, 8, 9, 10};
    vector<int> result=sortkarray(arr2,2);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    cout<<endl;


    vector<int> arr3={20,15,26,2,98,6,6};
    vector<int> result2=rankinsorted(arr3);
    for(int i=0;i<result2.size();i++){
        cout<<result2[i]<<" ";
    }
    cout<<endl;
    cout<<endl;


    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    cout << "Least Interval: "<<leastInterval(tasks, n) << endl;
    cout<<endl;


    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize = 3;
    if (isNStraightHand(hand, groupSize)) cout << "true\n";
    else cout << "false\n";



    return 0;

}