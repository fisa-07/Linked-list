// Remove dublicates from sorted linked list 
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=0;
    }
};

void insertAtTail(Node* &head,int data){
    Node* temp=new Node(data);
    Node* last;
    if(head==0){
        head=temp;
        last=head;
    }
    else{
        last->next=temp;
        last=temp;
    }
}

void removeDublicate(Node* head){
    Node* p=head;
    Node* q=head->next;
    while(q!=0){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }  
}
void display(Node* p){
    while(p!=0){
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main(){
    Node* head=0;
    insertAtTail(head,5);
    insertAtTail(head,5);
    insertAtTail(head,7);
    insertAtTail(head,8);
    insertAtTail(head,9);
    insertAtTail(head,9);
    insertAtTail(head,9);
    cout<<"Before removing"<<endl;
    display(head);
    cout<<endl;
    cout<<"After removing"<<endl;
    removeDublicate(head);
    display(head);
    return 0;  
}