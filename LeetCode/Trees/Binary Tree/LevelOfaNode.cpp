// Given a Binary Tree and a target key you need to find the level of target key in the given Binary Tree.
class Solution{
public:
int level=1;

int getLevel(struct Node *node, int target){ 

if(node==NULL)
return 0;

queue<Node*>q;
q.push(node);
int level = 1;

while(!q.empty()){
int size=q.size();

while(size--){
Node* temp = q.front();
q.pop();

if(temp->data==target)
return level;

if(temp->left)
q.push(temp->left);

if(temp->right)
q.push(temp->right);
}
level++;

}
return 0;
}
};