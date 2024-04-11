class Solution {
public:
    string removeKdigits(string num, int k) {
        // Stack bana lo store krne ke liye
        stack<char> numStack;
        
        // har num pe loop chalao
        for (char digit : num) {
            // agar k bacha hua hai aur stack khali nhi hua hai to current digit hai oo stack ke top digit se chota hai 
            while (k > 0 && !numStack.empty() && digit < numStack.top()) {
                // stack se romove kr do
                numStack.pop();
                k--;
            }
            // current digit ko la lo  stack me
            numStack.push(digit);
        }
        
             // agar loop ke baad koe aur remove krne ke liye bacha hai to remove kr do stack se
        while (k > 0 && !numStack.empty()) {
            numStack.pop();
            k--;
        }

              // string bana lo stack se digit ko pop krne ke liye
        string temp = "";
        while (!numStack.empty()) {
            temp.push_back(numStack.top());
            numStack.pop();
        }
             // string ko revesre kr do correct order ke liye
        reverse(temp.begin(), temp.end());

        // zero remove krne ke liye 
        int m = temp.size();
        string result = "";
        int foundNonZero = 0;
        for (int i = 0; i < m; i++) {
            if (temp[i] == '0' && foundNonZero == 0) {
                continue;
            } else {
                result.push_back(temp[i]);
                foundNonZero = 1;
            }
        }
        // agar stack khali hai to, return "0"
        if (result.size() == 0)
            result.push_back('0');
        return result;
    }
};
