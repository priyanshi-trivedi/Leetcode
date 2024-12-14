class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq, first, last;
        int degree = 0;

        // Step 1: Populate frequency, first occurrence, and last occurrence
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++; // Increment frequency
            degree = max(degree, freq[nums[i]]); // Track the degree
            if (first.find(nums[i]) == first.end()) {
                first[nums[i]] = i; // Store first occurrence
            }
            last[nums[i]] = i; // Update last occurrence
        }

        // Step 2: Find the shortest subarray with the same degree
        int minLength = INT_MAX;
        for (const auto& [num, count] : freq) {
            if (count == degree) {
                int length = last[num] - first[num] + 1;
                minLength = min(minLength, length);
            }
        }

        return minLength;
        
    }
};