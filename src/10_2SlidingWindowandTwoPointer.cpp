#include<bits/stdc++.h>
using namespace std;


int longestsubstringKdistintchar(string str,int k){
    int n=str.size();
    unordered_map<char,int> mpp;
    int right=0;
    int left=0;
    int maxlen=0;
    while(right<n){
        mpp[str[right]]++;
        if(mpp.size()>k){
            mpp[str[left]]--;
            if(mpp[str[left]]==0){
                mpp.erase(str[left]);
            }
            left++;
        }
        if(mpp.size()<=k){
            maxlen=max(maxlen,right-left+1);
        }
        right++;
    }
    return maxlen;
}


//leetcode 992-->
int subarraywithlessorequal(vector<int>& nums, int k){
    if(k<0) return 0;
    int n=nums.size();
    int left=0;
    int right=0;
    unordered_map<int,int> mpp;
    int ans=0;

    while(right<n){
        mpp[nums[right]]++;
        while(mpp.size()>k){
            mpp[nums[left]]--;
            if(mpp[nums[left]]==0) mpp.erase(nums[left]);
            left++;
        }
        ans+=right-left+1;
        right++;
    }
    return ans;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return subarraywithlessorequal(nums,k)-subarraywithlessorequal(nums,k-1);
}


//leetcode 76-->
string minWindow(string s, string t) {
    int tsize=t.size();
    if(tsize>s.size()) return "";
    unordered_map<char,long long> mpp;
    for(int i=0;i<t.size();i++){
        mpp[t[i]]++;
    }
    string ans="";
    int comp=INT_MAX;
    int n=s.size();
    int left=0;
    int right=0;
    int size=mpp.size();
    int ansleft;
    int ansright;
    while(right<n){
        if(mpp.find(s[right])!=mpp.end()){
            mpp[s[right]]--;
            if(mpp[s[right]]==0) size--;
        }
        while(size==0 && left<=right ){
            if(right-left+1<comp){
                ansleft=left;
                ansright=right;
                comp=right-left+1;
            }
            if(mpp.find(s[left])!=mpp.end()){
                mpp[s[left]]++;
                if(mpp[s[left]]==1){
                    size++;
                }
            }
            left++;
        }
        right++;
    }
    if(comp!=INT_MAX){
        ans=s.substr(ansleft,ansright-ansleft+1);
    }
    return ans;
}


//IMP--> different appoarch-->
string minWindowsubsequence(string s, string t){
    //optimal-->
    int n = s.size();
    int m = t.size();
    int start = -1;
    int minLen = INT_MAX;
    int i = 0;
    while (i < n) {
        // Forward scan: match T
        int j = 0;
        while (i < n) {
            if (s[i] == t[j])
                j++;
            if (j == m)
                break;
            i++;
        }
        if (i == n)
            break;
        // Current window ends at i
        int end = i;
        // Backward scan: minimize the window
        j = m - 1;
        while (j >= 0) {
            if (s[i] == t[j])
                j--;
            i--;
        }
        // i is one position before the start
        i++;
        if (end - i + 1 < minLen) {
            minLen = end - i + 1;
            start = i;
        }
        // Continue from next position
        i++;
    }
    return start == -1 ? "" : s.substr(start, minLen);


    
    // //mt solution-->
    // int ssize=s.size();
    // int tsize=t.size();
    // if(tsize>ssize) return "";

    // int minlen=INT_MAX;
    // int ansl;
    // int ansr;
    // string ans="";

    // for(int i=0;i<ssize;i++){
    //     int j=0;
    //     int z=i;
    //     while(z<ssize && j<tsize){
    //         if(s[z]==t[j]){
    //             j++;
    //         }
    //         z++;
    //     }
    //     if(j<tsize){
    //         break;
    //     }
    //     if(z-i<minlen){
    //         ansl=i;
    //         ansr=z;
    //         minlen=z-i;
    //     }

    // }
    // if(minlen!=INT_MAX){
    //     ans=s.substr(ansl,minlen);
    // }

    // return ans;
}




int main(){

    int ans=longestsubstringKdistintchar("aaabbccd",2);
    cout<<ans<<endl;
    cout<<endl;
    


    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;
    cout << "Number of subarrays with exactly " << k << " distinct integers: "<< subarraysWithKDistinct(arr, k) << endl;
    cout<<endl;


    string source = "ADOBECODEBANC";
    string target = "ABC";
    cout << "Minimum Window: " << minWindow(source, target) << endl;
    cout<<endl;

    string source2 = "abcdebdde";
    string target2 = "bde";
    cout << "Minimum Window Subsequence: " << minWindowsubsequence(source2, target2) << endl;


    return 0;
}