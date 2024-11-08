#include <iostream>
#include <stdlib.h>

using namespace std;
struct Node
{
  int data;
  Node *next;
  Node(int data = 0) : data(data), next(nullptr) {}
};

namespace my
{
  void Joseph(Node *head, int k, int m)
  {
    Node *p = head;
    Node *q = head;
    while (q->next != head)
    {
      q = q->next;
    }
    for (auto i = 1; i < k; i++)
    {
      p = p->next;
      q = q->next;
    }
    while (p != q)
    {
      for (auto i = 1; i < m; i++)
      {
        p = p->next;
        q = q->next;
      }
      cout << p->data << "  ";
      q->next = p->next;
      delete p;
      p = q->next;
    }
    cout << q->data;
    delete p;
    q = nullptr;
    p = nullptr;
  }

}

void Joseph(Node *head, int k, int m)
{
  Node *p = head;
  Node *q = head;
  while (q->next != head)
  {
    q = q->next;
  }

  for (int i = 1; i < k; i++)
  {
    q = p;
    p = p->next;
  }
  do
  {
    for (int i = 1; i < m; i++)
    {
      q = p;
      p = p->next;
    }
    cout << p->data << "  ";
    q->next = p->next;
    delete p;
    p = q->next;
  } while (p != q);

  if (p == q)
  {
    cout << p->data << endl;
    delete p;
  }
}

int main()
{
  Node *head = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);
  Node *n6 = new Node(6);
  Node *n7 = new Node(7);
  Node *n8 = new Node(8);

  head->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;
  n6->next = n7;
  n7->next = n8;
  n8->next = head;

  my::Joseph(head, 1, 3);
}
