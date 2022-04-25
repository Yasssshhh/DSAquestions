#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{
public:
T data;
vector<TreeNode<T>*>children;

TreeNode(T data){
    this->data=data;
}
~TreeNode() {
    for(int i=0;i<children.size();i++){
        delete children[i];
    }
}
};



TreeNode<int>*TakeInputLevelWise(){
    
    int rootData;
    cout<<"Enter root data:"<<endl;
    cin>>rootData;

    TreeNode<int>*root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*>pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size()!=0){

        TreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter number of childrens of "<<front->data<<endl;
        int numchild;
        cin>>numchild;

        for(int i=0;i<numchild;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;

            TreeNode<int>*child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printLevelWise(TreeNode<int>*root){

queue<TreeNode<int>*> pendingNodes;
pendingNodes.push(root);
while(pendingNodes.size()!=0){
    TreeNode<int>*front=pendingNodes.front();
    cout<<front->data<<":";
    for(int i=0;i<front->children.size();i++){
        if(i==front->children.size()-1){
            cout<<front->children[i]->data;
        }
        else{
            cout<<front->children[i]->data<<",";
        }
        pendingNodes.push(front->children[i]);
    }
    cout<<endl;
    pendingNodes.pop();
}
}

int numNodes(TreeNode<int>*root){

if(root==NULL) return 0;
int num=1;
for(int i=0;i<root->children.size();i++){
    num+=numNodes(root->children[i]);
}
return num;
}

//Get height of a tree

int getHeight(TreeNode<int>* root) {

    if(root==NULL) return 0;
    
    int ans=0;
    for(int i=0;i<root->children.size();i++){
        int height=getHeight(root->children[i]);
        ans=max(height,ans);
    }
    return ans+1;
}

void printAtLevelK(TreeNode<int>*root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<endl;
        return;
    }

    for(int i=0;i<root->children.size();i++){
    printAtLevelK(root->children[i],k-1);
    }
}

//Count Leaf Nodes.

int getLeafNodeCount(TreeNode<int>* root) {

    int leaves=0;
    if(root==NULL) return 0;
    
    if(root->children.size()==0)
    return 1;
    
    for(int i=0;i<root->children.size();i++){
        leaves+=getLeafNodeCount(root->children[i]);
    }
    return leaves;
}

//To check a node is present or Not

bool isPresent(TreeNode<int>* root, int x) {
    
    if(root->data==x) return true;
    
    for(int i=0;i<root->children.size();i++){
        bool ans=isPresent(root->children[i],x);
        if(ans){
            return ans;
        }
    }
    return false;
}

//Node greater than x

int getLargeNodeCount(TreeNode<int>* root, int x) {
    
    int count=0;
    if(root==NULL) return 0;
    
    if(root->data>x) count++;
    
    for(int i=0;i<root->children.size();i++){
        count+=getLargeNodeCount(root->children[i],x);
    }
    
    return count;
}


//Node with maximum child sum

template < typename T > 
class MaxNodePair
{
public:
TreeNode < T > *node;
  int sum;
};

MaxNodePair < int >*maxSumNodeHelper (TreeNode < int >*root)
{
  if (root == NULL)
    {
      MaxNodePair < int >*pair = new MaxNodePair < int >();
      pair->node = NULL;
      pair->sum = 0;
      return pair;
    }
   int sum = root->data;
   for (int i = 0; i < root->children.size (); i++)
    {
      sum += root->children[i]->data;
    } 
  MaxNodePair < int >*ans = new MaxNodePair < int >();
  ans->node = root;
  ans->sum = sum;
  for (int i = 0; i < root->children.size (); i++)
    {
      MaxNodePair < int >*childAns = maxSumNodeHelper (root->children[i]);
      if (childAns->sum > ans->sum)
	{
	  ans = childAns;
	}
    }
  return ans;
}

TreeNode < int >*maxSumNode (TreeNode < int >*root)
{
  return maxSumNodeHelper (root)->node;
}

//Structurally identical

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    
    if(root1==NULL && root2==NULL){
        return true;
    }
    if((root1==NULL && root2 !=NULL) || (root2==NULL && root1 !=NULL)){
        return false;
    }
    if(root1->children.size() != root2->children.size() || root1->data != root2->data){
        return false;
    }
      
    for(int i=0;i<root1->children.size();i++){
    return areIdentical(root1->children[i],root2->children[i]);
    }
    return true;
}


int main(){
    TreeNode<int>*root=TakeInputLevelWise();
    printLevelWise(root);
    int num=numNodes(root);
    cout<<num<<endl;

    int height=getHeight(root);
    cout<<height<<endl;
    
    int x1;
    cin>>x1;
    printAtLevelK(root,x1);
     
    cout<<getLeafNodeCount(root);

    int x2;
    cin >> x2;
    cout << (isPresent(root, x2) ? "true" : "false");

    int x3;
    cin >> x3;
    cout << getLargeNodeCount(root, x3);

    TreeNode<int>* root1 = TakeInputLevelWise();
    TreeNode<int>* root2 = TakeInputLevelWise();
    cout << (areIdentical(root1, root2) ? "true" : "false");

    delete root;
}

