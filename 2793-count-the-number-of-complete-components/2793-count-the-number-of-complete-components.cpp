class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
         vector<unordered_set<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        
        vector<bool> visited(n, false);
        int completeComponents = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, adj, visited, component);  // No 'this->' needed
                
                if (isComplete(component, adj)) {  // No 'this->' needed
                    completeComponents++;
                }
            }
        }
        
        return completeComponents;
    }
    
private:
    void dfs(int node, vector<unordered_set<int>>& adj, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, component);
            }
        }
    }
    
    bool isComplete(vector<int>& component, vector<unordered_set<int>>& adj) {
        int size = component.size();
        for (int node : component) {
            if (adj[node].size() != size - 1) {
                return false;
            }
        }
        return true;
    }
};