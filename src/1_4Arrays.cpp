//arrays
#include<iostream>
using namespace std;//else we need to write std::cout,std::endl,
//so basically we are standardzing using this line

int main(){


    //1D array
    int arr1[5];
    // giving input as 7.7 will become 7 due to int datatype
    cin >> arr1[0] >> arr1[1] >> arr1[2] >> arr1[3] >> arr1[4];// //way to take multiple input
    arr1[3] +=10;
    // adding 10 to 3rd no. in array
    arr1[2]=9;
    //changing value of 2 no. in aarray
    cout<<arr1[3]<<endl;
    cout<<arr1 <<endl;//this will print the address of the array not the array value.
    //to print the vale of array we need to use for loop

    //2D array
    int arr2[3][5];
    //left index=row,right index=column
    arr2 [1][3] = 78;
    cout << arr2 [1][3]<<endl;
    cout << arr2 [1][2]<<endl;//printing these will give a garbage value as no value is assigned to it.
    
    return 0;
}

