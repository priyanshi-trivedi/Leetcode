class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, 0);

        for (int i = n - 1; i >= 0; --i) {
        // Option 1: Buy a 1-day pass
        int cost1 = costs[0] + (i + 1 < n ? dp[i + 1] : 0);

        // Option 2: Buy a 7-day pass
        int j = i + 1;
        while (j < n && days[j] < days[i] + 7) ++j;
        int cost7 = costs[1] + (j < n ? dp[j] : 0);

        // Option 3: Buy a 30-day pass
        j = i + 1;
        while (j < n && days[j] < days[i] + 30) ++j;
        int cost30 = costs[2] + (j < n ? dp[j] : 0);

        // Take the minimum of all options
        dp[i] = min({cost1, cost7, cost30});
    }

    return dp[0];
    }
};