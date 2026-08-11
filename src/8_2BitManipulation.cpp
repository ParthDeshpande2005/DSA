#include<bits/stdc++.h>
using namespace std;

//leetcode 2220->
//minium bit flips to convert number
int minBitFlips(int start, int goal) {
    int num=start^goal; // after xor only the bits that are different in both number remain.
    int cnt=0;
    for(int i=0;i<32;i++){//as there are 31 bits.
        //checking foreach bit is set or not.
        //if bit is set cnt++.
        //then left shift num.
        cnt+=(num & 1);
        num=num>>1;
    }
    return cnt;
}


//leetcode 136->
int singleNumber(vector<int>& nums) {
    int n=nums.size();
    int ans=nums[0];
    //xor method
    for(int i=1;i<n;i++){
        ans=ans^nums[i];
    }
    return ans;
}


//leetcode 78->
//bit manipulation solution->
vector<vector<int>> subsets(vector<int>& nums) {
    int n=nums.size();
    int total=1<<n;  //total possibility  ex-> n=3   total=(1<<3)=8
    
    vector<vector<int>> result;
    
    for(int num=0;num<total;num++){ //checking fro all possibiliy.
        vector<int> subset;
        for(int i=0;i<n;i++){//check if each bit is set or not in each number and adding accordingly.
            if(num & (1<<i)){
                subset.push_back(nums[i]);
            }
        }
        result.push_back(subset);
    }
    return result;
}


//xor of numbers in a given range->
int xortillN(int n){
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    if(n%4==3) return 0;
    return n;
}
int findrangexor(int l,int r){
    //brute force->
    //loop from l to r and store ^ in variable called xxor.

    //optimal->
    //the xor of numbers from 1 to n follows a predictable pattern based on n%4.
    //to get xor of number in the range (l,r)  compute xor(1 to r) and xor(1 to l-1).
    //apply xor between these two results,commom prefixes cancel out due to xor properties.
    //TC-O(1)  SC-O(1)
    return xortillN(l-1)^xortillN(r);

}


int singleNumber2(vector<int>& nums) {
    //brute force ->
    //M1-> unordered map bana lo 1 bar traversal kar ke fir sab ka cnt store kar lo.
    //M2-> sort the array.then i ko left or right ko compare karte jayege.
    
    //optimal appoarch->
    int n=nums.size();
    int ans=0;

    for(int i=0;i<32;i++){
        int onecnt=0;
        int temp=(1<<i); 
        for(int j=0;j<n;j++){
            if((nums[j] & temp)!=0) onecnt++; //checking if ith bit is zero or one.
        }

        if(onecnt%3==1){
            //the bit of ans at i is 1
            ans= ans | temp;
        }
        //else the i th bit will be zero so no need to add condition for that.
    }   
    return ans;
}

//leetcode 260
//IMP 
//IMP-> int mask = x & (-x); is used to get the right most bit ..
vector<int> singleNumber3(vector<int>& nums) {
    int n=nums.size();
    int xor2num=0;

    for(int i=0;i<n;i++){
        xor2num=xor2num^nums[i];
    }
    //now xor2num stores the xor of two unique numbers.
    
    //now we find the right most 1.
    int rightsetbit=0;
    for(int i=0;i<32;i++){
        if(((xor2num>>i) & 1)!=0) {
            rightsetbit=i;
            break;
        }
    }
    
    //IMP-> int mask = x & (-x); is used to get the right most bit ..
    
    //the int we will compare with for bit set or not->
    int comp=1<<rightsetbit;
    //we take two xor one for whose right most bit set and one for whose right most bit is not set.
    int xor1=0;
    int xor2=0;
    for(int i=0;i<n;i++){
        //if the rightmost bit is set
        int cur_num=nums[i];
        if((cur_num & comp)==0){
            xor2=xor2^cur_num;
        }
        else{
            xor1=xor1^cur_num;
        }
    }
    return {xor1,xor2};
}




int main(){

    int start = 10;
    int goal = 7;
    cout << "Minimum bit flips required: " << minBitFlips(start, goal) << endl;


    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Single Number: " << singleNumber(nums) << endl;


    vector<int> nums2 = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums2);
    cout << "Subsets are:\n";
    for (auto &subset : ans) {
        cout << "{ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "}\n";
    }


    cout<<findrangexor(3,5)<<endl;



    vector<int> numss = {2, 2, 3, 2};
    cout << "Single Number = " << singleNumber2(numss) << endl;


    vector<int> numsy = {1, 2, 1, 3, 2, 5};
    vector<int> ans3 = singleNumber3(numsy);
    cout << "The two unique numbers are: ";
    cout << ans3[0] << " " << ans3[1] << endl;


    return 0;
}