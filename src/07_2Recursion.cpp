#include<bits/stdc++.h>
using namespace std;

void generate(int n,string curr,vector<string>& result){
    if(curr.length()==n){
        result.push_back(curr);
        return ;
    }
    generate(n,curr+"0",result);

    if(curr.empty() || curr.back() !='1'){//if we dont use the condition curr.back()!='1' then we can print all the possible combinations.
        generate(n,curr+"1",result);
    }
}


void generateparen(int n,string curr,int open,int close,vector<string>&result){
    if(curr.length()==2*n){
        result.push_back(curr);
        return;
    }

    if(open<n){
        generateparen(n,curr+'(',open+1,close,result);
    }

    if(close<open){
        generateparen(n,curr+')',open,close+1,result);
    }
}
vector<string> generateParenthesis(int n) {
    int open=0;
    int close=0;

    vector<string> result;

    generateparen(n,"",open,close,result);

    return result;
    
}


//Power set->
//S="abc"  ->  "",a,b,c,ab,ac,bc,abc
//allways for n size string there are 2^n subsequence including the empty string.
//a sequence derived from an original string or array by deleting zero or more
// elements without changing the relative order of the remaining elements.
//Recursive-> TC->O(n*2^n) SC->O(n*2^n)
void powerset(string s,int i,string curr,vector<string>& result){
    if(s.size()==i){
        result.push_back(curr);
        return;
    }
    //leave->
    powerset(s,i+1,curr,result);

    //take->
    string take = curr + s[i];
    powerset(s,i+1,take,result);
    
}


//using bitmnipulation-> TC->O(n*2^n)  SC->O(1)
//to understand this logic watch striver video.
void powerset2(string s){
    //for loop num=0->(2^n)-1
    //if n=3  num(0->7)
    int n=s.size();
    //total subsequence=2^n;
    int total=1<<n;

    for(int num=0;num<total;num++){
        string subseq="";
        for(int i=0;i<n;i++){
            //checking if the i th bit is set or not
            if(num & (1<<i)){
                subseq+=s[i];
            }
        }
        cout<<subseq<<" ";
    }
}

//IMP-> TC->O(n^2) as for all elements we check take or leave two condition
//print subsequence whose sum is K->
void printsubsequence(int cur,vector<int>& ds,int sum,int k,vector<int> &arr,int nn){
    if(cur==nn){
        if(sum==k){
            for(auto it:ds) cout<<it<<" ";
            cout<<endl;
        }
        return;
    }
    //pick / take->
    ds.push_back(arr[cur]);
    sum+=arr[cur];
    printsubsequence(cur+1,ds,sum,k,arr,nn);

    //leave->
    sum-=arr[cur];
    ds.pop_back();
    printsubsequence(cur+1,ds,sum,k,arr,nn);
}
//IMP->
//to print only one subsequence 
//same code as last one
bool printsub(int cur,vector<int>& ds,int sum,int k,vector<int> &arr,int nn){
    if(cur==nn){
        //condition satisfied.
        if(sum==k){
            for(auto it:ds) cout<<it<<" ";
            return true;
        }
        //condition not satisfied.
        else return false;
    }
    //pick / take->
    ds.push_back(arr[cur]);
    sum+=arr[cur];
    if(printsub(cur+1,ds,sum,k,arr,nn)==true){
        return true;
    }

    //leave->
    sum-=arr[cur];
    ds.pop_back();
    if(printsub(cur+1,ds,sum,k,arr,nn)==true){
        return true;
    }
    return false;
}
//IMP->
//to print the total subsequence with sum=k
int totalsubsequence(int cur,int sum,int k,vector<int> &arr,int nn){
    if(sum>k) return 0;//only when array contains only positives.
    if(cur==nn){
        if(sum==k){
            return 1;
        }
        return 0;
    }
    //take
    sum+=arr[cur];
    int take=totalsubsequence(cur+1,sum,k,arr,nn);
    //leaave
    sum-=arr[cur];
    int leave=totalsubsequence(cur+1,sum,k,arr,nn);

    return take+leave;
}


//leetcode39->
void recursion(int cur,vector<int>& ans,vector<int>& candidates,int target,vector<vector<int>>& result){
    if(target<0) return;
    if(cur==candidates.size()) {
        if(target==0){
            result.push_back(ans);
        }
        return;
    }

    //take->
    ans.push_back(candidates[cur]);
    //take same cur again.
    recursion(cur,ans,candidates,target-candidates[cur],result);
    

    //skip->
    ans.pop_back();
    recursion(cur+1,ans,candidates,target,result);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    
    vector<vector<int>> result;
    vector<int> ans;

    recursion(0,ans,candidates,target,result);
    
    return result;
}

