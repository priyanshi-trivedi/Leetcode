class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBitsNum2 = __builtin_popcount(num2); // Count the set bits in num2
        int result = 0;

        // Set bits in result based on num1
        for (int i = 31; i >= 0 && setBitsNum2 > 0; --i) {
            if (num1 & (1 << i)) { // If the bit at position i in num1 is set
                result |= (1 << i); // Set the same bit in result
                --setBitsNum2;      // Decrease the count of required set bits
            }
        }

        // Set remaining bits in result starting from the least significant bit
        for (int i = 0; i < 32 && setBitsNum2 > 0; ++i) {
            if (!(result & (1 << i))) { // If the bit at position i in result is not set
                result |= (1 << i);    // Set it
                --setBitsNum2;         // Decrease the count of required set bits
            }
        }

        return result;
        
    }
};