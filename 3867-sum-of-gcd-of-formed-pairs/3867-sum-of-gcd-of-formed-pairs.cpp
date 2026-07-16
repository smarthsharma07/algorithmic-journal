class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int> prefixGCD;
        int curr_max = nums[0];
        prefixGCD.push_back(gcd(nums[0],curr_max));
        for (int i = 1; i < n; ++i) {
            curr_max = max(curr_max, nums[i]);
            prefixGCD.push_back(gcd(nums[i], curr_max));
        }
        sort(prefixGCD.begin(),prefixGCD.end());
        int m = prefixGCD.size();
        long long total = 0;
        for (int i = 0; i < m / 2; ++i) {
            int a = prefixGCD[i];
            int b = prefixGCD[m - 1 - i];
            total +=gcd(a, b);
        }
        return total;
    }
};