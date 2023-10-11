#include<iostream>
#include<string.h>
using namespace std;

struct Student {
    string name;
    int roll;
    float gpa;
};


void swap(struct Student s[],int i,int j){
    struct Student temp=s[i];
    s[i]=s[j];
    s[j]=temp;
}

void accept (struct Student s[],int n){
    for(int i=0;i<n;i++)
    {

        cout<<"enter your name:";
        cin>>s[i].name;
        cout<<"enter your roll no.:";
        cin>>s[i].roll;
        cout<<"enter your gpa:";
        cin>>s[i].gpa;
        cout<<endl;
    }
        
}

void display(struct Student s[],int n)
{
    for (int i=0;i<n;i++){
        cout<<s[i].name<<"\t"<<s[i].roll<<"\t"<<s[i].gpa<<endl;
    }
}


void search(struct Student s[],float mygpa,int n)
{
    for(int i=0;i<n;i++)
    {
        if(s[i].gpa==mygpa)
        {
            cout<<i<<s[i].name<<"\t"<<s[i].roll<<"\t"<<s[i].gpa<<endl;
        }
        
        
    }

}

void bubblesort(struct Student s[],int n)
{
    for (int i=0;i<n;i++)
    {
        int flag;
        for (int j=0 ; j<n-i-1 ; j++){
            flag=0;
            if (s[j].gpa>s[j+1].gpa)
            {
                struct Student temp= s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
                flag=1;
            }
        }if (flag==1)
        {
            break;
        }
    }cout<<"sorted data is\n";
    for (int i=0;i<n;i++){
        cout<<s[i].name<<"\t"<<s[i].roll<<"\t"<<s[i].gpa<<endl;
    }

}
void insertionsort(struct Student s[], int n) {
    for (int i = 1; i < n; i++) {
        struct Student temp = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].name > temp.name) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = temp;
    }
}

void binarySearch(struct Student s[],int n, string myName)
{
    int low=0,flag=0;
    int high = n;
    int mid;

    while(low<=high){
        mid = (low+high)/2;
 
        if(s[mid].name==myName){
            flag=1;
            break;
        }
        else if(s[mid].name<myName){
            low =mid+1;
        }
        else{
            high=mid-1; 
        }
    }if(flag==1){
        cout<<s[mid].name<<"  "<<s[mid].gpa<<"  "<<s[mid].roll<<endl;
    }
    else{
        cout<<"entered name is not available\n";
    }
}


//partition function for quicksort
int partition(struct Student s[],int l ,int r){
    int pivot=s[r].roll;
    int i=l-1;

    for(int j=1;j<r;j++){
        if(s[j].roll<pivot){
            i++;
            struct Student temp=s[i];
            s[i]=s[j];
            s[j]=temp;
        }
    }
    struct Student temp=s[i+1];
    s[i+1]=s[r];
    s[r]=temp;
    return i+1;
}


void quicksort(struct Student s[], int l,int r){
    if(l<r){
        int pivot= partition(s,l,r);
        quicksort(s,l,pivot-1);
        quicksort(s,pivot+1,r);

    }
}




int main(){
    int n,p;
    char q;
    float mygpa;
    string myName;
    cout <<"enter the no. of student::";
    cin>>n;
    struct Student s[n];
    do{
        cout<<"enter what you want to do:\n 1:accept\n 2:display\n 3:search gpa\n 4:sort by gpa\n 5:sort by name\n 6:find by name\n 7:sort by roll\n\n";
        cin>>p;
        switch(p){
            case 1:
            accept(s,n);
            break;
            case 2:
            display(s,n);
            break;
            case 3:
            cout<<"enter gpa you want to search::  ";
            cin>>mygpa;
            search(s,mygpa,n);
            break;
            case 4:
            bubblesort(s,n);
            break;
            case 5:
            insertionsort(s,n);
            display(s,n);
            break;
            case 6:
            cout<<"enter the name you want to search::  ";
            cin>>myName;
            insertionsort(s,n);
            binarySearch(s,n,myName);
            break;
            case 7:
            quicksort(s,0,n-1);
            display(s,n);
            break;
            default:
            cout<<"enter valid no.\n";
        }cout<<"do you want to continue the loop(y/n)";
        cin>>q;
    }while(q=='y');
}