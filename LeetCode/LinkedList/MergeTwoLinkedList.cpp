//Only Function(without Implementing LinkedList);

//Given the head of a linked list, return the list after sorting it in ascending order.

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
    
    ListNode* merge(ListNode* list1, ListNode* list2) {
        
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        if(list1==NULL && list2==NULL){
            return NULL;
        }
        
        ListNode*dummy=new ListNode();
        ListNode*temp=dummy;
        
        
        while(list1!=NULL && list2!=NULL){
            
            if(list1->val >= list2->val){
                ListNode*node=new ListNode(list2->val);
                temp->next=node;
                temp=temp->next;
                
                list2=list2->next;
            }
            
            else{
                ListNode*node=new ListNode(list1->val);
                temp->next=node;
                temp=temp->next;
                
                list1=list1->next;
            }
        }
        
        while(list1!=NULL){
             ListNode*node=new ListNode(list1->val);
                temp->next=node;
                temp=temp->next;
                
                list1=list1->next;
        }
        while(list2!=NULL){
            ListNode*node=new ListNode(list2->val);
                temp->next=node;
                temp=temp->next;
                
                list2=list2->next;
        }
        return dummy->next;
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode*slow=head;
        ListNode*fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode*head1=head;
        ListNode*head2=slow->next;
        slow->next=NULL;
        
        head1=sortList(head1);
        head2=sortList(head2);
            
        return merge(head1,head2);     
         
    }
};