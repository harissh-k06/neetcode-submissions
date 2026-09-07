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
        if (!list1 && !list2) return nullptr;
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* res = nullptr;
        ListNode* head = res;
        while (curr1 && curr2){
            ListNode* less = nullptr;
            if (curr1->val < curr2->val){
                less = curr1;
                curr1 = curr1->next;
            }
            else{
                less = curr2;
                curr2 = curr2 -> next;
            }
            if (!res){
                res = less;
                head = res;
            }
            else{
                res->next = less;
                res = res->next;
            }
        }
        while (curr1){
            if (!res){
                res = curr1;
                head = res;
            }
            else{
                res->next = curr1;
                res = res->next;
            }
            curr1 = curr1 -> next;
        }

        while(curr2){
            if (!res){
                res = curr2;
                head = res;
            }
            else{
                res->next = curr2;
                res = res->next;
            }
            curr2 = curr2->next;
        }
        return head;
    }
};
