// Given a non-negative integer S represented as a string, 
// remove K digits from the number so that the new number is the smallest possible.
// Note : The given num does not contain any leading zero.

class Solution{
    public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> mystack;
        // Store the final string in stack
        for (char c : num) {
            while (!mystack.empty() && k > 0 && mystack.top() > c) {
                mystack.pop();
                k -= 1;
            }
    
            if (!mystack.empty() || c != '0')
                mystack.push(c);
        }
    
        // Now remove the largest values from the top of the
        // stack
        while (!mystack.empty() && k--)
            mystack.pop();
        if (mystack.empty())
            return "0";
    
        // Now retrieve the number from stack into a string
        // (reusing num)
        while (!mystack.empty()) {
            num[n - 1] = mystack.top();
            mystack.pop();
            n -= 1;
        }
        return num.substr(n);
    }
};