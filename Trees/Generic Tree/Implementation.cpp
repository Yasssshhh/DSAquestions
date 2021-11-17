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
};

TreeNode<int>*TakeInput(){
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;

    TreeNode<int>*root=new TreeNode<int>(rootData);

    int n;
    cout<<"Enter number of Childrens of"<<rootData<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        TreeNode<int>*child=TakeInput();
        root->children.push_back(child);
    }
    return root;
}

void PrintTree(TreeNode<int>*root){

    if(root==NULL){
        return;
    }

    cout<<root->data<<":";
    
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;

    for(int i=0;i<root->children.size();i++){
    PrintTree(root->children[i]);
    }
}

int main(){
    
    TreeNode<int>*root=TakeInput();
    PrintTree(root);
}