#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode**children;
    bool isTerminal;

    TrieNode(char data){
        this->data=data;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie{
    TrieNode*root;
    
    public:
    
    Trie(){
        root=new TrieNode('\0');
    }

    void insertword(TrieNode*root,string word){
        
        //Base Case
        if(word.size()==0){
            root->isTerminal=true;
            return;
        }

        //Small Calculation
        int index=word[0]-'a';
        TrieNode*child;
        if(root->children[index] !=NULL){
        child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        //Recursive Call
        insertword(child,word.substr(1));
    }

    void insertWord(string word) { 
        insertword(root, word); 
    }

    bool search(TrieNode*root,string word){
        if(word.size()==0){
            return root->isTerminal;
        }

        int index=word[0]-'a';
        
        TrieNode*child;
        if(root->children[index]==NULL){
            return false;
        }else{
            child=root->children[index];
        }
        return search(child,word.substr(1));
    }
    
    bool Search(string word) {
        return search(root,word);
    }

    void removeword(TrieNode*root,string word){
        
        //Base Case
        if(word.size()==0){
            root->isTerminal=false;
            return;
        }
        //Small Calculation
        TrieNode*child;
        int index=word[0]-'a';
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            return;
        }
    
        removeword(child,word.substr(1));
        if(child->isTerminal==false){
        for(int i=0;i<26;i++){
            if(child->children[i]!=NULL){
                return;
            }
        }
        delete child;
        root->children[index]=NULL;
      }
    }

    void removeWord(string word){
        removeword(root,word);
    }

};

int main(){
    Trie T;
    T.insertWord("and");
    T.insertWord("are");
    T.insertWord("dot");

    cout<<T.Search("and")<<endl;
    T.removeWord("and");
    cout<<T.Search("and")<<endl;
}