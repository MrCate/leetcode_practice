class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        //ListNode* neHead = l1;
        if(l1 == NULL||l2 == NULL)
            return nullptr;
        while(p1!=NULL && p2!=NULL)
        {
            if(p1->val+p2->val < 10)
                p1->val = p1->val+p2->val;
            else{
                p1->val = (p1->val+p2->val)%10;
                p1->next->val += 1;
            }
            p1=p1->next;
            p2=p2->next;
            //neHead=neHead->next;
        }
        return p1;
    }
};