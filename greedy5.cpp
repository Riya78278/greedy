// Reverse Words

#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string &s) {
        stack<string> st;
        string ans = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] != '.') {
                ans = ans + s[i];
            } else {
                // on dot: push only if we have a non-empty word
                if (!ans.empty()) {
                    st.push(ans);
                    ans.clear();
                }
                // otherwise it's a leading/extra dot -> skip
            }
        }

        // push the last collected word (if any)
        if (!ans.empty()) st.push(ans);

        // build reversed string from stack (no extra leading/trailing dots)
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
            if (!st.empty()) result += ".";
        }

        return result;
    }
};
