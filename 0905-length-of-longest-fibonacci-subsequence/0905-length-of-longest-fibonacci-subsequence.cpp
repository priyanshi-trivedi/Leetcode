class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
         int n = arr.size();
    unordered_map<int, int> index;
    for (int i = 0; i < n; i++) {
        index[arr[i]] = i;
    }
    
    unordered_map<int, int> dp;
    int maxLength = 0;
    
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < k; j++) {
            int i = index.count(arr[k] - arr[j]) ? index[arr[k] - arr[j]] : -1;
            if (i >= 0 && i < j) {
                int len = (dp[i * n + j] > 0 ? dp[i * n + j] : 2) + 1;
                dp[j * n + k] = len;
                maxLength = max(maxLength, len);
            }
        }
    }
    
    return maxLength >= 3 ? maxLength : 0;
    }
};