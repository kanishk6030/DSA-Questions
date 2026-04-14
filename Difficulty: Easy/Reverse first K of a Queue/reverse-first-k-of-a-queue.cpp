class Solution {
public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        
        // Edge case handling
        if (k > q.size() || k <= 0) {
            return q;
        }

        stack<int> s;

        // Step 1: Push first k elements into stack
        for (int i = 0; i < k; i++) {
            s.push(q.front());
            q.pop();
        }

        // Step 2: Push stack elements back into queue
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        // Step 3: Move remaining (n-k) elements to back
        int t = q.size() - k;

        while (t--) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};