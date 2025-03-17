class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int freq[501] = {0}; 
    for (int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;
    }
    for (int i = 1; i <= 500; i++) {
        if (freq[i] % 2 != 0) {
            return false;
        }
    }

    return true;
    }
};