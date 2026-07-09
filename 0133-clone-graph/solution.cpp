/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*,Node*>& hash){
        if(hash.count(node))return hash[node];
        Node* clone=new Node(node->val);
        hash[node]=clone;
        for(Node* i:node->neighbors)clone->neighbors.push_back(dfs(i,hash));
        return clone;
    }

    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        unordered_map<Node*,Node*> hash;
        return dfs(node,hash);
    }
};
