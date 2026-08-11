#include<bits/stdc++.h>//iostream,math.h,string.h,...etc.
using namespace std;


void explainPair(){

    pair<int,int> p={1,3};
    cout<<p.first<<" "<<p.second<<endl;

    pair<int,pair<int,int>> z={1,{3,4}};
    cout<<p.first<<" "<<z.second.first<<" "<<z.second.second<<endl;

    pair<int,int> arr[]={{1,2},{2,5},{5,1}};
    cout<<arr[1].second;
}

void explainVector(){
    /* vector are different than array as they
       allow the increase in size unlike array. */

    vector<int> vec1;//declaring vector

    vec1.push_back(1);//push_back and emplace back both are used to add value at end.
    vec1.emplace_back(2);//emplace back is faster than push_back.
    //{}->{1}due to push_back->{1,2}due to emplace_back.

    vector<pair<int,int>> pairvec;//declaring pair vector

    pairvec.push_back({1,2});
    pairvec.emplace_back(1,2);

    vector<int> vec2(5,100);//vec2={100,100,100,100,100}

    vector<int> vec3(5);//creates a vector with 5 garbage value or zero value depending on coplier.the size can be increased afterward

    vector<int> v1(5,20);//v1={20,20,20,20,20}
    vector<int> v2(v1);//creates a copy of v1 at another location.v2=v1


    //accessing vector
        vector<int> vec4 = {20,10,15,5,7};

    //Method 1-Using Iterators->iterators points to the memory of the vector.
        vector<int>::iterator anyname = vec4.begin();//now anyname points at the memory location of the first element in vector.

        cout<<*(anyname)<<" ";// * used to get the value at the memory.output->{20}
        anyname++;//we can also do anyname=anyname+2; to move 2 positions etc
        cout<<*(anyname)<<" ";//{10}

        //other iterators than begin()
        vector<int>::iterator enditerator=vec4.end();//{20,10,15,5,7}_ end() points at the _ which is right after last element.
        vector<int>::reverse_iterator renditerator=vec4.rend();//rend() will point left of first element. -- karne pe first element pe jayega
        vector<int>::reverse_iterator rbeginiterator=vec4.rbegin();//rbegin() will point at last element. ++ karne pe last second pe jayega

        cout<<endl;

    //Method 2 -
        cout<<vec4[0]<<" "<<vec4.at(0)<<" ";//both metod can used.output->{20}
        cout<<vec4.back()<<" ";//{7}

        cout<<endl;

    //printing complete vector using for loop

        for(vector<int>::iterator i=vec4.begin();i!=vec4.end();i++){
            cout<<*(i)<<" ";
        }
        cout<<endl;

        for(auto j=vec4.begin();j!=vec4.end();j++){//auto is used to automatically define datatype.
            cout <<*(j)<<" ";
        }
        cout<<endl;

        //using for each loop->
        for(auto k:vec4){
            cout<<k<<" ";
        }
        cout<<endl;
    

    //Erase
    
        //{10,20,12,34}
        // v.erase(v.begin()+1);//{10,12,34}

        //{10,23,12,23,35}
        // v.erase(v.begin()+2,v.begin()+4);//{10,20,34}
    
    //Insert 

        vector<int> v(2,100);//{100,100}
        v.insert(v.begin(),300);//{300,100,100}
        v.insert(v.begin()+1,2,10);//{300,10,10,100,100}

        vector<int> copy(2,50);//{50,50}
        v.insert(v.begin(),copy.begin(),copy.end());//{50,50,300,10,10,100,100}

    //{10,20}
    cout<<v.size();//2

    //{10,20}
    v.pop_back();//{10}

    //v1->{30,40}
    //v2->{10,20}
    // v1.swap(v2);//v1->{10,20} , v2->{30,40}

    // v.clear();//erases the vector to {}

    cout<<v.empty();//return True or False depending on vector being empty or nor

}

void explainList(){
    
    list<int> ls;

    ls.push_back(2);//{2}
    ls.emplace_back(4);//{2,4}

    //In List we can use push_front insted of insert used in vector 
    //push_front,emplace_front is faster than insert
    ls.push_front(5);//{5,2,4}
    ls.emplace_front(6);//{6,5,2,4}

    //rest functions same as vector
    //begin,end,rend,rbegin,clear,insert,size,swap.

}

