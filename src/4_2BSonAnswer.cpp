#include<bits/stdc++.h>
using namespace std;

int findsqrroot(int n){
    //we are finding floor of square root of n.
    int low=0;
    int high=n;

    while(low<=high){
        int mid=(low+high)/2;
        

        if(mid*mid<=n){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return  high;

}


int Binary_Exponential(int mid,int n){//function to find n times mid.can also use normal for loop.
    //we can add condition for checking if mid^n is grtater than num to avoid space complexity and unnecery iterations.
    long long ans=1;
    while(n>0){
        if(n%2==1){
            ans=ans*mid;
        }
        mid=mid*mid;
        n=n/2;
        
    }
    //ans=mid^n
    return ans;
}
int findNthroot(int num,int n){
    int low=0;
    int high=num;

    while(low<=high){
        int mid=(low+high)/2;

        int midN=Binary_Exponential(mid,n);

        if(midN==num){
            return mid;
        }

        else if(midN<num) low=mid+1;
        else high=mid-1;
    }
    return -1;
}


//leetcode 875
long long count(vector<int>piles,int current){
    int n=piles.size();
    long long sum=0;
    for(int i=0;i<n;i++){
        int y= piles[i]/current + (piles[i] % current != 0);
        sum+=(long long)y;
    }
    return sum;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int n=piles.size();
    int low=1;
    int high=*max_element(piles.begin(), piles.end());//can also use INT_MAX to resuce time complexity;
   
    while(low<=high){
        int mid=low+(high-low)/2;
        
        if(count(piles,mid)<=h){
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}

//leetcode 1482
int noofBouquet(vector<int>& bloomDay,int mid,int k){
    int n=bloomDay.size();
    // vector<int> hashmap(n,0);
    
    int temp=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(bloomDay[i]<=mid){
            // hashmap[i]=1;
            temp++;
        }
        else{
            count+=temp/k;
            temp=0;
        }
    }
    count+=temp/k;
    //avoid hashmap->
    // int count=0;
    // int temp=0;
    // for(int it:hashmap){
    //     if(it==0){
    //         count+=temp/k;
    //         temp=0;
    //     }
    //     else temp++;
    // }
    // count+=temp/k;
    return count;  
}
int minDays(vector<int>& bloomDay, int m, int k) {
    int n=bloomDay.size();

    if(n<(long long)m*k) return -1;

    int low=*min_element(bloomDay.begin(),bloomDay.end());
    int high=*max_element(bloomDay.begin(),bloomDay.end());

    while(low<=high){
        int mid=low+(high-low)/2;
        if(noofBouquet(bloomDay,mid,k)>=m){
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}

//leetcode 1283
long long sum(vector<int>& nums,int current){
    int n=nums.size();

    long long sum=0;

    for(int i=0;i<n;i++){
        long long y= (long long) nums[i]/current+ (nums[i] % current != 0);
        //can also use ceil((double)nums[i]/(double)(current));
        sum+=y;
    }

    return sum;
}
int smallestDivisor(vector<int>& nums, int threshold) {
    int low=1;
    int high=*max_element(nums.begin(),nums.end());

    while(low<=high){
        int mid=low+(high-low)/2;

        if(sum(nums,mid)<=threshold){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

//leetcode 1011
int requireddays(vector<int>& weights,int mid){
    int n=weights.size();

    int count=0;
    int currwei=0;

    for(int i=0;i<n;i++){
        currwei+=weights[i];

        if(currwei>mid){
            count++;
            currwei=weights[i];
        }
    }
    return count+1;
}
int shipWithinDays(vector<int>& weights, int days) {
    int n=weights.size();

    int low=*max_element(weights.begin(),weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while(low<=high){
        int mid=low+(high-low)/2;

        int midD=requireddays(weights,mid);

        if(midD<=days){
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}


//leetcode 1539
//bruteforce->
int findKthPositivebruteforce(vector<int>& arr, int k) {
    int n=arr.size();

    int count=0;
        
    int cur=1;

    while(count<k){
        if(find(arr.begin(),arr.end(),cur)==arr.end()){
            count++;
            if(count==k) break;
        }
        cur++;
    }
    return cur;
}
//Optimal->
int findKthPositive(vector<int>& arr, int k) {
    int n=arr.size();

    int low=0;
    int high=n-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        int missing=arr[mid]-(mid+1);

        if(missing < k){
            low = mid + 1;
        }
        else high = mid - 1;
    }

    //our ans=arr[high]+more
    //ans=arr[high]+k-(missing)
    //ans=arr[high]+k-arr[high]+high+1
    //ans=high+1+k
    //ans=low+1

    return low+k;
}


bool canweplace(vector<int>& tents,int distance,int cows){
    int n=tents.size();

    int count=1;
    int previous=tents[0];

    for(int i=1;i<n;i++){
        if((tents[i]-previous)>=distance){
            previous=tents[i];
            count++;
        }
        if(count==cows) return true;
    }
    return false;
}
int AggressiveCows(vector<int> tents,int cows){
    int n=tents.size();

    sort(tents.begin(),tents.end());

    int low=1;
    int high=tents[n-1]-tents[0];

    while(low<=high){
        int mid=(low+high)/2;

        if(canweplace(tents,mid,cows)==true){
            low=mid+1;
        }
        else high=mid-1;
    }
    return high;
}

bool ispossible(vector<int>&books,int maxbook,int students){
    int n=books.size();

    int cntstudent=1;
    int curcnt=0;

    for(int i=0;i<n;i++){
        curcnt+=books[i];
        if(curcnt>maxbook){
            curcnt=books[i];
            cntstudent++;
        }
    }
    return cntstudent<=students;
}
int AllocateBooks(vector<int> books,int students){
    int n=books.size();

    if(n<students) return -1;

    int low=*max_element(books.begin(),books.end());
    int high=accumulate(books.begin(),books.end(),0);

    while(low<=high){

        int mid=low+(high-low)/2;

        //here mid represent the maximum book one student can have.
        if(ispossible(books,mid,students)==true){
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}   


int possible(vector<int>& nums,int mid){
    int n=nums.size();

    int curr=0;
    int cnt=1;

    for(int i=0;i<n;i++){
        curr+=nums[i];
        if(curr>mid){
            curr=nums[i];
            cnt++;
        }
    }

    return cnt;
}
int splitArray(vector<int>& nums, int k) {
    int n=nums.size();

    int low=*max_element(nums.begin(),nums.end());
    int high=accumulate(nums.begin(),nums.end(),0);

        
    while(low<=high){
        int mid=low+(high-low)/2;
        if(possible(nums,mid)<=k){
            high=mid-1;
        }
        
        else low=mid+1;
    }
    return low;
}


//brute force mai hum priority queue use nahi karege har bar loop lagake difference nikale ge.
//better solution->
//without BS and using priority queue  TC->O(n log n + k log n)  SC->O(n-1)
long double Gasstations(vector<int>& arr,int k){
    //k is the number of new gasstations that are to be added.
    int n=arr.size();
    vector<int> howmany(n-1,0);
    priority_queue<pair<long double,int>> pq;
    for(int i=0;i<n-1;i++){
        pq.push({arr[i+1]-arr[i],i});
    }
    for(int gasStations=1;gasStations<=k;gasStations++){
        auto tp=pq.top();
        pq.pop();
        int secInd=tp.second;
        howmany[secInd]++;
        long double iniDiff=arr[secInd+1]-arr[secInd];//initial difference
        long double newSecLen=iniDiff/(long double)(howmany[secInd]+1);//new difference after adding howmany[secInd] gas stations.
        pq.push({newSecLen,secInd});
    }
    return pq.top().first;
}
//with BS->
//optimal solution->
int numberofGasStationsRequired(long double dist,vector<int>& arr){
    int cnt=0;
    for(int i=1;i<arr.size();i++){
        int numberinBetween=((arr[i]-arr[i-1])/dist);
        if((arr[i]-arr[i-1])==numberinBetween * dist){
            numberinBetween--;
        }
        cnt+=numberinBetween;
    }
    return cnt;
}
long double optimalGasstations(vector<int>& arr,int k){
    int n=arr.size();

    long double low=0;
    long double high=0;
    for(int i=0;i<n-1;i++){
        high=max(high,(long double)(arr[i+1]-arr[i]));
    }
    long double diff=1e-6;
    while(high-low>diff){
        long double mid=(low+high)/(2.0);
        int cnt=numberofGasStationsRequired(mid,arr);
        
        if(cnt>k){
            low=mid;
        }
        else high=mid;
    }
    return high;
}


//Better Soultion-> using a good logic removing the need to make new array->
double betterfindMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1=nums1.size();
    int n2=nums2.size(); 
    int i=0;
    int j=0;
    int n=(n1+n2);  
    int ind2=n/2;
    int ind1=ind2-1; 
    int cnt=0;  
    int ind1el=-1,ind2el=-1; 

    while(i<n1 && j<n2){
        if(nums1[i]<nums2[j]){
            if(cnt==ind1) ind1el=nums1[i];
            if(cnt==ind2) ind2el=nums1[i];
            cnt++;
            i++;
        }
        else{
            if(cnt==ind1) ind1el=nums2[j];
            if(cnt==ind2) ind2el=nums2[j];
            cnt++;
            j++;
        }
        if(ind1el!=-1 && ind2el!=-1) break;
    }

    while(i<n1){
        if(cnt==ind1) ind1el=nums1[i];
        if(cnt==ind2) ind2el=nums1[i];
        cnt++;
        i++;
        if(ind1el!=-1 && ind2el!=-1) break;
    }

    while(j<n2){
        if(cnt==ind1) ind1el=nums2[j];
        if(cnt==ind2) ind2el=nums2[j];
        cnt++;
        j++;
        if(ind1el!=-1 && ind2el!=-1) break;
    }

    if(n%2==1){
        return ind2el;
    }

    return (double)((double)(ind1el+ind2el))/2.0;
}
//optimal Solution-> trying to divide the two array around the middle->
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1=nums1.size();
    int n2=nums2.size();

    if(n1>n2) return findMedianSortedArrays(nums2,nums1);//I allways want n1 to be smaller array.

    int low=0,high=n1;

    int left=(n1+n2+1)/2;

    int n=n1+n2;

    while(low<=high){
        int mid1=(low+high)>>1;//binary method to get mid or like /2
        int mid2=left-mid1;

        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;

        if(mid1<n1) r1=nums1[mid1];
        if(mid2<n2) r2=nums2[mid2];

        if(mid1-1>=0) l1=nums1[mid1-1];
        if(mid2-1>=0) l2=nums2[mid2-1];

        if(l1<=r2 && l2<=r1){
            if(n%2==1) return max(l1,l2);
            return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
        }
        else if(l1>l2) high=mid1-1;
        else low=mid1+1;
    }
    return 0;
}

//dividing the array around K and K-1 similar approach as last one->
int Kthelementfromtwosortedarray(vector<int>& nums1,vector<int>& nums2,int k){
    int n1=nums1.size();
    int n2=nums2.size();

    if(n1>n2) return Kthelementfromtwosortedarray(nums2,nums1,k);//I allways want n1 to be smaller array.

    int low=max(0,k-n2),high=min(k,n1);

    int left=k;

    int n=n1+n2;

    while(low<=high){
        int mid1=(low+high)>>1;
        int mid2=left-mid1;

        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;

        if(mid1<n1) r1=nums1[mid1];
        if(mid2<n2) r2=nums2[mid2];

        if(mid1-1>=0) l1=nums1[mid1-1];
        if(mid2-1>=0) l2=nums2[mid2-1];

        if(l1<=r2 && l2<=r1){
            return max(l1,l2);  
        }
        else if(l1>l2) high=mid1-1;
        else low=mid1+1;
    }
    return 0;
}


int main(){

    // int ans=findsqrroot(64);
    // cout<<ans;


    // int num = 27;
    // int n = 3;
    // cout << findNthroot(num, n);


    // vector<int> piles = {3, 6, 7, 11};
    // int h = 8;
    // cout << "Minimum eating speed: "<< minEatingSpeed(piles, h) << endl;


    // vector<int> bloomDay = {1, 10, 3, 10, 2};
    // int m = 3;
    // int k = 1;
    // cout << "Minimum days: "<< minDays(bloomDay, m, k) << endl;


    // vector<int> nums = {1, 2, 5, 9};
    // int threshold = 6;
    // cout << "Smallest Divisor = "<< smallestDivisor(nums, threshold) << endl;


    // vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int days = 5;
    // cout << "Minimum capacity required: "<< shipWithinDays(weights, days) << endl;

    
    // vector<int> arr = {2, 3, 4, 7, 11};
    // int k = 5;
    // cout << "Kth missing positive number = "<< findKthPositive(arr, k) << endl;
    

    // vector<int> tents = {1, 2, 4, 8, 9};
    // int cows = 3;
    // cout << "Maximum minimum distance = "<< AggressiveCows(tents, cows);
    

    // vector<int> books = {12, 34, 67, 90};
    // int students = 2;
    // cout << "Minimum possible maximum pages = "<< AllocateBooks(books, students);


    // vector<int> nums = {7, 2, 5, 10, 8};
    // int k = 2;
    // cout << splitArray(nums, k);


    // vector<int> arr = {1, 7, 15};
    // int k = 2;
    // long double ans = Gasstations(arr, k);
    // cout << fixed << setprecision(6) << ans << endl;


    // vector<int> arr = {1, 7, 15};
    // int k = 2;
    // long double ans = optimalGasstations(arr, k);
    // cout << fixed << setprecision(6) << ans << endl;


    // vector<int> nums1 = {1, 3};
    // vector<int> nums2 = {2};
    // cout << "Median = "<<findMedianSortedArrays(nums1, nums2)<< endl;


    vector<int> nums1 = {2, 3, 6, 7, 9};
    vector<int> nums2 = {1, 4, 8, 10};
    int k = 5; // 1-based indexing
    cout << "The " << k << "th element is: "<< Kthelementfromtwosortedarray(nums1, nums2, k) << endl;

    return 0;

}