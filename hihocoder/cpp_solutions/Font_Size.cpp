//
//  main.cpp
//  hihocoder
//
//  Created by dirk on 1/26/16.
//  Copyright © 2016 dirk. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stdlib.h>
#include <math.h>
#include <unordered_map>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

// void read_from_file()
// {
// #define PC 1
// #ifdef PC
//     freopen("/Users/dirk/Documents/xcode/hihocoder/hihocoder/in.txt", "r", stdin);
// #endif
// }

int a[1001];

bool check(int N, int P, int W, int H, int fsize)
{
    int p = 0;
    int character_line = W/fsize;
    int lines = H/fsize;
    for (int i = 0; i < N; i++) {

        int tmp = a[i]%character_line;
        p += a[i]/character_line + (tmp > 0 ? 1: 0);
    }

    return P*lines >= p;
}

int font_size(int N, int P, int W, int H)
{
    int left = 1;
    int right = W;

    while(left + 1 < right) {
        int mid = (left + right) / 2;
        if (check(N, P, W, H, mid)) {
            left = mid;
        }
        else {
            right = mid - 1;
        }
    }

    if (check(N, P, W, H, right)) {
        return right;
    }
    return left;
}

int main()
{
    // read_from_file();
    int t;
    scanf("%d", &t);
    while (t > 0) {
        int N, P, W, H;
        scanf("%d%d%d%d", &N, &P, &W, &H);

        for (int i = 0; i < N; ++i) {
            scanf("%d", a + i);
        }

        printf("%d\n", font_size(N, P, W, H));

        t--;
    }
    return 0;
}
