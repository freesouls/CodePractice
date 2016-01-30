// https://leetcode.com/discuss/71656/c-solution-o-n-time-o-n-space
// https://leetcode.com/discuss/72739/two-o-n-solutions
// 1108ms
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int> > graph(n, vector<int>());

        vector<int> out_degree(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            pair<int, int> &edge = edges[i];
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
            out_degree[edge.first]++;
            out_degree[edge.second]++;
        }

        vector<int> mins;
        int min_height = INT32_MAX;
        int count = n;

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (out_degree[i] <= 1) {
                q.push(i);
            }
        }

        while (count > 2) {
            int num = q.size();
            count -= num;

            for (int i = 0; i < num; i++) {
                int leaf = q.front();
                q.pop();
                for (int node : graph[leaf]) {
                    // the commented line can also be uncommented, but with lower running speed
                    // graph[node].erase(leaf);
                    if (--out_degree[node] == 1) {
                        q.push(node);
                    }
                }
                // graph[leaf].clear();
            }
        }

        while(!q.empty()) {
            mins.push_back(q.front());
            q.pop();
        }

        return mins;
    }
};

//1132ms
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<set<int> > graph(n, set<int>());

        // vector<int> outer_degree;
        for (int i = 0; i < edges.size(); i++) {
            pair<int, int> &edge = edges[i];
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }

        vector<int> mins;
        int min_height = INT32_MAX;
        int count = n;

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() <= 1) {
                q.push(i);
            }
        }

        while (count > 2) {
            int num = q.size();
            count -= num;

            for (int i = 0; i < num; i++) {
                int leaf = q.front();
                q.pop();
                for (int node : graph[leaf]) {
                    graph[node].erase(leaf);
                    if (graph[node].size() == 1) {
                        q.push(node);
                    }
                }
                graph[leaf].clear();
            }
        }

        while(!q.empty()) {
            mins.push_back(q.front());
            q.pop();
        }

        // sort(mins.begin(), mins.end());
        return mins;
    }
};

// TLE
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int> > graph(n, vector<int>());

        for (int i = 0; i < edges.size(); i++) {
            pair<int, int> &edge = edges[i];
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }

        vector<int> mins;
        int min_height = INT32_MAX;
        for(int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            int height = BFS(graph, visited, i);
            if (height < min_height) {
                min_height = height;
                mins.clear();
                mins.push_back(i);
            }
            else if (height == min_height) {
                mins.push_back(i);
            }
        }
        return mins;
    }

    int BFS(vector<vector<int> > &graph, vector<bool> &visited, int root) {
        int height = 0;
        visited[root] = true;
        vector<int> &nodes = graph[root];
        for (int i = 0; i < nodes.size(); i++) {
            if (!visited[nodes[i]]) {
                height = std::max(height, BFS(graph, visited, nodes[i]));
            }
        }
        return height + 1;
    }
};
