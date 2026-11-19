class Solution {
public:
    // int loot(int idx, vector<int>& nums, vector<int>& dp){
    //     if(idx >= nums.size())return 0;  
    //     if(dp[idx] != -1)return dp[idx];   //check
    //      int pick = nums[idx] + loot(idx+2, nums, dp);
    //      int skip =loot(idx+1, nums, dp);
    //      dp[idx] = max(pick, skip);   //extra
    //      return dp[idx];
    // }
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(nums.size(), -1);
    //     dp[0] = nums[0];
    //     if(n > 1)dp[1] = max(nums[0], nums[1]);
    //     for(int i = 2; i < n; i++){
    //         dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
    //     }
    //     return dp[n-1];
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        if(n == 2)return max(nums[0], nums[1]);
        vector<int> dp(3);
        dp[0] = nums[0];
        if(n > 1)dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            dp[2] = max(nums[i]+dp[0], dp[1]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }

};



// int sum = 0;
        // int maxSum = 0;
        // for(int i = 1; i < nums.size(); i++){
        //     for(int j = i + 2; j < nums.size(); j++){
        //         sum += nums[i] + nums[j];
        //     }
        // }