//Only Function(without Implementing LinkedList);

//You are given two non-empty linked lists representing two non-negative integers.
//The most significant digit comes first and each of their nodes contains a single digit. 
//Add the two numbers and return the sum as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [8,0,7]
 
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
    
    ListNode*reverse(ListNode*head){
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*fwd=NULL;
        
        while(curr!=NULL){
            fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
        ListNode*l11=reverse(l1);
        ListNode*l22=reverse(l2);
        
        ListNode*dummy=new ListNode();
        ListNode*temp=dummy;
        
        int carry=0;
        int sum=0;
        

        while(l11!=NULL && l22!=NULL ){
            sum=l11->val+l22->val+carry;
            carry=sum/10;
            
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
        
            l11=l11->next;
            l22=l22->next;
        }
        
        while(l11!=NULL){
            sum=l11->val+carry;
            carry=sum/10;
            l11=l11->next;
            
             ListNode* node = new ListNode(sum%10);
             temp->next = node;
             temp = temp->next;
        }
        
        while(l22!=NULL){
            sum=l22->val+carry;
            carry=sum/10;
            l22=l22->next;
            
             ListNode* node = new ListNode(sum%10);
             temp->next = node;
             temp = temp->next;
        }
        
        if(carry){
        ListNode* node = new ListNode(carry);
        temp->next = node;
        temp = temp->next;
        }
        
        ListNode*temp2=dummy->next;
        ListNode*temp3=reverse(temp2);
       
       return temp3;
    }
};