class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        // Check if the XOR of all elements in derived is 0
        int xorSum = 0;
        for (int x : derived) {
            xorSum ^= x;
        }

        // If the XOR sum of derived is 0, a valid original array exists
        return xorSum == 0;
        
    }
};