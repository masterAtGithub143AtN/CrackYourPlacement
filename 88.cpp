#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int onel = m-1;
        int twol = n-1;
        int sortl = m+n-1;
        while(onel >= 0 && twol >= 0) {
            if (nums1[onel]<nums2[twol]) {
                nums1[sortl] = nums2[twol];
                twol--;
            } else {
                nums1[sortl] = nums1[onel];
                // nums1[onel] = nums2[twol];
                onel--;
            }
            sortl--;
        }

        while (twol >= 0) {
            nums1[sortl] = nums2[twol];
            sortl--;
            twol--;
        }
    }
};