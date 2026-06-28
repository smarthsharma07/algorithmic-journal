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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr && head->next!=nullptr){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevleft = dummy;
        ListNode* curr = head;
        for (int i = 1; i <left;i++){
            prevleft=curr;
            curr=curr->next;
        }
        ListNode* leftNode = curr;
        ListNode* prev = nullptr;
        int count = right - left + 1;
        while (count--){
            ListNode* nextnode = curr->next;
            curr->next=prev;
            prev = curr;
            curr = nextnode;
        }
        prevleft->next=prev;
        leftNode->next=curr;
        return dummy->next;
    }
};