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
int res=0;
void dfs( TreeNode* u,int val1,int val2,int val3,int val4,int val5,int val6,int val7,int val8,int val9,long long int som){
    
    if(u==NULL)return;  
    if(u->val==9){val9++;if(val9%2==0){som-=9*1e9;}else{som+=9*1e9;}}
    if(u->val==8){val8++;if(val8%2==0){som-=8*1e8;}else{som+=8*1e8;}}
    if(u->val==7){val7++;if(val7%2==0){som-=7*1e7;}else{som+=7*1e7;}}
    if(u->val==6){val6++;if(val6%2==0){som-=6*1e6;}else{som+=6*1e6;}}
    if(u->val==5){val5++;if(val5%2==0){som-=5*1e5;}else{som+=5*1e5;}}
    if(u->val==4){val4++;if(val4%2==0){som-=4*1e4;}else{som+=4*1e4;}}
    if(u->val==3){val3++;if(val3%2==0){som-=3*1e3;}else{som+=3*1e3;}}
    if(u->val==2){val2++;if(val2%2==0){som-=2*1e2;}else{som+=2*1e2;}}
    if(u->val==1){val1++;if(val1%2==0){som-=1*10;}else{som+=1*10;}}
    if((u->left==NULL)and(u->right==NULL)){
    if (((som % 10 == 0) or (som % 10 == som)) and
    ((som % 100 == 0) or (som % 100 == som)) and
    ((som % 1000 == 0) or (som % 1000 == som)) and
    ((som % 10000 == 0) or (som % 10000 == som)) and
    ((som % 100000 == 0) or (som % 100000 == som)) and
    ((som % 1000000 == 0) or (som % 1000000 == som)) and
    ((som % 10000000 == 0) or (som % 10000000 == som)) and
    ((som % 100000000 == 0) or (som % 100000000 == som)) and
    ((som % 1000000000== 0) or (som % 1000000000 == som))) {
    res += 1;
}}
    dfs(u->left,val1,val2,val3,val4,val5,val6,val7,val8,val9,som);
    dfs(u->right,val1,val2,val3,val4,val5,val6,val7,val8,val9,som);
 
   
		}
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
     res=0;
    dfs(root,0,0,0,0,0,0,0,0,0,0);
    
    return res;
    }
};