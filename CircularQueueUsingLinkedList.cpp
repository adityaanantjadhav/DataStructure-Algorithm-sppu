#include<iostream>
using namespace std;

class circleq{
    int data;
    circleq* next;
    public:
    circleq(int data){
        this->data=data;
        next=NULL;
    }
    static circleq* front;
    static circleq* rear;
    static void enqueue(int);
    static void dequeue();
    static void display();

};

circleq* circleq::front=NULL;
circleq* circleq::rear=NULL;

void circleq::enqueue(int data){
    circleq* newnode= new circleq(data);
    if(front==NULL){
        front=newnode;
    }
    else{
        rear->next=newnode;
    }
    newnode->next=front;
    rear=newnode;
    cout<<data<<" element is entered\n";
}

void circleq::dequeue(){
    if(front==NULL){
        cout<<"queue is empty\n";
        return;
    }
    cout<<front->data<<" is dequeued\n";

    if(front==rear){ 
        rear=NULL;
        front=NULL;
        return;
    }

    front=front->next;
    rear->next=front;
}

void circleq::display(){
    circleq* curr=front;
    while(curr!=rear){
        cout<<curr->data<<" -> ";
        curr=curr->next;
    }cout<<curr->data<<endl;
}
int main(){
    int opt;
    char choice;
    int k=0;
    do{
        cout<<"enter what to do:: 1-enqueue 2-dequeue 3-display ::";
        cin>>opt;
        switch(opt){
            case 1:
                int n,info;
                k=0;
                cout<<"enter no. of enqueues you want to do::";
                cin>>n;
                while(k<n){
                    cout<<"enqueue no."<<k+1<<"::";
                    cin>>info;
                    circleq::enqueue(info);
                    k++;
                }
                break;
            case 2:
                circleq::dequeue();
                break;
            case 3:
                circleq::display();
                break;
            default:
                cout<<"enter valid no \n";
        }
        cout<<"do you want to continue(y/n)::";
        cin>>choice;
    }while(choice=='y' || choice=='Y');
}
