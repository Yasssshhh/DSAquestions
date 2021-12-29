//Only Function(without Implementing LinkedList);

// Given the head of a linked list, rotate the list to the right by k places.
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        int n=0;
        ListNode*curr=head;
        while(curr){
            curr=curr->next;
            n++;
        }
        
        if(k>n){
            k=k%n;
        }
        
      for(int i=0;i<k;i++){
          ListNode*curr2=head;
          ListNode*curr3=head;
          
          while(curr2->next->next!=NULL && curr2->next!=NULL){
              curr2=curr2->next;
              curr3=curr3->next;
          }
          curr3=curr3->next;
          curr3->next=head;
          curr2->next=NULL;
          head=curr3;
      }
    return head;
    }
};