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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* index = head;
        ListNode* old_index = nullptr;
        while (index && index->next) {
            ListNode* tmp = index->next->next;
            if (old_index)
                old_index->next = index->next;
            else
                head = index->next;
            index->next->next = index;
            index->next = tmp;
            old_index = index;
            index = tmp;
        }
        return head;
    }
};
