class Solution {
public:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        int m = nums1.size();
        int n = nums2.size();
        vector<int> mergarr;
        mergarr.reserve(m+n);
        int i = 0;
        int j = 0;
        int k = m+n-1;
        while (i< nums1.size() && j<nums2.size()){
            if (nums1[i]<=nums2[j]){
                mergarr.push_back(nums1[i]);
                i++;
            }
            else{
                mergarr.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size()) {
            mergarr.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()) {
            mergarr.push_back(nums2[j]);
            j++;
        }
        return mergarr;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merged = merge(nums1,nums2);
        int n = merged.size();
        if (n%2==1){
            return merged[n/2];
        }
        else{
            return (merged[n/2 - 1] + merged[n/2]) / 2.0;
        }

    }
};