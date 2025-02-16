class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
        vector<int> result(size, 0);
        vector<bool> used(n + 1, false);
        generateSequence(result, used, n, 0);
        return result;
    }
    private:
    bool generateSequence(vector<int>& result, vector<bool>& used, int n, int index) {
        if (index == result.size()) return true;
        
        if (result[index] != 0) return generateSequence(result, used, n, index + 1);
        
        for (int num = n; num >= 1; --num) {
            if (used[num]) continue;
            
            if (num == 1) {
                result[index] = 1;
                used[num] = true;
                if (generateSequence(result, used, n, index + 1)) return true;
                result[index] = 0;
                used[num] = false;
            } else {
                int secondIndex = index + num;
                if (secondIndex < result.size() && result[secondIndex] == 0) {
                    result[index] = result[secondIndex] = num;
                    used[num] = true;
                    if (generateSequence(result, used, n, index + 1)) return true;
                    result[index] = result[secondIndex] = 0;
                    used[num] = false;
                }
            }
        }
        return false;
    }
};