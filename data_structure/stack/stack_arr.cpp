#include <iostream>

class stack_arr
{
private:
  // int data;
  int top;
  int *stack_array;
  int m_size;

public:
  stack_arr(int size);
  ~stack_arr();
  void push_back(int val);
  void pop();
  void show();
  int size();
  bool empty();
  void expand(int size);
  void return_top();
};

stack_arr::stack_arr(int size = 10) : m_size(size), top(0)
{
  stack_array = new int[size];
  top = 0;
}

stack_arr::~stack_arr()
{
  delete[] stack_array;
  stack_array = nullptr;
}

void stack_arr::push_back(int val)
{
  if (top == m_size)
  {
    std::cout << "满了，现在扩容" << std::endl;
    expand(2 * m_size);
  }
  stack_array[top++] = val;
}

void stack_arr::pop()
{
  if (top == 0)
  {
    throw "stack is empty";
  }
  top--;
}

int stack_arr::size()
{
  return m_size;
}

void stack_arr::show()
{
  for (auto i = 0; i < top; i++)
  {
    std::cout << stack_array[i] << "  ";
  }
  std::cout << std::endl;
}

bool stack_arr::empty()
{
  if (top == 0)
  {
    return true;
  }
  return false;
}

void stack_arr::expand(int size)
{
  auto new_stack = new int[size];
  memcpy(new_stack, stack_array, sizeof(int) * top);
  m_size = size;
  delete[] stack_array;
  stack_array = new_stack;
  std::cout << "已经扩容了" << std::endl;
}

void stack_arr::return_top()
{
  std::cout << stack_array[top - 1] << " is the top element of this stack." << std::endl;
}

int main()
{
  stack_arr test;
  // test.push_back(4);
  // test.push_back(5);
  // test.pop();
  // test.push_back(6);
  for (auto i = 0; i < 20; i++)
  {
    test.push_back(i);
  }
  test.show();
  std::cout << test.size() << std::endl;
  test.return_top();
}