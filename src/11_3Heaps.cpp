#include<bits/stdc++.h>
using namespace std;

//leetcode 355 --> IMP
//see this on leetcode..

//Minimum cost to connect sticks-->]
//this the problem statement on chatgpt as it is leetcode premium question.
int connectstick(vector<int> &arr){
    //correct algorithm-->
    int n=arr.size();
    if(n<=1) return 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    int totalcost=0;
    while(!pq.empty()){

        int one=pq.top();
        pq.pop();
        int two=pq.top();
        pq.pop();
        int cur_cost=one+two;

        totalcost+=cur_cost;
        if(pq.empty()) break;
        pq.push(cur_cost);
    }
    return totalcost;


    // //INCORRECT algorithm-->
    // int n=arr.size();
    // if(n<=1) return 0;
    // priority_queue<int,vector<int>,greater<int>> pq;
    // for(int i=0;i<n;i++){
    //     pq.push(arr[i]);
    // }

    // int totalcost=pq.top();
    // pq.pop();
    // totalcost+=pq.top();
    // pq.pop();
    // int cur_cost=totalcost;
    // while(!pq.empty()){
    //     cur_cost+=pq.top();
    //     totalcost+=cur_cost;
    //     pq.pop();
    // }
    // return totalcost;
}


//leetcode 703-->
class KthLargest {
public:
    //we use a priority_queue of k size.
    priority_queue<int,vector<int>,greater<int>> pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size){
            pq.pop();
        }
        return pq.top();
    }
};

//IMP-->
vector<int> maxsumcombition(vector<int> &arr1,vector<int> &arr2,int k){
    //optimal-->
    if (arr1.empty() || arr2.empty()) return {};
    //sort arr1 and arr2 in decreasing order
    sort(arr1.begin(),arr1.end(),greater<int>());
    sort(arr2.begin(),arr2.end(),greater<int>());
    //pq will store the sums this idea is like bfs  
    //it also stores the index of the element with that sum.
    priority_queue<tuple<int,int,int>> maxheap;
    //to keep track of visited elements.
    set<pair<int,int>> visited;
    //push the initial element in maxheap
    maxheap.push({arr1[0]+arr2[0],0,0});
    visited.insert({0,0});

    vector<int> result;

    while(k-- && !maxheap.empty()){

        // auto[sum,i,j]=maxheap.top();
        int sum=get<0>(maxheap.top());
        int i=get<1>(maxheap.top());
        int j=get<2>(maxheap.top());
        maxheap.pop();

        result.push_back(sum);

        if(i+1<arr1.size() && !visited.count({i+1,j})){
            maxheap.push({arr1[i+1]+arr2[j],i+1,j});
            visited.insert({i+1,j});
        }

        if(j+1<arr2.size() && !visited.count({i,j+1})){
            maxheap.push({arr1[i]+arr2[j+1],i,j+1});
            visited.insert({i,j+1});
        }
    }
    return result;


    //brute force find all the possible sum.
    //store it in an array.
    //sort the array in reverse . This is how you sort in reverse.
    //sort(allSums.begin(), allSums.end(), greater<int>());
    //return the first k elements
}


// leetcode 347-->
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mpp;
    int n=nums.size();
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }
    //Instead of storing all frequencies in the heap, keep only the top k.
    // using the k size heap is optimal solution.
    priority_queue<pair<int,int>> pq;
    for(auto it:mpp){
        int num=it.first;
        int freq=it.second;
        pq.push({freq,num});
    }
    vector<int> result;
    while(k--){
        auto[freq,num]=pq.top();
        result.push_back(num);
        pq.pop();
    }
    return result;
}


//IMP....
//leetcode 295--> Find Median from Data Stream
// watch codestorywithmik to get a better understanding..
//very different appoarch .
// we use two priority simultaniously.
// we use one min heap and one max heap.
class MedianFinder {
public:
    //we store the entire array in two parts.
    priority_queue<int> left_max_heap;
    priority_queue<int,vector<int>,greater<int>> right_min_heap;
    //when total elements are odd we will store one element extra in left_max_heap.
    int size;
    MedianFinder() {
        size=0;
    }
    
    void addNum(int num) {
        size+=1;
        if(size==1){
            left_max_heap.push(num);
            return;
        }
        if(num>left_max_heap.top()){
            right_min_heap.push(num);
        }
        else{
            left_max_heap.push(num);
        }

        if(right_min_heap.size()>left_max_heap.size()){
            int front=right_min_heap.top();
            right_min_heap.pop();
            left_max_heap.push(front);
        }
        else if(left_max_heap.size()-1>right_min_heap.size()){
            int front=left_max_heap.top();
            left_max_heap.pop();
            right_min_heap.push(front);
        }


    }
    
    double findMedian() {
        if(size%2==1){
            return left_max_heap.top();
        }
        int sum=left_max_heap.top();
        sum+=right_min_heap.top();
        return (double)sum/2.00;
    }   


    //BruteForce-->
    //we will create a max lenght vector according to our constraints.
    //then we will go on adding value in the vector keeping track of the current size.
    //we will do kind of insertion .
    // we wil add new element on its correct position..

};







int main(){

    vector<int> arr={1,2,2,2,2,100};
    int ans=connectstick(arr);
    cout<<ans<<endl;
    cout<<endl;


    vector<int> nums = {4, 5, 8, 2};
    int k = 3;
    KthLargest obj(k, nums);
    cout << obj.add(3) << " ";   // 4
    cout << obj.add(5) << " ";   // 5
    cout << obj.add(10) << " ";  // 5
    cout << obj.add(9) << " ";   // 8
    cout << obj.add(4) << endl;   // 8
    cout<<endl;


    vector<int> nums1 = {7, 3};
    vector<int> nums2 = {1, 6};
    int k2 = 2;
    vector<int> result = maxsumcombition(nums1, nums2, k2);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    cout<<endl;


    vector<int> nums3 = {1,1,1,2,2,3};
    int k3 = 2;
    vector<int> ans3 = topKFrequent(nums3, k3);
    cout << "Top " << k3 << " frequent elements: ";
    for(int x : ans3)
        cout << x << " ";
    cout << endl;
    cout<<endl;



    MedianFinder mf;
    vector<int> nums4 = {5, 15, 1, 3, 8, 7, 9};
    for (int x : nums4) {
        mf.addNum(x);
        cout << "Inserted: " << x
             << " -> Median = " << mf.findMedian() << endl;
    }

    
    return 0;
}