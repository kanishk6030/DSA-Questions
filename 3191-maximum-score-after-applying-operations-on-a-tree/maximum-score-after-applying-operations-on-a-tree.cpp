class Solution {
public:
    vector<vector<int>> adj;

    long long dfs(int node, int parent, vector<int>& values) {
        // Leaf node (except root)
        if (node != 0 && adj[node].size() == 1)
            return values[node];

        long long childSum = 0;

        for (int child : adj[node]) {
            if (child == parent)
                continue;

            childSum += dfs(child, node, values);
        }

        return min((long long)values[node], childSum);
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        adj.resize(n);

        long long total = 0;

        for (int v : values)
            total += v;

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        return total - dfs(0, -1, values);
    }
};