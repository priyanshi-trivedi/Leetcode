class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
         // Step 1: Count character frequencies
    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    // Step 2: Max-Heap to store characters by descending order
    priority_queue<pair<char, int>> maxHeap;
    for (auto &[ch, count] : freq) {
        maxHeap.push({ch, count});
    }

    string result = "";

    while (!maxHeap.empty()) {
        // Step 3: Get the largest character
        auto [ch, count] = maxHeap.top();
        maxHeap.pop();

        // Step 4: Add `ch` up to `repeatLimit` times
        int addCount = min(count, repeatLimit);
        result += string(addCount, ch);
        count -= addCount;

        if (count > 0) {
            // Step 5: Check for the second-largest character
            if (maxHeap.empty()) break; // No alternative character available

            auto [nextCh, nextCount] = maxHeap.top();
            maxHeap.pop();

            // Add the second-largest character once to break the sequence
            result += nextCh;
            nextCount--;

            // Push back the second-largest character if still available
            if (nextCount > 0) {
                maxHeap.push({nextCh, nextCount});
            }

            // Push back the original character
            maxHeap.push({ch, count});
        }
    }

    return result;
        
    }
};