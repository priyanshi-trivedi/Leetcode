class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
    
    // Generate each row
    for (int i = 0; i < numRows; i++) {
        vector<int> row(i + 1, 1); // Create a row with 'i+1' elements initialized to 1
        
        // Fill the middle values (not the first or last element)
        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        
        // Add the row to the triangle
        triangle.push_back(row);
    }
    
    return triangle;
    }
};