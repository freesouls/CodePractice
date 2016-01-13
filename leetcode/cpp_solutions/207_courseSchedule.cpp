class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
            indegree[prerequisites[i].first]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            vector<int>& pre = graph[cur];
            for(int i = 0; i < pre.size(); i++){
                indegree[pre[i]]--;
                if(indegree[pre[i]] == 0){
                    q.push(pre[i]);
                }
            }
            res.push_back(cur);
        }

        if (res.size() != numCourses){
            return false;
        }
        return true;
    }

    bool canFinish2(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i].first].push_back(prerequisites[i].second);
        }

        vector<bool> courses(numCourses, false);
        vector<bool> visited(numCourses, false);

        for(int i = 0; i < numCourses; i++){
            if(hasCycle(graph, courses, visited, i)){
                return false;
            }
        }
        return true;
    }

    bool hasCycle(vector<vector<int>>& graph, vector<bool>& courses, vector<bool>& visited, int co){
        if (visited[co]){ // check if revisited a node in the current path
            return true;
        }
        if(courses[co]){ // check courses[co] = true for details
            return false;
        }
        visited[co] = true;
        for(int i = 0; i < graph[co].size(); i++){
            if(hasCycle(graph, courses, visited, graph[co][i])){
                return true;
            }
        }

        visited[co] = false;
        courses[co] = true; // when a path contain this node, this path will not be a cycle, for prunning

        return false;
    }
};
