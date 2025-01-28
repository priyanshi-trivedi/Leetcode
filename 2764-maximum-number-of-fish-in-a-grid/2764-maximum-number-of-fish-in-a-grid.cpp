class Solution {
public:
    // Helper function to perform DFS
    int dfs(vector<vector<int>>& grid, int r, int c) {
    // Check if the cell is out of bounds or is land
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
        return 0;
    }

    // Collect the fish at the current cell
    int fish = grid[r][c];
    grid[r][c] = 0; // Mark the cell as visited

    // Explore all 4 possible directions
    int up = dfs(grid, r - 1, c);
    int down = dfs(grid, r + 1, c);
    int left = dfs(grid, r, c - 1);
    int right = dfs(grid, r, c + 1);

    // Return the total fish collected from this path
    return fish + up + down + left + right;
}

int findMaxFish(vector<vector<int>>& grid) {
    int maxFish = 0;

    // Iterate through all cells in the grid
    for (int r = 0; r < grid.size(); ++r) {
        for (int c = 0; c < grid[0].size(); ++c) {
            // If the cell is a water cell, start a DFS
            if (grid[r][c] > 0) {
                maxFish = max(maxFish, dfs(grid, r, c));
            }
        }
    }

    return maxFish;
    }
};