class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 1;
        
        for (int i = 0; i < n; i++) {
            int bitwiseAND = 0;
            for (int j = i; j < n; j++) {
                if ((bitwiseAND & nums[j]) == 0) {
                    bitwiseAND |= nums[j];
                    maxLength = max(maxLength, j - i + 1);
                } else {
                    break;
                }
            }
        }
        
        return maxLength;  
    }
};