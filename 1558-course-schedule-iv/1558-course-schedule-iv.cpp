class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjList(numCourses);
        for (auto& pre : prerequisites) {
            adjList[pre[0]].push_back(pre[1]);
        }

        vector<vector<bool>> isReachable(numCourses, vector<bool>(numCourses, false));

        for (int i = 0; i < numCourses; ++i) {
            vector<bool> visited(numCourses, false);
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int course = q.front();
                q.pop();
                for (int neighbor : adjList[course]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        isReachable[i][neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }

        vector<bool> result;
        for (auto& query : queries) {
            result.push_back(isReachable[query[0]][query[1]]);
        }

        return result;
    }
};