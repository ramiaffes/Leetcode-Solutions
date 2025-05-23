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
map<int, int>tin;
map< int, int>tout;
map<int,TreeNode*>hashing;
vector<int>res;
set<int>res1;
int timer=0;
int ans=0;
void dfs( TreeNode* u,int som){
    if(u==NULL)return;
    if((u->left==NULL)and(u->right==NULL)){if(som>ans){res1.clear();ans=som;res1.insert(u->val);}
                                          else if(som==ans) res1.insert(u->val);}
    hashing[u->val]=u;
    res.push_back(u->val);
	tin[u->val]=timer++;
    dfs(u->left,som+1);
    dfs(u->right,som+1);
		tout[u->val]=timer++;}
bool isancestor( int u, int v){
	return (tin[u]<=tin[v]) and (tout[u]>=tout[v]);}
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
         int val=0;
        ans=0;
        res.clear();
        tin.clear();
        tout.clear();
        res1.clear();
        hashing.clear();
        timer=0;
        dfs(root,0);
        for(int i=0;i<res.size();i++){
            bool test=true;
            for(auto v:res1){
            if(not(isancestor(res[i],v))){
                test=false;break;
            }
            }if(test==true)val=res[i];
        }
    return hashing[val];
    }
};