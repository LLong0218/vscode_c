#include <iostream>

class mutual_linklist
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

public:
  // 构造函数
  mutual_linklist();
  // 析构函数
  ~mutual_linklist();
  // 头插法
  void insert_head(int val);
  // 尾插法
  void insert_tail(int val);
  // 删除
  void erase(int val);
  // 寻找
  bool find(int val);
  // 显示
  void show();
};

mutual_linklist::mutual_linklist()
{
  head = new Node();
}

mutual_linklist::~mutual_linklist()
{
  auto p = head;
  while (p != nullptr)
  {
    head = head->next;
    delete p;
    p = head;
  }
}

void mutual_linklist::insert_head(int val)
{
  auto node = new Node(val);
  node->next = head->next;
  if (head->next != nullptr)
  {
    head->next->pre = node;
  }
  head->next = node;
  node->pre = head;
}

void mutual_linklist::insert_tail(int val)
{
  auto p = head;
  auto node = new Node(val);
  while (p->next != nullptr)
  {
    p = p->next;
  }
  p->next = node;
  node->pre = p;
}

// 我这个版本没有删除内存，应该还是要用双指针吧应该
void mutual_linklist::erase(int val)
{
  auto p = head->next;
  while (p != nullptr)
  {
    if (p->data == val)
    {
      p->pre->next = p->next;
      if (p->next != nullptr)
      {
        p->next->pre = p->pre;
      }
      // 破案了，每次都用暂时的变量留一下就行
      auto temp = p->next;
      delete p;
      p = temp;
    }
    else
    {
      p = p->next;
    }
  }
}

void mutual_linklist::show()
{
  auto p = head->next;
  while (p != nullptr)
  {
    std::cout << p->data << "  ";
    p = p->next;
  }
  std::cout << std::endl;
}

bool mutual_linklist::find(int val)
{
  auto p = head->next;
  while (p != nullptr)
  {
    if (p->data == val)
    {
      return true;
    }
    p = p->next;
  }
  return false;
}

int main()
{
  mutual_linklist test;
  test.insert_head(5);
  test.insert_head(4);
  test.insert_tail(6);
  test.insert_tail(6);
  test.erase(6);
  test.show();
  if (test.find(6))
  {
    std::cout << "找到啦" << std::endl;
  }
  else
  {
    std::cout << "没找到哦" << std::endl;
  }
  return 0;
}
