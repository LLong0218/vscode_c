#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

class Array
{

    // 先写成员变量
private:
    size_t size_curr; // 目前的数组容量
    size_t size_max;  // 最大容量
    int *my_arr;      // 指向数组第一个数据的指针

    // 构造析构函数
public:
    Array(int size) : size_curr(0), size_max(size)
    {
        my_arr = new int[size_max];
    }

    ~Array()
    {
        delete[] my_arr;
        my_arr = nullptr;
    }

public:
    // 类方法
    void push_back(int val)
    {
        if (size_curr == size_max)
        {
            expand(2 * size_max);
        }
        my_arr[size_curr++] = val;
    }

    void pop_back()
    {
        if (size_curr == 0)
        {
            return;
        }
        size_curr--;
    }

    void insert(int pos, int val)
    {
        if (pos < 0 || pos > size_curr)
        {
            throw "invaild position";
        }
        if (size_curr == size_max)
        {
            expand(2 * size_max);
        }
        for (size_t i = size_curr - 1; i >= pos; i--)
        {
            my_arr[i + 1] = my_arr[i];
        }
        my_arr[pos] = val;
        size_curr++;
    }

    void erase(int pos)
    {
        if (size_curr == 0)
        {
            return;
        }
        for (size_t i = pos + 1; i < size_curr; i++)
        {
            my_arr[i - 1] = my_arr[i];
        }
        size_curr--;
    }

    int find(int val)
    {
        for (size_t i = 0; i < size_curr; i++)
        {
            if (my_arr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }

    void show() const
    {
        for (size_t i = 0; i < size_curr; i++)
        {
            cout << my_arr[i] << "  ";
        }
        cout << endl;
    }

    int size() const
    {
        return size_curr;
    }

    void reverse()
    {
        auto mid = size_curr / 2;
        auto pre = 0;
        auto last = size_curr - 1;
        while (pre < last)
        {
            int temp;
            temp = my_arr[pre];
            my_arr[pre] = my_arr[last];
            my_arr[last] = temp;
            pre++;
            last--;
        }
    }

private:
    void expand(int new_size)
    {
        int *p = new int[new_size];
        memcpy(p, my_arr, sizeof(int) * size_max);
        delete[] my_arr;
        my_arr = p;
        size_max = new_size;
    }
};

void reverse_char(char ch[], int size)
{
    auto head = ch;
    auto tail = ch + size - 1;
    while (head < tail)
    {
        auto temp = *head;
        *head = *tail;
        *tail = temp;
        head++;
        tail--;
    }
}

void odd_even_adjust(int arr[], int size)
{
    auto odd = arr;
    auto even = arr + size - 1;
    while (odd < even)
    {
        if (*even & 0x1 == 0)
        {
            if (*odd & 0x1 == 1)
            {
                odd++;
                even--;
            }
            else
                even--;
        }
        else
        {
            if (*odd & 0x1 == 1)
            {
                odd++;
            }
            else
            {
                auto temp = *even;
                *even = *odd;
                *odd = temp;
                odd++;
                even--;
            }
        }
    }
}
int main()
{
    // auto arr = Array(10);
    // srand(time(NULL));
    // for (size_t i = 0; i < arr.size(); i++)
    // {
    //     arr.push_back(rand() % 100);
    // }
    // arr.show();
    // arr.reverse();
    // arr.show();

    // char ch[] = "hello world";
    // reverse_char(ch, strlen(ch));
    // cout << ch << endl;

    int arr[10] = {0};
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
    }
    for (int v : arr)
    {
        cout << v << "  ";
    }
    cout << endl;
    odd_even_adjust(arr, 10);
    for (int v : arr)
    {
        cout << v << "  ";
    }
    cout << endl;
}