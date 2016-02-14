#include <iostream>
#include <string>
using namespace std;

bool trans[10][10] = {
    {true,  false, false, false, false, false, false, false, false, false}, //0
    {true,  true,  true,  true,  true,  true,  true,  true,  true,  true }, //1
    {true,  false, true,  true,  false, true,  true,  false, true,  true }, //2
    {false, false, false, true,  false, false, true,  false, false, true }, //3
    {true,  false, false, false, true,  true,  true,  true,  true,  true }, //4
    {true,  false, false, false, false, true,  true,  false, true,  true }, //5
    {false, false, false, false, false, false, true,  false, false, true }, //6
    {true,  false, false, false, false, false, false, true,  true,  true }, //7
    {true,  false, false, false, false, false, false, false, true,  true }, //8
    {false, false, false, false, false, false, false, false, false, true }, //9
};

bool dfs(string& K, string& res, int depth, bool flag, int last)
{
    if (depth == K.length()) {
        return true;
    }

    if (flag) {
        int sub = K.length() - res.length();
        char ch = '9';
        if (res[depth] == '0') {
            ch = '0';
        }

        for (int i = 0; i < sub; i++) {
            res.push_back(ch);
        }

        return true;
    }

    for (int i = 9; i >=0 ; --i) {
        if (trans[last][i] && i <= K[depth] - '0') {
            res.push_back(('0' + i));

            if (dfs(K, res, depth + 1, res[depth] < K[depth], i)) {
                return true;
            }
            else {
                res.pop_back();
            }
        }
    }
    return false;
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string K;
        cin >> K;
        string res = "";
        dfs(K, res, 0, false, 1);
        cout << res << endl;
    }
}
