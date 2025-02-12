class Solution {
public:
    int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

    int maximumSum(vector<int>& nums) {
    unordered_map<int, int> maxValues; // Maps digit sum to max num with that sum
    int maxPairSum = -1;
    
    for (int num : nums) {
        int sum = digitSum(num);
        
        if (maxValues.find(sum) != maxValues.end()) {
            // Update maxPairSum with the best sum found so far
            maxPairSum = max(maxPairSum, maxValues[sum] + num);
            // Update the max value for this digit sum
            maxValues[sum] = max(maxValues[sum], num);
        } else {
            maxValues[sum] = num;
        }
    }
    
    return maxPairSum;
        
    }
};