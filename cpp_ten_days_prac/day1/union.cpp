// 联合体学习
#include <iostream>
using namespace std;

union myun
{
  struct
  {
    int x;
    int y;
    int z;
  } u;
  int k;
} a;

int main()
{
  a.u.x = 4;
  a.u.y = 5;
  a.u.z = 6;
  a.k = 0;
  cout << a.u.x << endl;
  cout << a.u.y << endl;
  cout << a.u.z << endl;
  cout << a.k << endl;
}
