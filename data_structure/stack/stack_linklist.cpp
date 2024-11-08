#include <iostream>

class stack_linklist
{
private:
  struct Node
  {
    int data;
    Node *next;
    Node(int data = 0) : data(data), next(nullptr) {}
  };
  Node *head;
  Node *top;

  // 其实正统的似乎不给这个top成员，所以后面的push应该是个头插法
  int size_;

public:
  stack_linklist(int size);
  ~stack_linklist();

  void push_back(int val)
  {
    auto node = new Node(val);
    auto p = head;
    while (p != top)
    {
      p = p->next;
    }
    p->next = node;
    top = node;
    size_++;
  }

  void push_without_top(int val)
  {
    Node *node = new Node();
    node->next = head->next;
    head->next = node;
    size_++;
  }

  void pop()
  {
    if (top == head)
    {
      throw "stack is empty";
    }
    auto p = head;
    while (p->next != top)
    {
      p = p->next;
    }
    p->next = nullptr;
    delete top;
    top = p;
    size_--;
  }

  void pop_without_top()
  {
    if (head->next == nullptr)
    {
      throw "stack is empty";
    }
    auto p = head->next;
    head->next = p->next;
    delete p;
    p = head->next;
    size_--;
  }

  void show()
  {
    auto p = head->next;
    while (p != nullptr)
    {
      std::cout << p->data << "  ";
      p = p->next;
    }
    std::cout << "\n";
  }

  bool empty()
  {
    if (top == head)
    {
      return true;
    }
    return false;
  }

  int size()
  {
    // auto count{0};
    return size_;
  }

  int get_top() const
  {
    return top->data;
  }

  int get_top_without_top() const
  {
    if (head->next == nullptr)
    {
      throw "stack is empty";
    }
    return head->next->data;
  }
};

stack_linklist::stack_linklist(int size = 0) : size_(size)
{
  head = new Node();
  top = head;
}

stack_linklist::~stack_linklist()
{
  auto p = head;
  while (p != nullptr)
  {
    head = head->next;
    delete p;
    p = head;
  }
}

int main()
{
  stack_linklist test;
  test.push_back(1);
  test.push_back(2);
  test.push_back(3);
  // test.pop();
  test.show();
  int size = test.size();
  std::cout << size << std::endl;
}
