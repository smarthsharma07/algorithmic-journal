class Solution {
public:
    int findbound(vector<int>& nums , int target , bool isFirst){
        int low =0;
        int high = nums.size()-1;
        while (low<=high){
            int mid = low + (high-low)/2;
            if (nums[mid]==target){
                if (isFirst){
                    if (mid==low || nums[mid-1]!=target){
                        return mid;
                    }
                    high = mid -1;
                }
                else {
                    if (mid==high || nums[mid+1]!=target){
                        return mid;
                    }
                    low=mid+1;
                }
            }
            else if (nums[mid]>target){
                high = mid -1;
            }
            else {
                low = mid +1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findbound(nums,target,true);
        if (first==-1){
            return {-1,-1};
        }
        int last = findbound(nums,target,false);
        return {first,last};
    }
};