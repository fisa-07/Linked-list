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
int count(struct Node *p)
{
    int c=0;
    while (p != 0)
    {
        c++;
        p = p->next;  // move pointer to next node
    }
    return c;
}

int main()
{
    int a[] = {4, 2, 6, 7, 3};
    create(a, 5);
    cout << count(first);

    return 0;
}