#include<iostream>
using namespace std;

int main(){
    string s = "parth";
    int len = s.size();//here len=5  //we can also use .length() for string.
    s[len-1]='z';//we can't do "z" as it is a 'z'->character and not a string
    cout<< s[0];
    cout<< s[4];//h is replaced by z
    return 0;
}

//in string we can even use tolower()--> this is implemented on charcter only.
//stoi(str) used to convert the string to int.

//out of size() and length() 
//size() is prefered as it works for all containers and string.
//where as length() does not work for containers
//for competive coding use size().
//use length() for stirng readiblity purpose.