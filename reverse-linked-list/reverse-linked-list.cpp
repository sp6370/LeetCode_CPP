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
    ListNode* reverseList(ListNode* head) {
        
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    ListNode* lnode = NULL;
    ListNode* gnode = NULL;
    
    while(head!=NULL)
    {
            ListNode* tmp = head->next;
            
            head->next = lnode;
            lnode = head;
            head = tmp;
    }
        
    return lnode;
        
    }
};