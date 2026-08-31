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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int index=2;
        int count=0;
        int firstcritical;
        int lastcritical;
        int mindistance=INT_MAX;
        int maxdistance;

        ListNode* prev=head;
        ListNode* curr=head-> next;
        ListNode* after=curr-> next;
        while(after!=NULL)
        {
            if((curr->val>prev->val && curr->val>after->val)||
            (curr->val<prev->val && curr->val<after->val))
            {
                if(count>0)
                {
                   mindistance = min(mindistance, index - lastcritical);
                    lastcritical = index;
                    count++;
                }
                else
                {
                firstcritical=index;
                lastcritical=index;
                     count++;

                }
               
            }
            prev=prev->next;
            curr=curr->next;
            after=after->next;
            index++;
        }
        maxdistance=lastcritical-firstcritical;
        if(count>=2)
        return {mindistance,maxdistance};
        else 
        return {-1,-1};


        
    }
};