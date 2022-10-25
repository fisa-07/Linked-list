// Using recursion display linked list
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int a[], int n)
{
    struct Node *last, *temp;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = a[i];
        temp->next = NULL;
        last->next = temp; //linking first node with 2nd and similerly other link with each other
        last = temp;
    }
}

void display(struct Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        display(p->next);  // move pointer to next node
    }
}

int main()
{
    int a[] = {4, 2, 6, 7, 3};
    create(a, 5);
    display(first);

    return 0;
}