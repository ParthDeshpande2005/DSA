#include<bits/stdc++.h>
using namespace std;
//All Monotonic Stack questions-->

//leetcode 496
//Next Greater element.
vector<int> NGE1(vector<int>& arr){
    //brute force-->
    // finding next greater for each element 
    // TC->O(n^2)
    // SC->O(n)  to store result.
    //for brute force we apply two for loop to find next greater to right.

    //Optimal -->
    //TC-->O(2N)-->O(N) one N for loop.second N as the while operation can run till max N times as only N elements can be added in stack.
    //SC-->O(2N)-->O(N) one for stack and one to return result.
    // Traverse from right to left.
// Remove all elements that are smaller than or equal to the current element.
// The remaining top (if any) is the next greater element.
// Push the current element onto the stack.
// The stack maintains elements in strictly decreasing order.
    int n=arr.size();
    vector<int> result(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]>=st.top()){ //only use >= as we also want to pop same value.
            st.pop();
        }
        if(st.empty()) result[i]=-1;
        else result[i]=st.top();

        st.push(arr[i]);
    }
    return result;


}

//leetcdoe 503.
vector<int> NGE2(vector<int>& arr){

    //Optimal->
    // TC --> O(2N) --> O(N)
    // Every element is pushed and popped at most once.
    // SC --> O(N)
    // O(N) for the stack and O(N) for the result.
    //we use the better index + the stack logic from NGE1.
    int n=arr.size();
    vector<int> result(n);
    stack<int> st;
    // Traverse the virtual array from right to left.
    // We iterate from (2*n-1) to 0 so that every element
    // has already seen all elements on its right in the
    // circular traversal.
    for(int i=2*n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i%n]){
            st.pop();
        }
        if(i<n){
            // Only store answers during the second half of the traversal.
            // During the first half (i >= n), we are only preparing the stack.
            if(st.empty()){
                result[i]=-1;
            }
            else{
                result[i]=st.top();
            }
        }
        // i % n converts the virtual index back to the original array index.
        st.push(arr[i%n]);
    }
    return result;


    // //Better-> 
    // //TC-->O(N^2)
    // //SC-->O(N)
    // //we virtualize the circular array by hypothetically adding arr to back of arr.
    // //we are able to do this using index manupulation .
    // //when ever our index go over n it gets % by n
    // int n=arr.size();
    // vector<int> result(n,-1);
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<i+n;j++){
    //         int idx=j%n;
    //         if(arr[idx]>arr[i]){
    //             result[i]=arr[idx];
    //             break;
    //         }
    //     }
    // }
    // return result;


    //Bruteforce->
    // TC-> O(N^2)
    // SC->O(N)
    // for(i=0-->n-1){
    //     for(j=i+1-->n-1){

    //     }
    //     if still value nort found
    //     for(j=0-->i-1){

    //     }
    // }
}


//Next Smaller element
vector<int>NSE(vector<int> &arr){
    //simillar to NGE1 only change in few conditions.
    int n=arr.size();
    vector<int> result(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]<=st.top()){ //only use  change is <= insted of >= from NGE1.
            st.pop();
        }
        if(st.empty()) result[i]=-1;
        else result[i]=st.top();

        st.push(arr[i]);
    }
    return result;
}


//rain water traping problem
//leetcode 42
int trap(vector<int>& height) {

    //Optimal-->TC->O(N)  SC->O(1)
    //idea--> we are allways ising minium of right max and left max.so we only need the smaller one.
    //we are allways traveling the smaller of left and right.
    //striver ke video mai mai explain karte wakt thoda galat karta hai according to algorithm.
    //to dry run kar na algorithm.
    //it is about traveling smaller element first.
    int n=height.size();
    int lMax=0;
    int rMax=0;
    int total=0;
    int l=0;
    int r=n-1;
    while(l<r){
        if(height[l]<=height[r]){
            if(lMax>height[l]){
                total+=lMax-height[l];
            }
            else{
                lMax=height[l];
            }
            l=l+1;
        }
        else{
            if(rMax>height[r]){
                total+=rMax-height[r];
            }
            else{
                rMax=height[r];
            }
            r=r-1;
        }
    }
    return total;


    //Better->
    // int n = height.size();
    // if (n == 0) return 0;
    // vector<int> maxi(n);
    // int cur_max = 0;
    // for(int i = n - 1; i >= 0; i--) {
    //     cur_max = max(cur_max, height[i]);
    //     maxi[i] = cur_max;
    // }
    // int cur_min = height[0];
    // int solution = 0;
    // for(int i = 1; i < n - 1; i++) {
    //     cur_min = max(cur_min, height[i]);
    //     solution += min(cur_min, maxi[i]) - height[i];
        
    // }
    // return solution;


    //Using Monotonic stack--> harder appoarch to understand 
    //also has higest time complexity out of all appoarch discused.
    //harder to understand but is similar to Next greater element code templete.
    // int n = height.size();
    // stack<int> st;      // stores indices
    // int water = 0;
    // for (int i = 0; i < n; i++) {
    //     while (!st.empty() && height[i] > height[st.top()]) {
    //         int bottom = st.top();
    //         st.pop();
    //         if (st.empty())
    //             break;
    //         int left = st.top();
    //         int width = i - left - 1;
    //         int boundedHeight =  min(height[left], height[i]) - height[bottom];
    //         water += width * boundedHeight;
    //     }
    //     st.push(i);
    // }
    // return water;
}


