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

int main(){
    TreeNode<int>*root=TakeInputLevelWise();
    printLevelWise(root);
}