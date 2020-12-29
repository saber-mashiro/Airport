#include <bits/stdc++.h>
using namespace std;
template <class T>
struct node
{
    T data;
    node<T> *next;
    node<T> *front;
    node(T d) : data(d), next(NULL) {}
};
template <class T>
class myqueue
{
public:
    myqueue();
    void push(T data);
    T pop();
    T peak();
    int length();
    void clear();

private:
    node<T> *head;
    node<T> *tail;
    int len;
};
template <class T>
myqueue<T>::myqueue()
{
    head = new node<T>(0);
    tail = new node<T>(0);
    head->next = tail;
    tail->front = head;
    len = 0;
}
template <class T>
void myqueue<T>::push(T data)
{
    node<T> *p = new node<T>(data);
    p->front = tail->front;
    p->next = tail;
    tail->front = p;
    p->front->next = p;
    len++;
}
template <class T>
T myqueue<T>::pop()
{
    node<T> *p = head->next;
    T m = p->data;
    head->next = p->next;
    p->next->front = head;
    delete p;
    len--;
    return m;
}
template <class T>
T myqueue<T>::peak()
{
    node<T> *p = head->next;
    return p->data;
}
template <class T>
int myqueue<T>::length() { return len; }
template <class T>
void myqueue<T>::clear()
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
    int n;
    cin >> n;
    int m;
    myqueue<int> que;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        que.push(m);
    }
    while (que.length() != 0)
    {
        int p = que.pop();
        cout << p << ' ';
    }
}