// leetcode 907  HARD  VVIMP
//see the edge case for repeat elements...IMP
const int MOD=1e9+7;
//next smallest left. we are storing index.
vector<int> NSL(vector<int>& arr){
    int n=arr.size();
    stack<int> st;//stores index.
    vector<int> result(n);//result is also storing index.

    for(int i=0;i<n;i++){
        //VVIMP se how we use < for NSL ans <= for NSR.
        //we need to use < in one and <= in one.
        // this is avoid the repeat element.
        while(!st.empty() && arr[i]<arr[st.top()]){
            st.pop();
        }
        if(st.empty()) result[i]=-1;
        else result[i]=st.top();
        st.push(i);
    }

    return result;
}
//next smallest right. we are sttoring index.
vector<int> NSR(vector<int> & arr){
    int n=arr.size();
    stack<int> st;
    vector<int> result(n);

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]<=arr[st.top()]){
            st.pop();
        }
        if(st.empty()) result[i]=n;
        else result[i]=st.top();
        st.push(i);
    }

    return result;
}
int sumSubarrayMins(vector<int>& arr) {
    int n=arr.size();

    vector<int> smallL=NSL(arr);
    vector<int> smallR=NSR(arr);

    int ans=0;

    for(int i=0;i<n;i++){
        int cur=(1LL*arr[i]*(i-smallL[i])*(smallR[i]-i))%MOD;
        ans=(ans+cur)%MOD;
    }

    return ans;
}


//leetcode 735
vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    int n=asteroids.size();
    for(int i=0;i<n;i++){
        int cur=asteroids[i];
        if(st.empty()){
            st.push(cur);
        }
        else{
            if(cur>0){
                st.push(cur);
            }
            else{
                while(!st.empty() && abs(cur)>st.top() && st.top()>0){
                    st.pop();
                }
                if(!st.empty()){
                    if(st.top()==abs(cur)){
                        st.pop();
                        continue;
                    }
                }
                if(!st.empty()){
                    if(abs(cur)>st.top()){
                        st.push(cur);
                    }
                }
                if(st.empty()){
                    st.push(cur);
                }
            }
        }
    }

    vector<int> result;
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }

    reverse(result.begin(),result.end());
    return result;



    // //neatly writen-->
    // stack<int> st;
    // for (int cur : asteroids) {
    //     // Positive asteroid: always push
    //     if (cur > 0) {
    //         st.push(cur);
    //     }
    //     // Negative asteroid
    //     else {
    //         // Destroy all smaller positive asteroids
    //         while (!st.empty() && st.top() > 0 && st.top() < abs(cur)) {
    //             st.pop();
    //         }
    //         // Equal-sized asteroids destroy each other
    //         if (!st.empty() && st.top() == abs(cur)) {
    //             st.pop();
    //         }
    //         // No collision (stack empty or top is negative)
    //         else if (st.empty() || st.top() < 0) {
    //             st.push(cur);
    //         }
    //         // Otherwise, current asteroid is destroyed.
    //     }
    // }
    // vector<int> ans;
    // while (!st.empty()) {
    //     ans.push_back(st.top());
    //     st.pop();
    // }
    // reverse(ans.begin(), ans.end());
    // return ans;
}


