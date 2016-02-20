#include <stdio.h>
// #include <iostream>
// #include <vector>
using namespace std;

#define MAX_SIZE 1002

int prefer[MAX_SIZE][MAX_SIZE];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j){
            int tmp;
            scanf("%d", &tmp);
            prefer[i][tmp] = j;
        }
    }

    int res = 0;
    int half = n/2;

    for (int i = k; i > 0; --i) {
        int vote = 0;

        for (int j = 0; j < n; ++j) {
            if (prefer[j][i] < prefer[j][res]) {
                ++vote;
            }
        }

        if (vote > half) {
            res = i;
        }
    }

    if (res) {
        printf("%d\n", res);
    }
    else {
        printf("otaku\n");
    }

    return 0;
}
