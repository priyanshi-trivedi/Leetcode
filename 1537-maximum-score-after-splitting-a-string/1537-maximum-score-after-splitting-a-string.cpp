class Solution {
public:
    int maxScore(string s) {
         int n = s.length();
    int max_score = 0;

    // Calculate the total number of ones in the string
    int total_ones = 0;
    for (char c : s) {
        if (c == '1') total_ones++;
    }

    int left_zeros = 0;
    int right_ones = total_ones;

    // Iterate through the string, keeping track of zeros on the left
    // and ones on the right for each split point
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0') left_zeros++;
        else right_ones--;

        // Calculate the score for the current split
        int current_score = left_zeros + right_ones;
        max_score = std::max(max_score, current_score);
    }

    return max_score;
    }
};