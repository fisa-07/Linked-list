// Insert at any position
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

void insertATtail(Node* &head,int d){
    Node* temp=new Node(d);
    Node* last;
    if(head==NULL){
        head=temp;
        last=head;
    }
    else{
        last->next=temp;
        last=temp;
    }
}

void display(Node* p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    
}

void insertATany(Node* &head,int data,int pos){
    if(pos==0){                                 // insert before head
        Node* temp=new Node(data);
        temp->next=head;
        head=temp;
        return;
    }
    if(pos==1){      // inser just after head
        Node* temp=new Node(data);
        temp->next=head->next;
        head->next=temp;
    }
    else{
        Node* temp=new Node(data);   // insert at any place
        Node* p=head;
        for(int i=1;i<pos;i++){
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
    }
}
int main(){
    Node* head = NULL;
    insertATtail(head,4);
    insertATtail(head,2);
    insertATtail(head,7);
    insertATtail(head,9);
    insertATtail(head,6);
    cout<<"Before insertion"<<endl;
    display(head);
    cout<<"position"<<endl;
    int pos;
    cin>>pos;
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;
    insertATany(head,data,pos);
    cout<<"After insertion"<<endl;
    display(head);
    return 0;
}