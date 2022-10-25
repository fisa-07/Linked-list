// searching data in linked list 
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *first = NULL;

void create(int a[], int n)
{
    Node *temp, *last;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = a[i];
        temp->next = NULL;
        last->next = temp; // linking node
        last = temp;
    }
}

int  search(int no,Node *p)
{
    int c=0;
    while(p!=NULL)
    {
        c++;
        if(no==p->data)
        {
            return c;
            
        }
        p=p->next;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    create(a,n);
    int no;
    cin >> no;
    cout << search(no,first);
    
    return 0;
}