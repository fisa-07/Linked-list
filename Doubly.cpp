#include<iostream>
using namespace std;
class Node
{
public:
          Node* prev;
          int data;
          Node* next;
};
Node* Create(int n,Node* head)
{
          Node* temp = new Node;
          temp->prev =NULL;
          temp->data = n;
          temp->next =NULL;
          Node* p = head;
          if(p==NULL)
          {
                    head = temp;
                   return head;
          }
          while(p->next!=NULL)
          {
                    p = p->next;
          }
          p->next = temp;
          temp->prev = p;
          return head;
}
void Display(Node* head)
{
          while(head!=NULL)
          {
                    cout<<head ->data<<" ";
                    head =head->next;
          }
          cout<<endl;
}
void reverseDisplay(Node* head)
{
          while(head->next!=NULL)
          {
                    head = head->next;
          }
          while(head!=NULL)
          {
                    cout<<head->data<<" ";
                    head = head->prev;
          }
          cout<<endl;
}
Node* inserting(Node* head,int pos,int value)
{
    Node* temp = new Node;
    temp->data = value;
    // add at beggening
    if(pos == 0)
    {
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
        head = temp;
        return head;
    }
    Node* p;
    p =head;
    // add at any position
    for(int i=0;i<pos-1;i++)
    {
        p = p->next; 
    }
    temp->prev = p;
    temp->next = p->next;
    if(p->next!=NULL)  // checking is it last node then p->next is NULL and NULL->prev has no
                      // meaning and give error
    {
        p->next->prev = temp;
    }
    p->next = temp;
    return head;
}
/* Here we take two pointer p and q initially p is ponting to head and q is one above of it 
and for storing address of before p node we take l so that when p become NULL after revering all node then we refer 
last node by l and pass to head */
Node* reverselist(Node* head) 
{
    Node* p = head;
    Node* q = head->next;
    Node* l;
     while (p!=NULL) {
       p->next = p->prev;
       p->prev = q;
       l = p->next;
       p=q;
       if(q)
       q = q->next;
   }
   return l->prev;
}
int main()
{
          Node* head = NULL;
          cout<<"1. Create Node"<<endl;
          cout<<"2. Display"<<endl;
          cout<<"3. Display Reverse"<<endl;
          cout<<"4. Inserting"<<endl;
          cout<<"5. Revese Node"<<endl;
          int flag = 1;
          int ch;
          while(flag)
          {
                   cin>>ch;
                   switch(ch)
                   {
                   case 1:
                    int n;
                    cout<<"Enter Element ";
                    cin>>n;
                    head = Create(n,head);
                    break;
                   case 2:
                    Display(head);
                    break;
                   case 3:
                    reverseDisplay(head);
                    break;
                   case 4:
                    int value,pos;
                    cout<<"Enter value and position ";
                    cin>>value>>pos;
                    head = inserting(head,pos,value);
                    break;
                   case 5:
                    head = reverselist(head);
                    break;
                   default :
                    exit(-1);
                   }
          }

}
