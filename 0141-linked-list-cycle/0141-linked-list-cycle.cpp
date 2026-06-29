/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> mpp;
        while (head!=nullptr){
            if(mpp.count(head)){
                return true;
            }
            mpp.insert(head);
            head=head->next;
        }
        return false;

    }
};