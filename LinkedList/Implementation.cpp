#include<iostream>
using namespace std;

class Node{
    public:
    int data;         //to store the data.
    Node*next;        //to store address of next pointer.
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node*takeinput()
{
    int data;
    cin>>data;

    Node*head=NULL;
    Node*tail=NULL;

    while(data !=-1){
        Node*newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        cin>>data;
    }
    return head;
}

Node*insertNode(Node*head,int i,int data){
 
 Node*newNode=new Node(data);
 int count=0;
 Node*temp=head;

 if(i==0){
     newNode->next=head;
     head=newNode;
     return head;
 }

 while(temp !=NULL & count<i-1){
     temp=temp->next;
     count++;
 }
 
 if(temp!=NULL){
     newNode->next=temp->next;
     temp->next=newNode;
 }
 return head;
}
 
Node*deleteNode(Node*head,int pos){
    
    if(head==NULL){
        return head;
    }
    if(pos==0){
        return head->next;
    }
    
    Node*curr=head;
    int currpos=0;
    
    while(curr!=NULL&& currpos<pos-1){
        ++currpos;
        curr=curr->next;
    }

    if(curr==NULL || curr->next==NULL){
        return head;
    }

    curr->next=curr->next->next;
    return head;
}

void print(Node*head){
    Node*temp=head;
    while(temp != NULL){
     cout<<temp->data<<" ";
     temp=temp->next;   
    }
    cout<<endl;
}

int main() {

	Node *head = takeinput();
	print(head);
	int i, data;
	cin >> i >> data;
	head = insertNode(head, i, data);
	print(head);


    int pos;
	cin >> pos;
 	head = deleteNode(head, pos);
 	print(head);
}