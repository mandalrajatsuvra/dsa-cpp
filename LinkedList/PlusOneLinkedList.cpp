#include "iostream"
 using namespace std;



 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* plusOne(ListNode* head) {

    }

    pair<ListNode*, int> solve(ListNode* head, ListNode* head_ref){
        if(head == nullptr){
            return {head, 0};
        }
        if(head->next == nullptr){
            int currVal = head->val;
            currVal+=1;
            int s = currVal%10;
            int c = currVal/10;
            head->val = s;
            if(head == head_ref && c == 1){
                ListNode* node = new ListNode(c);
                node->next = head;
                head = node;
            }
            return {head, c};
        }
        pair<ListNode*, int> nextResult = solve(head->next, head);
        ListNode* nextNode = nextResult.first;
        int nextCarry = nextResult.second;
        head->next = nextNode;
        if(nextCarry == 1){
            int currVal = head->val;
            currVal+=1;
            int s = currVal%10;
            int c = currVal/10;
            head->val = s;
            if(head == head_ref && c == 1){
                ListNode* node = new ListNode(c);
                node->next = head;
                head = node;
            }
            return {head, c};
        }
        return {head, 0};
    }


};

int main(){

}
// Question:https://leetcode.com/problems/plus-one-linked-list/editorial/