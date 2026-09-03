#include<bits/stdc++.h>
using namespace std;

int nCr(int n,int r){
    long long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}
int PascalTriangleType1(int row,int col){
    //we need to return the element at row,col
    //there is the formula for this
    //row-1 C col-1
    //nCr=n!/r!*(n-r)!
    return nCr(row-1,col-1);
}


void PascalTriangleType2(int row){
    //return entire row->
    //optimal->
    int ans=1;
    cout<<ans<<" ";
    for(int i=1;i<row;i++){
        ans=ans*(row-i);
        ans=ans/(i);
        cout<<ans<<" ";
    }


    //bruteforce->as nth row has n elements
    //for loop mai ncr wala formula use karke print karna
    //O(n*r)->time complexity
}


void PascalTriangleType3(int row){
    //print the entire triangle till n rows.
    //Optimal Solution->
    //using type 2 to solve type 3

    for(int i=1;i<=row;i++){
        PascalTriangleType2(i);
        cout<<endl;
    }


    //bruteforce->use nCr formula for finding all element.
    //O(n^3) time complexity
}


//Boyer–Moore Voting Algorithm
vector<int> MajorityElement2(vector<int> v){
    //return all the elements that appear more than n/3 times.

    //Optimal Solution->time->O(n+n=n) one n is for checking. space->O(1)
    int cnt1=0,cnt2=0;
    int el1=INT_MIN;
    int el2=INT_MIN;
    for(int i=0;i<v.size();i++){
        if(cnt1==0 && el1!=v[i]){
            cnt1=1;
            el1=v[i];
        }
        else if(cnt2==0 && el2!=v[i]){
            cnt2=1;
            el2=v[i];
        }
        else if(v[i]==el1) cnt1++;
        else if(v[i]==el2) cnt2++;
        else{
            cnt1--,cnt2--;
        }
    }
    vector<int> ls;
    cnt1=0,cnt2=0;
    for(int i=0;i<v.size();i++){
        if(el1==v[i]) cnt1++;
        if(el2==v[i]) cnt2++;
    }
    int mini=(int)(v.size()/3)+1;
    if(cnt1>=mini) ls.push_back(el1);
    if(cnt2>=mini) ls.push_back(el2);
    sort(ls.begin(),ls.end());
    return ls;


    // //Better Solution->time->O(n*logn) space->O(n)
    // vector<int> ls;
    // map<int,int> mpp;
    // int n=v.size();
    // int mini=(int)(n/3)+1;
    // for(int i=0;i<n;i++){
    //     mpp[v[i]]++;
    //     if(mpp[v[i]]==mini){
    //         ls.push_back(v[i]);  //time complexity for insert is O(log n)
    //     }
    //     if(ls.size()==2) break;
    // }
    // sort(ls.begin(),ls.end());
    // return ls;

}


vector<vector<int>> ThreeSum(vector<int> &nums){
    //our target value is zero
    
    //Optimal-> O(n^2 + nlog(n)) nlog(n)->for sorting.
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j=i+1;
        int k=nums.size()-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                vector<int> temp={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
        }
    }
    return ans;

    //better-> TC->O(n^2 x log(m))  log m to insert in set
    // set<vector<int>> st;
    // for(int i=0;i<nums.size();i++){
    //     set<int> hashset;
    //     for(int j=i+1;j<nums.size();j++){
    //         int third=t-(nums[i]+nums[j]);
    //         if(hashset.find(third) != hashset.end()){
    //             vector<int> temp={nums[i],nums[j],third};
    //             sort(temp.begin(),temp.end());
    //             st.insert(temp);
    //         }
    //         hashset.insert(nums[j]);
    //     }
    // }
    // vector<vector<int>> ans(st.begin(),st.end());
    // return ans;


    //bruteforce->
    //O(n^3 x log(m)) using 3 loops i(0->n) j(i+1->n) k(j+1->n)
    //using set to store the sorted value of(i,j,k) so that we get unique value.
}


