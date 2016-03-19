class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    //https://leetcode.com/discuss/82861/share-my-line-dfs-line-bfs-and-clean-union-find-java-solutions
    //https://leetcode.com/discuss/66984/simple-and-clean-c-solution-with-detailed-explanation
    /*
    To tell whether a graph is a valid tree, we have to:

    Make sure there is no cycle in the graph - this has to be a none-cyclic graph;
    Make sure every node is reached - this has to be a connected graph;
    Reference: https://en.wikipedia.org/wiki/Tree(graphtheory)

    Solution:

    To test cyclic, we can make an array for each node (as array index), and the array will store the parent of the node (as array index). Every time we fetch a new pair of nodes, we trace the root node (the deepest parent node) of these two nodes, if it has the same root, then is will be a cycle; otherwise, we set the parent of second node to be the first node;
    After we make sure there is node cycle in the graph, we simple test if there is enough edges to make this graph connected.
    */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        vector<int> nodes(n,0);
        for(int i=0; i<n; i++) nodes[i] = i;
        for(int i=0; i<edges.size(); i++){
            int f = edges[i][0];
            int s = edges[i][1];
            while(nodes[f]!=f) f = nodes[f];
            while(nodes[s]!=s) s = nodes[s];
            if(nodes[f] == nodes[s]) return false;
            nodes[s] = f;
        }
        return edges.size() == n-1;
    }
};
