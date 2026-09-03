//use ctrl+shift+B to get output in output.txt coloum and give input in input.txt coloum.

#include <bits/stdc++.h>//used to include all library
// normally we use #include<iostream>
using namespace std;
//we use using namespace std so we can directly write cout or we need to write std::cout

void str(){
    string str;
    cin.ignore();//only used when there is a previous cin before getline.
    cout<<"\n";//else getline will read an empty line
    getline(cin,str);
    cout<< str;
}

int main(){
    cout<<"hi Parth" << "\n" ;// we can use \n or endl
    int a,b,c;
    cin>>a;
    cin>>b>>c;
    cout<<"value of a is "<< a << endl << "hi again" << "\n" ;
    cout<<"value of b is "<< b << " and c is " << c;
    str();
    return 0;
}



    //for taking input as string and then converting it to vector ...
    // string line;
    // getline(cin, line);   // input: 1 2 3 4 5

    // vector<int> v;
    // stringstream ss(line);

    // int num;
    // while (ss >> num) {
    //     v.push_back(num);
    // }


//int,long,long-for intiger numbers
//float,double-for float numbeers
//string,getline-for words,line
//char-for a characterlike a,b,c,...
//char is defined in '' and not int in ""



//stringstream ss ko padh na hai
//take input as string and convert it to array