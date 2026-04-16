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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
        return NULL;

        ListNode* temp=head;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
         if (n == count)
         {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
         }

        int pos=count-n;;
        ListNode* curr=head;
    
       for(int i=1;i<pos;i++)
       {
        curr=curr->next;
       }
       ListNode* remv=curr->next;
        curr->next=remv->next;
        delete remv;
        return head;
        
    }
};