class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxChunks = 0;
        int maxSoFar = 0;

        for (int i = 0; i < arr.size(); ++i) {
            // Track the maximum value encountered so far
            maxSoFar = max(maxSoFar, arr[i]);

            // If the max value so far equals the current index, we can make a chunk
            if (maxSoFar == i) {
                maxChunks++;
            }
        }

        return maxChunks;
    }
};