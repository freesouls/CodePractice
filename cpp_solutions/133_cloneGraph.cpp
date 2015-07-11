/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        typedef unordered_map<int, UndirectedGraphNode *> Map;
        if(node == NULL)return NULL;
        Map gmap;//保存克隆图的节点的地址,顺便作为节点是否访问的标记
        stack<UndirectedGraphNode *>gstack;
        UndirectedGraphNode *res = new UndirectedGraphNode(node->label);
        gmap.insert(Map::value_type(res->label, res));
        gstack.push(node);
        while(gstack.empty() == false)
        {
            UndirectedGraphNode *p = gstack.top(), *newp;
            gstack.pop();
            if(gmap.find(p->label) != gmap.end())//查找克隆图节点是否已经构造
                newp = gmap[p->label];
            else
            {
                newp = new UndirectedGraphNode(p->label);
                gmap.insert(Map::value_type(p->label, newp));
            }
            for(int i = 0; i < p->neighbors.size(); i++)
            {
                UndirectedGraphNode *tmp = p->neighbors[i];
                if(gmap.find(tmp->label) == gmap.end())
                {
                    gmap.insert(Map::value_type(tmp->label,
                                    new UndirectedGraphNode(tmp->label)));
                    gstack.push(tmp);
                }
                //设置克隆图节点的邻接点
                newp->neighbors.push_back(gmap[tmp->label]);
            }
        }
        return res;
    }
};
