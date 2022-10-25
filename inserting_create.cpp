#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
// this function always add node to end 
void insertATtail(Node* &head,int d){   /* take head pointer as reference not by value because we have
to change head if head is NULL*/
    Node* n=new Node(d);
    //Node* temp;
    if(head==NULL){    // if there is no node then head will store n as first node
        head=n;
        //temp=head;
        return;
    }
    Node* temp=head;   // here temp is for accsessing first node that is head node 
    while(temp->next!= NULL){   // traverse to last node 
        temp=temp->next;
    }
    temp->next = n;    // add n as new node
    /*else{
        temp->next=n;
        temp=n;
    }*/
}

void display(Node* p){
    cout<<"Elements are"<<endl;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    
}

int main(){
    Node* head=NULL;
    insertATtail(head,6);
    insertATtail(head,4);
    insertATtail(head,9);
    display(head);

    return 0;
}