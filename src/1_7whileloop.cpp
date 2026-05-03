#include<iostream>
using namespace std;

int main(){
    int i=1;
    while(i<=5){
        cout<<"parth"<<i<<endl;
        i=i+1;//imp or we get stuck in infinite loop.
    }

    cout<<endl;
    //do while
    //allow the code to run minium of one time even if condition is not true
    int j=2;
    do{
        cout<<"parth"<<j<<endl;
        j=j+1;
    }while(j<=4);
    cout<<i<<" "<<j<<endl;
    return 0;
}