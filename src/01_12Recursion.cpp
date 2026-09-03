#include<bits/stdc++.h>
using namespace std;

/*Recursion->When a function calls
itself until a specified condition is met.*/

// //IMP->euclidian algorithm.
// int GCD(int a,int b){
//     if(b==0){
//         return a;
//     }
//     return GCD(b,a%b);
// }

int cnt0=0;
void recursion1(){//simple recursion example
    if(cnt0==3) return;//Base condition
    cout<<cnt0<<endl;
    cnt0++;
    recursion1();
}

void printnameNtimes(int i,int n){
    if(i>n) return;//Base conditon
    cout<<"Parth"<<endl;
    printnameNtimes(i+1,n);
}

void printfrom1toN(int i,int n){
    if(i>n) return;//Base condition
    cout<<i<<" ";
    printfrom1toN(i+1,n);
}

void printfromNto1(int i,int n){
    if(n<i) return;
    cout<<n<<" ";
    printfromNto1(i,n-1);
}

void printfrom1toNbacktracking(int i,int n){
    if(i<1) return;
    printfrom1toNbacktracking(i-1,n);
    cout<<i<<" ";
}

void printfromNto1backtracking(int i,int n){ 
    if(i>n) return;
    printfromNto1backtracking(i+1,n);
    cout<<i<<" ";
}

void SumofFirstNnumbers(int n,int sum){//In this method we use parameters to get sum
    if(n<1) {
        cout<<sum;
        return;
    }
    SumofFirstNnumbers(n-1,sum+n);
}

int SumofNnumberMethod2(int n){
    if(n==0) return 0;
    return n+SumofNnumberMethod2(n-1);
}

int factorialofN(int n){
    if(n==1) return 1;
    return factorialofN(n-1)*n;
    /*can also be done using parameters like factorial(n*n-1) 
    and giving base condition as n>1*/
}

void reversearray(int i,int arr[],int n){
    if(i>=n/n) return;
    swap(arr[i],arr[n-i-1]);
    reversearray(i+1,arr,n);

}

bool checkPalindrome(int i,string &s){
    if(i>=s.size()/2) return true;
    if(s[i]!=s[s.size()-i-1]) return false;
    return checkPalindrome(i+1,s);
}  

//Multiple Recursion calls
int Fibonacci(int n){
    //time complexity=2^n

    // if(n==1) return 1;
    // if(n==2) return 1;
    if(n<=1) return n;
    return Fibonacci(n-1)+Fibonacci(n-2);

}

int main(){
    
    // recursion1();
    // printnameNtimes(1,6);
    // printfrom1toN(1,5); 
    // printfromNto1(1,5);
    // printfrom1toNbacktracking(5,5);
    // printfromNto1backtracking(1,5);
    // SumofFirstNnumbers(6,0);
    // cout<<SumofNnumberMethod2(5);
    // cout<<factorialofN(4);

    // int arr[]={1,2,3,4,5};
    // int n=5;
    // reversearray(0,arr,5);
    // for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    // string s="madam";
    // cout<<checkPalindrome(0,s);

    // cout<<Fibonacci(5);

    return 0;
}