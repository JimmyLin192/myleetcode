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
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> cmap;
        UndirectedGraphNode* cloned = cloneGraphHelper(node, cmap);
        return cloned;
    }
    UndirectedGraphNode* cloneGraphHelper(UndirectedGraphNode *node, 
                                          unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& cmap) {
        if (!node) {
            return NULL;
        } 
        if (cmap.count(node)) {
            return cmap[node];
        }
        UndirectedGraphNode* cloned = new UndirectedGraphNode (node->label);
        cmap[node] = cloned;
        for (UndirectedGraphNode* next : node->neighbors) {
            cloned->neighbors.push_back(cloneGraphHelper(next, cmap));
        }
        return cloned;
    }
};
