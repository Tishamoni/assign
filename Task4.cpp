#include <iostream>
#include <vector>
using namespace std;

//class of node
class node{
public:
    int value;
    node* left;
    node*right;
    node(int d){
        value = d;
        left = NULL;
        right = NULL;
    }
};

int height(node*root){
    if(root==NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return 1 + max(l,r);
}

int count_leaves(node*root){
    if(root==NULL) return 0;
    if(root->left==NULL and root->right==NULL) return 1;
    int l = count_leaves(root->left);
    int r = count_leaves(root->right);
    return l+r;
}


void insert(node ** pRoot, int val){
    if(*pRoot == NULL)
        *pRoot = new node(val);
    else if((*pRoot)->value <= val)
        insert(&((*pRoot)->right), val);
    else if((*pRoot)->value > val)
        insert(&((*pRoot)->left), val);
}

node * getBST(vector<int>list){
    node * root = NULL;
    for(int i = 0; i < list.size(); i++)
        insert(&root, list[i]);
    return root;
}

int main(){
    vector<int> list = {100,90,110,80,95,105,103,107,130,20};
    node * root = getBST(list);
    
    
    cout<<"tree height: "<<height(root)<<endl;
    cout<<"tree leaves: "<<count_leaves(root)<<endl;
    return 0;
}
