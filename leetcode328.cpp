/*
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL

输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL
*/

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next){
            return(head);
        }      

        ListNode* r1 = new ListNode(0);
        ListNode* r2 = new ListNode(0);
        ListNode* p = r1;
        ListNode* q = r2;
        ListNode* next_p = head;
        ListNode* next_q;
        while(next_p){
            next_q = next_p->next;
            p->next = next_p;
            p = p->next;
            if(p){
                p->next = NULL;
            }
            p->next = NULL;

            if(next_q){
                next_p = next_q->next;
            }
            else{
                next_p = NULL;
            }

            q->next = next_q;
            q = q->next;
            if(q){
                q->next = NULL;
            }
        }

        p->next = r2->next;
        return(r1->next);
    }
};
