class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
    vector<int> dp(high + 1, 0);
    dp[0] = 1; // Base case: one way to form an empty string

    // Fill the DP table
    for (int i = 1; i <= high; ++i) {
        if (i >= zero) {
            dp[i] = (dp[i] + dp[i - zero]) % MOD;
        }
        if (i >= one) {
            dp[i] = (dp[i] + dp[i - one]) % MOD;
        }
    }

    // Compute the result by summing up dp[low] to dp[high]
    int result = 0;
    for (int i = low; i <= high; ++i) {
        result = (result + dp[i]) % MOD;
    }

    return result;
        
    }
};