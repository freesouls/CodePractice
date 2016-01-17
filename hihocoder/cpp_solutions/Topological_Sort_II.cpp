#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stdio.h>

using namespace std;
// https://www.wikiwand.com/en/Topological_sorting
int main()
{
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);

    vector<int> counts(N, 0);

    for (int i = 0; i < K; i++) {
        int tmp;
        scanf("%d", &tmp);
        counts[tmp - 1] = 1;
    }
    vector<set<int> > edges(N, set<int>());

    vector<int> indegree(N, 0);
    // vector<int> outdegree(N, 0);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        edges[u-1].insert(v-1);
        indegree[v-1]++;
        // outdegree[u-1]++; //it is better not use outdegree generally
    }
    queue<int> q;
    for (int i = 0; i < N; i++) {
        // if (indegree[i] == 0 && outdegree[i] > 0) {
        //     q.push(i);
        // }
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        set<int> &vs = edges[u];
        for (int v : vs) {
            counts[v] += (counts[u]%142857);
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    long res = 0;
    for (int i : counts) {
        res += (i%142857);
    }

    printf("%d\n", int(res%142857));
}