void explainDeque(){

    deque<int> dq;
    dq.push_back(1);//{1}
    dq.emplace_back(2);//{1,2}
    dq.push_front(4);//{4,1,2}
    dq.emplace_front(3);//{3,4,1,2}

    dq.pop_back();//{3,4,1}
    dq.pop_front();//{4,1}

    dq.back();

    dq.front();

    //rest functions same as vector.
    //begin,end,rend,rbegin,clear,insert,size,swap.

}

void explainStack(){
    //follows LIFO- Last In First Out
    //in stack we cant use indexing like st[3]

    stack<int> st;
    st.push(1);//{1}
    st.push(2);//{2,1}
    st.push(3);//{3,2,1}
    st.push(3);//{3,3,2,1}
    st.emplace(5);//{5,3,3,2,1}


    cout<<st.top();//print 5.used to know the top

    st.pop();//st looks like {3,3,4,1}

    cout<<st.top();//3

    cout<<st.size();//4

    cout<<st.empty();//True or False return hoga

    stack<int>st1,st2;
    st1.swap(st2);//used to swap two stack

}

void explainQueue(){
    //follows FIFO -> First In First Out
    queue<int> q;

    q.push(1);//{1}
    q.push(2);//{1,2}
    q.emplace(4);//{1,2,4}

    q.back() +=5;//4+5=9.

    cout<<q.back();//prints 9

    //q ={1,2,9}
    cout<<q.front();//prints 1

    q.pop();//{2,9}

    cout<<q.front();//prints 2

    //size swap empty as stack

}

void explainPQ(){

    //maximum element stays at the top also known as Max heap
    priority_queue<int> pq;

    pq.push(5);//{5}
    pq.push(2);//{5,2}
    pq.push(8);//{8,5,2}
    pq.emplace(10);//{10,8,5,2}

    cout<<pq.top()<<" ";//prints 10

    pq.pop();//{8,5,2}

    cout<<pq.top();//prints 8

    //size swap empty function same as others

    cout<<endl;

    //Minimum Heap
    priority_queue<int,vector<int>,greater<int>> pq2;
    pq2.push(5);//{5}
    pq2.push(2);//{2,5}
    pq2.push(8);//{2,5,8}
    pq2.emplace(10);//{2,5,8,10}

    cout<<pq2.top();//prints 2

}

void explainSet(){

    //Set stores everthing in a sorted order and every element is unique.

    set<int>st;
    st.insert(1);//{1}
    st.emplace(2);//{1,2}
    st.insert(2);//{1,2}--> Repeat entry not allowed
    st.insert(4);//{1,2,4}
    st.insert(3);//{1,2,3,4}
    st.insert(5);//{1,2,3,4,5}

    //Funtionality of insert in vector
    //can be used also,that only increases
    //efficiency

    //begin(),end(),rbegin(),rend(),size(),
    //empty() and swap() are as those of above

    //{1,2,3,4,5}
    auto it=st.find(3);//->return iterator which points to 3

    //{1,2,3,4,5}
    auto it1=st.find(6);//->return st.end() which points right of last element

    st.erase(5);//erases 5 //take logarithmic time

    int cnt =st.count(1);//return 0 or 1 depending apon the existing of element in set.

    auto it2=st.find(3);
    st.erase(it2);// erases iterator and thakes constant time.

    //{1,2,3,4,5}
    auto it3=st.find(2);
    auto it4=st.find(4);
    st.erase(it3,it4);//after erase {1,4,5}[first,last]

    //lower_bound() and upper_bound() function works in same way
    //as in vector it does

    //this is the syntax
    auto it5=st.lower_bound(2);
    auto it6=st.upper_bound(3);
  
}

void explainMultiSet(){

    //Everything is same as set
    //only stores duplicate elements also

    multiset<int>ms;
    ms.insert(1);//{1}
    ms.insert(1);//{1,1}
    ms.insert(1);//{1,1,1}

    ms.erase(1); //all 1's erased

    multiset<int>ms2={1,1,1,1,1};

    int cnt=ms2.count(1);

    //only a single one erased
    ms2.erase(ms2.find(1));

    // ms.erase(ms.find(1),ms.find(1)+2);////code gives error
    //rest all function same as set
}

