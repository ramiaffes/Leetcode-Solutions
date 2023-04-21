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
 ListNode* reverseList(ListNode* head) {
        ListNode* res1= NULL;
        ListNode* res=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
        res1=new ListNode();
        res1->val=curr->val;
        res1->next=res;
        res=res1;
        curr=curr->next;}
    return res;
    }
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res1=l1;
        ListNode* res2=l2;
        ListNode* resf=NULL;
         ListNode* curr1=res1;
        ListNode* curr2=res2;
        int val2=0;
        ListNode* res3=NULL;
        while((curr1!=NULL)or(curr2!=NULL)){
            res3=new ListNode();
            res3->val+=val2;
            if(curr1!=NULL){
            res3->val+=curr1->val;
            curr1=curr1->next;}
            if(curr2!=NULL){
            res3->val+=curr2->val;
            curr2=curr2->next;}
            if(res3->val>=10){val2=1;res3->val=res3->val%10;}
            else val2=0;
            res3->next=resf;
            resf=res3;
        
        }
        if(val2==1){
             res3=new ListNode();
            res3->val+=val2;
             res3->next=resf;
            resf=res3;
        }
        
    return reverseList(resf);
    }
};