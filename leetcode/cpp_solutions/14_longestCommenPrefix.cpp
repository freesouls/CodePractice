class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0){
            return "";
        }
        bool flag = true;
        int j = 0;
        while(flag){
            if(strs[0].length()<=j){
                return strs[0].substr(0,j);
            }
            else{
                char current = strs[0][j];
                for(int i=1; i < strs.size(); i++){
                    if(strs[i].length()<=j){
                        return strs[0].substr(0,j);
                    }
                    if(strs[i][j]==current){
                        continue;
                    }else{
                        return strs[0].substr(0,j);
                    }
                }
                j++;
            }
        }
    }
};