#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode*left;
    BinaryTreeNode*right;

    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>*takeInputLevelWise(){
    int rootData;
    cout<<"Enter Root Data:"<<endl;
    cin>>rootData;

    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){

        BinaryTreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter Left Child of"<<front->data<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if(leftchilddata != -1){
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(leftchilddata);
            front->left=child;
            pendingNodes.push(child);
        }

        cout<<"Enter Right Child of"<<front->data<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if(rightchilddata != -1){
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(rightchilddata);
            front->right=child;
            pendingNodes.push(child);
        }
    }
return root;
}

void PrintLevelWise(BinaryTreeNode<int>*root){
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(q.size()!=0){
    BinaryTreeNode<int>*front=q.front();

    cout<<front->data<<";";
    if(front->left){
        q.push(front->left);
        cout<<"L"<<":"<<front->left->data<<",";
    }
    else{
        cout<<"L:"<<-1<<",";
    }
    if(front->right){
        q.push(front->right);
        cout<<"R"<<":"<<front->right->data<<",";
    }
    else{
        cout<<"R:"<<-1<<",";
    }
    cout<<endl;
    q.pop();
    }
}

int countNodes(BinaryTreeNode<int>*root){
    if(root==NULL)
    return 0;

    return 1+countNodes(root->left)+countNodes(root->right);
}

int height(BinaryTreeNode<int>* root) {
    if(root==NULL) return 0;

    int lheight=height(root->left);
    int rheight=height(root->right);
    
    return max(lheight,rheight)+1;
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if(root==NULL)return;

    BinaryTreeNode<int>*temp=root->left;
    root->left=root->right;
    root->right=temp;
    
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    
}

pair<int,int> heightDiameter(BinaryTreeNode<int>*root){
    if(root==NULL){
        pair<int,int>p;
        p.first=0;
        p.second=0;
        return p;
    }

    pair<int,int>leftans=heightDiameter(root->left);
    pair<int,int>rightans=heightDiameter(root->right);
    
    int lh=leftans.first;
    int rh=rightans.first;
    int ld=leftans.second;
    int rd=rightans.second;

    int height=1+ max(lh,rh);
    int diameter=max(lh+rh,max(ld,rd));
    
    pair<int,int> p;
    p.first=height;
    p.second=diameter;

    return p;
}

pair<int,int> minAndmax(BinaryTreeNode<int>*root){
    pair<int,int>ans=make_pair(INT_MIN,INT_MAX);

    if(root==NULL)return ans;

    pair<int,int>leftans=minAndmax(root->left);
    pair<int,int>rightans=minAndmax(root->right);

    ans.first=min(root->data,min(leftans.first,rightans.first));
    ans.second=min(root->data,max(leftans.first,rightans.first));

    return ans;
}

int getSum(BinaryTreeNode<int>* root) {
if(root==NULL)
    return 0;
    
return root->data + getSum(root->left) + getSum(root->right);
}

class BalancedReturnType {
  public: 
    int height;
  	bool balanced;
};
BalancedReturnType * isBalancedHelper(BinaryTreeNode < int > * root) {
  if (root == NULL) {
    BalancedReturnType * ans = new BalancedReturnType();
    ans -> height = 0;
    ans -> balanced = true;
    return ans;
  }
  BalancedReturnType * ans1 = isBalancedHelper(root -> left);
  BalancedReturnType * ans2 = isBalancedHelper(root -> right);
  bool flag;
  if (!(ans1 -> balanced) || !(ans2 -> balanced) || abs(ans1 -> height - ans2 -> height) > 1) {
    flag = false;
  } else {
    flag = true;
  }
  BalancedReturnType * output = new BalancedReturnType();
  output -> height = max(ans1 -> height, ans2 -> height) + 1;
  output -> balanced = flag;
  return output;
}
bool isBalanced(BinaryTreeNode < int > * root) {
  if (root == NULL) {
    return true;
  }
  return isBalancedHelper(root) -> balanced;
}




int main(){

    BinaryTreeNode<int>*root=takeInputLevelWise();
    PrintLevelWise(root);

    pair<int,int>p=heightDiameter(root);
    cout<<"Height:"<<p.first<<"Diameter:"<<p.second<<endl;

    pair<int, int> ans = minAndmax(root);
    cout <<"Minimum:"<<" "<<ans.first <<"Maximum:"<<" " << ans.second;

    cout <<"Sum of Roots:"<<getSum(root);

    cout << (isBalanced(root) ? "true" : "false");
}