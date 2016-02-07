#include <stdio.h>
#include <iostream>
#include <string>
// #include <vector>
// #include <algorithm>
#include <set>
using namespace std;

int main()
{
    string str;
    cin >> str;

    set<string> list;

    for (int i = 0; i < str.length(); i++) {
        int cnt = 0;
        bool letter[26] = {false};
        // vector<bool> letter(26, false);

        for (int j = i; j < str.length(); j++) {
            if (letter[str[j]-'a'] == false) {
                cnt++;
                letter[str[j]-'a'] = true;
            }

            if (cnt <= 3 || cnt == 5 || cnt == 8 || cnt == 13 || cnt == 21) {
                string sub_str = str.substr(i, j - i + 1);
                list.insert(sub_str);
            }
        }
    }

    for (auto & sub_str : list) {
        // cout << sub_str << endl;
        printf("%s\n", sub_str.c_str()); // printf is much faster than cout, the same as cin
    }
    return 0;
}
