#include<iostream>
#include<queue>
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

// void PrintTree(BinaryTreeNode<int>*root){
//     if(root==NULL){
//         return;
//     }
//     cout<<root->data<<":";
//     if(root->left!=NULL){
//         cout<<"L"<<root->left->data<<" ";
//     }
//     if(root->right!=NULL){
//         cout<<"R"<<root->right->data<<" ";
//     }
//     cout<<endl;
//     PrintTree(root->left);
//     PrintTree(root->right);
// }

// BinaryTreeNode<int>*takeInput(){
//     int rootData;
//     cout<<"Enter Data"<<endl;
//     cin>>rootData;

//     if(rootData==-1){
//         return NULL;
//     }
//     BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
//     BinaryTreeNode<int>*leftChild=takeInput();
//     BinaryTreeNode<int>*rightChild=takeInput();

//     root->left=leftChild;
//     root->right=rightChild;
//     return root;
// }

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

int main(){
// BinaryTreeNode<int>*root=new BinaryTreeNode<int>(1);
// BinaryTreeNode<int>*node1=new BinaryTreeNode<int>(2);
// BinaryTreeNode<int>*node2=new BinaryTreeNode<int>(3);

// root->left=node1;
// root->right=node2;

// PrintTree(root);

BinaryTreeNode<int>*root=takeInputLevelWise();
PrintLevelWise(root);

}