//leetcode 2104
//nearest smaller right
vector<int> NSR2(vector<int>& arr,int n){
    stack<int> st;
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]<=arr[st.top()]){
            st.pop();
        }
        if(st.empty()) ans[i]=n;
        else ans[i]=st.top();
        st.push(i);
    }
    return  ans;
}
//nearest smaller left
vector<int> NSL2(vector<int> & arr,int n){
    stack<int> st;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]<arr[st.top()]){
            st.pop();
        }
        if(st.empty()) ans[i]=-1;
        else ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
//nearest larger right
vector<int> NLR2(vector<int> & arr,int n){
    stack<int> st;
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]>=arr[st.top()]){
            st.pop();
        }
        if(st.empty()) ans[i]=n;
        else ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
//nearest larger left
vector<int> NLL2(vector<int> & arr,int n){
    stack<int> st;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            st.pop();
        }
        if(st.empty()) ans[i]=-1;
        else ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
long long subArrayRanges(vector<int>& nums) {
    //optimal--> TC-->O(N)  SC-->O(4N)(for storing 4 stack.)
    //the key idea is to apply sum of subarray minium and sum of subarray maximum together.
    //answer=totalmax-totalmin.
    int n=nums.size();
    long long totalmin=0;
    long long totalmax=0;
    vector<int> nsr=NSR2(nums,n);
    vector<int> nsl=NSL2(nums,n);
    vector<int> nlr=NLR2(nums,n);
    vector<int> nll=NLL2(nums,n);
    for(int i=0;i<n;i++){
        totalmin+=1LL*nums[i]*(i-nsl[i])*(nsr[i]-i); //1LL(multiplying 1 in LL) is same as (long long) 
        totalmax+=(long long)nums[i]*(i-nll[i])*(nlr[i]-i);
    }
    return totalmax-totalmin;



    // //brute force works for the leetcode problem--> TC-->O(N^2) SC-->O(1)
    // long long sum=0;
    // int n=nums.size();
    // for(int i=0;i<n;i++){
    //     int largest=nums[i];
    //     int smallest=nums[i];
    //     for(int j=i+1;j<n;j++){
    //         largest=max(largest,nums[j]);
    //         smallest=min(smallest,nums[j]);
    //         sum+=(largest-smallest);
    //     }
    // }
    // return sum;

}


//leetcode 402-->
string removeKdigits(string num, int k) {
    //there are three edge cases -->
    //watch video to get complete idea--> youtube.com/watch?v=jmbuRzYPGrg&feature=youtu.be
    int n=num.size();
    if(k==n) return "0";
    stack<char> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && k>0 && st.top()-'0'>(num[i]-'0')){
            st.pop();
            k=k-1;
        }
        st.push(num[i]);
    }
    while(k>0) {
        st.pop();
        k--;
    }
    if(st.empty()) return "0";
    string result="";
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    while(result.size()!=0 && result.back()=='0' ){
        result.pop_back();
    }
    reverse(result.begin(),result.end());
    if(result.empty()) return "0";
    return result;
}



// leetcode 84-->
//Method 1 --> finding nsr nsl precompute ,2 pass solution.
//TC-> O(5N) 2N for nsl and 2N for nsr and 1 for nums traversal in arr./
vector<int> NSR3(vector<int> &arr){
    int n=arr.size();
    stack<int> st;
    vector<int> result(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]<=arr[st.top()]){
            st.pop();
        }
        if(st.empty()) result[i]=n;
        else result[i]=st.top();
        st.push(i);
    }
    return result;
}
vector<int> NSL3(vector<int> &arr){
    int n=arr.size();
    stack<int> st;
    vector<int> result(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]<=arr[st.top()]){
            st.pop();
        }
        if(st.empty()) result[i]=-1;
        else result[i]=st.top();
        st.push(i);
    }
    return result;
}
int largestRectangleArea1(vector<int>& heights) {
    int n=heights.size();
    vector<int> nsr=NSR3(heights);
    vector<int> nsl=NSL3(heights);
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,heights[i]*(nsr[i]-nsl[i]-1));
        //or
        // int idx=(nsr[i]-i)+(i-nsl[i])-1;
        // maxi=max(maxi,heights[i]*idx);
    }
    return maxi;
}

