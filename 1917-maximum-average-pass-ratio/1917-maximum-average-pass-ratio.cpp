class Solution {
public:
    // Function to calculate the gain in pass ratio by adding one student
double calculateGain(int passi, int totali) {
    return ((double)(passi + 1) / (totali + 1)) - ((double)passi / totali);
}
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Max-heap to store classes based on the potential gain in pass ratio
    priority_queue<pair<double, pair<int, int>>> maxHeap;

    // Initialize the heap with all classes
    for (const auto& c : classes) {
        double gain = calculateGain(c[0], c[1]);
        maxHeap.push({gain, {c[0], c[1]}});
    }

    // Assign extra students
    while (extraStudents > 0) {
        auto [gain, classInfo] = maxHeap.top();
        maxHeap.pop();

        int passi = classInfo.first;
        int totali = classInfo.second;

        // Add one extra student to the class
        passi++;
        totali++;

        // Recalculate the gain and push back into the heap
        maxHeap.push({calculateGain(passi, totali), {passi, totali}});
        extraStudents--;
    }

    // Calculate the final average pass ratio
    double totalPassRatio = 0.0;
    while (!maxHeap.empty()) {
        auto [gain, classInfo] = maxHeap.top();
        maxHeap.pop();

        int passi = classInfo.first;
        int totali = classInfo.second;
        totalPassRatio += (double)passi / totali;
    }

    return totalPassRatio / classes.size();
        
    }
};