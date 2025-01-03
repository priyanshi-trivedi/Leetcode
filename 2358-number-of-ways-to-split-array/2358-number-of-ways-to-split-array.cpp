class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
    vector<long long> prefixSum(n, 0), suffixSum(n, 0);

    // Compute prefix sum
    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    // Compute suffix sum
    suffixSum[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffixSum[i] = suffixSum[i + 1] + nums[i];
    }

    // Count valid splits
    int validSplitsCount = 0;
    for (int i = 0; i < n - 1; i++) {
        if (prefixSum[i] >= suffixSum[i + 1]) {
            validSplitsCount++;
        }
    }

    return validSplitsCount;
        
    }
};