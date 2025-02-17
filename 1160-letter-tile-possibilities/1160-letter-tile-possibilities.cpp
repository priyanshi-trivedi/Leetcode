class Solution {
public:
    void backtrack(unordered_map<char, int>& count, int& result, int length) {
    for (auto& [ch, freq] : count) {
        if (freq > 0) {
            result++; // Count the new sequence
            count[ch]--; // Use the tile
            backtrack(count, result, length + 1);
            count[ch]++; // Backtrack
        }
    }
}
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> count;
    for (char tile : tiles) {
        count[tile]++;
    }
    int result = 0;
    backtrack(count, result, 0);
    return result;
    }
};