vector<vector<int>> FourSum(vector<int> &nums,int target){

    //Optimal-> O(n^3)
    int n=nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j!=(i+1) && nums[j]==nums[j-1]) continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum=nums[i];
                sum +=nums[j];
                sum +=nums[k];
                sum +=nums[l];
                if(sum ==target){
                    vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;l--;
                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;
                }
                else if(sum<target) k++;
                else l--;
            }
        }
    } 
    return ans;  


    //Better->O(n^3 x log(m))
    //using hashmap to find last element 
    //fourth element =target-[first+second+third]
    //har bar hashmap second and third ke bick ke elements ko store karega

    // int n=nums.size();
    // set<vector<int>> st;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         set<long long> hashset;
    //         for(int k=j+1;k<n;k++){
    //             long long sum=nums[i]+nums[j];
    //             sum += nums[k];
    //             long long fourth=target-(sum);
    //             if(hashset.find(fourth)!=hashset.end()){
    //                 vector<int> temp={nums[i],nums[j],nums[k],(int)fourth};
    //                 sort(temp.begin(),temp.end());
    //                 st.insert(temp);
    //             }
    //             hashset.insert(nums[k]);
    //         }
    //     }
    // }
    // vector<vector<int>> ans(st.begin(),st.end());
    // return ans;


    //Brute Force-> O(n^4)->checking for all the values

}


//
int largestsubarraywithsumzero(vector<int> &nums){

    // optimal-> TC->O(NlogN)  SC->O(n)
    int n=nums.size();
    map<int,int> hashmap;
    int sum=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        sum += nums[i];
        if(sum==0){
            maxi=i+1;
        }
        else{
            if(hashmap.find(sum)!=hashmap.end()){
                maxi=max(maxi,i-hashmap[sum]);
                // auto itmap=hashmap.find(sum);->ye mera code tha
                // int temp =i-(*itmap).second;
                // if(temp>maxi) maxi=temp;
            }
            else{
                hashmap[sum]=i; //hashmap.insert({sum,i});
            }
        }
    }
    return maxi;


    //Brute force->
    // check for all subarray 2 for loop use karege O(n^2)
}


//
int NoofsubarraywithxorK(vector<int> a,int k){
    int xr=0;
    map<int,int> mpp;
    mpp[xr]++; //{0,1}
    int cnt=0;
    for(int i=0;i<a.size();i++){
        xr =xr^a[i];
        //k
        int x=xr^k;
        cnt+=mpp[x];
        mpp[xr]++;
    }
    return cnt;
}


vector<vector<int>> merge(vector<vector<int>>& intervals) {//leetcode 56 check there for test cases and question.
    int n=intervals.size();//sorting in pair first element ke base par hota hai. agar first element same hai to second element ke base par hota hai.

    sort(begin(intervals),end(intervals));//can also write like this

    vector<vector<int>> result;

    result.push_back(intervals[0]);

    for(int i=1;i<n;i++){
        if(intervals[i][0]<=result.back()[1]){//overlapping
            // result.back()[0]=min(result.back()[0],intervals[i][0]);// // this line is ignored as we have allready sorted the array.
            
            
            //editing the last entry in result.
            result.back()[1]=max(result.back()[1],intervals[i][1]);
        }
        else{
            result.push_back(intervals[i]);
        }
    }
    return result;
}


//Merge 2 sorted array without extra space
//Method 1->
void mergeM1(vector<int>& nums1,vector<int>& nums2){
    
    //O(min(n,m)+ n log n + m log m)
    //Method 1-> 2 pointer x&y
    //x pointer at end of nums1 and y at start of nums2 replace if x>y  
    //this movies all the correct elements to there required array
    //sort both the array and get the answer.

    // int n=nums1.size();
    // int m=nums2.size();
    // int left=n-1;
    // int right=0;
    // while(left>=0 && right<m){
    //     if(nums1[left]>nums2[right]){
    //         swap(nums1[left],nums2[right]);
    //         left--,right++;
    //     }
    //     else{
    //         break;
    //     }
    // }
    // sort(nums1.begin(),nums1.end());//O(n log n)
    // sort(nums2.begin(),nums2.end());//O(m log m)
}


