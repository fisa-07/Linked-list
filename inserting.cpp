// Finding max element in linked list
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

}*first=NULL;

void create(int a[],int n)
{
    Node *temp,*last;
    temp=new Node;
    temp->data=a[0];
    temp->next=NULL;
    first=temp;
    last=temp;

    for(int i=1;i<n;i++)
    {
        temp=new Node;
        temp->data=a[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }

}

void display(struct Node *p)
{
    while (p != 0)
    {
        cout << p->data << " ";
        p = p->next;  // move pointer to next node
    }
}

void insert(Node *p,int value,int pos)
{
    Node *temp;
    temp=new Node;
    temp->data=value;
    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    temp->next=p->next;
    p->next=temp;  
}

int main()
{
    int n;
    cout<<"No of elements you want to enter : ";
    cin>>n;
    int a[n];
    cout<<"Enter elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    create(a,n);
    cout<<"Before Insertion : ";
    display(first);
    cout<<endl;
    int value, pos;
    cout<<"Enter vlaue and posintion for insertion : ";
    cin>>value>>pos;
    insert(first,value,pos);
    cout<<"After insertion : ";
    display(first);
    
    return 0;
}