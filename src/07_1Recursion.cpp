#include<bits/stdc++.h>
using namespace std;




//leetcode 8 using recursion->
int helper(int i,string s,long long sum,int sign){
    if(i>=s.size()|| !isdigit(s[i])){
        return (int)sum*sign;
    }

    sum=(sum*10)+(s[i]-'0');

    if(sum*sign<=INT_MIN) return INT_MIN;
    if(sum*sign>=INT_MAX) return INT_MAX;

    return helper(i+1,s,sum,sign);
}
int myAtoi(string s) {
    //recursixe solution->
    int i=0;
    int n=s.size();

    while(i<n && s[i]==' '){
        i++;
    }
    int sign=1;
    if(i<n && (s[i]=='+' || s[i]=='-')){
        if(s[i]=='-') sign=-1;
        i++;
    }
    long long sum=0;
    return helper(i,s,sum,sign);
}


//IMP  range of int->
//-2,147,483,648 to 2,147,483,647
//see how range in negative is 1 more than even range so you can not directly 
//convert negatie to positive as it will go out of range.

//Binary exponential->  //leetcode 50
double helper2(double ans,double x,long long nn,int sign){
    //can be writen better -> no need to send ans variable,sign can be checked and maintaied in fun and not recursion.
    if(nn==0){
        if(sign==-1){
            return 1/ans;
        }
        else return ans;
    }
    if(nn%2==0){
        return helper2(ans,x*x,nn/2,sign);
    }
    else {
        return helper2(ans*x,x,nn-1,sign);
    }

}
double myPow(double x, int n) {
    //recursive->
    long long nn=n;
    int sign=1;
    if(nn<0){
        nn=nn*-1;
        sign =-1;
    }
    double ans=1;
    return helper2(ans,x,nn,sign);


    //Optimal iterative->
    // double ans=1;
    // long long nn=n;
    // if(nn<0){
    //     nn=-1*nn;
    // }
    // while(nn){
    //     if(nn%2){  //1 is treated as true and 0 is treated as false in cpp.
    //         ans=ans*x;
    //         nn=nn-1;
    //     }
    //     else{
    //         x=x*x;
    //         nn=nn/2;
    //     }
    // }
    // if(n<0) ans=(1)/(ans);
    // return ans;

    //Brute force-> 
    //for(1->n) ans=ans*x;

}


//leetcode 1922->
const long long MOD = 1000000007;
long long power(long long x, long long n) {
    if (n == 0) return 1.0;
    if (n == 1) return x;

    if (n % 2 == 0) {  
        return power((x * x)%MOD, n / 2)%MOD;//har bar MOD karna padta hai.
    }
    return x * power((x)%MOD, n - 1)%MOD;
}
int countGoodNumbers(long long n) {
    if(n%2==0){
        return (power(4,n/2)*power(5,n/2))%MOD;
    }

    return (power(4,n/2)*power(5,n/2+1))%MOD;
}



//sort a stack->
void insert(stack<int> &st,int temp){
    if(st.empty() || st.top()<=temp){
        st.push(temp);
        return;
    }
    int val=st.top();
    st.pop();
    insert(st,temp);

    st.push(val);
}
void sortstack(stack<int> &st){
    if(!st.empty()){
        int val=st.top();
        st.pop();

        sortstack(st);
        
        insert(st,val);
    }
}


void insertbottom(stack<int> st,int val){
    if(st.empty()){
        st.push(val);
        return;
    }
    int topval=st.top();
    st.pop();

    insertbottom(st,val);

    st.push(topval);
}
void reverseStack(stack<int> st){
    if(st.empty()) return;

    int topval=st.top();
    st.pop();

    reverseStack(st);

    insertbottom(st,topval);
}


int main(){


    string s1 = "42";
    string s2 = "   -42";
    string s3 = "4193 with words";
    string s4 = "words and 987";
    string s5 = "-91283472332";
    string s6 = "2147483648";
    cout << myAtoi(s1) << endl;
    cout << myAtoi(s2) << endl;
    cout << myAtoi(s3) << endl;
    cout << myAtoi(s4) << endl;
    cout << myAtoi(s5) << endl;
    cout << myAtoi(s6) << endl;
    cout<<endl;


    cout << myPow(2.0, 10) << endl;      // 1024
    cout << myPow(2.1, 3) << endl;       // 9.261
    cout << myPow(2.0, -2) << endl;      // 0.25
    cout << myPow(-2.0, 3) << endl;      // -8
    cout << myPow(-2.0, 4) << endl;      // 16
    cout << myPow(1.0, INT_MIN) << endl; // 1
    cout<<endl;


    cout << "n = 1  -> " << countGoodNumbers(1) << endl;
    cout << "n = 4  -> " << countGoodNumbers(4) << endl;
    cout << "n = 50 -> " << countGoodNumbers(50) << endl;
    cout << "n = 1000000     -> " << countGoodNumbers(1000000) << endl;
    cout << "n = 1000000000  -> " << countGoodNumbers(1000000000LL) << endl;
    cout<<endl;



    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);
    st.push(5);
    sortstack(st);
    cout << "Sorted stack (descending order): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout<<endl;



    stack<int> st1;
    st1.push(4);
    st1.push(1);
    st1.push(3);
    st1.push(2);
    // Reverse the stack
    reverseStack(st1);
    // Print the reversed stack
    cout << "Reversed Stack: ";
    while (!st1.empty()) {
        cout << st1.top() << " ";
        st1.pop();
    }
    cout << endl;


    return 0;
}