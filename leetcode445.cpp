/*
给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。
进阶:
如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> p;
        stack<ListNode*> q;
        stack<int> result;
        int i,j,n,m,state;

        ListNode* root = l1;
        while(root != NULL){
            p.push(root);
            root = root->next;
        }

        root = l2;
        while(root != NULL){
            q.push(root);
            root = root->next;
        }

        state = 0;
        ListNode* node1;
        ListNode* node2;
        root = new ListNode(0);
        ListNode* now = root;
        while((!p.empty()) && (!q.empty())){
            node1 = p.top();
            node2 = q.top();
            p.pop();
            q.pop();
            result.push((node1->val+node2->val+state)%10);
            if((node1->val+node2->val+state) >= 10){
                state = 1;
            }
            else{
                state = 0;
            }
        }

        while(!p.empty()){
            node1 = p.top();
            p.pop();
            result.push((node1->val+state)%10);
            if((node1->val+state) >= 10){
                state = 1;
            }
            else{
                state = 0;
            }
        }

        while(!q.empty()){
            node1 = q.top();
            q.pop();
            result.push((node1->val+state)%10);
            if((node1->val+state) >= 10){
                state = 1;
            }
            else{
                state = 0;
            }
        }

        if(state == 1){
            result.push(1);
        }

        ListNode* node;
        while(!result.empty()){
            node = new ListNode(result.top());
            now->next = node;
            now = now->next;
            result.pop();
        }

        return(root->next);
    }
};
