
#include <stdio.h>
#include <iostream>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // int i=m-1, j=n-1, k=m+n-1;
    // while(i>=0 && j>=0){
    //     if(nums1[i]>nums2[j]){
    //         nums1[k] = nums1[i];
    //         i--;
    //         k--;
    //     }
    //     else{
    //         nums1[k]=nums2[j];
    //         j--;
    //         k--;
    //     }
    // }
    // while(i>=0){
    //     nums1[k--]=nums1[i--];
    // }
    // while(j>=0){
    //     nums1[k--]=nums2[j--];
    // }

    /* slower code */    
    int j = 0;
    for(int i = m; i < m+n; i++) {
     
        nums1[i] = nums2[j];
        j++;
    }
    sort(nums1.begin(), nums1.end());
    
}


int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    merge(nums1, 3, nums2, 3);
    for(auto i: nums1) cout << i << " ";
    cout << endl;
}