//Gap Method->
//Method 2-> Gap Method(gap method comes from shell sorting)
void swapifgreater(long long arr1[],long long arr2[],int ind1,int ind2){
    if(arr1[ind1]>arr2[ind2]){
        swap(arr1[ind1],arr2[ind2]);
    }
}
void mergeM2(long long arr1[],long long arr2[],int n,int m){//TC->O(log2(n+m) * O(n+m))  SC->O(1)
    int len=(n+m);
    int gap=(len/2)+(len%2);
    while(gap>0){
        int left=0;
        int right=left+gap;
        while(right<len){
            //arr1(left) and arr2(right) 
            if(left<n && right >=n){
                swapifgreater(arr1,arr2,left,right-n);
            }
            //arr2 and arr2
            else if(left>=n){
                swapifgreater(arr2,arr2,left-n,right-n);
            }
            //arr1 and arr1
            else{
                swapifgreater(arr1,arr1,left,right);
            }
            left++,right++;
        }
        if(gap==1) break;
        gap = (gap/2)+(gap%2);
    }
}


vector<int> missingandrepeating(vector<int> & nums,int n){
    //ex->input=({3,4,6,2,1,1},6)
    //output={5,1} 5 is missing and 1 is repeating

    //optimal-> XOR  TC->O(n)  SC->O(1)
    //watch sriver video to understand this solution this uses bit manupulation
    //1.(nums[i])^(1^2^3^..n)
    //2.find a difference bit in num(this is the differenciating bit),first 1 from the right
    //3.put them in two parts based on the 0 or 1 on num
    int xr=0;
    for(int i=0;i<n;i++){
        xr=xr^nums[i];
        xr=xr^(i+1);
    }
    int bitNo=0;
    while(1){
        if((xr & (1<<bitNo))!=0){
            break;
        }
        bitNo++;
    }
    int zero=0;
    int one=0;
    for(int i=0;i<n;i++){
        //part of one club
        if((nums[i]&(1<<bitNo))!=0){
            one=one^nums[i];
        }
        //part of 0 club
        else{
            zero=zero^nums[i];
        }
    }

    for(int i=1;i<=n;i++){
        //part of one club
        if((i&(1<<bitNo))!=0){
            one=one^i;
        }
        //part of 0 club
        else{
            zero=zero^i;
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(nums[i]==zero) count++;
    }
    if(count ==2) return {zero,one};
    return {one,zero};


    // //Optimal-> TC->O(n)  SC->O(1)
    // //Maths-> geting 2 equation
    // //we consider x->missing  y->repeating
    // //then we find x-y(from array sum - sum of n number ) and x+y(by finding x^2-y^2 by sumbtract squre of arr and square of n numbers)
    // //and the solve both to get answer.
    // //S-Sn=x-y
    // //S2-S2N
    // long long SN=(n*(n+1))/2;
    // long long S2N=(n*(n+1) *(2*n+1))/6; //finding sum of square of n natural number
    // long long S=0,S2=0;
    // for(int i=0;i<n;i++){
    //     S+=nums[i];
    //     S2+=(long long)nums[i] * (long long)nums[i];
    // }
    // long long val1=S-SN;//x-y
    // long long val2=S2-S2N;
    // val2 =val2/val1;//x+y
    // long long x=(val1+val2)/2;//missing
    // long long y=x-val1;
    // return {(int)x,(int)y};//repeating


    //better->hashing TC-> O(2n)
    //hasharr(n+1,0);
    //for(i ->n) hash[arr[i]]++
    //for(i in hash) check count and return missing and repeating 


    //brute force O(n^2)
    //for(i->n)
    //  cnt=0
    //  for(j->n-1  in array)
    //      if(arr[j]==i) cnt++;
    //  if(cnt==0) missing;
    //  if(cnt==2) repeating;
}


int Merge(vector<int> &arr,int low,int mid,int high){//here & is used to pass by reference. which changes the original value . 
    vector<int> temp;
    //1st arr->[low....mid]
    //2nd arr->[mid+1....high]
    int left=low;
    int right=mid+1;
    int cnt=0;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        //right is smaller
        else{
            temp.push_back(arr[right]);
            cnt+=(mid-left+1);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
    return cnt;
}
int Merge_Sort(vector<int> &arr,int low,int high){
    //we pass by reference as we need changes in the original vector.
    //Divide and Merge
    int cnt=0;
    if(low==high) return cnt;
    int mid=(low+high)/2;
    cnt += Merge_Sort(arr,low,mid);
    cnt += Merge_Sort(arr,mid+1,high);
    cnt += Merge(arr,low,mid,high);
    return cnt;
}
int CountInversions(vector<int> nums,int n){
    return Merge_Sort(nums,0,n-1);
}


void merge(vector<int> &arr,int low,int mid,int high){//here & is used to pass by reference. which changes the original value . 
    vector<int> temp;
    //1st arr->[low....mid]
    //2nd arr->[mid+1....high]
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
int CountPairs(vector<int> arr,int low,int mid,int high){
    int right=mid+1;
    int cnt=0;
    for(int i=low;i<=mid;i++){
        while(right<=high && arr[i]>2*arr[right]) right++;
        cnt+=(right-(mid+1));
    }
    return cnt;
}
int merge_sort(vector<int> &arr,int low,int high){
    //we pass by reference as we need changes in the original vector.
    //Divide and Merge
    int cnt=0;
    if(low==high) return cnt;
    int mid=(low+high)/2;
    cnt+=merge_sort(arr,low,mid);
    cnt+=merge_sort(arr,mid+1,high);
    cnt+=CountPairs(arr,low,mid,high);
    merge(arr,low,mid,high);
    return cnt;
}
int ReversePair(vector<int> nums){
    int n=nums.size();
    return merge_sort(nums,0,n-1);
}


int maxProduct(vector<int>& nums) {
    int n=nums.size();

    int ans=INT_MIN;

    int pre=1;
    int suff=1;

    for(int i=0;i<n;i++){
        if(pre==0) pre=1;
        if(suff==0) suff=1;
        pre=pre*nums[i];
        suff=suff*nums[n-i-1];
        ans=max(ans,max(pre,suff));
    }
    return ans;
    //logic is from striver video.
    //can also use brute force O(n^2) where we check for all the subarray
}



int main(){

    // cout<<PascalTriangleType1(5,3);
    // PascalTriangleType2(6);
    // PascalTriangleType3(6);

    // vector<int> ls=MajorityElement2({1,1,1,1,3,2,2,2});
    // cout<<ls[0]<<" "<<ls[1];

    // vector<int> arr={-1,0,1,2,-1,-4,4};
    // // vector<vector<int>> ans=ThreeSum(arr);
    // vector<vector<int>> ans2=FourSum(arr,0);
    // for(int i=0;i<ans2.size();i++){
    //     for(int j=0;j<4;j++){//change to 3 for 3 sum
    //         cout<<ans2[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // vector<int> que={15,-2,2,-8,1,7,10,23};
    // int ans=largestsubarraywithsumzero(que);
    // cout<<ans;

    // vector<int> que2={4,2,2,6,4};
    // int ans=NoofsubarraywithxorK(que2,6);
    // cout<<ans;


    // long long a[]={1,3,5,7},b[]={0,2,6,8,9};
    // mergeM2(a,b,4,5);
    // for(auto i:a) cout<<i<<" ";
    // cout<<"\n";
    // for(auto i:b) cout<<i<<" ";
    

    // vector<int> nums={3,4,6,2,1,1};
    // vector<int> ans=missingandrepeating(nums,6);
    // cout<<"Missing = "<<ans[0]<<"\n";
    // cout<<"Repeating = "<<ans[1];


    // vector<int> nums = {5, 3, 2, 4, 1};
    // int n = nums.size();
    // cout << "Number of Inversions = "<< CountInversions(nums, n) << endl;


    // vector<int> nums = {1,3,2,3,1};
    // cout << "Number of Reverse Pairs = "<< ReversePair(nums) << endl;


    // vector<int> nums = {2, 3, -2, 4};
    // cout << "Maximum Product Subarray = " << maxProduct(nums);

    return 0;
}