/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     void construct(TreeNode * root,map<int,vector<int>>adj,int u){
        root->val=u;
        if(adj[u].empty())return ;
        root->left=new TreeNode();
        construct(root->left,adj,adj[u][0]);
        if(adj[u].size()>=2){root->right=new TreeNode();
        construct(root->right,adj,adj[u][1]);}
     }
     void tokenize(string const &str, const char delim,
            vector<int> &out)
{
    size_t start;
    size_t end = 0;
 
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(stoi(str.substr(start, end - start)));
    }
}
    TreeNode* recoverFromPreorder(string traversal) {
        map<int,vector<int>>adj;
        map<int,int>hashing;
        vector<int>out;
        tokenize(traversal,'-',out);
        vector<int>res;
        int val=0;
        for(int i=0;i<traversal.length();i++){
            if(isdigit(traversal[i])){if(val!=0)res.push_back(val);val=0;}
            else{
                val++;
            }
        }
        if(val!=0)res.push_back(val);
        hashing[0]=out[0];
        for(int i=1;i<out.size();i++){
            adj[hashing[res[i-1]-1]].push_back(out[i]);
            hashing[res[i-1]]=out[i];
        }
       TreeNode * root=new TreeNode();
        construct(root,adj,out[0]);
        return root;
    }
};