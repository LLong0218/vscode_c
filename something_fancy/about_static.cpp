#include <iostream>
using namespace std;

class Apple
{

public:
  static int i;

  Apple() {

  };
};

// static静态成员必须类外分配内存空间和定义
int Apple::i = 0;

int main()
{
  Apple a1;
  Apple a2;
  a1.i = 2;
  a2.i = 3;
  cout << a1.i << " " << a2.i << endl;

  return 0;
}
