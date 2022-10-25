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

int max(Node *p)
{
    int m= INT_MIN;
    while(p!=0)
    {
        if(p->data>m)
        {
            m=p->data;
        }
            p=p->next;
    }

    return m;
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
    cout<<"Linked list is created"<<endl;
    cout<<"Max element is : "<<max(first);

    return 0;
}