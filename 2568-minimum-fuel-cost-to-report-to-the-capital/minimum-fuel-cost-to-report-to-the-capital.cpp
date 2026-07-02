class Solution {
public:
    vector<vector<int>> adj;
    long long fuel = 0;

    long long dfs(int node, int parent, int seats) {
        long long people = 1;

        for (int child : adj[node]) {
            if (child == parent)
                continue;

            people += dfs(child, node, seats);
        }

        if (node != 0) {
            fuel += (people + seats - 1) / seats; // ceil(people / seats)
        }

        return people;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        adj.resize(n);

        for (auto &e : roads) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, seats);

        return fuel;
    }
};