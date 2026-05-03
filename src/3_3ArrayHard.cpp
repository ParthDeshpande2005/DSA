#include<bits/stdc++.h>
using namespace std;

int nCr(int n,int r){
    long long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}
int PascalTriangleType1(int row,int col){
    //we need to return the element at row,col
    //there is the formula for this
    //row-1 C col-1
    //nCr=n!/r!*(n-r)!
    return nCr(row-1,col-1);
}

void PascalTriangleType2(int row){
    //return entire row->
    //optimal->
    int ans=1;
    cout<<ans<<" ";
    for(int i=1;i<row;i++){
        ans=ans*(row-i);
        ans=ans/(i);
        cout<<ans<<" ";
    }


    //bruteforce->as nth row has n elements
    //for loop mai ncr wala formula use karke print karna
    //O(n*r)->time complexity
}

void PascalTriangleType3(int row){
    //print the entire triangle till n rows.
    //Optimal Solution->
    //using type 2 to solve type 3

    for(int i=1;i<=row;i++){
        PascalTriangleType2(i);
        cout<<endl;
    }


    //bruteforce->use nCr formula for finding all element.
    //O(n^3) time complexity
}

vector<int> MajorityElement2(vector<int> v){
    //return all the elements that appear n/3 times.

    //Optimal Solution->time->O(n*n) one n is for checking. space->O(1)
    int cnt1=0,cnt2=0;
    int el1=INT_MIN;
    int el2=INT_MIN;
    for(int i=0;i<v.size();i++){
        if(cnt1==0 && el2!=v[i]){
            cnt1=1;
            el1=v[i];
        }
        else if(cnt2==0 && el1!=v[i]){
            cnt2=1;
            el2=v[i];
        }
        else if(v[i]==el1) cnt1++;
        else if(v[i]==el2) cnt2++;
        else{
            cnt1--,cnt2--;
        }
    }
    vector<int> ls;
    cnt1=0,cnt2=0;
    for(int i=0;i<v.size();i++){
        if(el1==v[i]) cnt1++;
        if(el2==v[i]) cnt2++;
    }
    int mini=(int)(v.size()/3)+1;
    if(cnt1>=mini) ls.push_back(el1);
    if(cnt2>=mini) ls.push_back(el2);
    sort(ls.begin(),ls.end());
    return ls;


    // //Better Solution->time->O(n*logn) space->O(n)
    // vector<int> ls;
    // map<int,int> mpp;
    // int n=v.size();
    // int mini=(int)(n/3)+1;
    // for(int i=0;i<n;i++){
    //     mpp[v[i]]++;
    //     if(mpp[v[i]]==mini){
    //         ls.push_back(v[i]);
    //     }
    //     if(ls.size()==2) break;
    // }
    // sort(ls.begin(),ls.end());
    // return ls;

}

vector<vector<int>> ThreeSum(vector<int> &nums){

    //Optimal-> O(n^2 + nlog(n)) nlog(n)->for sorting.
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j=i+1;
        int k=nums.size()-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                vector<int> temp={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
        }
    }
    return ans;

    //better-> O(n^2 x log(m)) log m to store in set
    // set<vector<int>> st;
    // for(int i=0;i<nums.size();i++){
    //     set<int> hashset;
    //     for(int j=i+1;j<nums.size();j++){
    //         int third=-(nums[i]+nums[j]);
    //         if(hashset.find(third) != hashset.end()){
    //             vector<int> temp={nums[i],nums[j],third};
    //             sort(temp.begin(),temp.end());
    //             st.insert(temp);
    //         }
    //         hashset.insert(nums[j]);
    //     }
    // }
    // vector<vector<int>> ans(st.begin(),st.end());
    // return ans;


    //bruteforce->
    //O(n^3 x log(m)) using 3 loops i(0->n) j(i+1->n) k(j+1->n)
    //using set to store the sorted value of(i,j,k) so that we get unique value.
}

vector<vector<int>> FourSum(vector<int> &nums,int target){

    //Optimal-> O(n^3)
    int n=nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j!=(i+1) && nums[j]==nums[j-1]) continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum=nums[i];
                sum +=nums[j];
                sum +=nums[k];
                sum +=nums[l];
                if(sum ==target){
                    vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;l--;
                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;
                }
                else if(sum<target) k++;
                else l--;
            }
        }
    } 
    return ans;  


    //Better->O(n^3 x log(m))
    //using hashmap to find last element 
    //fourth element =target-[first+second+third]
    //har bar hashmap second and third ke bick ke elements ko store karega

    // int n=nums.size();
    // set<vector<int>> st;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         set<long long> hashset;
    //         for(int k=j+1;k<n;k++){
    //             long long sum=nums[i]+nums[j];
    //             sum += nums[k];
    //             long long fourth=target-(sum);
    //             if(hashset.find(fourth)!=hashset.end()){
    //                 vector<int> temp={nums[i],nums[j],nums[k],(int)fourth};
    //                 sort(temp.begin(),temp.end());
    //                 st.insert(temp);
    //             }
    //             hashset.insert(nums[k]);
    //         }
    //     }
    // }
    // vector<vector<int>> ans(st.begin(),st.end());
    // return ans;


    //Brute Force-> O(n^4)->checking for all the values

}

int largestsubarraywithsumzero(vector<int> &nums){

    // optimal-> TC->O(NlogN)  SC->O(n)
    int n=nums.size();
    map<int,int> hashmap;
    int sum=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        sum += nums[i];
        if(sum==0){
            maxi=i+1;
        }
        else{
            if(hashmap.find(sum)!=hashmap.end()){
                maxi=max(maxi,i-hashmap[sum]);
                // auto itmap=hashmap.find(sum);->ye mera code tha
                // int temp =i-(*itmap).second;
                // if(temp>maxi) maxi=temp;
            }
            else{
                hashmap[sum]=i; //hashmap.insert({sum,i});
            }
        }
    }
    return maxi;


    //Brute force->
    // check for all subarray 2 for loop use karege O(n^2)
}




int main(){

    // cout<<PascalTriangleType1(5,3);
    // PascalTriangleType2(6);
    // PascalTriangleType3(6);

    // vector<int> ls=MajorityElement2({1,1,1,1,3,2,2,2});
    // cout<<ls[0]<<" "<<ls[1];

    // vector<int> arr={-1,0,1,2,-1,-4,4};
    // // vector<vector<int>> ans=ThreeSum(arr);
    // vector<vector<int>> ans2=FourSum(arr,0);
    // for(int i=0;i<ans2.size();i++){
    //     for(int j=0;j<4;j++){//change to 3 for 3 sum
    //         cout<<ans2[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // vector<int> que={15,-2,2,-8,1,7,10,23};
    // int ans=largestsubarraywithsumzero(que);
    // cout<<ans;




    return 0;
}