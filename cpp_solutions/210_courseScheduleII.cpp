class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
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
            res.clear();
        }
        return res;
    }
};
