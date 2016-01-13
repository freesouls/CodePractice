class Solution {
public:
    string simplifyPath(string path) {
        vector<string> s;
        int i = 0;
        while (i < path.length()){
            int end = i;
            while(end < path.length() && path[end] != '/'){
                end++;
            }
            string tmp = path.substr(i, end - i);
            if (tmp != "."){
                if (tmp == ".."){
                    if (!s.empty()){
                        s.pop_back();
                    }
                }
                else if(tmp == ""){
                    if (s.empty()){
                        s.push_back(tmp);
                    }
                }
                else{
                    s.push_back(tmp);
                }
            }

            i = end + 1;
        }

        stringstream res;
        if (s.empty()){
            res << "/";
        }
        else{
            i = 0;
            if (s.size() > 1 && s[0] == ""){
                i = 1;
            }
            for (; i < s.size(); i++){
                res << "/"  << s[i];
            }
        }
        return res.str();
    }
};
