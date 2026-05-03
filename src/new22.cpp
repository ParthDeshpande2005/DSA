#include <bits/stdc++.h>
using namespace std;



int alter1888_bruteforce(string s){
    int cnt2=INT_MAX;
    int n=s.size();
    if(n==1){
        return 0;
    }
    for(int i=0;i<n;i++){
        int cnt=0;
        string temp=s;
        s = s.substr(1) + s[0];
        for(int i=0;i<n-1;i++){
            if(temp[i]==temp[i+1]){
                cnt=cnt+1;
                if(temp[i+1]=='0'){
                    temp[i+1]='1';
                }
                else if(temp[i+1]=='1'){
                    temp[i+1]='0';
                }
            }   
        }
        cnt2=min(cnt,cnt2);
    }
    return cnt2;
}

int alter1888(string s){
    int n=s.size();
    string s2=s+s;
    string alt1="";
    string alt2="";
    for(int i=0;i<2*n;i++){
        if(i%2==0){
            alt1+='1';
            alt2+='0';
        }
        else{
            alt1+='0';
            alt2+='1';
        }
    }
    int l=0;
    int diff1=0;
    int diff2=0;
    int ans=INT_MAX;
    

    for(int r=0;r<2*n;r++){
        if(s2[r]!=alt1[r]) diff1++;
        if(s2[r]!=alt2[r]) diff2++;

        if(r-l+1>n){
            if(s2[l]!=alt1[l]) diff1--;
            if(s2[l]!=alt1[l]) diff2--;
            l++;
        }

        if(r-l+1==n){
            
            ans=min(ans,min(diff1,diff2));
        }

    }
    return ans;
}

string find1980(vector<string>& nums){
    int n= nums.size();
    for(int i=0;i<n+1;i++){
        string binary="";
        int temp =i;
        while(temp>0){
            binary=char('0'+temp%2)+binary;
            temp=temp/2;
        }
        while(binary.size()<n){
            binary='0'+binary;
        }
        if(find(nums.begin(),nums.end(),binary)==nums.end()){
            return binary;
        }
    }
}

int alter1758(string s){
    int n=s.size();
    string alt1,alt2;
    for(int i=0;i<n;i++){
        if(i%2==0){
            alt1=alt1+'0';
            alt2=alt2+'1';
        }
        else{
            alt1=alt1+'1';
            alt2=alt2+'0';
        }
    }
    int diff1=0;
    int diff2=0;
    for(int i=0;i<n;i++){
        if(s[i]!=alt1[i]) diff1++;
        if(s[i]!=alt2[i]) diff2++;
    }
    return min(diff1,diff2);

    //better solution->
    // int minOperations(string s) {
    //     int n = s.size();
    //     int startWith0 = 0;
    //     for(int i = 0;i<n;i++)
    //     {
    //         if(i%2 == 0)
    //         {
    //             if(s[i] == '1') startWith0++;
    //         }
    //         else
    //         {
    //             if(s[i] == '0') startWith0++;
    //         }
    //     }
    //     return min(startWith0, n -startWith0);
    // }

}

int fac(int num){
    if(num==0 || num==1){
        return 1;
    }
    else{
        return num*fac(num-1);
    }
}
int Binary3129(int zero,int one,int limit){
    int tot=fac(zero+one);
    int facone=fac(one);
    int faczero=fac(zero);
    int pos=(fac(zero+one)/(fac(one)*fac(zero)));
    int diff=0;
    if(one>limit && zero>limit){
        int new1=(fac((zero+one)-limit));
        int ans1=new1/(fac(limit+1)*fac(one-limit+1));

        int new2=(fac((zero+one)-limit));
        int ans2=new2/(fac(limit+1)*fac(zero-limit+1));

        int new3=(fac((zero+one)-2*limit));
        int ans=new3/((fac(limit+1))*(fac(limit+1))); 
        diff=diff+ans1+ans2-ans;
    }
    else if(one>limit){
        int new1=(fac((zero+one)-limit));
        int ans=new1/(fac(limit+1)*fac(one-limit+1));
        diff=diff+ans;
    }
    else if(zero>limit){
        int new1=(fac((zero+one)-limit));
        int ans=new1/(fac(limit+1)*fac(zero-limit+1));
        diff=diff+ans;
    }
    return pos-diff;



    // string s = string(zero, '0') + string(one, '1');
    // vector<string> vec1;
    // do{
    //         // vec1.push_back(s);
    //         cout<<s<<endl;
    //     }
    //     while(next_permutation(s.begin(),s.end()));
}

int main(){
    // int a=alter3("10001100101000000");
    // cout<<a;
    
    // vector<string> num={"111","011","001"};
    // string ans= find1980(num);
    // cout<<ans;

    // int a=alter1758("0100");
    // cout<<a;

    int a=Binary3129(1,1,2);
    cout<<a;
}

//01001001101 it should be 2 as output.