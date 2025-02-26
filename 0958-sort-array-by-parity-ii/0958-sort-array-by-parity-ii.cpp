class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int evenIndex = 0, oddIndex = 1;
    int n = nums.size();

    while (evenIndex < n && oddIndex < n) {
        while (evenIndex < n && nums[evenIndex] % 2 == 0) {
            evenIndex += 2;  // Even index pe even number hai to aage badho
        }
        while (oddIndex < n && nums[oddIndex] % 2 == 1) {
            oddIndex += 2;  // Odd index pe odd number hai to aage badho
        }
        // Ab humare paas ek galat evenIndex aur ek galat oddIndex hoga, to swap karenge
        if (evenIndex < n && oddIndex < n) {
            swap(nums[evenIndex], nums[oddIndex]);
        }
    }
    
    return nums; 
    }
};