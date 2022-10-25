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
    Node* temp=new Node(d);
    Node* last;
    if(head==NULL){    // if there is no node then head will store n as first node
        head=temp;
        last=head;
        return;
    }
    else{
        last->next=temp;  // here last store the last node and from this we can link new node to last
        last=temp;
    }
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