#include<bits/stdc++.h>
using namespace std;



//leetcode 3-->
int lengthOfLongestSubstring(string s) {
    int left=0;
    int right=0;
    int n=s.size();
    int maxcnt=0;
    vector<int> hashmap(256,0);
    while(right<n){
        char cur=s[right];
        hashmap[cur]++;
        while(hashmap[cur]>1){
            hashmap[s[left]]--;
            left++;
        }
        maxcnt=max(maxcnt,right-left+1);
        right++;
    }
    return maxcnt;
}


//leetcode 1004-->
int longestOnes(vector<int>& nums, int k) {
    // TC->O(n)
    int n=nums.size();
    int left=0;
    int right=0;
    int cntzero=0;
    int maxlen=0;
    while(right<n){
        if(nums[right]==0) cntzero++;  //can be writen as cntzero+=!nums[right];
        
        if(cntzero>k){
            if(nums[left]==0) {
                cntzero--;
            }
            left++;
        }
        if(cntzero<=k) maxlen=max(maxlen,right-left+1);
        right++;
    }
    return maxlen;

    //better very close to optimal solution-->
    // //TC--> O(2N)
    // int left=0;
    // int right=0;
    // int cntzero=0;
    // int n=nums.size();
    // int maxlen=0;
    // while(right<n){
    //     if(nums[right]==0) cntzero++;
    //     while(cntzero>k){
    //         if(nums[left]==0) cntzero--;
    //         left++;
    //     }
    //     maxlen=max(maxlen,right-left+1);
    //     right++;
    // }
    // return maxlen;

}


//leetcode 904--> the movement of l&r depend on two variable
int totalFruit(vector<int>& fruits) {
    //most optimal keeping the size of the max consistence-->
    //try dry run to get better idea.
    int left=0;
    int right=0;
    unordered_map<int,int> freq;  //stores the type and freq;
    int n=fruits.size();
    int maxtree=0;
    while(right<n){
        freq[fruits[right]]++;
        if(freq.size()<=2){
            maxtree=max(maxtree,right-left+1);
        }
        else if(freq.size()>2){
            freq[fruits[left]]--;
            if(freq[fruits[left]]==0) freq.erase(fruits[left]);
            left++;
        }
        right++;
    }
    return maxtree;



    // //Optimal -->my solution is harder to understand than standard solution which uses map.
    // //TC--> O(N)  //SC-->O(2)=O(1)
    // int n=fruits.size();
    // int left=0;
    // int right=0;
    // int type1=fruits[0];
    // int type1cnt=0;
    // while(right<n && fruits[right]==type1){
    //     right++;
    //     type1cnt++;
    // }
    // if(right==n) return n;
    // int type2=fruits[right];
    // int type2cnt=0;
    // int maxtree=0;
    // while(right<n){
    //     if(fruits[right]==type1){
    //         type1cnt++;
    //     }
    //     else if(fruits[right]==type2){
    //         type2cnt++;
    //     }
    //     else{ //when the fruit is of neither type.
    //         while(left<right && (type1cnt!=0 && type2cnt!=0)){
    //             if(fruits[left]==type1){
    //                 type1cnt--;
    //             }
    //             else if(fruits[left]==type2){
    //                 type2cnt--;
    //             }
    //             left++;
    //         }
    //         //now one of type1 or type2 is zero
    //         if(type1cnt==0){
    //             type1=fruits[right];
    //             type1cnt=1;
    //         }
    //         else{
    //             type2=fruits[right];
    //             type2cnt=1;
    //         }
    //     }
    //     maxtree=max(maxtree,type1cnt+type2cnt);
    //     right++;
    // }
    // return maxtree;




    //also optimal using map-> easy to understand--> as map will allways store 2 size.
    //map store type and the freq of that type.
    // int totalFruit(vector<int>& fruits) {
    // unordered_map<int,int> freq;
    // int left = 0;
    // int ans = 0;
    // for (int right = 0; right < fruits.size(); right++) {
    //     freq[fruits[right]]++;
    //     while (freq.size() > 2) {
    //         freq[fruits[left]]--;
    //         if (freq[fruits[left]] == 0)
    //             freq.erase(fruits[left]);
    //         left++;
    //     }
    //     ans = max(ans, right - left + 1);
    // }
    // return ans;


    //brute force--> using 2 for loop by checking for all subarray present.
    //also using set to store the unique elements.
    //we will break out of the inner for loop when ever the set size will be greater than 2.

}


//leetcode 424--> we use new variable name as max
int characterReplacement(string s, int k) { //IMP--> we can even skip the maxfreqele and still get correct ans.
    int left=0;
    int right=0;
    int n=s.size();
    unordered_map<char,int> freq;
    int maxlen=0;
    char maxfreqele=s[0];
    int maxfreq=0; //this new variable will help us to solve the problem.
    // we know Number of changes=length-maxfreq.
    // will all ways change all others than the one with max freq.
    while(right<n){
        freq[s[right]]++;
        //updating max freq.
        // maxfreq=max(maxfreq,freq[s[right]]);
        if(freq[s[right]]>maxfreq){
            maxfreq=freq[s[right]];
            maxfreqele=s[right];
        }
        //if k satisfy
        int totalchange=((right-left+1)-maxfreq);//IMP..
        if(totalchange<=k){ 
            maxlen=max(maxlen,right-left+1);
        }
        else{ //when k does not satisfy
            if(s[left]==maxfreqele){
                maxfreq--;
            }
            freq[s[left]]--;
            if(freq[s[left]]==0) freq.erase(s[left]);
            left++;
        }
        right++;
    }
    return maxlen;
}


