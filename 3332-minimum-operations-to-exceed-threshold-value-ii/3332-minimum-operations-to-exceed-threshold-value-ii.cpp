class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());
    int operations = 0;

    while (minHeap.top() < k) {
        // Extract the two smallest elements
        long long x = minHeap.top(); minHeap.pop();
        long long y = minHeap.top(); minHeap.pop();

        // Create the new value using long long to prevent overflow
        long long newValue = min(x, y) * 2LL + max(x, y);

        // Insert back into heap
        minHeap.push(newValue);
        
        // Increment the count of operations
        operations++;
    }

    return operations;
    }
};