/*
https://leetcode.com/problems/add-two-numbers/
maples1
12/12/2021
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Allocate pointers for the resulting list    
        ListNode* head = new ListNode();
        ListNode* tail = head;
        int carryOver = 0; // overflow if sum is 10 or greater
        
        while (l1 != nullptr || l2 != nullptr)
        {
            int val1, val2;
            // if one of the lists has run out of numbers, assume 0
            if (l1 != nullptr)
            {
                val1 = l1->val;
            }
            else
            {
                val1 = 0;
            }
            if (l2 != nullptr)
            {
                val2 = l2->val;
            }
            else
            {
                val2 = 0;
            }    
            
            // get sum of values
            int sum = val1 + val2 + carryOver;
            
            // carry over one if sum is double digits
            if (sum >= 10)
            {
                // set sum to remainder
                sum = sum%10;
                // carry over one
                carryOver = 1;
            }
            else
            {
                carryOver = 0;
            }

            // set current value to tail node
            tail->val = sum;
            // allocate space for the next node if needed
            if((l1 != nullptr) && (l1->next != nullptr) || (l2 != nullptr) && (l2->next != nullptr))
            {
                ListNode* newTail = new ListNode();
                tail->next = newTail;
                tail = tail->next;
            }
            
            // iterate to next set of values
            if (l1 != nullptr)
            {
                (l1 = l1->next);
            }
            if (l2 != nullptr)
            {
                (l2 = l2->next);
            }
        }
        
        if (carryOver)
        {
            ListNode* newTail = new ListNode(1);
            tail->next = newTail;
            tail = tail->next;
        }
        
        return head;        
    }
};