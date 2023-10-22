//Expression tree 
/*
    inorder recursive
    preorder recursive
    postorder recursive
    inorder iterative
    preorder iterative
*/

#include<iostream>
using namespace std;

class tree{
    private:
    char data;
    tree* ltree;
    tree* rtree;
    public:
    tree* root=NULL;
    tree(){
        ltree=NULL;
        rtree=NULL;
    }
    tree* create(char );
    void formtree(char[]);
    void inorder_r(tree*);
    void preorder_r(tree*);
    void postorder_r(tree*);
    void inorder_i(tree*);
    void preorder_i(tree*);
    void postorder_i(tree*);
};

class node{
    private:
    tree* info;
    node* child;
    public:
    node* top=NULL;

    node(){
        child=NULL;
    }
    tree* pop();
    void push(tree*);
    
};

tree* tree::create(char a){
    tree* newtree = new tree();
    newtree->data=a;
}

void node::push(tree* newtree){
    node* newnode= new node();
    newnode->info=newtree;
    if(top==NULL){
        top=newnode;
    }
    else{
        newnode->child=top;
        top=newnode;
    }
}

tree* node::pop(){
    node* temp=NULL;
    temp=top;
    top=top->child;
    return temp->info;
}

void tree::formtree(char postfix[]){
    int i=0;
    node s;
    while(postfix[i]!='\0'){
        tree* newtree= create(postfix[i]);
        if(isalnum(postfix[i])){
            s.push(newtree);
            i++;
        }
        else{
            newtree->rtree=s.pop();
            newtree->ltree=s.pop();
            s.push(newtree);
            i++;
        }
    }root=s.pop();
}

void tree::inorder_r(tree* curr){
    if(curr!=NULL){
        inorder_r(curr->ltree);
        cout<<curr->data<<" ";
        inorder_r(curr->rtree);
    }
}

void tree::preorder_r(tree* curr){
    if(curr!=NULL){
        cout<<curr->data<<" ";
        preorder_r(curr->ltree);
        preorder_r(curr->rtree);
    }
}

void tree::postorder_r(tree* curr){
    if(curr!=NULL){
        postorder_r(curr->ltree);
        postorder_r(curr->rtree);
        cout<<curr->data<<" ";
    }
}

void tree::inorder_i(tree* curr){
    node obj2;
    while(1){
        while(curr!=NULL){
            obj2.push(curr);
            curr=curr->ltree;
        }
        if(obj2.top!=NULL){
        curr=obj2.pop();
        cout<<curr->data<<" ";
        curr=curr->rtree;
        }
        else
            break;
    }
}

void tree::preorder_i(tree* curr){
    node obj3;
    while(1){
        while(curr!=NULL){
            cout<<curr->data<<" ";
            if(curr->rtree!=NULL){
                obj3.push(curr->rtree);
            
            }
            curr=curr->ltree;    
        }
        if(obj3.top!=NULL){
            curr=obj3.pop();
        }
        else{
            break;
        }
    }
}

int main(){
    tree a;
    char postfix[40];
    cout<<"enter the postfix ex.::";
    cin>>postfix;
    a.formtree(postfix);
    tree* curr=a.root;
    cout<<"\ninorder recursive::";
    a.inorder_r(curr);
    cout<<endl<<"preorder recursive::";
    a.preorder_r(curr);
    cout<<endl<<"postorder recursive::";
    a.postorder_r(curr);
    cout<<endl<<"inorder iterative::";
    a.inorder_i(curr);
    cout<<endl<<"preorder iterative::";
    a.preorder_i(curr);
}