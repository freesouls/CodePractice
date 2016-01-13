class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> arr;

        //将num转成string存入数组
        for(int i : num)
            arr.push_back(to_string(i));
            
        //比较排序
        sort(arr.begin(), arr.end(), compare);

        //连接成字符串
        string ret;
        for(string s : arr)
            ret += s;

        //排除特殊情况
        if(ret[0] == '0' && ret.size() > 0)
            return "0";

        return ret;
    }

private:
    //自定义比较函数
    static bool compare(string &s1, string &s2)
    {
        return s1 + s2 > s2 + s1;
    }
};
