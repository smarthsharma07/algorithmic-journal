class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int ans = nums[0];
        int right = nums.size()-1;
        if (n==1){
            return nums[0];
        }
        while (left<=right){
            if (nums[left]< nums[right]){
                ans = min(ans,nums[left]);
            }
            int mid = (left+right)/2;
            ans = min(ans,nums[mid]);
            if (nums[left]<=nums[mid]){
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return ans;
    }
};