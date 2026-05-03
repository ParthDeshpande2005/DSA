
//functions
//allways define function before main()
#include<iostream>
using namespace std;
//void-> which does not return anything
//return
//parameterised
//non parameterised


// void printname(string name){
//     cout << "hey" << name << endl;
//     }
// int main(){
    // string name;
    // cin>>name;
    // printname(name);

    // string name2;
    // cin>>name2;
    // printname(name2);
    

//take two number and print its sum
//there are also inbuilt function such as min,max,gcd,..ect which can be used by including different library
//return function are used to return the output which can be used by any other function.
int sum(int num1,int num2){//if we take void insted of int we need to use cout insted of return.
    int num3=num1+num2;//5+6=11
    return num3;//return 11
}
int maxx(int num1,int num2){
    if(num1>num2)return num1;//single line statement does not require {}.
    else if(num2>num1)return num2;//if return is not specified it will return a garbage value.
//here we get a garbage value for = case.but the garbage value is sometimes from history so we may get correct answer by coincidence
}
int main(){
    int num1,num2;
    cin>>num1>>num2;
    int ans = sum(num1,num2);
    cout<<ans<<endl;
    int ans2 = maxx(num1,num2);
    cout<<ans2;
    return 0;
}


// //pass by value
// void dosomething(int num){
//     cout<<num<<endl;
//     num+=5;
//     cout<<num<<endl;
//     num+=5;
//     cout<<num<<endl;
// }
// int main(){
//     int num=10;
//     dosomething(num);//copy of num=10 is send to dosomthing function
//     cout<<num<<endl;//output is 10 and not 20,also work with string
//     return 0;
// }


// //pass by reference
// void dosomething(string &s){// //due to the use of &s the original value of s will be changed.
//     s[0] ='t';
//     cout<< s << endl;
// }
// int main(){
//     string s ="raj";// //can be done same of int,float...
//     dosomething(s);
//     cout << s << endl;
//     return 0;
// }


//pass by reference in array

// void dosomething(int arr[],int n){
//     arr[0]+=100;
//     cout<<"value inside function: "<<arr[0]<<endl;
// }//array is allways pass by reference and not pass by value.
// int main(){
//     int n = 5;
//     int arr[n];
//     for(int i=0;i<=4;i=i+1){
//         cin>>arr[i];
//     }
//     dosomething(arr,n);
//     cout<<"value inside int main: "<<arr[0]<<endl;
//     return 0;
// }