// sum of all nodes data
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
int add(Node *p)
{
    int sum = 0;
    while (p != 0)
    {
        sum = sum + p->data;
        p = p->next; // moving pointer to next node
    }
    return sum;
}

int count(struct Node *p)
{
    int c = 0;
    while (p != 0)
    {
        c++;
        p = p->next; // move pointer to next node
    }
    return c;
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
    create(a, n);
    cout << count(first) << endl;
    cout << add(first) << endl;

    return 0;
}