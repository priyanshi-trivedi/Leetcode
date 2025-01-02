class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = words.size();
        vector<int> prefixSum(n + 1, 0);

        // Precompute the prefix sum for words that start and end with vowels
        for (int i = 0; i < n; ++i) {
            char first = words[i][0];
            char last = words[i][words[i].size() - 1];
            prefixSum[i + 1] = prefixSum[i] + (vowels.count(first) && vowels.count(last) ? 1 : 0);
        }

        // Answer each query in O(1)
        vector<int> ans;
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            ans.push_back(prefixSum[r + 1] - prefixSum[l]);
        }
        return ans;
    }
};