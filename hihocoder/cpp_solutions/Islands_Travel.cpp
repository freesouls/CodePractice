#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 200000;//数组要开大些，防止越界
int n , dis[maxn] , isQueue[maxn];
vector < pair < int , int > > graph[maxn];//注意后面两个尖括号之前有空格！

class nodd
{
public:
    int x , y , num;
    //重载"<"符号
    bool operator < (const nodd  A) const {
        return x < A.x;
    }
} A[maxn];

void build()
{
    sort( A , A + n );
    for ( int i = 0; i < n; i ++ ) {
        int nex = i + 1;
        while ( nex < n && A[nex].x == A[i].x ) { //当两个点的x值相等时
            int a = A[nex].num , b = A[i].num; //排序后点的序号改变，不能直接用i表示，建立新的变量获取该点原来的序号
            graph[a].push_back( make_pair( b , 0 ) );//建立一条从a到b的边，距离为0
            graph[b].push_back( make_pair( a , 0 ) );//因为是无向图，同样建立一条从b到a的边，距离为0
            nex ++; //把所有x相等的点连起来
        }
        if ( i > 0 ) {
            int a = A[i].num , b = A[i-1].num;
            graph[a].push_back( make_pair( b , A[i].x - A[i-1].x ) );
            graph[b].push_back( make_pair( a , A[i].x - A[i-1].x ) );
        }
        i = nex - 1; //因为while中进行nex++操作，所以i要从最后一个x与前面一个点x值相同的点开始
    }
}

int main()
{
    scanf("%d",&n);
    for ( int i = 0; i < n; i ++ ) {
        scanf("%d%d",&A[i].x,&A[i].y);
        A[i].num = i;
    }
    build(); //将x之间的差作为距离
    for ( int i = 0; i < n; i ++ )
        swap( A[i].x , A[i].y );
    build(); //将y之间的差作为距离

    queue < int > q;
    for ( int i = 0; i < n; i ++ )
        dis[i] = 2000000000;
    dis[0] = 0;
    q.push( 0 ); //第一个点入队
    isQueue[0] = 1;
    while ( !q.empty() ) {
        int now = q.front() , nex;
        q.pop(); //当前点出队
        isQueue[now] = 0;
        for ( int i = graph[now].size()-1; i >= 0; i -- ) { //遍历跟当前点有边的所有点
            nex = graph[now][i].first; //获得与当前点相连的点的编号
            if ( dis[now] + graph[now][i].second < dis[nex] ) { //当前点到起点的距离+当前点到下一个点的距离<下一个点到起点的距离
                dis[nex] = dis[now] + graph[now][i].second;
                if ( isQueue[nex] == 0 ) { //如果下一个点不在队列中，入队；否则让它留在队中供其他点做判断
                    isQueue[nex] = 1 ;
                    q.push( nex );
                }
            }
        }
    }
    cout << dis[n-1] << endl;
    return 0;
}


#include <set>
#include <unordered_set>
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
#include <cstdint> //or <stdint.h>
#include <limits>
using namespace std;

// TLE version
class Node {
public:
    int x;
    int y;
    int id;
    int dist;
    int known;
    unordered_map<int, int> adj;

    Node(int xx, int yy, int iid): x(xx), y(yy), id(iid), dist(INT32_MAX), known(false) {}

};


bool compare_x(Node* n1, Node* n2) {
    return n1->x < n2->x;
}
bool compare_y(Node* n1, Node* n2) {
    return n1->y < n2->y;
}


