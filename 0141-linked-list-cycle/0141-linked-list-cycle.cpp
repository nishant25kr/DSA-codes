/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, bool>mapp;
        ListNode* temp=head;

        while(temp!=NULL){
            if(mapp[temp]) return true;
            mapp[temp]=true;
            temp=temp->next;

        }
        return false;
        
    }
};