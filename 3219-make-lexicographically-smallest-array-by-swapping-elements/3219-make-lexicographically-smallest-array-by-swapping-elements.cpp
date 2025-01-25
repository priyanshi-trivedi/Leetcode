class Solution {
public:
    class UnionFind {
    public:
        vector<int> parent, rank;

        UnionFind(int n) {
            parent.resize(n);
            rank.resize(n, 1);
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        }

        void unionSets(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }
    };

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> valueIndexPairs;

        // Step 1: Create value-index pairs and sort by values
        for (int i = 0; i < n; ++i) {
            valueIndexPairs.emplace_back(nums[i], i);
        }
        sort(valueIndexPairs.begin(), valueIndexPairs.end());

        // Step 2: Union indices with value differences <= limit
        UnionFind uf(n);
        for (int i = 0; i < n - 1; ++i) {
            if (abs(valueIndexPairs[i + 1].first - valueIndexPairs[i].first) <= limit) {
                uf.unionSets(valueIndexPairs[i].second, valueIndexPairs[i + 1].second);
            }
        }

        // Step 3: Group indices by connected components
        unordered_map<int, vector<int>> components;
        for (int i = 0; i < n; ++i) {
            components[uf.find(i)].push_back(i);
        }

        // Step 4: Sort each component and update the result
        vector<int> result = nums;
        for (auto& [root, indices] : components) {
            vector<int> values;
            for (int index : indices) {
                values.push_back(nums[index]);
            }

            sort(values.begin(), values.end());
            sort(indices.begin(), indices.end());

            for (int i = 0; i < indices.size(); ++i) {
                result[indices[i]] = values[i];
            }
        }

        return result;
    }
};