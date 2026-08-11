//Binary Search->
// used to find in a sorted array
#include<bits/stdc++.h>
using namespace std;

//using recursion.
//keep in mid sare case mai return karna padta hai 
int recursionBS(vector<int> &nums,int low,int high,int target){
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(nums[mid]==target) return mid;
    else if(target>nums[mid]){
        return recursionBS(nums,mid+1,high,target);
    }
    return recursionBS(nums,low,mid-1,target);
}
int search(vector<int>& nums, int target) {
// //  while Method
//     int n=nums.size();
//     int low=0;
//     int high=n-1;
//     while(low<=high){
//         int mid=(low+high)/2;
//         if(nums[mid]==target) return mid;
//         if(target>nums[mid]) low=mid+1;
//         else high=mid-1;
//     }
//     return -1;
    //Recursive Method->
    int n=nums.size();
    int low=0;
    int high=n-1;
    return recursionBS(nums,low,high,target);
}
//to tackel overflow we use->
//int mid=low+((high-low)/2)


int lowerbound(vector<int> nums,int target){//(arr[i]>=target) find such first element
    int n=nums.size();

    int low=0;
    int high=n-1;

    int ans=n;//Default answer if not found in array

    while(low<=high){
        int mid=(low+high)/2;

        if(nums[mid]>=target) {
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;


    //in cpp we can use 
    int lb=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    //this is a direct function in stl;


    // //Brute Force->
    // int n=nums.size();
    // for (int i = 0; i < n; i++) {
    //     // If current element is greater than or equal to x
    //     if (nums[i] >= target) {
    //         return i;  // Return index of the first such element
    //     }
    // }
    // // If all elements are smaller than x
    // return n;

}


int upperbound(vector<int> nums,int target){//(arr[i]>target) find such first element
    int n=nums.size();

    int low=0;
    int high=n-1;

    int ans=n;//Default answer if not found in array

    while(low<=high){
        int mid=(low+high)/2;

        if(nums[mid]>target) {
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;

    
    //In cpp we can use->
    // int up=upper_bound(nums.begin(), nums.end(), target) - nums.begin();

}


//floor and ceil.
//floor->greatest number which is smaller or equal than target.
//ceil->smallest number which is greater or equal tham target.(lower bound)
int findfloor(vector<int> nums,int target){
    int n=nums.size();

    int low=0;
    int high=n-1;

    int ans=-1;//Default ans

    while(low<=high){
        int mid=(low+high)/2;

        if(nums[mid]<=target){
            ans=nums[mid];//potential floor
            low=mid+1;  //search right side
        }
        else{
            high=mid-1;//search left side
        }
    }
    return ans;
}
int findceil(vector<int> nums,int target){
    //same as lowerbound
    int n=nums.size();

    int low=0;
    int high=n-1;

    int ans=-1;//Default answer if not found in array

    while(low<=high){
        int mid=(low+high)/2;

        if(nums[mid]>=target) {
            ans=nums[mid];
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}


//Find the First and Last occurance->
//also for countind occurance in sorted array->
//we can use the uppper bound insted of normal binary search and then find if element is equal to the target.
int Binarysearch(vector<int> &nums,int target){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            ans=mid;
            high=mid-1;
        }
        else{
            if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    }
    return ans;
}
//insted of using upper bound we could have use normal binary search as well.
int upper_bound(vector<int> nums,int target){//(arr[i]>target) find such first element
    int n=nums.size();

    int low=0;
    int high=n-1;

    int ans=n;//Default answer if not found in array

    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>target) {
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
vector<int> searchRange(vector<int>& nums, int target) {
    int lb=Binarysearch(nums,target);
    if(lb==-1){
        return {-1,-1};
    }
    return {lb,upper_bound(nums,target)-1};
}


//Search in a rotated Sorted array for unique elements->
//Codestorywithmik->
//split array in two sorted parts and uses to BS in both array
int findpivot(vector<int>& nums,int n){
    int l=0,r=n-1;
    while(l<r){
        int mid=l+(r-l)/2;
        if(nums[mid]>nums[r]){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    return r;
} 
int binarySearch(int l,int r,vector<int> &nums,int target){
    int idx=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(nums[mid]==target){
            idx=mid;
            break;
        }
        else if(nums[mid]<target){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return idx;
}
int searchinrotated1(vector<int>& nums, int target) {
    int n=nums.size();
    //as we know there will be two sorted part in the array.
    //we are finding the pivot element 
    //we are finding the two sorted part using pivot element
    int pivot_idx=findpivot(nums,n);

    int idx=binarySearch(0,pivot_idx-1,nums,target); //left sorted part

    if(idx!=-1) return idx;

    idx=binarySearch(pivot_idx,n-1,nums,target);//right side ka sorted part

    return idx;
}
//striver->
//when dividing array in two part atleat one part is sorted striver solution tries to find solution in that part only;
//if the target is not in the sorted part it repeat the same for the remeaning part.  
int searchinrotated2(vector<int>& nums, int target) {
    int n=nums.size();
    int low=0;
    int high=n-1;
    
    while(low<=high){
        int mid=(high+low)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<=nums[mid]){
                high=mid-1;
            }
            else low=mid+1;
        }
        else{
            if(nums[mid]<=target && target<=nums[high]){
                low=mid+1;
            }
            else{
                high=low-1;
            }
        }
    }
    return -1;
}


//Search in a rotated Sorted array with repeat element->
//same as old code only one new condition is added
bool searchinrotated3(vector<int>& nums, int target) {
    int n=nums.size();
    int low=0;
    int high=n-1;
    
    while(low<=high){
        int mid=(high+low)/2;
        if(nums[mid]==target){
            return true;
        }
        if(nums[mid]==nums[low]  && nums[mid]==nums[high]) {//new condition for duplicate check.
            low++;
            high--;
        }
        else if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<=nums[mid]){
                high=mid-1;
            }
            else low=mid+1;
        }
        else{
            if(nums[mid]<=target && target<=nums[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return false;
}


int MininRotatedSorted(vector<int> &nums){
        //codestorywithmik->
    
    
    //     int n=nums.size();
    //     int left=0;
    //     int right=n-1;
    //     while(left<right){
    //         int mid=left+(right-left)/2;

    //         if(nums[mid]>nums[right]){
    //             left=mid+1;
    //         }
    //         else right=mid;
    //     }
    //     return nums[right];
    


    //   time complexity-> O(n)
    //     int n=nums.size();
    //     int mini=nums[0];
    //     if(n==1){
    //         return nums[0];
    //     }
    //     if(n==2){
    //         return min(nums[0],nums[1]);
    //     }
    //     int i=0;
    //     while(i+1<n && nums[i]<nums[i+1]){
    //         i++;
    //     }
    //     if(i==n-1){
    //         return min(nums[i],mini);
    //     }
    //     else{
    //         return min(nums[i+1],mini);
    //     }
    

    //striver->

    int n=nums.size();
    int ans=INT_MAX;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        
        //Bonus case to reduce Time complexity->
        // if search space is allready sorted than nums[low] will be minium in that search space->
        if(nums[low]<=nums[high]){
            ans=min(ans,nums[low]);
            break;
        }


        if(nums[low]<=nums[mid]){
            ans=min(ans,nums[low]);
            low=mid+1;
        }
        else{
            ans=min(ans,nums[mid]);
            high=mid-1;
        }
    }
    return ans;
    
}

//find how many times the array is rotated->
//same logic as mininrotatedsorted
int timesrotated(vector<int> &nums){
    int n=nums.size();

    int low=0;
    int high=n-1;

    int ans=INT_MAX;
    int index=0;

    while(low<=high){
        int mid=(low+high)/2;
        
        if(nums[low]<=nums[high]){
            if(nums[low]<ans){
                ans=nums[low];
                index=low;
            }
            break;
        }
        if(nums[low]<=nums[mid]){
            if(nums[low]<ans){
                ans=nums[low];
                index=low;
            }
            low=mid+1;
        }
        else{
            if(nums[mid]<ans){
                ans=nums[mid];
                index=mid;
            }
            high=mid-1;
        }
    }
    return index;
    
}

int singleNonDuplicate(vector<int>& nums) {
    int n=nums.size();

    if(n==1) return nums[0];

    if(nums[0]!=nums[1]) return nums[0];
    if(nums[n-1]!=nums[n-2]) return nums[n-1];

    int low=1;
    int high=n-2;

    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])  return nums[mid];
        if(nums[mid]==nums[mid-1]){
            if((mid-1)%2==0) low=mid+1;
            else high=mid-1;
        }
        if(nums[mid]==nums[mid+1]){
            if((mid)%2==0) low=mid+1;
            else high=mid-1;
        }
    }
    return -1;
}

int findPeakElement(vector<int>& nums) {
    int n=nums.size();

    if(n==1) return 0;
    
    if(nums[0]>nums[1]) return 0;
    if(nums[n-1]>nums[n-2]) return n-1;

    int low=1;
    int high=n-2;

    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]) return mid;
        if(nums[mid+1]>nums[mid-1]) low=mid+1;
        else high=mid-1;
    }
    return -1;
}


int main(){

    // vector<int> nums = {10, 20, 30, 40, 50, 60, 70};
    // int target = 50;
    // int ans = search(nums, target);
    // cout << "Target found at index: " << ans << endl;


    // vector<int> arr = {3, 5, 8, 15, 19};
    // int target= 9;
    // int ans=lowerbound(arr,target);
    // cout<<ans;//getting the index of ans.


    // vector<int> arr = {3, 5, 8, 15, 19};
    // int target= 9;
    // int ans=upperbound(arr,target);
    // cout<<ans;//getting the index of ans.


    // vector<int> arr = {3, 4, 4, 7, 8, 10};
    // int x = 5;
    // int floor=findfloor(arr,x);
    // int ceil=findceil(arr,x);
    // cout<<"floor: "<<floor<<"  "<<"ceil: "<<ceil;


    // vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    // int target = 2;
    // vector<int> ans = searchRange(nums, target);
    // cout << "First occurrence: " << ans[0] << endl;
    // cout << "Last occurrence: " << ans[1] << endl;
    // cout<<"No of Occurance: "<<ans[1]-ans[0]+1;


    // vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    // int target = 0;
    // int ans = searchinrotated1(nums, target);
    // int ans2= searchinrotated2(nums,target);
    // if (ans != -1) cout << "Target found at index: " << ans2 << endl;
    // else cout << "Target not found" << endl;


    // vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    // int target = 0;
    // if (searchinrotated3(nums, target)) cout << "Target found" << endl;
    // else cout << "Target not found" << endl;


    // vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    // cout << "Minimum element: " << MininRotatedSorted(nums) << endl;
    

    // vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    // cout << "Array is rotated "<< timesrotated(nums) << " times" << endl;


    // vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    // cout << "Single element: " << singleNonDuplicate(nums) << endl;


    // vector<int> nums = {1, 2, 3, 1};
    // int peakIndex = findPeakElement(nums);
    // cout << "Peak element index: " << peakIndex << endl;
    // cout << "Peak element value: " << nums[peakIndex] << endl;



    return 0;



}