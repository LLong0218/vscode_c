#include <iostream>

class mutual_circle_linklist
{
private:
  struct Node
  {
    int data;
    Node *next;
    Node *pre;
    Node(int data = 0) : data(data), next(nullptr), pre(nullptr) {}
  };

  Node *head;
  Node *tail;

public:
  mutual_circle_linklist();
  ~mutual_circle_linklist();
  void insert_tail(int val);
  void insert_head(int val);
  void erase(int val);
  void show();
  void find(int val);
};

mutual_circle_linklist::mutual_circle_linklist()
{
  head = new Node();
  tail = head;
  // 其实我是觉得这两行没必要写，但是确实显示表示了这个数据结构的逻辑
  tail->next = head;
  head->pre = tail;
}

mutual_circle_linklist::~mutual_circle_linklist()
{
  auto p = head->next;
  while (p != head)
  {
    head->next = p->next;
    p->next->pre = head;
    delete p;
    p = head->next;
  }
  delete head;
}

void mutual_circle_linklist::insert_head(int val)
{
  auto node = new Node(val);
  if (head->next == head)
  {

    head->next = node;
    node->pre = head;
    node->next = head;
    head->pre = node;
    tail = node;
  }
  else
  {
    node->next = head->next;
    head->next->pre = node;
    head->next = node;
    node->pre = head;
  }
}
void mutual_circle_linklist::insert_tail(int val)
{
  auto node = new Node(val);
  {
    tail->next = node;
    node->pre = tail;
    node->next = head;
    tail = node;
    head->pre = tail;
  }
}

void mutual_circle_linklist::show()
{
  auto p = head->next;
  while (p != head)
  {
    std::cout << p->data << "  ";
    p = p->next;
  }
  std::cout << std::endl;
}

int main()
{
  mutual_circle_linklist test;
  test.insert_head(6);
  test.insert_head(4);
  test.insert_tail(7);
  test.show();
}
