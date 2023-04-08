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
map<int,bool>vis;
map<int,vector<int>>adj;
map<int,bool>vis1;
map<int,Node*>hashing;
void remplir(Node* node){
    if(node==NULL)return;
    if(vis[node->val]==1)return;
    vis[node->val]=1;
    for(int i=0;i<(node->neighbors.size());i++){
        adj[node->val].push_back(node->neighbors[i]->val);
            remplir((node->neighbors)[i]);
        
    }
}
  Node* resultat(int val,map<int,vector<int>>adj){
      Node* nd=new Node();
      nd->val=val;
      vis1[val]=1;hashing[val]=nd;
      vector<Node*>neighbors;
      for(auto v:adj[val]){
          
          if(vis1[v]){ neighbors.push_back(hashing[v]);continue;}
          neighbors.push_back(resultat(v,adj));
          
          
      }
      nd->neighbors=neighbors;
      
      return nd;
    
}
class Solution {
public:
    Node* cloneGraph(Node* node) { if(node==NULL)return NULL;
        vis.clear();
        adj.clear();
        vis1.clear();
        hashing.clear();
        remplir(node);
       
   return resultat(1,adj);
    
        
        
    }
};