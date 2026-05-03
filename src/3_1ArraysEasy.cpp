#include<bits/stdc++.h>
using namespace std;

void LargestinArray(vector<int> arr){
    int max=arr[0];
    for(auto it:arr){
        if(it>max) max=it;
    }
    cout<<max<<endl;
}

void SecondLargest(vector<int> arr){
    int largest=arr[0];
    int secondlargest=-1;
    for(auto it:arr){
        if(it>largest){
            secondlargest=largest;
            largest=it;
        }
        else if(it<largest && it>secondlargest){
            secondlargest=it;
        }
    }
    cout<<secondlargest;
}

void SecondSmallest(vector<int> arr){
    int smallest=arr[0];
    int secondsmallest=INT_MAX;//take large number.
    for(auto j:arr){
        if(j<smallest){
            secondsmallest=smallest;
            smallest=j;
        }
        else if(j!=smallest && j<secondsmallest){//can also use j>smallest instead of j!=smallest.
            secondsmallest=j;
        }
    }
    cout<<secondsmallest;
}

bool CheckforSortedArray(vector<int> arr,int n){
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]) {}
        else return false;
    }
    return true;
}

void Printuniqenum(vector<int> arr){//both method only work on sorted array(key point)
    //my Method->
    int count=1;
    int comp=arr[0];
    for(auto it:arr){
        if(it!=comp){
            comp=it;
            count++;
        }
    }
    cout<<count<<endl;

    //Striver Method->
    int i=0;
    for(auto j:arr){
        if(arr[i]!=j){
            arr[i+1]=j;
            i++;
        }
    }
    cout<<i+1<<endl;
}

void leftrotatearraybyone(vector<int> &arr,int n){
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
}

void reverse(vector<int> &arr,int start,int end){
    while(start<=end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
void leftrotatebyDplaces(vector<int> &arr,int n,int d){

    //Optimal Solution--> time complexity increase to 2N but space complexity decreases
    /*
    reverse(a,a+d)
    reverse(a+d,a+n)
    reverse(a,a+n)
    */
    d=d%n;
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
    
    /*for right rotate-->
    reverse(nums,0,n-1);
    reverse(nums,0,d-1);
    reverse(nums,d,n-1);
    */


    //Brute force Solution-->
    // int rotation=d%n;
    // int temp[rotation];
    // for(int i=0;i<rotation;i++){
    //     temp[i]=arr[i];
    // }
    // int j=0;
    // for(int i=rotation;i<n;i++){
    //     arr[j]=arr[i];//can also do arr[i-rotate]=arr[i];.instead of using j variable
    //     j++;
    // }
    // int k=0;
    // for(int i=n-rotation;i<n;i++){
    //     arr[i]=temp[k];//can also use arr[i]=temp[i-(n-rotate)];
    //     k++;
    // }
   
}

vector<int> moveallzerotoend(vector<int> &arr,int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1) return arr;
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    return arr;
}

int linearsearch(vector<int> arr,int num,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==num){
            return i+1;
        }
    }
    return -1;
}

vector<int> unionofsortedarray(vector<int>a,vector<int>b){
    
    //Optimal-->
    int n1=a.size();
    int n2=b.size();
    int i=0;
    int j=0;
    vector<int> unionArr;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            if(unionArr.size()==0||unionArr.back()!=a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else{
            if(unionArr.size()==0||unionArr.back()!=b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if(unionArr.size()==0||unionArr.back()!=a[i]){
            unionArr.push_back(a[i]);
        }
        i++;
    }
    while(j<n2){
        if(unionArr.size()==0||unionArr.back()!=b[j]){
            unionArr.push_back(b[j]);
        }
        j++;
    }
    return unionArr;


    // //bruteforce-->
    // int n1=a.size();
    // int n2=b.size();
    // set<int> st;
    // for(int i=0;i<n1;i++){
    //     st.insert(a[i]);
    // }
    // for(int i=0;i<n2;i++){
    //     st.insert(b[i]);
    // }
    // vector<int> temp;
    // for(auto it:st){
    //     temp.push_back(it);
    // }
    // return temp;
}

vector<int> intersectionofsortedarray(vector<int>a,vector<int>b){
    int n1=a.size();
    int n2=b.size();
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            i++;
        }
        else if(a[i]>b[j]){
            j++;
        }
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int findmissingnumber(vector<int> arr,int N){
    
    //Method 1-->using xor.
    //xor of two same number is = 0.(n^n)=0
    //and xor of 0^number=number
    //this is teh most optimal solution for this problem
    int xor1=0,xor2=0;
    int n=N-1;
    for(int i=0;i<n;i++){
        xor2=xor2^(i+1);//xor2=(1^2^3^4)
        xor1=xor1^arr[i];//xor1=(1^2^4^5)
    }
    xor2=xor2^N;//xor2=(1^2^3^4^5)
    return xor1^xor2;//=(1^1^2^2^3^4^4^5^5)=>(3)


    // //Method 2--> using sum of natural numbers
    // //as we know sum of natural numbers is (N(N+1))/2
    // //so we find sum of all elements in vector and subtract it from sum of natural numbers till N.
    // int sum=(N*(N+1))/2;
    // int s2=0;
    // for(auto it:arr){
    //     s2=s2+it;
    // }
    // return sum-s2;
    // // Method 2 is not as good as Method 1 as find sum might extend the limit of int which increases the space complexity.
    
    
    //bruteforce method->for(for()) two for for checking for all possible values in the array from 1-n.
    //better soultion->using hashing and assigning missing value as 0 and other values as one


}

int maxconsecuteones(vector<int> arr,int n){
    int count=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
            maxi=max(maxi,count);
        }
        else{
            count=0;
        }
    }
    return maxi;
}

