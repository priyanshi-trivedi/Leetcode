class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
         long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2; // Total number of pairs
        unordered_map<int, long long> freq;
        long long goodPairs = 0;
        
        for (int j = 0; j < n; ++j) {
            int key = nums[j] - j;
            if (freq.find(key) != freq.end()) {
                goodPairs += freq[key];
            }
            freq[key]++;
        }
        
        return totalPairs - goodPairs;
        
    }
};