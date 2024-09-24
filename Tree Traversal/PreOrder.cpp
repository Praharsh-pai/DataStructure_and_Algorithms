#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data=value;
        left=right=nullptr;
    }
};

void preorderTraversal(Node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<< " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

Node* createTree(){
    int data;
    cout<<"Enter the root node value: ";
    cin>>data;
    if(data==-1){
        return nullptr;
    }
    Node* root= new Node(data);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current=q.front();
        q.pop();
        cout<<"Enter the left child of "<<current->data<<"(-1 if no left child): ";
        cin>>data;
        if(data!=-1){
            current->left= new Node(data);
            q.push(current->left);
        }
        cout<<"Enter the right child of "<<current->data<<"(-1 if no right child): ";
        cin>>data;
        if(data!=-1){
            current->right= new Node(data);
            q.push(current->right);
        }
    }
    return root;
}

int main(){
    cout<<"Create a binary tree:"<<endl;
    Node* root=createTree();
    cout<<"Preorder Traversal: ";
    preorderTraversal(root);
    return 0;
}
