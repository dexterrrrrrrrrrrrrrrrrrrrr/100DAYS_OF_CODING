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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, last = -1, mn = INT_MAX;
        int pos = 1;

        auto prev = head;
        auto curr = head->next;

        while (curr && curr->next) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {

                if (first != -1)
                    mn = min(mn, pos - last);
                else
                    first = pos;

                last = pos;
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        if (first == last) return {-1, -1};

        return {mn, last - first};
    }
};