//leetcode 930-->
int numsubarrayswithsumlessorequal(vector<int>& nums, int goal){
    if(goal<0) return 0;
    int l=0;
    int r=0;
    int sum=0;
    int cnt=0;
    int n=nums.size();
    while(r<n){
        sum+=nums[r];
        while(sum>goal){
            sum-=nums[l];
            l++;
        }
        cnt+=(r-l+1);
        r++;
    }
    return cnt;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
    //solution using 2 pointer sliding window -->
    //TC-O(4N) SC-O(1) improved space complexity.
    //we can't directly find how many are equal to goal..
    // but we can use 100% of our brain to->
    // fun(sum==goal) =fun(sum<=goal)-fun(sum<=goal-1)  IMP Formula
    return numsubarrayswithsumlessorequal(nums,goal)-numsubarrayswithsumlessorequal(nums,goal-1);
    // //prefix sum solution using hashmap.
    // //TC-O(N)  SC-O(N)
    // //this is optimal for array containing positive and negative.
    // unordered_map<int,int> hashmap; //map store sum and freq of that sum.
    // int n=nums.size();
    // hashmap[0]=1;
    // int presum=0;
    // int ans=0;
    // for(int i=0;i<n;i++){
    //     presum+=nums[i];
    //     int remain=presum-goal; //we don't write goal-presum as it will go negative as presum gets larger.
    //     ans+=hashmap[remain];
    //     hashmap[presum]++;
    // }
    // return ans;
}


//leetcode 1248-->
//simillar to previous question we will find the sum of subarray having number of odd elements less than k.
int numofsubwithlessorequaltoK(vector<int>& nums, int k){
    if(k<0) return 0;
    int n=nums.size();
    int cnt=0;
    int left=0;
    int right=0;
    int totalsub=0;
    while(right<n){
        if(nums[right]%2==1){ //if nums of right is odd.
            cnt++;
        }
        while(left<=right && cnt>k){
            if(nums[left]%2==1){
                cnt--;
            }
            left++;
        }
        totalsub+=right-left+1;
        right++;
    }
    return totalsub;
}
int numberOfSubarrays(vector<int>& nums, int k) {
    return numofsubwithlessorequaltoK(nums,k)-numofsubwithlessorequaltoK(nums,k-1);
}


//leetcode 1358--> IMP..the apporach is different 
int numberOfSubstrings(string s) {
    int left=0;
    int right=0;
    int n=s.size();
    int ans=0;
    vector<int> freq(3,0);
    while(right<n){
        freq[s[right]-'a']++;
        while(freq[0]>0 && freq[1]>0 && freq[2]>0){
            //observation formula...
            ans+=n-right;
            freq[s[left]-'a']--;
            left++;
        }
        right++;
    }
    return ans;

    // Brute Force->
    //     int n=s.length();
    //     int ans=0;
    //     for(int i=0;i<n;i++){
    //         int cnta=0;
    //         int cntb=0;
    //         int cntc=0;                    
    //         for(int j=i;j<n;j++){
    //             if(s[j]=='a') cnta++;
    //             if(s[j]=='b') cntb++;
    //             if(s[j]=='c') cntc++;
    //             if(cnta>0 && cntb>0 && cntc>0) ans++;
    //         }
    //     }
    //     return ans;

}


//leetcode 1423-->
int maxScore(vector<int>& cardPoints, int k) {
    int lsum=0;
    int rsum=0;
    int maxsum=0;
    int n=cardPoints.size();
    for(int i=0;i<k;i++){
        lsum+=cardPoints[i];
    }
    maxsum=lsum;
    int rightindex=n-1;
    for(int i=k-1;i>=0;i--){
        lsum=lsum-cardPoints[i];
        rsum=rsum+cardPoints[rightindex];
        rightindex--;
        maxsum=max(maxsum,rsum+lsum);
    }
    return maxsum;
}



int main(){

    string s = "abcabcbb";
    cout << "Input String: " << s << endl;
    cout << "Length: " << lengthOfLongestSubstring(s) << endl;
    cout<<endl;


    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout<<longestOnes(nums, k) << endl;
    cout<<endl;


    vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};
    cout << "Maximum Fruits: "<<totalFruit(fruits) << endl;
    cout<<endl;


    string s2 = "AABABBA";
    int k2 = 1;
    cout << characterReplacement(s2, k2) << endl;
    cout<<endl;


    vector<int> nums2 = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << numSubarraysWithSum(nums2, goal) << endl;
    cout<<endl;

    vector<int> nums3= {1, 1, 2, 1, 1};
    int k3 = 3;
    cout << numberOfSubarrays(nums3, k3) << endl;
    cout<<endl;


    string sampleInput1358 = "abcabc";
    int totalSubstrings1358 = numberOfSubstrings(sampleInput1358);
    cout << "Input: " << sampleInput1358 << '\n';
    cout << "Output: " << totalSubstrings1358 << '\n';
    cout<<endl;


    vector<int> sampleCards = {1, 2, 3, 4, 5, 6, 1};
    int cardsToPick = 3;
    int obtainedScore =maxScore(sampleCards, cardsToPick);
    cout << "Maximum Score = " << obtainedScore << endl;

    return 0;
}