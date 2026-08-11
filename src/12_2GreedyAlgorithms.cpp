#include<bits/stdc++.h>
using namespace std;


// N meeting room problem..
// TC->O(2N+NlogN)
// SC->O(3*N)+O(N)
bool cmp(vector<int> a,vector<int> b){
    return a[1]<b[1];
}
vector<int> Nmeetingroom(vector<int> start, vector<int> end){
    int n=start.size();
    vector<vector<int>> database(n,vector<int> (3,0));
    for(int i=0;i<n;i++){
        database[i][0]=start[i];
        database[i][1]=end[i];
        database[i][2]=i+1;
    }
    
    sort(database.begin(),database.end(),cmp);

    int cnt=1;
    int freetime=database[0][1];
    vector<int> idx;
    idx.push_back(database[0][2]);
    for(int i=1;i<n;i++){
        if(database[i][0]>freetime){
            cnt+=1;
            freetime=database[i][1];
            idx.push_back(database[i][2]);
        }
    }
    return idx; // can even return the cnt if cnt is asked.

}



// leetcode 55 really a very different appoarch..
// both appoarch used are preety unique..
bool canJump(vector<int>& nums) {
    // //my try--> my appoarch is like dp
    // // TC->O(n^2)  SC->O(n)
    // int n=nums.size();
    // if(n==1) return true;
    // vector<bool> pos(n,false);
    // pos[n-1]=true;
    // for(int i=n-2;i>=0;i--){
    //     if(i+nums[i]>=n-1){
    //         pos[i]=true;
    //     }
    //     else{
    //         for(int it=i+1;it<=i+nums[i];it++){
    //             if(pos[it]==true){
    //                 pos[i]=true;
    //                 break;
    //             }
    //         }
    //     }
    // }
    // return pos[0];


    // optimal solution-->
    // // TC->O(n)  SC->O(1)
    // we will find the max in the current jumps available and jump on that index
    int n=nums.size();
    if(n==1) return true;
    int maxi=0;
    for(int i=0;i<n;i++){
        if(i>maxi) return false;
        maxi=max(maxi,i+nums[i]);
    }
    return true;
}



//IMP-->
int minNumberofplatform(vector<int> &arrival, vector<int>& depart){
    
    //optimal--> TC-O(2N log N + 2N)=O(N log N)  SC-O(1)
    // we sort both the array seperately IMP.. 
    // as we can consider the arrival of one train and depart of other train together.
    // then we take two pointer 1 for arrival array and one for depart array. 
    sort(arrival.begin(), arrival.end());
    sort(depart.begin(),depart.end());
    int n=arrival.size();
    int i=0;
    int j=0;
    int cnt=0;
    int maxcnt=0;
    while(i<n && j<n){
        if(arrival[i]<depart[j]){
            cnt+=1;
            i++;
        }
        else{
            j++;
            cnt-=1;
        }
        maxcnt=max(cnt,maxcnt);
    }
    return maxcnt;
    
    
    // //brute force--> TC-O(n^2)  SC-O(1)
    // int n=arrival.size();
    // int maxcnt=0;
    // for(int i=0;i<n;i++){
    //     int cnt=1;
    //     for(int j=i+1;j<n;j++){
    //         if(arrival[j]<=arrival[i] ){
    //             if(depart[j]>arrival[i]) cnt+=1;
    //         }
    //         else if(arrival[j]<=depart[i]){
    //             cnt+=1;
    //         }
    //     }
    //     maxcnt=max(maxcnt,cnt);
    // }
    // return maxcnt;

}



int main(){

    vector<int> start={0,3,1,5,5,8};
    vector<int> end={5,4,2,9,7,9};
    vector<int> meetingind=Nmeetingroom(start,end);
    for(int it:meetingind){
        cout<<it<<" ";
    }
    cout <<endl;
    cout<<endl;



    vector<int> jumpPower = {2, 3, 1, 1, 4};
    bool result = canJump(jumpPower);
    cout << "Array: ";
    for (int value : jumpPower)  cout << value << " ";
    cout << "\nCan reach the last index: ";
    if (result)  cout << "true";
    else  cout << "false";
    cout<<endl<<endl;


    vector<int> arrival={900,945,955,1100,1500,1800};
    vector<int> depart={920,1200,1130,1150,1900,2000};
    cout<<minNumberofplatform(arrival,depart);
    cout<<endl<<endl;



    return 0;
}