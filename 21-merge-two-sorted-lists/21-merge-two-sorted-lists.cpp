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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL && list2==NULL)
        {
            return NULL;
        }
        
        if(list1==NULL)
        {
            return list2;
        }
        
        if(list2==NULL)
        {
            return list1;
        }
        
        ListNode* resultHead = NULL;
        ListNode* curNode = NULL;
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val<list2->val)
            {
                if(resultHead!=NULL)
                {
                    curNode->next = list1;
                    curNode=list1;
                    list1 = list1->next;
                }
                else
                {
                    resultHead=list1;
                    curNode=list1;
                    list1=list1->next;
                }
            }
            else
            {
                if(resultHead!=NULL)
                {
                    curNode->next = list2;
                    curNode=list2;
                    list2 = list2->next;
                }
                else
                {
                    resultHead=list2;
                    curNode=list2;
                    list2=list2->next;
                }
            }
        }
        
        while(list1!=NULL)
        {
            
            curNode->next = list1;
            curNode=list1;
            list1 = list1->next;
        }
        
        while(list2!=NULL)
        {
            curNode->next = list2;
            curNode=list2;
            list2 = list2->next;
        }
        
        return resultHead;
        
    }
};