class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size(), maxCycleLength = 0, combinedCycleInvitations = 0;
        vector<int> incomingEdges(n, 0), distance(n, 1);

        for (int i = 0; i < n; ++i)
            incomingEdges[favorite[i]]++;

        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (incomingEdges[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            int next = favorite[current];
            distance[next] = max(distance[next], distance[current] + 1);
            if (--incomingEdges[next] == 0)
                q.push(next);
        }

        for (int i = 0; i < n; ++i) {
            if (incomingEdges[i] == 0) continue;
            int cycleLength = 0, current = i;
            while (incomingEdges[current] != 0) {
                incomingEdges[current] = 0;
                cycleLength++;
                current = favorite[current];
            }
            if (cycleLength == 2)
                combinedCycleInvitations += distance[i] + distance[favorite[i]];
            else
                maxCycleLength = max(maxCycleLength, cycleLength);
        }

        return max(maxCycleLength, combinedCycleInvitations);
    }
};
