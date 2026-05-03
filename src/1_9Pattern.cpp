#include<iostream>
using namespace std;
//to add a loop for printing all patterns at once.

void pattern00(int n)//doing using one for loop.for pattern 2.//string use karna padta hai.
{
    string name="";
    char add='*';
    for(int i=0;i<n;i++)
    {
        name=name+" "+add;
        cout<<name<<endl;
    }
}

void pattern1(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"* ";
        }
        cout<<endl;    
    }
}

void pattern2(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;    
    }
}

void pattern3(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;    
    }
}

void pattern4(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<i<<" ";
        }
        cout<<endl;    
    }
}

void pattern5(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n-i+1;j++)
        {
            cout<<"* ";
        }
        cout<<endl;    
    }
}

void pattern6(int n)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<n-i+1;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;    
    }
}

void pattern7(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<2*i+1;j++){
            cout<<"*";
        }
         for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        cout<<endl;    
    }
}

void pattern8(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<2*n-(2*i+1);j++){
            cout<<"*";
        }
         for(int j=0;j<i;j++)
        {
            cout<<" ";
        }
        cout<<endl;    
    }
}

void pattern9(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<2*i+1;j++){
            cout<<"*";
        }
         for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        cout<<endl;    
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<2*n-(2*i+1);j++){
            cout<<"*";
        }
         for(int j=0;j<i;j++)
        {
            cout<<" ";
        }
        cout<<endl;    
    }
}

void pattern10(int n){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern10_2(int n){
    for(int i=1;i<=2*n-1;i++){
        int stars=i;
        if(i>n) stars=2*n-i;
        for(int j=1;j<=stars;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern11(int n){
    int start=1;
    for(int i=0;i<=n;i++){
        if(i%2==0)start=1;
        else start=0;
        for(int j=1;j<=i+1;j++){
            cout<<start;
            start=1-start;
        }
        cout<<endl;  
    }
}

void pattern12(int n){
    for(int i=0;i<n;i++){
        int a=i;
        for(int j=1;j<=i+1;j++){
            cout<<j;
        }
        for(int j=0;j<2*n-2*(i+1);j++){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            cout<<a+1;
            a=a-1;
        }
        /*for(int j=i;j>=1;j--)
            cout<<j */
        cout<<endl;
    }
}

void pattern13(int n){
    int num=1;
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=i;k++)
        {
            cout<<num<<" ";
            num=num+1;
        }
        cout<<endl;
    }
}

void pattern14(int n){
    for(int i=0;i<n;i++){
        for(char ch='A';ch<='A'+i;ch++){
            cout<<ch<<" ";
        }
    cout<<endl;
    }
}

void pattern15(int n){
    for(int i=n;i>=0;i--){
        for(char ch='A';ch<='A'+i;ch++){
            cout<<ch<<" ";
        }
    cout<<endl;
    }
}

void pattern16(int n){
    for(int i=0;i<=n;i++){
        
        char ch='A'+i;
        for(int j=0;j<=i;j++){
            cout<<ch<<" ";
        }
    cout<<endl;
    }
}

void pattern17(int n){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout<<"  ";
        }
        for(char ch='A';ch<'A'+i;ch++)
        {
            cout<<ch<<" ";
        }
        for(char ch='A'+i;ch>='A';ch--)
        {
            cout<<ch<<" ";
        }
        for(int j=0;j<n-i-1;j++)
        {
            cout<<"  ";
        }
        cout<<endl;
    }
    /*
    strtiver->for characters he uses a singlr for loop which ios better
    cahr ch='A';
    int breakpoint=(2*i+1)/2;
    for(int j=1;j<2*i+1;j++){
        cout<<ch;
        if(j<=breakpoint)ch++;
        else ch--;
    }
    */
}

void pattern18(int n){
    for(int i=0;i<n;i++)
    {
        char ch='A'+n-i-1;
        for(int j=0;j<=i;j++){//for(char ch='A'+n-i;ch<='A'+n;ch++){cout<<ch<<" ";}
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
}

void pattern19(int n){
    for(int i=0;i<n;i++)
    {
        int breakpoint=n;
        for(int j=0;j<n-i;j++)
        {
            cout<<"*";
        }
        for(int j=0;j<2*i;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<n-i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        int breakpoint=n;
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        for(int j=2*n-2*i-2;j>0;j--)
        {
            cout<<" ";
        }
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    
}

void pattern20(int n){
    for(int i=0;i<n;i++)
    {
        int breakpoint=n;
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        for(int j=2*n-2*i-2;j>0;j--)
        {
            cout<<" ";
        }
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=1;i<n;i++)
    {
        int breakpoint=n;
        for(int j=0;j<n-i;j++)
        {
            cout<<"*";
        }
        for(int j=0;j<2*i;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<n-i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern20_2(int n){//better method than pattern20 as requries less for loop.
    int stars=1;
    int spaces=2*n-2;
    for(int i=0;i<2*n-1;i++)
    {
        for(int j=0;j<stars;j++)
        {
            cout<<"*";
        }
        for(int j=0;j<spaces;j++)
        {
            cout<<" ";
        }
        if(i<n-1)spaces=spaces-2;
        else spaces=spaces+2;
        for(int j=0;j<stars;j++)
        {
            cout<<"*";
        }
        if(i<n-1)stars++;
        else stars--;
        cout<<endl;
    }
}

void pattern21(int n){
    for(int i=0;i<n;i++)
    {
        int stars=1;
        if(i==0||i==n-1) stars=n;
        for(int j=0;j<stars;j++)
        {
            cout<<"*";
        }
        if(i!=0&&i!=n-1)
        {
            for(int j=0;j<n-2;j++)
            {
                cout<<" ";
            }
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern21_2(int n){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 || j==0 || i==n-1 || j==n-1){
                cout<<"*";
            }
            else cout<<" ";
        }
        cout<<endl;
    }
}

void pattern22(int n){
    for(int i=0;i<2*n-1;i++)
    {
        for(int j=0;j<2*n-1;j++)
        {
            int top=i;
            int left=j;
            int right=(2*n-2)-j;
            int down=(2*n-2)-i;
            cout<<(n-min(min(top,down),min(right,left)));
        }
        cout<<endl;
    }
}


int main(){
    pattern00(5);
    cout<<"1"<<endl;
    pattern1(5);
    cout<<"2"<<endl;
    pattern2(5);
    cout<<"3"<<endl;
    pattern3(5);
    cout<<"4"<<endl;
    pattern4(5);
    cout<<"5"<<endl;
    pattern5(5);
    cout<<"6"<<endl;
    pattern6(5);
    cout<<"7"<<endl;
    pattern7(5);
    cout<<"8"<<endl;
    pattern8(5);
    cout<<"9"<<endl;
    pattern9(5);
    cout<<"10"<<endl;
    pattern10(5);
    cout<<"11"<<endl;

    return 0;
}