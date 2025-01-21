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

        if(head==NULL or head->next == NULL) return NULL;

        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        
        int new_n=(count-n);
        if (new_n == 0) {
            ListNode* newHead = head->next; 
            delete head;                   
            return newHead;
        }
        ListNode* temp2=head;
        int newcount=0;
        while(temp2!=NULL)
        {
            newcount++;
            if(newcount == new_n) break;
            temp2=temp2->next;
        }
        ListNode* next=NULL;
        next=temp2->next;
        temp2->next=temp2->next->next;
        delete next;
        return head;
    }
};