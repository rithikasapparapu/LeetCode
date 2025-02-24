#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> parent(n, -1);
        queue<int> q;
        q.push(0);
        parent[0] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (parent[v] == -1) {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        vector<int> bob_path;
        int current = bob;
        while (current != 0) {
            bob_path.push_back(current);
            current = parent[current];
            if (current == -1) break;
        }
        bob_path.push_back(0);

        unordered_map<int, int> bob_time;
        for (int i = 0; i < bob_path.size(); ++i) {
            bob_time[bob_path[i]] = i;
        }

        int max_sum = INT_MIN;
        dfs(0, -1, 0, 0, bob_time, adj, amount, max_sum);

        return max_sum;
    }

private:
    void dfs(int u, int parent_u, int time_alice, int current_sum, unordered_map<int, int>& bob_time, vector<vector<int>>& adj, vector<int>& amount, int& max_sum) {
        int contribution = 0;
        if (bob_time.find(u) != bob_time.end()) {
            int time_bob = bob_time[u];
            if (time_alice < time_bob) {
                contribution = amount[u];
            } else if (time_alice == time_bob) {
                contribution = amount[u] / 2;
            } else {
                contribution = 0;
            }
        } else {
            contribution = amount[u];
        }

        current_sum += contribution;

        bool is_leaf = true;
        for (int v : adj[u]) {
            if (v != parent_u) {
                is_leaf = false;
                break;
            }
        }

        if (is_leaf) {
            max_sum = max(max_sum, current_sum);
            return;
        }
        
        for (int v : adj[u]) {
            if (v != parent_u) {
                dfs(v, u, time_alice + 1, current_sum, bob_time, adj, amount, max_sum);
            }
        }
    }
};
