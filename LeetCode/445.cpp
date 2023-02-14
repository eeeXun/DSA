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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        bool carry = false;
        stack<int> i1, i2;
        ListNode* result;
        while (l1) {
            i1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            i2.push(l2->val);
            l2 = l2->next;
        }
        while (!i1.empty() || !i2.empty()) {
            ListNode* node = carry ? new ListNode(1) : new ListNode();
            if (!i1.empty()) {
                node->val += i1.top();
                i1.pop();
            }
            if (!i2.empty()) {
                node->val += i2.top();
                i2.pop();
            }
            if (node->val >= 10) {
                carry = true;
                node->val %= 10;
            } else {
                carry = false;
            }
            node->next = result;
            result = node;
        }
        if (carry) {
            ListNode* node = new ListNode(1);
            node->next = result;
            result = node;
        }
        return result;
    }
};
