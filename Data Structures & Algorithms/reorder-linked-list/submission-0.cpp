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
    void reorderList(ListNode* head) {
        vector<ListNode*>v;
        while(head!=nullptr){
            v.push_back(head);
            head = head->next;
        }
        int last = v.size()-1;
        int start = 0;
        int count = (last)/2;
        while(count--){
            v[start]->next = v[last];
            v[last]->next = v[start+1];
            start++;
            last--;
        }
        v[last]->next = nullptr;
    }
};