// Merge two sorted linked list
#include<iostream>
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

Node* insertAtTail(Node* head,int data){
    Node* temp=new Node(data);
    if(head==NULL){
        head=temp;
        return head;
    }
    Node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=temp;
    return head;
}

void display(Node* p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}

Node* merge(Node* head1,Node* head2){
    Node* first=NULL;
    Node* last=NULL;
    while(head1!=NULL&&head2!=NULL){
        if(head1->data<=head2->data){
            if(first==NULL&&last==NULL){   
                first=last=head1;
                head1=head1->next;
            }
            else{
                last->next=head1;
                last=head1;
                head1=head1->next;
            }   
        }
        else{
            if(first==NULL&&last==NULL){
                first=last=head2;
                head2=head2->next;
            }
            else{
                last->next=head2;
                last=head2;
                head2=head2->next;
            }
        }
    }
    if(head1!=NULL){
        last->next=head1;
    }
    else{
        last->next=head2;
    }
    return first;
}
int main(){
    Node* head1=NULL;
    Node* head2=NULL;
    head1=insertAtTail(head1,1);
    head1=insertAtTail(head1,2);
    head1=insertAtTail(head1,3);
    head2=insertAtTail(head2,4);
    head2=insertAtTail(head2,5);
    head2=insertAtTail(head2,6);
    display(merge(head1,head2));
    return 0;  
}