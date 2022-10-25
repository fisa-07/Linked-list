#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=0;
    }
};

void insertAtTail(node* &head,int data){
    node* temp=new node(data);
    node* last;
    if(head==0){
        head=temp;
        last=head;
        return;
    }
    else{
        last->next=temp;
        last=temp;
    }
}

void display(node* p){
    while(p!=0){
        cout<<p->data<<" ";
        p=p->next;
    }
}

void reverselist(node* &head){
    node* p=0;
    node* c=head;
    if(head==0){
        return;
    }
    node* n;
    while(c!=0){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    head=p;
}
int main(){
    node* head=0;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    reverselist(head);
    cout<<"After reversing"<<endl;
    display(head);
    
    return 0;
}