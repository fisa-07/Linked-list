// check list are same or not
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};
Node* insertATtail(Node* head,int data){
    Node* temp = new Node(data);
    Node* p=head;
    if(head==NULL){
        head=temp;
        return head;
    }
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=temp;
    return head;

}
void isSame(Node* p1,Node* p2){
    int count=0;
    int len=0;
    while(p1!=0&&p2!=0){
    if(p1->data==p2->data){
        count++;
    }
    p1=p1->next;
    p2=p2->next;
    len++;
    }
    if(len==count){
        cout<<"Same";
    }
    else{
        cout<<"Not same";
    }
}
int main(){
    Node* head1 = NULL;
    Node* head2=NULL;
    head1=insertATtail(head1,4);
    head1=insertATtail(head1,8);
    head1=insertATtail(head1,11);
    head2=insertATtail(head2,4);
    head2=insertATtail(head2,8);
    head2=insertATtail(head2,11);
    head2=insertATtail(head2,9);
    isSame(head2,head1);
    return 0;

}