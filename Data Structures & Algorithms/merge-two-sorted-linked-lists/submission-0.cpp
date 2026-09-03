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
        // Create a dummy node to act as a starting point for the merged list.
        // It makes the code way simpler!
        ListNode* dummy = new ListNode(-1);
        
        // 'tail' will always point to the last node in our merged list.
        ListNode* tail = dummy;

        // Loop as long as we have nodes in BOTH lists.
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                // If list1's node is smaller, attach it to our tail.
                tail->next = list1;
                // Move list1's pointer to the next node.
                list1 = list1->next;
            } else {
                // If list2's node is smaller, attach it instead.
                tail->next = list2;
                // Move list2's pointer to the next node.
                list2 = list2->next;
            }
            // Move the tail pointer forward to the node we just added.
            tail = tail->next;
        }

        // After the loop, one of the lists might still have nodes left.
        // We just need to attach the rest of the non-empty list to our tail.
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // The merged list starts right after our dummy node.
        ListNode* head = dummy->next;
        // It's good practice to delete the memory we allocated for the dummy node.
        delete dummy;
        
        return head;
    }
};
