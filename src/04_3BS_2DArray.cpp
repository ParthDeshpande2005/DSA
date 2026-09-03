#include<bits/stdc++.h>
using namespace std;

//return the Nth number of row->
//the row only has 0 and 1 and is sorted 
int lowerbound(vector<int> arr,int x){
    int n=arr.size();

    int low=0,high=n-1;
    int ans=n;

    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int find_row_with_max_1(vector<vector<int>>& matrix){
    int n=matrix.size();
    int m=matrix[0].size();

    int cnt_max=0;
    int index=-1;

    for(int i=0;i<n;i++){
        int cnt_ones=m-lowerbound(matrix[i],1);//get cnt of one
        if(cnt_ones>cnt_max){
            cnt_max=cnt_ones;
            index=i;
        }
    }
    return index;
}

//Method 1 -> my solution
bool searchinarray(vector<int>& arr,int target){
    int m=arr.size();
    int low=0,high=m-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(arr[mid]==target) return true;
            
        if(arr[mid]>target){
            high=mid-1;
        }
        else low=mid+1;
    }
    return false;
}
bool searchMatrix1part1(vector<vector<int>>& matrix, int target) {
    int n=matrix.size();
    int m=matrix[0].size();

    int low=0;
    int high=n-1;

    bool ans=false;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(matrix[mid][0]<=target && matrix[mid][m-1]>=target){
            ans=searchinarray(matrix[mid],target);
            return ans;
        }

        if(matrix[mid][0]>target){
            high=mid-1;
        }

        else low=mid+1;
    }
    return ans;
}
//method 2-> flate the 2D array in 1D->
bool searchMatrix2part1(vector<vector<int>>& matrix, int target) {
    int n=matrix.size();
    int m=matrix[0].size();

    int low=0,high=n*m-1;

    while(low<=high){
        int mid=(low+high)/2;

        int row=mid/m;
        int col=mid%m;

        if(matrix[row][col]==target) return true;

        else if(matrix[row][col]<target) low=mid+1;

        else high=mid-1;
    }
    return false;
}


//Better solution-> O(n log m) using binary searh for each array.
//optimal Solution-> we dont directly apply binary search but we use the concept of elemination.
bool searchMatrixpart2(vector<vector<int>>& matrix, int target) {
    int n=matrix.size();
    int m=matrix[0].size();

    int row=0,col=m-1;

    while(row<n && col>=0){
        if(matrix[row][col]==target) return true;
        else if(matrix[row][col]<target) row++;
        else col--;
    }
    return false;
}


//Brute Force-> O(n*m*4) check for all elements.
//Better Solution-> O(n*m) return the largest element in the matrix.
//optimal using same kind of idea we used to find the solution of peak element 1(BS on 1D array last que)
//TC->O(log2m * n)  SC->O(1)
int maxele_in_col(vector<vector<int>>& mat,int n,int m,int mid){
    int maxi=-1;
    int maxi_ind=-1;
    for(int i=0;i<n;i++){
        if(maxi<mat[i][mid]) {
            maxi=mat[i][mid];
            maxi_ind=i;
        }
    }
    return maxi_ind;
}
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n=mat.size();
    int m=mat[0].size();

    int low=0;
    int high=m-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        int row_max=maxele_in_col(mat,n,m,mid);

        int left,right;

        if(mid-1>=0){
            left=mat[row_max][mid-1];
        }
        else left=-1;

        if(mid+1<m){
            right=mat[row_max][mid+1];
        }
        else right=-1;

        if(mat[row_max][mid]>left && mat[row_max][mid]>right){
            return {row_max,mid};
        }

        else if(mat[row_max][mid]<left){
            high=mid-1;
        }

        else{
            low=mid+1;
        }
    }
    return {-1,-1};
}


//BS on Answer in 2D array->
//find median of a matrix where rows are sorted
//the length of row and col is both odd so we have only one center.
int upperbound(vector<int> & arr,int x,int n){
    int low=0,high=n-1;
    int ans=n;

    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int countSmallEqual(vector<vector<int>> & matrix,int n,int m,int x){
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=upperbound(matrix[i],x,m);
    }
    return cnt;
}
int median2Darray(vector<vector<int>>& matrix){
    int n=matrix.size();
    int m=matrix[0].size();

    int low=INT_MAX; int high=INT_MIN;

    for(int i=0;i<n;i++){
        low=min(low,matrix[i][0]);
        high=max(high,matrix[i][m-1]);
    }

    int req=(n*m)/2;

    while(low<=high){
        int mid=(low+high)/2;
        int smallEqual=countSmallEqual(matrix,n,m,mid);
        if(smallEqual<=req) low=mid+1;
        else high=mid-1;
    }
    return low;
}


//leetcode 2812 //BFS+BS question.


int main(){

    // vector<vector<int>> matrix = {
    // {0, 0, 1, 1},
    // {0, 1, 1, 1},
    // {0, 0, 0, 1},
    // {1, 1, 1, 1}};
    // cout << find_row_with_max_1(matrix) << endl;

   
    // vector<vector<int>> matrix = {
    // {1, 3, 5, 7},
    // {10, 11, 16, 20},
    // {23, 30, 34, 60}};
    // int target = 16;
    // if (searchMatrix2part1(matrix, target)) cout << "Target found\n";
    // else cout << "Target not found\n";


    // vector<vector<int>> matrix = {
    // {1, 4, 7, 11, 15},
    // {2, 5, 8, 12, 19},
    // {3, 6, 9, 16, 22},
    // {10, 13, 14, 17, 24},
    // {18, 21, 23, 26, 30}};
    // int target = 16;
    // if (searchMatrixpart2(matrix, target)) cout << "Target found" << endl;
    // else cout << "Target not found" << endl;


    // vector<vector<int>> mat = {{1, 4},{3, 2}};
    // vector<int> ans = findPeakGrid(mat);
    // cout << "Peak found at: (" << ans[0] << ", " << ans[1] << ")\n";
    // cout << "Value = " << mat[ans[0]][ans[1]] << endl;


    // vector<vector<int>> matrix = {{1, 3, 5},{2, 6, 9},{3, 6, 9}};
    // cout << "Median = " << median2Darray(matrix) << endl;



    return 0;
}