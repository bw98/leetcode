//Runtime: 52 ms
#include<algorithm>
using std::min;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() && nums2.empty()) {
            return 0;
        }
        int l1 = nums1.size(), l2 = nums2.size();
        int l3 = l1 + l2;
        int i1 = 0, i2 = 0, i3 = 0;
        int indexM1 = (l3-1)/2, indexM2 = l3/2; //the former for odd,the latter for even
        double res1 = 0, res2 = 0;
        //mergeSort
        while (i1 < l1 && i2 < l2) { 
            if (i3 > indexM2) {
                break;
            }
            if (i3 == indexM1) {
                res1 = min(nums1[i1],nums2[i2]);
            }
            if (i3 == indexM2) {
                res2 = min(nums1[i1],nums2[i2]);
            }
            if (nums1[i1] < nums2[i2]) {
                i1++;
            }
            else {
                i2++;
            }
            i3++;
        }
        
        while (i1 < l1) { //nums1 has element
            if (i3 > indexM2) {
                break;
            }
            if (i3 == indexM1) {
                res1 = nums1[i1];
            }
            if (i3 == indexM2) {
                res2 = nums1[i1];
            }
            i1++;
            i3++;  
        }
        while (i2 < l2) { //nums2 has element
            if (i3 > indexM2) {
                break;
            }
            if (i3 == indexM1) {
                   res1 = nums2[i2];
            }
            if (i3 == indexM2) {
                res2 = nums2[i2];
            }
            i2++;
            i3++;
        }
        
        //for odd,return res1;for even,return (res1 + res2)/2.0;
        if (l3%2 == 0) {
            return (res1 + res2)/2.0;
        }
        else {
            return res1;
        }
    }
};
