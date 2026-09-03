// #include <bits/stdc++.h>
// using namespace std;

// //If,else
// int main(){
//     int age;
//     cin>>age;
//     if(age<18){
//         cout<<"Not an adult";
//     }
//     else{//it is not madatory to write a else statement.we can also omite the else statement.then noting will be printed.
//         cout<<"adult";
//     }
//     return 0;
// }

// /*
// this is how we 
// write a multiple line
// comment
// */

// //Else If
// #include <iostream>
// using namespace std;
// int main(){
//     int marks;
//     cin>>marks;
//     if(marks<25){
//         cout<<"F";
//     }
//     else if(marks<=44){ //agar upar ka condition true hoga to ye wala condition check nahi hoga.
//         cout<<"E";
//     }
//     else if(marks<=49){
//         cout<<"D";
//     }
//     else if(marks<=59){
//         cout<<"C";
//     }
//     else if(marks<=79){
//         cout<<"B";
//     }
//     else if(marks<=100){
//         cout<<"A";
//     }
//     return 0;
// }

//Nested if- we are able to use multiple if inside of a if
#include <bits/stdc++.h>
using namespace std;
int main(){
    int age;
    cin>>age;
    if(age<18){
        cout<<"not eligible for job";
    }
    else if(age<=57){
        cout<<"eligible for job";
        if(age>=55){
            cout<<", but retirement soon";
        }    
    }
    else{
        cout<<"retriment time";
    }
    return 0;
}