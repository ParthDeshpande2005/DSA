#include<bits/stdc++.h>
using namespace std;

void Selection_Sort(int arr[],int n){
    //select minium and swap
    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
        //swaping i and mini
        int temp=arr[mini];
        arr[mini]=arr[i];
        arr[i]=temp;
    }

}


void Bubble_Sort(int arr[],int n){
    //push the max to last by doing adjacent swap.
    for(int i=0;i<n;i++){
        int didswap=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                didswap=1;
            }
        }
        if(didswap==0){
            break;
        }
        // cout<<"runs"<<endl;
    }
}


void Insertion_Sort(int arr[],int n){
    //you take an element and insert it into allready sorted left portion.
    for(int i=0;i<n;i++){//har bar arr[i] jitna part sort ho raha hai.first time 1 element fir 2 fir 3 and so on
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            //swap
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }   
    }
}


void Merge(vector<int> &arr,int low,int mid,int high){//here & is used to pass by reference. which changes the original value . 
    vector<int> temp;
    //1st arr->[low....mid]
    //2nd arr->[mid+1....high]
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void Merge_Sort(vector<int> &arr,int low,int high){
    //we pass by reference as we need changes in the original vector.
    //Divide and Merge
    if(low==high) return;
    int mid=(low+high)/2;
    Merge_Sort(arr,low,mid);
    Merge_Sort(arr,mid+1,high);
    Merge(arr,low,mid,high);

}


int Partitionele(vector<int> &arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void Quick_Sort(vector<int> &arr,int low,int high){
    //Pick a Pivot element and place it its correct place in the sorted array.
    //smaller on the left and larger on the right.
    //divide and conquer Algorithm
    if(low<high){
        int PIndex=Partitionele(arr,low,high);
        Quick_Sort(arr,low,PIndex-1);
        Quick_Sort(arr,PIndex+1,high);
    }
}   


int main(){
    int n;
    cin>>n;
    int arr[n];
    vector<int> arrvec;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arrvec.emplace_back(arr[i]);
    }

    // Selection_Sort(arr,n);

    // Bubble_Sort(arr,n);

    // Insertion_Sort(arr,n);

    Merge_Sort(arrvec,0,n-1);//taking vector for merge sort.

    // Quick_Sort(arrvec,0,n-1);//taking vector for quick sort as well.

    for(int i=0;i<n;i++){
        cout<<arrvec[i]<<" ";//print arrvec or arr according to the sorting algorithm used.
    }

    return 0;
}

/*input-> for selection,bubble,insertion.
6
13 46 24 52 20 9
*/

/*input for Merge sort selection sort
9
3 1 2 4 1 5 2 6 4
*/