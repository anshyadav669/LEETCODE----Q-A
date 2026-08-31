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
        int firstCP = -1;
        int prevCP = -1;

        int minDist = INT_MAX;
        int lastCP = -1;

        int pos = 1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != nullptr && curr->next != nullptr) {
            ListNode* next = curr->next;

            // Check if curr is a critical point
            bool isCritical =
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);

            if (isCritical) {
                // First critical point
                if (firstCP == -1) {
                    firstCP = pos;
                }
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - prevCP);
                }

                prevCP = pos;
                lastCP = pos;
            }

            prev = curr;
            curr = next;
            pos++;
        }

        // Fewer than two critical points
        if (firstCP == -1 || firstCP == prevCP) {
            return {-1, -1};
        }

        int maxDist = lastCP - firstCP;

        return {minDist, maxDist};
    }
};