//leetcode->40
//IMP 
//We use seconf pattern of skip or take using for loop.
//this question we avoid same value.
//check striver video to understand properly.
void recursion2(int cur,vector<int>& ans,vector<int>& candidates,int target,vector<vector<int>>& result){
    if(target==0){
        result.push_back(ans);
        return;
    }

    for(int i=cur;i<candidates.size();i++){
        if(i>cur && candidates[i]==candidates[i-1]){
            continue;
        }

        if(candidates[i]>target) break;

        ans.push_back(candidates[i]);
        recursion2(i+1,ans,candidates,target-candidates[i],result);
        ans.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> ans;

    sort(candidates.begin(),candidates.end());

    recursion2(0,ans,candidates,target,result);
    
    return result;
}


// leetcode->78
//this this pattern 1 of take or skip there are two patterns.
void recursion4(int cur,vector<int> &ans,vector<int>& nums,vector<vector<int>> &result){
    if(cur==nums.size()) {
        result.push_back(ans);
        return;
    }

    //take->
    ans.push_back(nums[cur]);
    recursion4(cur+1,ans,nums,result);

    //skip->
    ans.pop_back();
    recursion4(cur+1,ans,nums,result);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> ans;

    recursion4(0,ans,nums,result);

    return result;
}


//leetcode->90
void recursion5(int cur,vector<int> &ans,vector<int>& nums,vector<vector<int>> &result){
    result.push_back(ans);
    for(int i=cur;i<nums.size();i++){
        if(i>cur && nums[i]==nums[i-1]) continue;
        ans.push_back(nums[i]);
        recursion5(i+1,ans,nums,result);
        ans.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> ans;
    sort(nums.begin(),nums.end());
    recursion5(0,ans,nums,result);
    return result;
}


//leetcode->216
void recursion6(int cur,int n,vector<int> &ans,vector<vector<int>>&result,int k){
    if(ans.size() == k){
        if(n == 0){
            result.push_back(ans);
        }
        return;
    }
    for(int i=cur;i<=9;i++){
        if(i>n) break;
        ans.push_back(i);
        recursion6(i+1,n-i,ans,result,k);
        ans.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> ans;
    int cur=0;
    int sum=0;
    recursion6(1,n,ans,result,k);
    return result;
}


void recursion7(int cur,string ans,string digits,unordered_map<char,string> mpp,vector<string> &result){
    if(ans.length()==digits.length()){
        result.push_back(ans);
        return;
    }

    string current=mpp[digits[cur]];

    for(int j=0;j<current.size();j++){
        ans+=current[j];
        recursion7(cur+1,ans,digits,mpp,result);
        ans.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    unordered_map<char,string> mpp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> result;

    recursion7(0,"",digits,mpp,result);

    return result;
}



int main(){


    int n=3;
    vector<string> result;
    generate(n,"",result);
    for(string &s:result){
        cout<<s<<" ";
    }
    cout<<endl;
    cout<<endl;



    int n1 = 3;
    vector<string> ans = generateParenthesis(n1);
    cout << "Valid Parentheses for n = " << n1 << ":\n";
    for (string s : ans) {
        cout << s << endl;
    }
    cout<<endl;



    string s="abc";
    vector<string> result1;
    powerset(s,0,"",result1);
    for(string s:result1){
        cout<<s<<" ";
    }
    cout<<endl;
    powerset2("abc");
    cout<<endl;
    cout<<endl;



    vector<int> arr={1,2,1};
    int nn=arr.size();
    int k=2;
    vector<int> ds;
    printsubsequence(0,ds,0,k,arr,nn);
    cout<<endl;
    //to print only one subsequence->
    if(printsub(0,ds,0,k,arr,nn)==false){
        cout<<"false";
    }
    cout<<endl;
    //to print the number of subsequence with sum K
    int number=totalsubsequence(0,0,k,arr,nn);
    cout<<number;

    

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result3 = combinationSum(candidates, target);
    cout << "Combinations are:\n";
    for (const auto &combination : result3) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    cout<<endl;

    

    vector<int> candidates2 = {10, 1, 2, 7, 6, 1, 5};
    int target2 = 8;
    vector<vector<int>> result2 = combinationSum2(candidates2, target2);
    cout << "Combinations are:\n";
    for (auto &vec : result2) {
        cout << "[ ";
        for (int x : vec) {
            cout << x << " ";
        }
        cout << "]\n";
    }
    cout<<endl;


    vector<int> subsetInput = {1, 2, 3};
    vector<vector<int>> subsetOutput = subsets(subsetInput);
    cout << "All Subsets:\n";
    for (const auto &subset : subsetOutput) {
        cout << "[ ";
        for (int element : subset) {
            cout << element << " ";
        }
        cout << "]\n";
    }
    cout<<endl;


    vector<int> duplicateSubsetInput = {1, 2, 2};
    vector<vector<int>> duplicateSubsetOutput = subsetsWithDup(duplicateSubsetInput);
    cout << "Subsets (without duplicates):\n";
    for (const auto &subset : duplicateSubsetOutput) {
        cout << "[ ";
        for (int value : subset) {
            cout << value << " ";
        }
        cout << "]\n";
    }
    cout<<endl;



    int requiredNumbers = 3;
    int targetSum = 9;
    vector<vector<int>> combinationSum3Output = combinationSum3(requiredNumbers, targetSum);
    cout << "Combination Sum III:\n";
    for (const auto &combination : combinationSum3Output) {
        cout << "[ ";
        for (int value : combination) {
            cout << value << " ";
        }
        cout << "]\n";
    }
    cout<<endl;


    string phoneDigits = "23";
    vector<string> letterCombinationOutput = letterCombinations(phoneDigits);
    cout << "Letter Combinations:\n";
    for (const string &combination : letterCombinationOutput) {
        cout << combination << " ";
    }
    cout << endl;





    return 0;

}