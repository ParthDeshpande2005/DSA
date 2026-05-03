#include<bits/stdc++.h>
using namespace std;

void leetcode22(int n){
    string s(n,'(');
    string t(n,')');
    string st=s+t;
    vector<string> allcombination;
    do{
        allcombination.emplace_back(st);
    }
    while(next_permutation(st.begin(),st.end()));

    vector<string> answer;
    
    for(string c:allcombination){
        int balance=0;
        for(char check:c){
            if(check=='(') balance++;
            if(check==')'){
                balance--;
                if(balance<0) break;
            }
        }
        if(balance==0) answer.emplace_back(c);
    }
    cout<<"[";
    for(string ans:answer){
        cout<<'"'<<ans<<'"'<<",";
    }
    cout<<"]";
}

void find_max1838(map<int,int>mpp)
    {
        int maxvalue=1;
        int maxkey;
        for(auto it: mpp)
        {
            if(it.second>=maxvalue)
            {
                maxvalue=it.second;
                maxkey=it.first;
            }
        }
        cout<<maxkey;
    }
void leetcode1838(vector<int> nums,int k){
    map<int,int> mpp;
    int sum=k;
    int length=0;
    for(auto it:nums){
        sum +=it;
        length+=1;
        mpp[it]++;
    }
    cout<<sum<<" ";
    int avg=sum/length;
    cout<<avg;
    auto it=mpp.find(avg);
    int freqavg=(*it).second;
    
    for(int j=0;j<k;j++){
        if(freqavg==0){
            
        }
    }

}


void leetcode125(string s){
    //is ka time limit excide ho raha hai->
    // string newstring="";
    // for(int i=0;i<s.size();i++){
    //     char lowercase=static_cast<char>(tolower(static_cast<unsigned char>(s[i])));
    //     if(isalnum(lowercase)){
    //         newstring=newstring+lowercase;
    //         // cout<<lowercase-'a'<<endl;
    //     }
    // }
    // // cout<<newstring;
    // string answer="";
    // for(int i=newstring.size()-1;i>=0;i--){
    //     char ans;
    //     ans=newstring[i];
    //     answer=answer+ans;
    // }
    // if(newstring==answer) cout<<"true";
    // else cout<<"False";

    string a="";
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])) {
                a+=s[i];
            }
        }

        transform(a.begin(),a.end(),a.begin(),[](unsigned char c){return tolower(c);});

        string temp=a;
        reverse(temp.begin(),temp.end());
        if(temp==a) cout<<"true";
        else cout<<"false";
}


int pivotIndex724(vector<int>& nums) {
    int frontsum=0;
    for(int i=0;i<nums.size();i++){
        int backsum=0;
        // cout<<i<<endl;
        for(int j=nums.size()-1;j>i;j--){
            backsum +=nums[j];
            if(j-1==i){
                // cout<<i<<" "<<j<<endl;
                // cout<<frontsum<<" "<<backsum<<endl;
                if(frontsum==backsum) return i;
            }   
        }
        frontsum +=nums[i];
    }
    // cout<<frontsum;
    return -1;
    
        // int index=-1;

        // int end=0;
        // map<int,int> mpp;
        // mpp[0]=-1;
        // int sum=0;
        // for(int i=0;i<nums.size();i++){
        //     sum=sum+nums[i];
        //     mpp[sum]=i;
        //     end=sum;
        // }
        // cout<<end<<endl;
        // for(auto it:mpp){
        //     cout<<it.first<<" "<<it.second+1<<endl;
        //     if(2*(it.first)+nums[it.second+1]==end){
                
        //         index=it.second+1;
        //     }
        // }
        // return index;

}



void maxFrequency1838(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    for(int i=0;i<k;i++){
        int maxi=1;
        int maxindex=nums[nums.size()-1];
        int count=1;
        int tempindex=nums[0];
        for(int j=0;j<nums.size()-1;j++){
            if(nums[j]==nums[j+1]){
                count +=1;
                if(count>maxi){
                    maxi=count;
                    maxindex=tempindex;
                }
            }
            else{
                // cout<<"1"<<" ";
                count=1;
                tempindex=nums[j+1];
            }
            cout<<endl;
        }
        nums[maxindex-1] +=1;
    }
}



bool comp(string a,string b){
    if(a.size()<=b.size()) return true;
    else return false;
}
string longestCommonPrefix(vector<string>& strs) {
    sort(strs.begin(),strs.end(),comp);
    string answer="";
    for(int i=0;i<strs[0].size();i++){
        for(int j=0;j<strs.size();j++){
            if(strs[j][i]!=strs[0][i]) return answer;  
        }
        answer += strs[0][i]; 
    }

}






int main(){
    // leetcode22(2);

    // leetcode1838({1,2,4},5);
    
    // leetcode125("0P");

    // vector<int> arr={1,2,3};
    // string ans="";
    // for(auto it:arr){
    //     ans=ans+to_string(it);
    // }
    
    // if(next_permutation(ans.begin(),ans.end())){
    //     cout<<ans;
    // }
    
    // vector<int> arr={1,7,3,6,5,6};
    // cout<<pivotIndex724(arr);

    // vector<int> arr={1,2,4};
    // maxFrequency1838(arr,5);
    // for(auto it:arr){
    //     cout<<it<<" ";
    // }

    // vector<string> que={"cardog","carracecar","car"};
    // string ans=longestCommonPrefix(que);
    // cout<<ans;


    // vector<int> que={1,2,3,12};
    // int ans=minimumCost(que);
    // cout<<ans;



    return 0;
}