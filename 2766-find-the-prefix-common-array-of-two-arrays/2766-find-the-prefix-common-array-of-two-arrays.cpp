class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
    unordered_set<int> seenA, seenB; // Sets to track seen elements
    vector<int> result(n);
    int commonCount = 0;

    for (int i = 0; i < n; ++i) {
        // Check and update for A[i]
        if (seenB.find(A[i]) != seenB.end()) {
            ++commonCount; // A[i] is already in seenB, so it is common
        }
        seenA.insert(A[i]); // Mark A[i] as seen in A

        // Check and update for B[i]
        if (seenA.find(B[i]) != seenA.end() && seenB.find(B[i]) == seenB.end()) {
            ++commonCount; // B[i] is common and hasn't been double-counted
        }
        seenB.insert(B[i]); // Mark B[i] as seen in B

        // Update the result for index i
        result[i] = commonCount;
    }

    return result;
        
    }
};