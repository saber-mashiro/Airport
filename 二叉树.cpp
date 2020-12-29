#include <bits/stdc++.h>
using namespace std;
template <class T>
struct node
{
    T data;
    node<T> *left;
    node<T> *right;
    node<T> *father;
    node(T d) : data(d), left(NULL), right(NULL), father(NULL) {}
};
template <class T>
class binarytree
{
public:
    binarytree(int i);                                //构造函数
    node<T> *precreate();                             //前序创建二叉树并返回根的指针
    void preorder(node<T> *p);                        //前序遍历二叉树
    void inorder(node<T> *p);                         //中序遍历二叉树
    void postorder(node<T> *p);                       //后序遍历二叉树
    void levelorder(node<T> *p);                      //层序遍历二叉树
    node<T> *find(node<T> *p, T data);                //查找数据为data的节点
    void insert(node<T> *t, T data);                  //插入一个新节点作为t的左儿子，原来的左儿子变成新节点的左儿子
    void del(node<T> *t);                             //删除指定结点及其左右子树
    node<T> *getroot();                               //返回根的指针
    int getnum();                                     //返回二叉树中的节点数
    int level(node<T> *t, node<T> *p);                //在根为t的树中找到p的层数（根的层数为1）
    int height(node<T> *p);                           //返回二叉树的高度（叶节点高度定义为1）
    node<T> *LCA(node<T> *t, node<T> *q, node<T> *p); //返回两个结点最小共同祖先
    int maxpath(node<T> *t, int &cnt);                //求最大路径和,cnt为随意路径最大和，返回值为以根为起点的最大路径和
    node<T> *rebuild(char *post, char *in, int n);    //根据后序和中序重建二叉树，返回根结点指针（n为字符串长度）
    void clear(node<T> *p);                           //释放二叉树
private:
    node<T> *root;
    int num;
};
template <class T>
binarytree<T>::binarytree(int i)
{
    if (i == 1)
        root = precreate();
    num = 0;
}
template <class T>
node<T> *binarytree<T>::precreate()
{
    node<T> *p;
    T data;
    cin >> data;
    if (data == 0)
        return NULL;
    else
    {
        p = new node<T>(data);
        num++;
        p->left = precreate();
        p->right = precreate();
    }
    if (p->left != NULL)
    {
        p->left->father = p;
    }
    if (p->right != NULL)
    {
        p->right->father = p;
    }
    return p;
}
template <class T>
node<T> *binarytree<T>::getroot() { return root; }
template <class T>
int binarytree<T>::getnum() { return num; }
template <class T>
void binarytree<T>::preorder(node<T> *p)
{
    if (p == NULL)
        return;
    cout << p->data;
    preorder(p->left);
    preorder(p->right);
}
template <class T>
void binarytree<T>::inorder(node<T> *p)
{
    if (p == NULL)
        return;
    inorder(p->left);
    cout << p->data;
    inorder(p->right);
}
template <class T>
void binarytree<T>::postorder(node<T> *p)
{
    if (p == NULL)
        return;
    postorder(p->left);
    postorder(p->right);
    cout << p->data;
}
template <class T>
void binarytree<T>::levelorder(node<T> *p)
{
    queue<node<T> *> q;
    if (p)
    {
        q.push(p);
    }
    while (!q.empty())
    {
        node<T> *front = q.front();
        cout << front->data;
        q.pop();
        if (front->left)
        {
            q.push(front->left);
        }
        if (front->right)
            q.push(front->righit);
    }
}

template <class T>
node<T> *binarytree<T>::find(node<T> *p, T data)
{
    node<T> *t;
    node<T> *q;
    if (p == NULL || p->data == data)
        return p;
    t = find(p->left, data);
    if (t != NULL)
        return t;
    else
        return q = find(p->right, data);
}
template <class T>
void binarytree<T>::insert(node<T> *t, T data)
{
    if (t == NULL)
        return;
    node<T> *p = new node<T>(data);
    p->left = t->left;
    p->right = NULL;
    if (p->left != NULL)
        p->left->father = p;
    t->left = p;
}
template <class T>
void binarytree<T>::del(node<T> *t)
{
    if (t == NULL)
        return;
    if (t->father == NULL)
    {
        clear(t);
        return;
    }
    node<T> *p, *q;
    p = t;
    q = t->father;
    if (q)
    {
        if (q->left == p)
            q->left = NULL;
        if (q->right == p)
            q->right = NULL;
    }
    clear(p);
}
template <class T>
int binarytree<T>::height(node<T> *p)
{
    if (p)
    {
        int leftheight = height(p->left);
        int rightheight = height(p->right);
        return (leftheight > rightheight ? leftheight : rightheight) + 1;
    }
    else
    {
        return 0;
    }
}
template <class T>
int binarytree<T>::level(node<T> *t, node<T> *q)
{
    if (t == NULL)
        return 0;
    if (t == q)
        return 1;
    int leftlevel = level(t->left, q);
    int rightlevel = level(t->right, q);
    if (leftlevel || rightlevel)
        return (leftlevel > rightlevel ? leftlevel : rightlevel) + 1;
}

template <class T>
void binarytree<T>::clear(node<T> *p)
{
    if (p == NULL)
        return;
    clear(p->left);
    clear(p->right);
    delete p;
    p = NULL;
}
template <class T>
node<T> *binarytree<T>::LCA(node<T> *t, node<T> *p, node<T> *q)
{
    if (t == NULL)
        return NULL;
    if (t == p || t == q)
        return t;
    node<T> *leftlca = LCA(t->left, p, q);
    node<T> *rightlca = LCA(t->right, p, q);
    if (leftlca != NULL && rightlca != NULL)
        return t;
    else if (leftlca != NULL)
        return leftlca;
    else if (rightlca != NULL)
        return rightlca;
    else
        return NULL;
}
template <class T>
int binarytree<T>::maxpath(node<T> *t, int &cnt)
{
    if (t == NULL)
        return 0;
    int left = max(maxpath(t->left, cnt), 0);
    int right = max(maxpath(t->right, cnt), 0);
    cnt = max(cnt, left + right + t->data);
    return t->data + max(left, right);
}

template <class T>
node<T> *binarytree<T>::rebuild(char *post, char *in, int n)
{
    char key;
    int i;
    int k;
    int count = 0;
    if (n <= 0 || post == NULL || in == NULL)
        return NULL;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
            if (*(post + x) == *(in + y))
                count++;
    }
    if (count != n)
    {
        cout << "INVALID";
        exit(0);
    }
    key = *(post + n - 1);
    node<T> *b = new node<T>(key);
    for (i = 0; i < n; i++)
        if (*(in + i) == key)
            break;
    k = i;
    b->left = rebuild(post, in, k);
    b->right = rebuild(post + k, in + k + 1, n - k - 1);
    return b;
}
int main()
{
    binarytree<int> tree(1);
    node<int> *i = tree.getroot();
    int cnt = -100;
    tree.maxpath(i, cnt);
    cout << cnt;
}