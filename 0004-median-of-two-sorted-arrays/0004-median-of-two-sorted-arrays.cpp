class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int low = 0 , high = m;
        while (low<=high){
            int cuta = (low+high)/2;
            int cutb = (m+n+1)/2 - cuta;
            int leftA  = (cuta == 0) ? INT_MIN : nums1[cuta - 1];
            int rightA = (cuta == m) ? INT_MAX : nums1[cuta];
            int leftB  = (cutb == 0) ? INT_MIN : nums2[cutb - 1];
            int rightB = (cutb == n) ? INT_MAX : nums2[cutb];
            if (leftA<=rightB && leftB<=rightA){
                if ((m+n)%2==1){
                    return max(leftA,leftB);
                }
                else{
                    return (max(leftA,leftB) + min(rightA,rightB)) / 2.0;
                }
            }
            else if (leftA>rightB){
                high = cuta-1;
            }
            else{
                low = cuta+1;
            }
        }
        
        return 0.0;
    }
};