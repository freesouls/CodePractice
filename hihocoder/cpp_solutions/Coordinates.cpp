#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> get_divisors(int P) {
    vector<int> res;
    int upper = sqrt(P);
    for (int i = 1; i <= upper; i++) {
        if (P%i==0) {
            res.push_back(i);
            int remain = P/i;
            if (remain != i) {
                res.push_back(remain);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    int P, Q;
    scanf("%d%d", &P,&Q);
    vector<int> ps = get_divisors(P);
    vector<int> qs = get_divisors(Q);
    for (int i = 0; i < ps.size(); i++) {
        for (int j= 0; j < qs.size(); j++) {
            printf("%d %d\n", ps[i], qs[j]);
        }
    }
    return 0;
}
