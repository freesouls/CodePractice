class Solution {
    int n;
    vector<string> res;
//    vector<string> strs;
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        res.clear();
        n = tickets.size();
        unordered_map<string, map<string, int> > from_tos;

        for (pair<string, string> &p : tickets) {
            from_tos[p.first][p.second]++;
            // if (from_tos.find(p.first) != from_tos.end()) {
            //     unordered_map<string, int> &tos = from_tos[p.first];
            //     if (tos.find(p.second) != tos.end()) {
            //         tos[p.second]++;
            //     }
            //     else {
            //         tos[p.second] = 1;
            //     }
            // }
            // else {
            //     unordered_map<string, int> a;
            //     a[p.second] = 1;
            //     from_tos[p.first] = a;
            // }
        }

        vector<string> path;
        path.push_back("JFK");
        dfs(from_tos, path);

        return res;
    }

    bool dfs(unordered_map<string, map<string, int> > &from_tos, vector<string> &path) {
        if (path.size() == n+1) {
            res = path;
            return true;
        }

        // string from = path.substr(path.length() - 3, 3);
        string &prev = path[path.size() - 1];
        if (from_tos.find(prev) == from_tos.end()) {
            return false;
        }

        // unordered_map<string, int> &tos = from_tos[prev];
        for (auto &it: from_tos[prev]) {
            if (it.second > 0) {
                it.second--;
                path.push_back(it.first);
                if (dfs(from_tos, path) == true) {
                    return true;
                }
                it.second++;
                path.pop_back();
            }
        }
        return false;
    }
};

// iterative one
// https://leetcode.com/discuss/84774/c-iterative-versions

// interesting post
// https://leetcode.com/discuss/84659/short-ruby-python-java-c

class Solution {

public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (auto ticket : tickets)
            targets[ticket.first].insert(ticket.second);
        visit("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }

    map<string, multiset<string>> targets;
    vector<string> route;

    void visit(string airport) {
        while (targets[airport].size()) {
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next);
        }
        route.push_back(airport);
    }


};
