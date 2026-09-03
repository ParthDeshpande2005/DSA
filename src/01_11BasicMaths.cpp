#include<bits/stdc++.h>
using namespace std;

void Digit(int n){
    int temp=n;
    int temp2=n;
    int count=0;
    //Method 1-->
    while(temp>0){
        temp=temp/10;
        count++;
    }
    cout<<count<<endl;

    // We also use % to find the digits
    //prints all digit in reverse order
    while(temp2>0){
        int n;
        n=temp2%10;
        temp2=temp2/10;
        cout<<n<<endl;
    }

    //Method 2-->using log10 as we are dividing by 10 multiple times.
    int count2=(int)(log10(n)+1);//converting float to int
    cout<<count2;
}

void ReverseNumber(int n){

    // int temp=n;
    // while(temp>0){
    //     int n;
    //     n=temp%10;
    //     temp=temp/10;
    //     cout<<n;
    // }
    //above method cant be used as it converts 100 to 001 etc.

    int temp2=n;
    int solution=0;
    while(temp2>0){
        int digit;
        digit=temp2%10;
        temp2=temp2/10;
        solution=(solution*10)+digit;
    }
    cout<<solution;
}

void CheckPalindrome(int n){

    int temp2=n;
    int solution=0;
    int digit;

    while(temp2>0){
        digit=temp2%10;
        temp2=temp2/10;
        solution=(solution*10)+digit;
    }
    
    if(n==solution) cout<<"True";
    else cout<<"False";
}

void ArmstrongNumber(int n){
    //numbers whose addition of power(power of number of digit) of digits gives same number.
    //371=3^3+7^3+1^3
    //1634=1^4+6^4+3^4+4^4
    //the power=no of digits in number.
    int temp2=n;
    int solution=0;
    int digit;

    int count1=(int)(log10(n)+1); //IMP 

    while(temp2>0){
        digit=temp2%10;
        temp2=temp2/10;
        solution=solution+pow(digit,count1);
    }
    if(n==solution) cout<<"True";
    else cout<<"False";

}

void PrintAllDivision(int n){
    
    //Method 1-->
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }  
    }
    cout<<endl;

    //Method 2-->
    vector<int> answer;
    for(int i=1;i*i<=n;i++){//can also use i<=sqrt(n) instead of i*i<=n.allways use i*i<=n 
        //as the n might be updating some time so the n must also be changed with each loop. 
        if(n%i==0){
            answer.emplace_back(i);
            if(n/i!=i) answer.emplace_back(n/i);
        }   
    }   
    sort(answer.begin(),answer.end());
    for(int it:answer){
        cout<<it<<" ";
    }

}

void CheckForPrime(int n){

    int count=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            count++;
            if((n/i)!=i) count++;
        }
    }
    if(count==2) cout<<"True";
    else cout<<"False";
}

void GCD_HCF(int n1,int n2){
    int gcd=1;
    for(int i=1;i<=min(n1,n2);i++)//we can also do this in reverse but time complexity remains same.
    {
        if(n2%i==0 && n1%i==0){
            gcd=i;
        }
    }
    cout<<gcd;
}

void EquilateralAlgorithm(int a,int b){//to find hcf
    //gcd(a,b)=gcd=(a%b,b)  a>b
    //this algorithm has lower time complexity that above gcd code
    while(a>0&&b>0)
    {
        if(a>b) a=a%b;
        else b=b%a;
    }
    if(a==0) cout<<b;
    else cout<<a;

}


int main(){

    // Digit(9362);
    // ReverseNumber(1234500);
    // CheckPalindrome(112211);
    // ArmstrongNumber(1634);
    // PrintAllDivision(36);
    // CheckForPrime(17);
    // GCD_HCF(9,12);
    // EquilateralAlgorithm(10,52);

    return 0;
}