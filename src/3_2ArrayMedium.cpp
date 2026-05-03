#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
    
    //Optimal Solution-> 2 pointer approach
    //this solution is used when we need to return yes or no and not the index of the values.
    //here i am taking 1 for yes and 0 for no. as we must return int.
    int left=0,right=nums.size()-1;
    sort(nums.begin(),nums.end());
    while(left<right){
        int sum=nums[left]+nums[right];
        if(sum==target){
            return {1,1};
        }
        else if(sum<target) left++;
        else right--;
    }
    return {0,0};


    // //Better solution-> using hashing. this is optimal when you have to return the index of the value.
    // map<int,int> mpp;
    // for(int i=0;i<nums.size();i++){
    //     int a=nums[i];
    //     int more=target-a;
    //     if(mpp.find(more) != mpp.end()){
    //         return {mpp[more],i};
    //     }
    //     mpp[a]=i;
    // }


    // //Brute solution->
    // for(int i = 0; i<nums.size(); i++)
    // {
    //     for(int j = i+1; j<nums.size(); j++)
    //     {
    //         if(nums[i]+nums[j]==target)
    //         {
    //             return {i,j};
    //         }
    //     }
    // }
    // return {};

}

vector<int> sortarrayof0_1_2(vector<int> &arr){
    //Dutch national flag algorithm..

    //optimal solution->
    int n=arr.size()-1;
    int low=0,mid=0,high=n;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }

    //Better solution-->
    //taking 3 valrable to the count the 0,1,2 in array. and creating new array from this count
}

int MajorityElement(vector<int> arr){

    //optimal solution-> Moore's voting Algorithm
    int cnt=0;
    int el;
    for(int i=0;i<arr.size();i++){
        if(cnt==0){
            cnt=1;
            el=arr[i];
        }
        else if(arr[i]==el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    //optional step if no majority element in array->
    int cnt1=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==el) cnt1++;
    }
    if(cnt1>(arr.size()/2)) {
        return el;
    }
    return -1;


    // //Better solution->using hash map
    // map<int,int> mpp;
    // for(int i=0;i<arr.size();i++){
    //     mpp[arr[i]]++;
    // }
    // for (auto it:mpp){
    //     if(it.second>(arr.size()/2)){
    //         return it.first;
    //     }
    // }
    // return -1;
}

int MaxSubarraySum(vector<int> arr){
      
    //Optimal Solution--> Kadane's Algorithm
    int sum=0;
    int maxi=INT_MIN;
    for(int i=0;i<arr.size();i++){
        //int start=-1,ansstart=-1,ansend=-1;
        //if(sum==0) start=i;
        sum=sum+arr[i];
        if(sum>maxi){
            maxi=sum;
            //ansstart=start,ansend=i;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxi;

    //Brtute force->
    //all possibe subarray will be checked for max sum
    //time complexity O(n^3) agar 3 loop banege
    //O(n^2) agar sum variable ko sahi tara use kare to. 
}

int Besttimetobuyandsellstock(vector<int> arr){
    //if you are selling on i'th day 
    //you buy on the minium price form 1st->(i-1)
    int mini=arr[0];
    int profit=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]-mini>profit){
            profit=arr[i]-mini;
        }
        if(arr[i]<mini){
            mini=arr[i];
        }
    }
    return profit;


}   

vector<int> Rearrangearrayelementsbysign(vector<int> &arr){
    
    //when number of positves and negative are equal->
    int n=arr.size();
    vector<int> ans(n,0);
    int posIndex=0,negIndex=1;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            ans[negIndex]=arr[i];
            negIndex +=2;
        }
        else{
            ans[posIndex]=arr[i];
            posIndex +=2;
        }
    }
    return ans;


    // //when number of positve and negative is unequal->
    // vector<int> pos,neg;
    // int n=arr.size();
    // for(int i=0;i<n;i++){
    //     if(arr[i]>0){
    //         pos.push_back(arr[i]);
    //     }
    //     else{
    //         neg.push_back(arr[i]);
    //     }
    // }
    // if(pos.size()>neg.size()){
    //     for(int i=0;i<neg.size();i++){
    //         arr[2*i]=pos[i];
    //         arr[2*i+1]=neg[i];
    //     }
    //     int index=neg.size()*2;
    //     for(int i=neg.size();i<pos.size();i++){
    //         arr[index]=pos[i];
    //         index++;
    //     }
    // }
    // else{
    //     for(int i=0;i<pos.size();i++){
    //         arr[2*i]=pos[i];
    //         arr[2*i+1]=neg[i];
    //     }
    //     int index=pos.size()*2;
    //     for(int i=pos.size();i<neg.size();i++){
    //         arr[index]=neg[i];
    //         index++;
    //     }
    // }
    // return arr;

    
    //BruteForce->
    //make two array of n/2 to store positive and negative elements seprately. 
}

void nextpermutation(vector<int> &arr){

    // //using stl
    // next_permutation(arr.begin(),arr.end());

    //without using the built in function
    int ind=-1;
    int n=arr.size();
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            ind=i;
            break;
        }
    }
    if(ind==-1){
        reverse(arr.begin(),arr.end());
    }
    for(int i=n-1;i>ind;i++){
        if(arr[i]>arr[ind]){
            swap(arr[i],arr[ind]);
            break;
        }
    }
    reverse(arr.begin()+ind+1,arr.end());
}

