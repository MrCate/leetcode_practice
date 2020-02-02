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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next == nullptr)
            return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(temp);
        ListNode* h = new ListNode(0);
        ListNode* res = h;
        while(left!=nullptr&&right!=nullptr){
            if(left->val<right->val)
            {
                h->next = left;
                left = left->next;
            }
            else{
                h->next=right;
                right=right->next;
            }
            h=h->next;
        }
        h->next=left!=nullptr?left:right;
        return res->next;
    }
};