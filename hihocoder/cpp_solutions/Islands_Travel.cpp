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
