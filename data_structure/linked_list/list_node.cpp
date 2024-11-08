#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// 结点结构
struct Node
{
    int data;
    Node *next;

    Node(int data = 0) : data(data), next(nullptr) {}
};

// 链表结构
class Clink
{
public:
    Clink()
    {
        head = new Node();
    }
    ~Clink()
    {
        Node *p = head;
        while (p != nullptr)
        {
            head = head->next;
            delete p;
            p = head;
        }
    }

public:
    void insert_head(int val)
    {
        auto p = new Node(val);
        p->next = head->next;
        head->next = p;
    }

    void insert_tail(int val)
    {
        auto p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        auto node = new Node(val);
        p->next = node;
    }

    void Show()
    {
        auto p = head->next;
        while (p != nullptr)
        {
            std::cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void search(int val)
    {
        int count = 1;
        auto p = head->next;
        while (p != nullptr)
        {
            if (p->data == val)
            {
                cout << "找到了,在第" << count << "位" << endl;
                break;
            }
            else
            {
                count++;
                p = p->next;
            }
            if (count == 11)
            {
                cout << "没找到" << endl;
            }
        }
    }

    void erase(int val)
    {

        auto q = head;
        auto p = head->next;
        while (p != nullptr)
        {
            if (p->data == val)
            {
                q->next = p->next;
                delete p;
                p = q->next;
            }
            else
            {
                q = p;
                p = p->next;
            }
        }
    }

    // 合并链表
    void Mergetwolists(Clink &link1, Clink &link2)
    {
        auto last = link1.head;
        auto p = link1.head->next;
        auto q = link2.head->next;
        link2.head = nullptr;
        while (p != nullptr && q != nullptr)
        {
            if (p->data > q->data)
            {
                last->next = q;
                q = q->next;
                last = last->next;
            }
            else
            {
                last->next = p;
                p = p->next;
                last = last->next;
            }
        }
        if (p == nullptr)
        {
            last->next = q;
        }
        else
        {
            last->next = p;
        }
    }

    // 逆转链表
    void Reverselist()
    {
        auto p = head->next;
        head->next = nullptr;
        if (p == nullptr)
        {
            return;
        }
        while (p != nullptr)
        {
            auto q = p->next;
            p->next = head->next;
            head->next = p;
            p = q;
        }
    }

    void find_index_x(int k, int data = 0)
    {
        auto p = head;
        auto q = head;
        for (auto i = 0; i < k; i++)
        {
            p = p->next;
        }
        while (p != nullptr)
        {
            p = p->next;
            q = q->next;
        }
        data = q->data;
        cout << "倒数第" << k << "个元素的数据是" << data << endl;
    }

private:
    Node *head;
};

int main()
{
    Clink link_1, link_2;
    auto arr = {1, 14, 21, 54, 61, 72};
    auto arr2 = {2, 11, 32, 44, 51};
    for (auto &v : arr)
    {
        link_1.insert_tail(v);
    }
    for (auto &v : arr2)
    {
        link_2.insert_tail(v);
    }

    // link_1.find_index_x(2);
    // link_1.Reverselist();
    link_1.Mergetwolists(link_1, link_2);

    link_1.Show();
    return 0;
}