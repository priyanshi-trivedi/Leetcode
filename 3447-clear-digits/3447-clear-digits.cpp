class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
    
    for (char c : s) {
        if (isdigit(c)) {
            // Remove the closest non-digit character to its left
            if (!st.empty() && isalpha(st.top())) {
                st.pop();
            }
        } else {
            st.push(c);
        }
    }
    
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    
    return result;
    }
};