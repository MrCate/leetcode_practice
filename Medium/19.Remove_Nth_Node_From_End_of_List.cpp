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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr)
            return nullptr;
        ListNode* rear = head;
        ListNode* temp = head;
        int count = 1;
        while(rear->next != nullptr){
            rear = rear->next;
            count++;
        }
        if(n==count)
            head=head->next;
        for(int i=0;i<count-n-1;i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};