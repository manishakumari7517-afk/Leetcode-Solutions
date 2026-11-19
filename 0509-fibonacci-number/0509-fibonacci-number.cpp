class Solution {
public:
vector<int> dp;
     
     int fib(int n){
        if(n <= 1)return n;
        vector<int> dp(3);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[2] = dp[1] + dp[0];
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
     }
    // int fibo(int n, vector<int>& dp) {
    //     if(n <= 0 or n == 1)return n;
    //     if(dp[n] != -1)return dp[n];
    //     int ans = fib(n-1) + fib(n-2);
    //     dp[n] = ans;
    //     return ans;
    // }
    // int fib(int n){
    //     vector<int> dp(n+1, -1);
    //     return fibo(n, dp);
    // }
};