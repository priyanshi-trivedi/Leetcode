class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball_colors;   // Maps ball to its color
    unordered_map<int, int> color_count;   // Maps color to its count
    vector<int> result;
    
    for (const auto& query : queries) {
        int x = query[0], y = query[1];

        if (ball_colors.count(x)) {
            int prev_color = ball_colors[x];
            if (--color_count[prev_color] == 0) {
                color_count.erase(prev_color);
            }
        }

        ball_colors[x] = y;
        color_count[y]++;
        result.push_back(color_count.size());
    }

    return result;
        
    }
};