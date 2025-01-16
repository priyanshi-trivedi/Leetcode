class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
    
    // XOR all elements in nums1
    for (int num : nums1) {
        xor1 ^= num;
    }
    
    // XOR all elements in nums2
    for (int num : nums2) {
        xor2 ^= num;
    }
    
    int result = 0;
    if (nums1.size() % 2 != 0) {
        result ^= xor2; // nums2 contributes
    }
    if (nums2.size() % 2 != 0) {
        result ^= xor1; // nums1 contributes
    }
    return result;
    }
};