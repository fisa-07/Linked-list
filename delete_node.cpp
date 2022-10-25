// Deletion of any node 
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};

void insertATtail(node* &head,int d){
    node* temp=new node(d);
    node* last;
    if(head==NULL){      
        last=head=temp;
    }
    else{
        last->next=temp;
        last=temp;
    }
}
/* the for loop will continue until temp1 reaches to that node that we want to delete
and temp2 is helping pointer which is just before the temp1..temp2 works is to link the node of that node which is just 
behind the node of delete and to just above the node of delete NOTE-temp2 is called tailing pointer of temp1 */

void deleteNode(node* &head,int pos){
    if(pos==1){                           // delete first node or head node
       node* temp=head;
       head=head->next;
       cout<<temp->data<<" "<<"is deleted"<<endl;
       delete temp; 
    }
    else{                           // delete other nodes
        node* temp1=head;
        node* temp2=head;
        for(int i=1;i<pos;i++){     // here we take i<pos because i is already pointing to first node so it take pos-1 to reach desired node 
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=temp1->next;
        cout<<temp1->data<<" "<<"is deleted"<<endl;
        delete temp1;
    }
}

void display(node* p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    
}
int main(){
    node* head = NULL;
    insertATtail(head,4);
    insertATtail(head,2);
    insertATtail(head,7);
    insertATtail(head,9);
    insertATtail(head,6);
    cout<<"Before delete"<<endl;
    display(head);
    cout<<"Enter position you want to delete"<<endl;
    int pos;
    cin>>pos;
    if(pos>5){
        cout<<"Error";
        exit(1);
    }
    cout<<"After delete"<<endl;
    deleteNode(head,pos);
    display(head);  
    return 0;
}