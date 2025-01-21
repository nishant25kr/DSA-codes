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
    ListNode* deleteMiddle(ListNode* head) {
        // if(head == NULL) return 0;
        
        int count=0;
        ListNode* temp=head;
        while(temp != NULL)
        {
            count++;
            temp=temp->next; 
        }
        if(count == 1) return NULL;
        if(count == 2) 
        {
            ListNode *next=head->next;
            head->next=NULL;
            delete next;
            return head;
        }
        ListNode *temp2 = head;
        int n = count/2;
        for(int i=1;i<n;i++){
            temp2 = temp2->next;
        }
        ListNode *next=temp2->next;
        temp2->next = temp2->next->next;
        delete next;

        return head;      
    }
};