int findthenumberthatappearsonce(vector<int> arr){
    //Brute Force->O(n^2) checking for each element in array
    //better->O(3n) one for finding max element used to define hash size,second for hashing,third for finding from hash array
    //second better->using map data structure instead of hash array.


    //Optimal->doing xor for all elements as all other elements occur twice
    int ans=0;
    for(auto it:arr){
        ans=ans^it;
    }
    return ans;
}

int longestsubarraywithsumK(vector<int> arr,long long k){
   
    // //Optimal solution-->
    // int left=0,right=0;
    // long long sum=arr[0];
    // int maxLen=0;
    // int n=arr.size();
    // while(right<n){
    //     while(left<=right && sum>k){
    //         sum-=arr[left];
    //         left++;
    //     }
    //     if(sum==k){
    //         maxLen=max(maxLen,right-left+1);
    //     }
    //     right++;
    //     if(right<n) sum += arr[right];
    // }
    // return maxLen;



    //Beter solution-->                   
    //this is best solution when the array also include negative numbers->
    map<long long,int> preSumMap;
    long long sum=0;
    int maxLen=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum==k){
            maxLen=max(maxLen,i+1);
        }
        long long rem=sum-k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len=i-preSumMap[rem];
            maxLen=max(maxLen,len);
        }
        if(preSumMap.find(sum)==preSumMap.end()) preSumMap[sum]=i;
    }
    return maxLen;


}   



int main(){
    vector<int> arr={3,2,1,4,5,2};
    int n=6;

    // LargestinArray(arr);

    // SecondLargest(arr);

    // SecondSmallest(arr);

    // bool ans=CheckforSortedArray(arr,n);
    // cout<<ans;

    // Printuniqenum({1,1,2,2,3,4,4,4,5,6});//prints number of unique element from sorted array

    // leftrotatearraybyone(arr,6);
    // for(auto it:arr){
    //     cout<<it<<" ";
    // }

    // leftrotatebyDplaces(arr,6,3);
    // for(auto it:arr){
    //     cout<<it<<" ";
    // }

    // vector<int> arr1={1,0,2,3,2,0,0,4,5,1};
    // vector<int> ans= moveallzerotoend(arr1,10);
    // for(auto it:ans){
    //     cout<<it<<" ";
    // }

    // int z=linearsearch(arr,4,6);
    // cout<<z<<endl;

    // vector<int> asorted={1,1,2,2,5,5,6};
    // vector<int> bsorted={1,1,2,3,4,4,4,5,5,7,9};
    // // vector<int> answer1=unionofsortedarray(asorted,bsorted);
    // vector<int> answer2=intersectionofsortedarray(asorted,bsorted);
    // for(auto it:answer2){
    //     cout<<it<<" ";
    // }

    // int mis=findmissingnumber({1,2,4,5},5);
    // cout<<mis;

    // int max1=maxconsecuteones({1,1,0,1,1,0,1,1,1,1},10);
    // cout<<max1;

    // int once=findthenumberthatappearsonce({1,1,2,3,3,4,4});
    // cout<<once;

    int ansl=longestsubarraywithsumK({1,2,3,1,1,1,1,1,4,2,3},3);
    cout<<ansl<<endl;

    return 0;
}