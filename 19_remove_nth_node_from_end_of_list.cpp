/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
maples1
5/28/2022
*/

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
        ListNode* it = head;
        int listLen = 0;
        int m;      // nth from end, mth from beginning
        int i = 1; // 1 index to match linked list
        
        // get length of list and find nth node
        while (it != nullptr)
        {
            listLen ++;
            it = it->next;
        }
        
        // Special cases
        // return empty list if there's only one element
        if (1 == listLen) return nullptr;
        // return first element after head if nth element is the head
        if (n == listLen) return head->next;
        
        // listLen is 1st from end
        m = (listLen + 1) - n;
          
        it = head; // reset to beginning

        while (i < (m-1))
        {
            it = it->next;
            i++;
        }
        
        ListNode* toRemove = it->next;
        it->next = toRemove->next;
        delete toRemove;
       
        return head;
    }
};