#include <bits/stdc++.h>
using namespace std;
template <class T>
struct node
{
    T data;
    node<T> *next;
    node(T d) : data(d), next(NULL) {}
};
template <class T>
class stack1
{
public:
    stack1();
    void push(T data);
    T pop();
    T peak();
    int length();
    void clear();

private:
    node<T> *head;
    int len;
};
template <class T>
stack1<T>::stack1()
{
    head = new node<T>(0);
    len = 0;
}
template <class T>
void stack1<T>::push(T data)
{
    node<T> *p = new node<T>(data);
    p->next = head->next;
    head->next = p;
    len++;
}
template <class T>
T stack1<T>::pop()
{
    node<T> *p = head->next;
    T m = p->data;
    head->next = p->next;
    delete p;
    len--;
    return m;
}
template <class T>
T stack1<T>::peak()
{

    node<T> *p = head->next;
    return p->data;
}

template <class T>
int stack1<T>::length() { return len; }
template <class T>
void stack1<T>::clear()
{
    node<T> *p = head;
    while (p)
    {
        node<T> *q = p->next;
        delete p;
        p = q;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}