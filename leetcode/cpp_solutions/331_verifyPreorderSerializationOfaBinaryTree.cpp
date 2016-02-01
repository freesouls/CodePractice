class Solution {
public:

    vector<string> split(string str) {
        vector<string> res;

        for (int i = 0; i < str.length(); i++) {
            int j = i;
            if (str[j] == '#'){
                res.push_back("#");
                i = ++j;
            }
            else{
                while(str[j] != ',') {
                    j++;
                }
                res.push_back(str.substr(i, j - i));
                i = j;
            }
        }
        return res;
    }


    bool isValidSerialization(string preorder) {
        queue<string> q;
        vector<string> nodes = split(preorder);
        if (nodes.size() == 0) {
            return false;
        }
        q.push(nodes[0]);
        int index = 1;
        int n = nodes.size();
        while(!q.empty()) {
            string node = q.front();
            q.pop();
            if (node != "#") {
                if (index + 1 >= n) {
                    return false;
                }
                else {
                    q.push(nodes[index++]);
                    q.push(nodes[index++]);
                }
            }
        }

        if (index < n) {
            return false;
        }
        return true;
    }
};
