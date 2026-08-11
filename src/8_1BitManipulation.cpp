#include<bits/stdc++.h>
using namespace std;


string convert2binary(int n){
    string result="";
    if(n==0) return "0";
    while(n>0){
        if(n%2==1) result+="1";
        else result+="0";
        n=n/2;
    }
    reverse(result.begin(),result.end());
    return result;
}


int convert2decimal(string s){
    int sum=0;
    int p2=1; //stores power of 2.
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='1'){
            sum+=p2;
        }
        p2=p2*2;
    }
    return sum;
}

//int -> 32 bits.
//long long -> 64 bits.

//1's compliment  and 2's compliment. i dont know the code yet but i know the concept.

//about operators    and(&)   or(|)    xor(^)   shift-> rightshift(>>)  leftshift(<<)    NOT(~)
// and ( & )--> all true=true  else false.
// or ( | )--> all false=false  else true.
// xor ( ^ )--> odd 1's= 1   even 1's=0
// rightshift  >>  shift binary to right.
// leftshift   <<  shift binary to left.
// ~  ex=>  ~(10110)-->01001     0->1 and 1->0

//also the INT_MIN and INT_MAX storing logic that why is INT_MIN one larger etc in notes->
//read the photo of notes on day 21-7-26 from galary to get best understanding


//check if the ith bit is set or not.
//using leftshift operator.
bool ifithbitset(int n,int i){
    //brute force->
    //convert decimal into binary string
    //then traversal from the back check if the ith bit is 1 or 0.

    //optimal -> using leftshift and & oprator
    if((n & (1<<i))!=0) return true;
    // 1<<2 --> 00...00100
    //similar to 2 the 1 moves i places and rest is zero.
    // so when we use & operator if the bit is set we get number greater than 0
    //if the bit is not set we get 0.
    return false;

}
//using rughtshift operator.
bool ifithbitset2(int n,int i){
    //we will right shift the number by i places and do & with 1.->
    if((n>>i)&1==1) return true;
    else return false;
}


//set ith bit-> if the bit is all ready set keep it that way.
int setithbit(int n,int i){
    //bruter force->
    //convert into binary string change the ith bit from end and change the string into binary again.

    //optimal-> leftshift 1 by i place and then use |.
    return n|(1<<i);
}

//different apporach learn this->
//clear ith bit->
int clearithbit(int n,int i){
    return (n & (~(1<<i)));
}


//toggle the ith bit--> using xor ^
int toggleithbit(int n,int i){
    return n^(1<<i);
}


//remove the last set bit-->
int removelastsetbit(int n){
    //logic->
    //n=16 (10000) --> n-1=15(01111)
    //n=40 (101000)--> n-1=39(100111)
    //we observe the right most bit turns to 0 and every next bit gets converted to 1.

    //so 16 & 15
    //(10000 & 01111) = 00000.
    //for 40 & 39
    //(101000 & 100111) = 100000.

    return n & n-1;
}


//check if the number is a power of 2
bool checkifpowerof2(int n){
    //if there is only 1 set bit then it is a power->
    if(n<=0) return false; // as negative number and 0 can't be power of 2
    if((n & (n-1))==0) return true;
    else return false;
}


//count the number of set bit->
int cntsetbits(int n){
    //only brute force solution->
    int cnt=0;
    while(n>1){
        //odd number when & with one will give 1.
        //even number when & with 1 will give 0.
        cnt+=n&1;  //insted of n%2==1
        n=n>>1;    //n=n/2
    }
    if(n==1) cnt+=1;
    return cnt;
}

//method 2-> finding 
//watch last 5 min of video to understand this concept.
//https://www.youtube.com/watch?v=nttpF8kwgd4
//multiple time right most bit ko 0 kar rahe hai jab tak n zero nahi hota
int cntsetbits2(int n){
    int cnt=0; 
    while(n!=0){
        n=n&(n-1);
        cnt++;
    }    
    return cnt;
}


//leetcode 29 
//Divide two intigers without /,*,%->
int divide(int dividend, int divisor) {
    bool sign=true;
    if(dividend<0 && divisor>0) sign=false;
    if(dividend>=0 && divisor<0) sign=false;

    long long quotient = 0;
    long long n = llabs((long long)dividend);
    long long d = llabs((long long)divisor);

    while(n>=d){
        int i=0;
        while(n>=(d<<i)){ 
            i++;
        }
        //striver while(n>=(d<<(cnt+1))){cnt+=1}
        //he starts from cnt+1.
        n=n-(d<<(i-1));
        quotient+=(1<<(i-1));
    }

    if(quotient==(1<<31)){
        if(sign){
            return INT_MAX;
        }
        else{
            return INT_MIN;
        }
    }
    if(sign){
        return quotient;
    }
    return -quotient;

}


int main(){

    string binary13=convert2binary(13);
    cout<<binary13<<endl;


    int decimal13=convert2decimal(binary13);
    cout<<decimal13<<endl;


    //swap 2 number using 2 number and no extra space.
    //we can evsn use +,-,/,* to do the same.
    //this code is using recursion.
    int a=2;
    int b=3;
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<"a="<<a<<" "<<" b="<<b<<endl;

    //using left shift.
    if(ifithbitset(13,2)==true){ //false for ifithbitset(13,1)
        cout<<"bit is set.";
    }
    else{
        cout<<"bit is not set.";
    }
    cout<<endl;

    //using right shift
    if(ifithbitset2(13,1)==true){ //true for ifithbitset2(13,2)
        cout<<"bit is set.";
    }
    else{
        cout<<"bit is not set.";
    }
    cout<<endl;

    //set ith bit.
    cout<<setithbit(13,1)<<endl; //13(1101)--> 15(1111) changes 2nd bit to 1.


    //clear ith bit.
    cout<<clearithbit(13,2)<<endl; //13(1101)--> 9(1001)


    //toggle ith bit 0-->1  1-->0
    cout<<toggleithbit(13,2)<<endl; //13(1101)--> 9(1001)
    cout<<toggleithbit(13,1)<<endl; //13(1101)--> 15(1111)


    //remove the last set bit-> 
    //12(1100) -->  8(1000)
    //13(1101) --> 12(1100)
    //logic is explained in function.
    cout<<removelastsetbit(12)<<endl;
    cout<<removelastsetbit(13)<<endl;


    //check if number is power of 2.
    if(checkifpowerof2(16)==true){
        cout<<"number is power of 2"<<endl;
    }
    else cout<<"number is not power of 2"<<endl;


    //count the number of set bits->
    cout<< cntsetbits(13)<<endl;
    cout<< cntsetbits2(13)<<endl;


    
    cout <<divide(10, 3) << endl;                  // 3
    cout <<divide(7, -3) << endl;                  // -2
    cout <<divide(-2147483648, -1) << endl;        // 2147483647
    cout <<divide(-2147483648, 1) << endl;         // -2147483648
    cout <<divide(2147483647, 2) << endl;          // 1073741823




    return 0;
}