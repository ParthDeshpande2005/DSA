#include<bits/stdc++.h>
using namespace std;

//IMP
//using i*i<=n is allways better than writing i<=sqrt(n)

//print all divisor of number
vector<int> alldivisor(int N){
    vector<int> result;
    for(int i=1;i<=sqrt(N);i++){
        if(N%i==0){
            result.push_back(i);
            if(N/i!=i){
                result.push_back(N/i);
            }
        }
    }
    sort(result.begin(),result.end());
    return result;
}  


//print all prime factors of number->
//to check prime->
bool isprime(int n){
    int cnt=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            cnt++;
            if(n/i!=i){
                cnt++;
            }
        }
        if(cnt>2) break;
    }
    if(cnt==2) return true;
    return false;
}
//to print all prime factors->
//using the same kind of appoarch as we used in finding all divisor.
vector<int> allprimefactors(int n){
    vector<int> result;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(isprime(i)) result.push_back(i);
            if(n/i!=i){
                if(isprime(n/i)) result.push_back(n/i);
            }
        }
    }
    sort(result.begin(),result.end());
    return result;
}


//we use the school method to find the prime factors.
//   2|780
//   2|390
//   3|195
//   5|65
//  13|13
//    |1
//watch video to get better idea-> https://www.youtube.com/watch?v=LT7XhVdeRyg
vector<int> primefactorsbetter(int n){
    vector<int> result;
    for(int i=2;i<=n;i++){
        if(n%i==0){
            result.push_back(i);
            while(n%i==0){
                n=n/i;
            }
        }
    }
    return result;
}

vector<int> primefactorsoptimal(int n){
    vector<int> result;
    for(int i=2;i*i<=n;i++){ // can't use i<=sqrt(n) as the value of n changes every time.
        if(n%i==0){
            result.push_back(i);
            while(n%i==0){
                n=n/i;
            }
        }
    }
    if(n!=1) result.push_back(n);  //do dry run on 780 & 16 as n and know why this condition is used.
    //keep in mind the n changes in each iteration. so hence we need to check if the number n is it self prime or not.
    //n will reduce to either a prime or 1.
    return result;
}


//binary exponentiation power->
double power(int x,int n){//x is number and n is power.
    double ans=1.0;
    long long nn=n;
    if(nn<0) nn=-1*nn;
    while(nn>0){
        //if nn is even --> we multiply x*x  and reduce nn=nn/2
        if(nn%2==0){
            x=x*x;
            nn=nn/2;
        }
        //when nn is odd--> we multiply ans*x  and nn=nn-1
        else{
            ans=ans*x;
            nn=nn-1;
        }
    }
    if(n<0) ans=(double)1.0/ans;
    return ans;
}


//Sieve of Eratosthenes -> check if the number is prime in O(1)
//must watch video to understand teh concept completely ->
//https://www.youtube.com/watch?v=g5Fuxn_AvSk
vector<bool> isprimesieve(int n){//the bool will be true for prime and false for non prime.
    vector<bool> prime(n+1,true);
    //we use pre computation to find the prime factors till the given number.
    
    // We iterate while i*i <= n because multiples below i*i
    // have already been marked by smaller prime numbers.
    for(int i=2;i*i<=n;i++){
        if(prime[i]==true){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=false;
            }
        }
    }
    if(n >= 0) prime[0] = false;
    if(n >= 1) prime[1] = false;
    return prime;
}


//leetcode 204--> dek lena same as sieve.




int main(){

    // Test Case 1: All Divisors
    int n1 = 36;
    cout << "All divisors of " << n1 << " : ";
    vector<int> divisors = alldivisor(n1);
    for (int x : divisors)
        cout << x << " ";
    cout << "\n\n";

    // Test Case 2: Prime Check
    int n2 = 29;
    cout << n2 << " is ";
    if (!isprime(n2))
        cout << "not ";
    cout << "a prime number\n\n";

    // Test Case 3: All Prime Factors (Divisor Approach)
    int n3 = 780;
    cout << "Prime factors of " << n3 << " (Divisor Approach): ";
    vector<int> pf1 = allprimefactors(n3);
    for (int x : pf1)
        cout << x << " ";
    cout << "\n\n";

    // Test Case 4: Prime Factors (School Method)
    cout << "Prime factors of " << n3 << " (Better): ";
    vector<int> pf2 = primefactorsbetter(n3);
    for (int x : pf2)
        cout << x << " ";
    cout << "\n\n";

    // Test Case 5: Prime Factors (Optimal)
    cout << "Prime factors of " << n3 << " (Optimal): ";
    vector<int> pf3 = primefactorsoptimal(n3);
    for (int x : pf3)
        cout << x << " ";
    cout << "\n\n";

    // Test Case 6: Binary Exponentiation
    int base = 2, exponent = 10;
    cout << base << "^" << exponent << " = "
         << power(base, exponent) << "\n";

    base = 2;
    exponent = -3;
    cout << base << "^" << exponent << " = "
         << power(base, exponent) << "\n\n";

    // Test Case 7: Sieve of Eratosthenes
    int limit = 50;
    vector<bool> prime = isprimesieve(limit);

    cout << "Prime numbers up to " << limit << " : ";
    for (int i = 2; i <= limit; i++) {
        if (prime[i])
            cout << i << " ";
    }
    cout << "\n";



    return 0;
}