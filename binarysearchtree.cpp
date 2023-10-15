#include <iostream>
using namespace std;

class tree{
    int data;
    tree* lchild;
    tree* rchild;
    public :
    tree(){
        lchild=NULL;
        rchild=NULL;
    }
    tree* root=NULL;
    tree* curr=NULL;
    tree* parent=NULL;
    tree* create(int );
    void insert(int);
    void search(int);
    void deletion(int);
};

void tree::insert(int a){
    tree* newtree=new tree();
    tree* curr=root;
    tree* parent=curr;
    newtree->data=a;
    if(root==NULL){
        root=newtree;
    }
    else{
        while(curr!=NULL){
            if(curr->data>=newtree->data){
                parent=curr;
                curr=curr->lchild;
            }
            else{
                parent=curr;
                curr=curr->rchild;
            }
        }
        if(parent->data>=newtree->data){
            parent->lchild=newtree;
        }
        else{
            parent->rchild=newtree;
        }

    }
}

void tree::search(int a){
    int key=a;
    curr=root;
    while(curr!=NULL){
        if(curr->data==key){
            cout<<"element found\n";
            break;
        }
        else if(curr->data>key){
            parent=curr;
            curr=curr->lchild;
        }
        else if(curr->data<key){
            parent=curr;
            curr=curr->rchild;
        }
    }if(curr==NULL){
        cout<<"element not found";
    }
}

int main(){
    tree obj;
    int key;
    int n;
    cout<<"how many elements you want to enter::";
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cout<<"element"<<i+1<<": ";
        cin>>temp;
        obj.insert(temp);
    }
    cout<<"enter the number to search::";
    cin>>key;
    obj.search(key);
    cout<<"enter the number to search::";
    cin>>key;
    obj.search(key);

}