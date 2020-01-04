/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//solution 1
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        ListNode* r = nullptr;
        ListNode* pre = nullptr;
        while(p!=nullptr)
        {
            r = p->next;
            p->next=pre;
            pre = p;
            p = r;
        }
        return pre;
}
};
//solution 2
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
}
};