vector<int> LeadersinanArray(vector<int> arr){
    //Leader in array is the greatest element from its right.
    //so we start the loop from right end.
    vector<int> ans;
    int maxi=INT_MIN;
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        maxi=max(maxi,arr[i]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int longestConsecutiveSequence(vector<int> &a){
    
    //Optimal solution->
    int n=a.size();
    if(n==0) return 0;
    int longest=1;
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(a[i]);
    }
    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;
            while(st.find(x+1) != st.end()){
                x=x+1;
                cnt=cnt+1;
            }
            longest=max(longest,cnt);
        }
    }
    return longest;


    // //Better solution->//we will sort the array.
    // if(a.size()==0) return 0;
    // sort(a.begin(),a.end());
    // int n=a.size();
    // int lastsamaller=INT_MIN;
    // int cnt=0;
    // int longest=1;
    // for(int i=0;i<n;i++){
    //     if(a[i]-1==lastsamaller){
    //         cnt+=1;
    //         lastsamaller=a[i];
    //     }
    //     else if(lastsamaller!=a[i]){
    //         cnt=1;
    //         lastsamaller=a[i];
    //     }
    //     longest=max(longest,cnt);
    // }
    // return longest;
}

vector<vector<int>> SetZeroMatrix(vector<vector<int>> &matrix,int n,int m){
    
    //Optimal Solution->
    int col0=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                //mark the i-th row
                matrix[i][0]=0;
                //mark the j-th col
                if(j!=0) matrix[0][j]=0;
                else col0=0;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]!=0){
                //check for col & row
                if(matrix[0][j]==0||matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
    if(matrix[0][0]==0){
        for(int j=0;j<m;j++) matrix[0][j]=0;
    }
    if(col0==0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
    }
    return matrix;


    // //Better Solution->
    // int col[m]={0};
    // int row[n]={0};
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(matrix[i][j]==0){
    //             row[i]=1;
    //             col[j]=1;
    //         }
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(row[i]||col[j]){
    //             matrix[i][j]=0;
    //         }
    //     }
    // }
    // return matrix;
}

vector<vector<int>> RotateMatrix90(vector<vector<int>> &matrix){
    
    //Optimal Solution->
    //matrix ko transpose karo(row ko colm and colm ko row)
    //fir each row ko reverse karo
    int n=matrix.size();
    //transpose-->O(N/2*N/2)
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //reverse-->O(N*N/2)
    for(int i=0;i<n;i++){
        //row in matrix[i]
        reverse(matrix[i].begin(),matrix[i].end());
    }

    return matrix;


    //brute force->TC=O(n^2),SC=O(n^2)
    //new matrix bana ke arr[j][n-i-1]=arr[i][j];
}

vector<int> SpiralMatrix(vector<vector<int>> matrix){
    //we will move in a way like
    //lefttop->righttop, righttop+1->rightbottom
    //rightbottom-1->leftbottom, leftbottom-1->lefttop+1.
    int n=matrix.size();
    int m=matrix[0].size();
    int left=0,right=m-1;
    int top=0,bottom=n-1;
    vector<int> ans;

    while(top<=bottom && left <=right){
        
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int findAllSubarraywithgivenSum(vector<int> &arr,int k){
    map<int,int> mpp;
    mpp[0]=1;
    int preSum=0,cnt=0;
    for(int i=0;i<arr.size();i++){
        preSum +=arr[i];
        int remove =preSum-k;
        cnt +=mpp[remove];
        mpp[preSum]+=1;
    }
    return cnt;
}



int main(){

    // vector<int> arr={2,7,11,15};
    // vector<int> anstwosum=twoSum(arr,9);
    // cout<<anstwosum[0]<<" "<<anstwosum[1]<<endl;
    
    // vector<int> arr1={0,1,1,0,1,2,1,2,0,0,0};
    // sortarrayof0_1_2(arr1);
    // for(auto it:arr1){
    //     cout<<it<<" ";
    // }

    // int ans=MajorityElement({7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5});
    // cout<<ans<<endl;

    // int ansmax=MaxSubarraySum({-2,-3,4,1,-2,1,5,-3});
    // cout<<ansmax<<endl;

    // int ansprofit=Besttimetobuyandsellstock({7,1,5,3,6,4});
    // cout<<ansprofit<<endl;

    // vector<int> vecarr={3,1,-2,-5,2,-4};//add unequal values of positive and negative to check for that  type of que as well.solution to second type of problem is commented.
    // vector<int> ans=Rearrangearrayelementsbysign(vecarr);
    // for(auto it:ans){cout<<it<<" ";}

    // vector<int> que={1,3,2};
    // nextpermutation(que);
    // for(auto it: que){
    //     cout<<it<<" ";
    // }

    // vector<int> ans=LeadersinanArray({10,22,12,3,0,6});
    // for(auto it:ans) cout<<it<<" ";

    // vector<int> vec1={100,102,100,101,101,4,3,2,3,2,1,1,1,2};
    // int ans=longestConsecutiveSequence(vec1);
    // cout<<ans<<" ";


    // vector<vector<int>> vecarr={{1,1,1},{1,0,1},{1,1,1}};
    // vector<vector<int>> ans=SetZeroMatrix(vecarr,3,3);
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    // vector<vector<int>> vecarr={{1,0,1},{1,0,1},{1,0,1}};
    // vector<vector<int>> ans=RotateMatrix90(vecarr);
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    // vector<vector<int>> vecarr={{1,0,1},{1,0,1},{1,0,1}};
    // vector<int> ans=SpiralMatrix(vecarr);
    // for(auto it:ans){
    //     cout<<it<<" ";
    // }


    vector<int> vecarr={1,2,3,-3,1,1,1,4,2,-3};
    cout<<findAllSubarraywithgivenSum(vecarr,3);


    
    return 0;
}