int main()
{
    int n;
    // cin >> n;
    scanf("%d", &n);

    vector<Node*> nodes(n, NULL);
    vector<Node*> nodes_x(n, NULL);
    vector<Node*> nodes_y(n, NULL);

    for (int i = 0; i < n; i++) {
        int x, y;
        // cin >> x >> y;
        scanf("%d%d", &x, &y);
        nodes[i] = new Node(x, y, i);
        nodes_x[i] = nodes[i];
        nodes_y[i] = nodes[i];
    }

    std::sort(nodes_x.begin(), nodes_x.end(), compare_x);
    for(int i = 0; i < n; i++) {
        int j = i + 1;
        while(j < n && nodes_x[i]->x == nodes_x[j]->x) {
            nodes_x[i]->adj[nodes_x[j]->id] = 0;
            nodes_x[j]->adj[nodes_x[i]->id] = 0;
            j++;
        }
        i = j;
    }

    for(int i = 0; i < n; i++) {
        int j = i + 1;
        while(j < n && nodes_x[i]->x == nodes_x[j]->x) {
            j++;
        }

        if (j < n) {
            int tmp = abs(nodes_x[i]->x - nodes_x[j]->x);
            // if (nodes_x[i]->adj.find(nodes_x[j]->id) != nodes_x[i]->adj.end()) {
                // nodes_x[i]->adj[nodes_x[j]->id] = std::min(tmp, nodes_x[i]->adj[nodes_x[j]->id]);
            // }
            // else {
                nodes_x[i]->adj[nodes_x[j]->id] = tmp;
            // }
            // if (nodes_x[j]->adj.find(nodes_x[i]->id) != nodes_x[j]->adj.end()) {
                // nodes_x[j]->adj[nodes_x[i]->id] = std::min(tmp, nodes_x[j]->adj[nodes_x[i]->id]);
            // }
            // else {
                nodes_x[j]->adj[nodes_x[i]->id] = tmp;
            // }
        }
    }

    std::sort(nodes_y.begin(), nodes_y.end(), compare_y);
    for(int i = 0; i < n; i++) {
        int j = i + 1;
        while(j < n && nodes_y[i]->y == nodes_y[j]->y) {
            nodes_y[i]->adj[nodes_y[j]->id] = 0;
            nodes_y[j]->adj[nodes_y[i]->id] = 0;
            j++;
        }
        i = j;
    }

    for(int i = 0; i < n; i++) {
        int j = i + 1;
        while(j < n && nodes_y[i]->y == nodes_y[j]->y) {
            j++;
        }
        if (j < n) {
            int tmp = std::min(abs(nodes_y[i]->y - nodes_y[j]->y), abs(nodes_y[i]->x - nodes_y[j]->x));
            // if (nodes_y[i]->adj.find(nodes_y[j]->id) != nodes_y[i]->adj.end()) {
                // nodes_y[i]->adj[nodes_y[j]->id] = std::min(tmp, nodes_y[i]->adj[nodes_y[j]->id]);
            // }
            // else {
                nodes_y[i]->adj[nodes_y[j]->id] = tmp;
            // }
            // if (nodes_y[j]->adj.find(nodes_y[i]->id) != nodes_y[j]->adj.end()) {
                // nodes_y[j]->adj[nodes_y[i]->id] = std::min(tmp, nodes_y[j]->adj[nodes_y[i]->id]);
            // }
            // else {
                nodes_y[j]->adj[nodes_y[i]->id] = tmp;
            // }
        }
    }

    nodes[0]->dist = 0;

    int V = -1, W = -1;
    unordered_set<int> unknown_vertex;
    unknown_vertex.insert(0);

    for (; ;) {
        V = -1;
        if (!unknown_vertex.empty()){
            for (int index : unknown_vertex) {
                if (V == -1) {
                    V = index;
                }
                else if (nodes[index]->dist < nodes[V]->dist) {
                    V = index;
                }
            }
            unknown_vertex.erase(V);
        }
        else {
            break;
        }

        nodes[V]->known = true;
        for (auto it : nodes[V]->adj ) {
            W = it.first;
            if (!nodes[W]->known) {
                if (nodes[V]->dist + nodes[V]->adj[W] < nodes[W]->dist) {
                    nodes[W]->dist = nodes[V]->dist + nodes[V]->adj[W];
                    unknown_vertex.insert(W);
                }
            }
        }
        if (V == n-1) {
            break;
        }
    }

    std::cout << nodes[n-1]->dist << std::endl;
    return 0;
}
