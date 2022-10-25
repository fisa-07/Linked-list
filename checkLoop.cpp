// Check loop in list
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
void insertATtail(Node* &head,int data){
    Node* temp=new Node(data);
    if(head==NULL){
        head=temp;
        return ;
    }
    Node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=temp;
}
void display(Node* p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}
/*void makeitloop(Node* head){
    Node* fast=head;
    Node* slow=head;
    while(fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    fast->next->next=slow;
}*/
bool isloop(Node* head){
    Node* fast=head;
    Node* slow=head;
    while(fast->next!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        else{
            return false;
        }
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
int main(){
    Node* head=NULL;
    Node* t1;
    Node* t2;
    int data;
    int n=6;
    while(n--){
        cin>>data;
        insertATtail(head,data);
    }
    cout<<isloop(head);
    cout<<endl;
    t2=t1=head;
    t1=t1->next->next->next;
    t2=t2->next->next->next->next->next->next;
    t2=t1;
    cout<<isloop(head);
    return 0;
}