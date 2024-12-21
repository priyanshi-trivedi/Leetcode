class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
         // Step 1: Build the adjacency list representation of the tree
        vector<vector<int>> tree(n);
        for (const auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        
        // Step 2: Initialize variables
        vector<bool> visited(n, false);
        int components = 0;

        // Step 3: Define the DFS function
        function<long long(int)> dfs = [&](int node) {
            visited[node] = true;
            long long subtree_sum = values[node]; // Use long long to prevent overflow
            
            for (int neighbor : tree[node]) {
                if (!visited[neighbor]) {
                    subtree_sum += dfs(neighbor);
                }
            }
            
            // Check if the current subtree sum is divisible by k
            if (subtree_sum % k == 0) {
                components++;
                return 0LL; // Reset the subtree sum for this component
            }
            return subtree_sum; // Return the remaining sum for the parent node
        };

        // Step 4: Start DFS from node 0
        dfs(0);
        
        return components;
    }
};