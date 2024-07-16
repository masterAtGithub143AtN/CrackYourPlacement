
#include <bits/stdc++.h>
using namespace std;




class Solution {
public:

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2 * (long long)arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += countPairs(arr, low, mid, high); //Modification
    merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}











    int merge(int low,int mid,int high,vector<int> &nums){
        vector<int> temp;
        int left=low;
        int right=mid+1;
        int cnt=0;
        int ans=0;
        int left1=low;
        int right1=mid+1;
        while(left1<=mid && right1<=high){
            cnt=0;
            while(left1<=mid && right1<=high){
            if(nums[left1]>2*(long long)nums[right1]){
                cnt++;
                right1++;
                if(right1>high){
                    ans+=cnt;
                }
            }
            else{
                ans+=cnt;
                left1++;
            }
        }
        // cout<<ans<<"   ans ";
        left1++;
        right1=mid+1;
        }
        // cout<<ans<<"    ";
        // for(int i=low;i<=mid;i++){
        //     cout<<nums[i]<<" ";
        // }
        // cout<<"    ";
        // for(int i=mid+1;i<=high;i++){
        //     cout<<nums[i]<<" ";
        // }
        // cout<<endl;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        int n=high-low+1;
        for(int i=0;i<n;i++){
            nums[i+low]=temp[i];
        }
        return ans;
    }
    int mergesort(int low,int high,vector<int> &nums){
        if(low>=high){
            return 0;
        }
        int cnt=0;
        int mid=(high+low)/2;
        cnt+=mergesort(low,mid,nums);
        cnt+=mergesort(mid+1,high,nums);
        cnt+=merge(low,mid,high,nums);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        // return mergeSort(nums,0,nums.size()-1);
        int x= mergesort(0,nums.size()-1,nums);
        // for(int i=0;i<nums.size();i++){
        //     cout<<nums[i]<<" ";
        // }
        return x;
    }
};