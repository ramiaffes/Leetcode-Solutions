/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* curr=head;
        int som=0;
        while(curr!=NULL){
            som++;
            curr=curr->next;
        }
        int p=1;
        for(int i=0;i<(som-1);i++){
            p*=2;
        }
    curr=head;
    int res=0;
     while(curr!=NULL){
         if(curr->val==1)
            res+=p;
            curr=curr->next;
         p/=2;
        }
    return res;
    }
};