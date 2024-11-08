#include <iostream>
using namespace std;

class Circlelink
{
public:
  Circlelink()
  {
    head = new Node();
    tail = head;
    tail->next = head;
  }
  ~Circlelink()
  {
    auto p = head->next;
    while (p != head)
    {
      head->next = p->next;
      delete p;
      p = head->next;
    }
    delete head;
  }

  void show() const
  {
    auto p = head->next;

    while (p != head)
    {
      cout << p->data << " ";
      p = p->next;
    }
  }

  void insert_tail(const int val)
  {
    auto node = new Node(val);
    tail->next = node;
    tail = node;
    node->next = head;
  }

  void insert_head(const int val)
  {
    auto node = new Node(val);
    node->next = head->next;
    head->next = node;
    if (node->next == head)
    {
      tail = node;
    }
  }

  void erase(int val)
  {
    auto p = head;
    auto q = head->next;
    while (q != head)
    {
      if (q->data == val)
      {
        // if (q == tail)
        // {
        //   tail = p;
        //   p->next = head;
        //   delete q;
        //   q = head;
        // }
        // else
        // {
        //   p->next = q->next;
        //   delete q;
        //   q = p->next;
        // }
        p->next = q->next;
        delete q;
        if (q == tail)
        {
          tail = p;
        }
        q = p->next;
      }
      else
      {
        p = p->next;
        q = q->next;
      }
    }
  }

  bool find(int val)
  {
    auto p = head;
    while (p != head)
    {
      if (p->data == val)
      {
        return true;
      }
    }
    return false;
  }

private:
  struct Node
  {
    Node(int data = 0) : data(data), next(nullptr) {}
    int data;
    Node *next;
  };

  Node *head;
  Node *tail;
};

int main()
{
  Circlelink test;
  test.insert_tail(1);
  test.insert_tail(2);
  test.insert_tail(2);
  test.insert_head(0);
  test.insert_head(1);
  test.erase(2);
  test.erase(1);
  test.show();
  test.find(0);
}