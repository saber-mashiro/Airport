#include <bits/stdc++.h>
using namespace std;
string sda[30];
int sdas = 0;
struct node
{
    char data;
    int weight;
    string hfmstring;
    node *left;
    node *right;
    node *father;
};
class hfmtree
{
public:
    hfmtree();
    int nodecreat(string str, node a[]);
    void mysort(node a[]);
    node *hfmcreate(node a[]);
    void preorder(node *p);
    void setstring(node *p, char data);
    node *find(node *p, char data);
    int len() { return length; }
    void unzip(node *p, string a);
    void clear(node *p);

private:
    int num;
    int length;
};

hfmtree::hfmtree()
{
    num = 0;
    length = 0;
}
int hfmtree::nodecreat(string str, node a[])
{
    for (int i = 0; i < 30; i++)
    {
        a[i].weight = 0;
    }
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        int judge = 0;
        if (num == 0)
        {
            a[0].data = str[i];
            a[0].weight++;
            num++;
        }
        else
        {
            for (int j = 0; j < num; j++)
            {
                if (a[j].data == str[i])
                {
                    a[j].weight++;
                    judge = 1;
                    break;
                }
            }
            if (judge == 0)
            {
                a[num].data = str[i];
                a[num].weight++;
                num++;
            }
        }
    }
    return num;
}
void hfmtree::mysort(node a[])
{
    for (int i = 0; i < num - 1; i++)
        for (int j = 0; j < num - i - 1; j++)
        {
            if (a[j].weight > a[j + 1].weight)
            {
                int mweight = a[j].weight;
                char mdata = a[j].data;
                a[j] = a[j + 1];
                a[j + 1].data = mdata;
                a[j + 1].weight = mweight;
            }
        }
}
node *hfmtree::hfmcreate(node a[])
{
    node *m[30];
    node *t;
    int j;
    for (int i = 0; i < num; i++)
    {
        m[i] = new node;
        m[i]->data = a[i].data;
        m[i]->weight = a[i].weight;
        m[i]->left = NULL;
        m[i]->right = NULL;
        m[i]->father = NULL;
    }
    for (int i = 0; i < num - 1; i++)
    {
        t = new node;
        t->data = '#';
        t->father = NULL;
        t->weight = m[i]->weight + m[i + 1]->weight;
        t->left = m[i];
        t->right = m[i + 1];
        m[i]->father = t;
        m[i + 1]->father = t;
        m[i + 1] = t;
        if (i != num - 2)
        {
            j = i + 2;
            while (j < num && t->weight >= m[j]->weight)
            {
                m[j - 1] = m[j];
                j = j + 1;
            }
            m[j - 1] = t;
        }
    }
    return t;
}
void hfmtree::preorder(node *p)
{
    if (p == NULL)
        return;
    cout << p->weight << endl;
    preorder(p->left);
    preorder(p->right);
}
node *hfmtree::find(node *p, char data)
{
    node *t;
    node *q;
    if (p == NULL || p->data == data)
        return p;
    t = find(p->left, data);
    if (t != NULL)
        return t;
    else
        return q = find(p->right, data);
}
void hfmtree::setstring(node *p, char data)
{
    node *t = find(p, data);
    node *q = t;
    while (q->father != NULL)
    {
        if (q == q->father->left)
            t->hfmstring += '0';
        if (q == q->father->right)
            t->hfmstring += '1';
        q = q->father;
    }
    length += t->hfmstring.size() * t->weight;
    reverse(t->hfmstring.begin(), t->hfmstring.end());
    sda[sdas] = t->hfmstring;
    sdas++;
}
void hfmtree::unzip(node *p, string a)
{
    node *t = p;
    string k;
    int real1 = 1;
    int count = a.size();
    for (int i = 0; i < count; i++)
    {
        if (a[i] == '0')
            t = t->left;
        if (a[i] == '1')
            t = t->right;
        if (t->left == NULL && t->right == NULL)
        {
            k += t->data;
            t = p;
        }
        if (i == count - 1 && t->left != NULL && t != p)
        {
            cout << "INVALID" << endl;
            real1 = 0;
            break;
        }
    }
    if (real1 == 1)
        cout << k << endl;
}
void hfmtree::clear(node *p)
{
    if (p == NULL)
        return;
    clear(p->left);
    clear(p->right);
    delete p;
    p = NULL;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    node a[30];
    string str1, str2, str3;
    getline(cin, str1);
    getline(cin, str2);
    getline(cin, str3);
    hfmtree hfm;
    int count = hfm.nodecreat(str1, a);
    hfm.mysort(a);
    node *i = hfm.hfmcreate(a);
    for (int n = 0; n < count; n++)
        hfm.setstring(i, a[n].data);
    cout << str1.size() << ' ';
    int Bit = hfm.len();
    cout << (Bit % 8 == 0 ? Bit / 8 : Bit / 8 + 1) << endl;
    for (int n = 0; n < count; n++)
    {
        //node* q=hfm.find(i,a[n].data);
        //cout<<q->data<<':'<<q->hfmstring<<endl;
        cout << a[n].data << ':' << sda[n] << endl;
    }
    hfm.unzip(i, str2);
    hfm.unzip(i, str3);
    hfm.clear(i);
    return 0;
}