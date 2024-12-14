class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen; // To store numbers we have already seen
        
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n); // Add the current number to the set
            n = getSumOfSquares(n); // Get the next number
        }
        
        return n == 1; // If n becomes 1, it's a happy number
    }

private:
    int getSumOfSquares(int num) {
        int sum = 0;
        while (num > 0) {
            int digit = num % 10; // Extract the last digit
            sum += digit * digit; // Add the square of the digit
            num /= 10; // Remove the last digit
        }
        return sum;
    }
};