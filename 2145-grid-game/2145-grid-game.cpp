class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

    // Prefix sums for the top and bottom rows using long long to prevent overflow.
    vector<long long> topPrefixSum(n + 1, 0), bottomPrefixSum(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        topPrefixSum[i] = topPrefixSum[i - 1] + grid[0][i - 1];
        bottomPrefixSum[i] = bottomPrefixSum[i - 1] + grid[1][i - 1];
    }

    long long result = LLONG_MAX;

    // Try breaking the path of the first robot at every column.
    for (int col = 1; col <= n; ++col) {
        long long pointsTop = topPrefixSum[n] - topPrefixSum[col]; // Remaining points in the top row.
        long long pointsBottom = bottomPrefixSum[col - 1];         // Collected points in the bottom row.

        // Minimize the max points collected by the second robot.
        result = min(result, max(pointsTop, pointsBottom));
    }

    return result;
        
    }
};