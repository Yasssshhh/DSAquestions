#include<iostream>
using namespace std;

template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};


template <typename T>

class BST{
    BinaryTreeNode<int>*root;

    public:
    BST(){
        root=NULL;
    }
    ~BST(){
        delete root;
    }

    private:
    BinaryTreeNode<int>*remove(int data,BinaryTreeNode<int>*node){
    if(node==NULL){
        return node;
    }

    if(data>node->data){
        node->right =remove(data,node->right);
        return node;
    }

    else if(data<node->data){
        node->left=remove(data,node->left);
        return node;
    }

    else{
        if(node->left==NULL && node->right==NULL){
            delete node;
            return NULL;
        }
        else if(node->left==NULL){
            BinaryTreeNode<int>*temp=node->right;
            node->right=NULL;
            delete node;
            return temp;
        }
        else if(node->right==NULL){
            BinaryTreeNode<int>*temp=node->left;
            node->left=NULL;
            delete node;
            return temp;
        }
        else{
            BinaryTreeNode<int>*minNode=node->right;
            while(minNode->left !=NULL){
                minNode=minNode->left;
            }
            int rightMin=minNode->data;
            node->data=rightMin;
            node->right=remove(rightMin,node->right);
            return node;

        }
        
    }
}

void print(BinaryTreeNode<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    
    if(root->left !=NULL){
        cout<<"L"<<":"<<root->left->data<<",";
    }
    
    if(root->right !=NULL){
        cout<<"R"<<":"<<root->left->data<<",";
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}

    private:
    BinaryTreeNode<int>*insert(int data,BinaryTreeNode<int>*node){
    if(node==NULL){
        BinaryTreeNode<int>*newNode=new BinaryTreeNode<int>(data);
        return newNode;
    }

    if(data<=node->data){
        node->left=insert(data,node->left);
    }

    else{
        node->right=insert(data,node->right);
    }
    return node;
    }

    public:
    void insert(int data){
    this->root=insert(data,this->root);
    } 
    void remove(int data){
    root=remove(data,root);
    }

	private:
	bool search(int data, BinaryTreeNode<int>* node) 
    {
		if (node == NULL) 
        {
			return false;
		}

		if (node->data == data) 
        {
			return true;
		}
        else if (data < node->data) 
        {
			return search(data, node->left);
		} 
        else {
			return search(data, node->right);
		}
	}
     
     public:
     void print()
     {
        print(root);
     }
     
     bool search(int data) {
     return search(data, root);   
    }

};