//Method 2--> using one pas  solution-->
//crazy crazy algorithm .. very intresting
//optimal one pass-->
int largestRectangleArea2(vector<int>& heights) {
    int maxrec=0;
    stack<int> st;
    int n=heights.size();
    for(int i=0;i<n;i++){
        while(!st.empty() && heights[i]<heights[st.top()]){
            int cur=st.top();
            st.pop();
            int nse=i; //next small element.
            int pse=-1;
            if(!st.empty()) pse=st.top();
            //calclate for current buliding.
            int rec=heights[cur]*(nse-pse-1);
            maxrec=max(maxrec,rec);
        }
        st.push(i);
    }
    while(!st.empty()){
        int cur=st.top();
        st.pop();
        int nse=n;
        int pse=-1;
        if(!st.empty()) pse=st.top();
        int rec=heights[cur]*(nse-pse-1);
        maxrec=max(maxrec,rec);
    }
    return maxrec;
}




//simillar to 84. we pass by adding row height.
// same as largest area in histogram .
int maxarea(vector<int> &arr){
    int n=arr.size();
    stack<int> st;
    int ans=0;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            int cur=st.top();
            st.pop();
            int nse=i;
            int pse=-1;
            if(!st.empty()) pse=st.top();
            int cur_max=arr[cur]*(nse-pse-1);
            ans=max(ans,cur_max);
        }
        st.push(i);
    }
    while(!st.empty()){
        int cur=st.top();
        st.pop();
        int nse=n;
        int pse=-1;
        if(!st.empty()) pse=st.top();
        int cur_max=arr[cur]*(nse-pse-1);
        ans=max(ans,cur_max);
    }
    return ans;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    int row=matrix.size();
    int col=matrix[0].size();
    vector<int> heights(col,0);
    int maxrectangle=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]=='0'){
                heights[j]=0;
            }
            else{
                heights[j]=heights[j]+1;
            }
        }
        int cur_max=maxarea(heights);
        maxrectangle=max(maxrectangle,cur_max);
    }
    return maxrectangle;
}




int main(){


    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ans = NGE1(arr);
    cout << "Array: ";
    for (int x : arr){
        cout << x << " ";
    }
    cout << "\nNext Greater Elements: ";
    for (int x : ans){
        cout << x << " ";
    }
    cout<<endl;
    cout<<endl;


    vector<int> arr2 = {2,10,12,1,11};
    vector<int> ans2 = NGE2(arr2);
    cout << "Array: ";
    for (int x : arr2){
        cout << x << " ";
    }
    cout << "\nNext Greater Elements 2 : ";
    for (int x : ans2){
        cout << x << " ";
    }
    cout<<endl;
    cout<<endl;


    vector<int> arr3 = {4,8,5,2,25};
    vector<int> ans3 = NSE(arr3);
    cout << "Array: ";
    for (int x : arr3){
        cout << x << " ";
    }
    cout << "\nNext Greater Elements: ";
    for (int x : ans3){
        cout << x << " ";
    }
    cout<<endl;
    cout<<endl;


    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Height array: ";
    for (int x : height)
        cout << x << " ";
    cout << "\n\nTrapped Water = " << trap(height) << endl;
    cout<<endl;


    vector<int> asteroids = {10, 2, -5, -15, 20, -20, 5, -3};
    cout << "Input: ";
    for (int x : asteroids)
        cout << x << " ";
    cout << "\nOutput: ";
    vector<int> ans4 = asteroidCollision(asteroids);
    for (int x : ans4)
        cout << x << " ";
    cout << endl;
    cout<<endl;



    vector<int> nums = {1, 2, 3};
    cout << "Array: ";
    for (int x : nums)
        cout << x << " ";
    cout << "\n";
    cout << "Sum of Subarray Ranges = " << subArrayRanges(nums) << endl;
    cout<<endl;


    string num = "1432219";
    int k = 3;
    cout << "Number: " << num << endl;
    cout << "k = " << k << endl;
    cout << "Result: " << removeKdigits(num, k) << endl;
    cout<<endl;


    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Histogram: ";
    for (int x : heights)
        cout << x << " ";
    cout << "\n";
    cout << "Largest Rectangle Area 1 = " << largestRectangleArea1(heights) << endl;
    cout<<endl;


    vector<int> heights2 = {2, 1, 5, 6, 2, 3};
    cout << "Histogram: ";
    for (int x : heights2)
        cout << x << " ";
    cout << "\n";
    cout << "Largest Rectangle Area 2 = " << largestRectangleArea2(heights2) << endl;
    cout<<endl;


    vector<vector<char>> matrix = {{'1','0','1','0','0'}, {'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << "Maximum Rectangle Area = " << maximalRectangle(matrix) << endl;




    return 0;
}