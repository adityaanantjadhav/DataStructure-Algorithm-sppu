#include <iostream>
using namespace std;

void swap(int i,int j,int arr[]){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void maxheapify(int n,int arr[],int i){
    int l=2*i+1;
    int r=2*i+2;
    int large=i;
    if(l<n && arr[i]<arr[l]){
        large=l;
    }
    if(r<n && arr[large]<arr[r]){
        large=r;
    }
    if(large!=i){
        swap(i,large,arr);
        maxheapify(n,arr,large);
    }
}

void heapsort(int n,int arr[]){
    for(int p=n/2-1;p>=0;p--){
        maxheapify(n,arr,p);
    }
    for(int k=0;k<n;k++){
        cout<<arr[k]<<"  ";
    }
    for(int q=n-1;q>0;q--){
        swap(0,q,arr);
        maxheapify(q,arr,0);
    }
}

int main(){
    int n;
    cout<<"enter the no. of elements::";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of array::\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"the elements you entered are::";
    heapsort(n,arr);
    cout<<"\nsorted elements are::";
    for(int k=0;k<n;k++){
        cout<<arr[k]<<"  ";
    }
}