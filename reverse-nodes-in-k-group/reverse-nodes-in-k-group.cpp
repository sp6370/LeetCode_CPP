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
    
    struct npair{
    ListNode* head;
    ListNode* tail;
    };
    
    int listLen(ListNode *head)
    {
        int count = 0;
        while(head!=NULL)
        {
            head = head->next;
            count++;
        }
        return count;
    }

    struct npair revList(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        {
            struct npair a;
            a.head = head;
            a.tail = head;
            return a;
        }
        
        ListNode* gnode = head;
        ListNode* lnode = NULL;
        
        while(head!=NULL)
        {
                ListNode* tmp = head->next;
                head->next = lnode;
                lnode = head;
                head = tmp;
        }

        struct npair a;
        a.head = lnode;
        a.tail = gnode;
        return a;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            {
                return head;
            }
    
        if(k == 0)
        {
            return head;
        }
    
        // reverse the k nodes linked list
        ListNode* head1 = NULL;
        ListNode* tail1 = NULL;
        
        int count = 0;
        
        while(head!=NULL && count!=k)
        {
            if(count == 0)
            {
                head1 = head;
            }
            
            count++;
            tail1 = head;
            head = head->next;
        }
        
        tail1->next = NULL;
        
        auto len = listLen(head1);
        if(len < k)
        {
            return head1;
        }
        
        struct npair revKnodes = revList(head1);
        // recursive call to find reverse of list after k nodes
        //head now points to k+1th node
        
        ListNode* rans = reverseKGroup(head, k);
        revKnodes.tail->next = rans;
        
        return revKnodes.head;
    }
};