void explainUSet(){
    unordered_set<int>ust;
    /*lower_bound and upper_bound function
    does not work,rest all functions are same
    as above. it does not store in any
    paricular order it has better complexity than 
    set in most cases,except some when collision happens
    stores uniqe elements(no repeat) */
}

void explinMap(){
    
    //unique key assign to each element,repeat element are allowed.
    //stores in sorted order.
    map<int,int> map1;
    map<int,pair<int,int>> map2;
    map<pair<int,int>,int> map3;

    map1[1]=2;//key 1 pe 2 store hoga//[{1,2}]
    map1.emplace(3,1);//[{1,2}{3,1}]
    map1.insert({2,4});//[{1,2},{2,4},{3,1}]

    map3[{2,3}]=10;
    map3.emplace(pair<int,int>(1,2),20);
    //map3=[{{1,2},20},{{2,3},10}]

    //using for each loop to print map1
    for(auto it : map1){
        cout<< it.first << " " << it.second<<endl;
    }

    cout<<map1[1]<<endl;//2
    cout<<map1[5]<<endl;//0 as no value available

    //to get iterator for certain element
    auto itmap=map1.find(3);
    cout<<(*itmap).second;

    auto it_2=map1.find(5);//points at map1.end() as 5 is not in map.

    //lower_bound and upper_bound functions can also be used in map.
    //erase,swap,size,empty,are same as above

}

void explainMultiMap(){
    //multimap<int,int> mpp;
    //everything same as map,it can store multiple duplicate keys
    //only mapname[key] cannot be used here
}

void explainUnorderedMap(){
    //stores in unordered form and only unique keys.
}

bool comp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second<p2.second) return true;
    else if(p1.second==p2.second){
        if(p1.first>p2.first) return true;
    }
    return false;
}
void Algorithms(){

    //Sorting
        int arr[]={1,5,3,2,9,7};
        int n=sizeof(arr)/sizeof(arr[0]);//size of array gets divided by size of single element
        sort(arr,arr+n);

        for(int x:arr){
            cout<<x<<" ";
        }
        cout<<endl;

        //for vector
        vector<int> arr2 = {1,5,3,2};
        sort(arr2.begin(), arr2.end());

        sort(arr+2,arr+6,greater<int>());//greater<int>() used to get in decreasing order
        //begin and end are specified to only sort particular elements.
        for(int x:arr){
            cout<<x<<" ";
        }
        cout<<endl;

    //Sorting in my way
        
        pair<int,int> a[]={{1,2},{2,1},{4,1}};

        //sort it according to second element
        //if second element is same,the sort
        //it according to first element but in decreasing

        sort(a,a+3,comp);//{4,1}{2,1}{1,2}
        for (pair<int,int> y : a) {
        cout << "(" << y.first << "," << y.second << ")";
        }

        cout<<endl;
    
    //__builtin_popcount
        
        int num1=7;
        int cnt1=__builtin_popcount(num1);//return 1's bit in 7 binary form which is 3(111)
        cout<<cnt1<<" ";

        long long num2=162679547292;
        int cnt2=__builtin_popcountll(num2);//for long long data type we use ll at end.
        cout<<cnt2<<" ";
        
        cout<<endl;
    
    //Next Permutation-->used to print all permutations of strings.
    //rearranges numbers into the next lexicographically greater permutation
    //if not possible, rearranges into the lowest possible order (sorted ascending)
    //we alsso have prev_permutation in cpp
        string s="123";//start matter karta hai kyu ki increasing order mai print hota hai.

        do{
            cout<<s<<endl;
        }
        while(next_permutation(s.begin(),s.end()));

    //IMP
    //*max_element
    int maxi=*max_element(arr,arr+n);//find max element in array
    cout<<maxi;

}


int main(){
    // explainPair();
    // explainVector();
    // explainList();
    // explainDeque();
    // explainStack();
    // explainQueue();
    // explainPQ();
    // explainSet();
    // explainMultiSet();
    // explainUSet();
    // explinMap();
    // explainMultiMap();
    // explainUnorderedMap();
    // Algorithms();

    return 0;
}