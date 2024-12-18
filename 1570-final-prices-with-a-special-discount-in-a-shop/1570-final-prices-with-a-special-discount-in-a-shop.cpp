class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
     int n = prices.size();
    vector<int> answer(n);
    
    for (int i = 0; i < n; i++) {
        // Start with no discount
        answer[i] = prices[i];
        
        // Look for the first valid discount
        for (int j = i + 1; j < n; j++) {
            if (prices[j] <= prices[i]) {
                answer[i] -= prices[j]; // Apply the discount
                break; // Stop searching
            }
        }
    }
    return answer;  
    }
};