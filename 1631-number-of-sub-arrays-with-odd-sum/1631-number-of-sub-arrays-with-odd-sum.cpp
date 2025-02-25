class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
       const int MOD = 1e9 + 7;
        int odd = 0, even = 1;  // Initialize even = 1 (empty subarray considered even)
        int prefixSum = 0;
        int result = 0;

        for (int num : arr) {
            prefixSum += num;

            if (prefixSum % 2 == 0) {
                result = (result + odd) % MOD;  // Even - Odd = Odd
                even++;
            } else {
                result = (result + even) % MOD;  // Odd - Even = Odd
                odd++;
            }
        }

        return result; 
    }
};