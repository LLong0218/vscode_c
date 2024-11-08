#include <iostream>

class queue
{
private:
  int *m_queue;
  int first;
  int rear;
  int size_;
  int num_of_ele{0};

public:
  queue(int size = 10);
  ~queue();

  bool empty()
  {
    return first == rear;
  }

  bool full()
  {
    return (rear + 1) % size_ == first;
  }

  void expand(int new_cap)
  {
    int *temp = new int[new_cap];
    int i = 0;
    int j = first;
    while (j != rear)
    {
      temp[i] = m_queue[j];
      i++;
      j = (j + 1) % size_;
    }
    delete[] m_queue;
    m_queue = temp;
    size_ = new_cap;
    first = 0;
    rear = i;
    std::cout << "扩容了" << std::endl;
  }

  void push(int val)
  {
    if (full())
    {
      expand(2 * size_);
    }
    m_queue[rear] = val;
    rear = (rear + 1) % size_;
    num_of_ele++;
  }

  void pop()
  {
    if (!empty())
    {
      first = (first + 1) % size_;
    }
    else
    {
      throw "queue is empty";
    }
    num_of_ele--;
  }

  int get_first()
  {
    if (empty())
    {
      throw "queue is empty , no first element.";
    }
    else
      return m_queue[first];
  }

  int get_back()
  {
    if (empty())
    {
      throw "queue is empty , no rear element.";
    }
    else
      return m_queue[(rear - 1 + size_) % size_];
  }

  void show()
  {
    for (auto i = first; i != rear; i = (i + 1) % size_)
    {
      std::cout << m_queue[i] << "  ";
    }
    std::cout << "\n";
  }

  int numbers() const
  {
    return num_of_ele;
  }
};

queue::queue(int size) : size_(size)
//,first(nullptr),rear(nullptr)
{
  m_queue = new int[size_];
  rear = first = 0;
}

queue::~queue()
{
  delete[] m_queue;
  m_queue = nullptr;
}

int main()
{
  queue test;
  int arr[] = {12, 4, 56, 7, 89, 31, 53, 75, 66, 23, 12, 57, 77, 98};
  for (int v : arr)
  {
    test.push(v);
  }

  std::cout << test.get_first() << "\n";
  std::cout << test.get_back() << "\n";
  std::cout << test.numbers() << "\n";
}
