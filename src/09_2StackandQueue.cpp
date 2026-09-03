#include<bits/stdc++.h>
using namespace std;

//operators->
//            priority
//     ^    -->  3
//    *  /  -->  2
//    +  -  -->  1

//operands->
//  A->Z
//  a->z
//  0->9

//Prefix  -->  x+pq-mn
//Infix   -->  (p+q)*(m-n)
//Postfix -->  pq+mn-*


int priority(char ch){
    if(ch=='^') return 3;
    if(ch=='*' || ch=='/') return 2;
    if(ch=='+' || ch=='-') return 1;
    return -1;
}


// TC--> O(N)+O(N)=O(N)
// SC--> O(N)+O(N)=O(N)   one for ans and one for stack
string InfixtoPostfix(string s){
    int N=s.size();
    int i=0;
    stack<char> st;
    string ans="";
    while(i<N){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            ans=ans+s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop(); // used to pop '('
        }
        else{
//we only push when the priority of st.top() is lesser  than s[i]
//if priority of s[i] is lower than st.top() we pop the top and add it to ans until it's priority is lesser than s[i] or stack is empty.
            while(!st.empty() && priority(s[i])<=priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans=ans+st.top();
        st.pop();
    }
    return ans;
}


// TC--> O(N/2)+O(N/2)+O(2N)=O(3N)=O(N)  for 2 reverse(O(N/2))
// SC--> O(N)+O(N)=O(N)   one for ans and one for stack
string InfixtoPrefix(string s){
    // 3 steps-->
    // 1.reverse the string (also change the brackets.)
    // 2.Infix to postfix with little change in opetator condition.
    // 3.reverse the ans.

    int N=s.size();

    // Step 1-->
    reverse(s.begin(),s.end());
    for(int i=0;i<N;i++){
        if(s[i]=='('){
            s[i]=')';
        }
        else if(s[i]==')'){
            s[i]='(';
        }
    }

    // Step 2-->
    int i=0;
    stack<char> st;
    string ans="";
    while(i<N){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            ans=ans+s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop(); // used to pop '('
        }
        else{
            if(s[i]=='^'){
                // imp comdition.
                //this condition as we can't have repeat '^' in stack.
                while(!st.empty() && priority(s[i])<=priority(st.top())){
                    ans=ans+st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && priority(s[i])<priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());

    return ans;

}


// TC->O(N)+O(N)=O(N)
// SC->O(N)
string PostfixtoInfix(string s){
    int N=s.size();
    int i=0;
    stack<string> st;
    while(i<N){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1,s[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();

            string con='('+t2+s[i]+t1+')';
            st.push(con);
        }
        i++;
    }
    return st.top();
}

// TC->O(N)+O(N)=O(N)
// SC->O(N)
string PrefixtoInfix(string s){
    int N=s.size();
    int i=N-1;
    stack<string> st;
    while(i>=0){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1,s[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();

            string con='('+t1+s[i]+t2+')';
            st.push(con);
        }
        i--;
    }
    return st.top();
}

// TC->O(N)+O(N)=O(N)
// SC->O(N)
string PostfixtoPrefix(string s){
    int N=s.size();
    int i=0;
    stack<string> st;
    while(i<N){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1,s[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();

            string con=s[i]+t2+t1;
            st.push(con);
        }
        i++;
    }
    return st.top();
}

string PrefixtoPostfix(string s){
    int N=s.size();
    int i=N-1;
    stack<string> st;
    while(i>=0){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1,s[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();

            string con=t1+t2+s[i];
            st.push(con);
        }
        i--;
    }
    return st.top();
}





int main(){

    string ans1=InfixtoPostfix("a+b*(c^d-e)");
    cout<<ans1<<endl;

    string ans2=InfixtoPrefix("(A+B)*C-D+F");
    cout<<ans2<<endl;

    string ans3=PostfixtoInfix("AB-DE+F*/");
    cout<<ans3<<endl;

    string ans4=PrefixtoInfix("*+PQ-MN");
    cout<<ans4<<endl;

    string ans5=PostfixtoPrefix("AB-DE+F*/");
    cout<<ans5<<endl;

    string ans6=PrefixtoPostfix("/-AB*+DEF");
    cout<<ans6<<endl;



    return 0;
}