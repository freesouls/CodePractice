#include <set>
#include <queue>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stdio.h>
#include <map>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N, M;
        scanf("%d%d", &N, &M);
        // some cases can not be passed, when using vector<set<int>>
        // while the logic is almost identity to the above two versions
        vector<set<int> > edges(N+1, set<int>());
        vector<int> indegree(N+1, 0);
        for (int j = 1; j <= M; j++) {

            int u, v;
            scanf("%d%d", &u, &v);

            edges[u].insert(v);
            indegree[v]++;
        }

        queue<int> q;

        for (int j = 1; j <= N; j++) {
            if (indegree[j] == 0) {
                q.push(j);
            }
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            N--;
            for (int v : edges[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (N != 0) {
            printf("Wrong\n");
        }
        else{
            printf("Correct\n");
        }

    }
}


#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include <ctime>
#include <cfloat>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>

using namespace std;

const int N = 1e5 + 1;
const int E = 5e5 + 1;

int c;
int v[E];
int next_index[E];

int deg[N];
int entry[N];

int Q[N];
int head, tail;

void read_int(int &n)
{
    int c;
    while (isspace(c = getchar()));
    n = c - '0';
    while (isdigit(c = getchar()))
        n = n * 10 + c - '0';
}

int main()
{
#ifdef PC
    freopen("in.txt", "r", stdin);
#endif

    int t;

    for (read_int(t); t--; )
    {
        int n, m, p, q;

        read_int(n);
        read_int(m);

        c = 0;
        memset(deg, 0, (n + 1) * sizeof (int));
        memset(entry, -1, (n + 1) * sizeof (int));

        while (m--)
        {
            read_int(p);
            read_int(q);

            deg[q]++;
            v[c] = q;
            next_index[c] = entry[p];
            entry[p] = c++;
        }

        head = tail = 0;

        for (int i = 1; i <= n; i++)
            if (deg[i] == 0)
                Q[tail++] = i;

        while (head != tail)
        {
            p = Q[head++];
            n--;

            for (q = entry[p]; q != -1; q = next_index[q])
            {
                if (--deg[v[q]] == 0)
                    Q[tail++] = v[q];
            }
        }

        if (n == 0)
            puts("Correct");
        else
            puts("Wrong");
    }

    return 0;
}


#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct EDGE{
	int to;
	struct EDGE *next;
}e[500010];
struct EDGE* p[100010];
int size,n,m,d[100010];
queue<int> h;
void addedge(int a,int b)
{
	e[size].next=p[a];e[size].to=b;
	d[b]++;p[a]=&e[size];
	size++;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int i;
		scanf("%d%d",&n,&m);size=0;
		for(i=1;i<=n;i++) {p[i]=NULL;d[i]=0;}
		while(!h.empty()) h.pop();
		for(i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			addedge(a,b);
		}

		for(i=1;i<=n;i++) if(!d[i])
			h.push(i);
		while(!h.empty()){
			struct EDGE* u=p[h.front()];h.pop();
			for(;u;u=u->next){
				int v=u->to;
				d[v]--;
				if(!d[v]) h.push(v);
			}
		}
		bool flag=true;
		for(i=1;i<=n;i++) if(d[i]){
			flag=false;break;
		}
		printf("%s\n",flag?"Correct":"Wrong");
	}
	return 0;
}
