#include <bits/stdc++.h>
using namespace std;
int aa[10000];
int jcount = 0;
struct Arcnode
{ //边结点
    int veradj;
    int weight;
    Arcnode *next;
    Arcnode() : veradj(0), weight(0), next(NULL) {}
    Arcnode(int a, int b) : veradj(a), weight(b), next(NULL) {}
};
struct Vnode
{ //顶点结点
    int name;
    Arcnode *head1; //出度边
    Arcnode *head2; //入度边
    Vnode() : name(0), head1(NULL), head2(NULL) {}
    Vnode(int d) : name(d), head1(NULL), head2(NULL) {}
};
struct node
{
    int head;
    int tail;
    int cost;
};
class unionfindset
{ //并查集
public:
    unionfindset(int t);
    void makeset(int x);
    void Union(int x, int y);
    int find(int x);

private:
    int num;
    int *father;
};
unionfindset::unionfindset(int t)
{
    num = 0;
    father = new int[t];
}
void unionfindset::makeset(int x)
{
    father[x] = 0;
}
int unionfindset::find(int x)
{
    if (father[x] <= 0)
        return x;
    return father[x] = find(father[x]);
}
void unionfindset::Union(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx == fy)
        return;
    if (father[fx] < father[fy])
        father[fy] = fx;
    else
    {
        if (father[fx] == father[fy])
            father[fy]--;
        father[fx] = fy;
    }
}
class Graph
{
public:
    Graph(int vern, int arcn, int t); //构造函数，输入结点和边数，初始化结点数组,t为0为无向图，t为1为有向图
    ~Graph();
    void buildgraph(); //根据输入构建有向图，格式（出发点，目标点，权值）
    Vnode *verlist();  //返回结点数组指针
    void dfs();        //深度优先遍历图所有结点
    void dfs(int t);   //以在邻接表序号为t的顶点出发，深度优先遍历图
    void dfs(int t, int *visited);
    void bfs(int t); //以在邻接表序号为t的顶点出发，广度优先遍历图
    void bfs(int, int *visited);
    void delarc(int a, int b); //删除a指向b的边
    int indegree(int t);       //返回结点i的入度
    int outdegree(int t);      //返回结点i的出度
    int topoorder();           //对图经行拓扑排序列，排序成功返回1，否则返回0
    void criticalpath();
    void shortestpath(int t); //以t为顶点，用djikstra算法寻找到其他各顶点的最短路径
    void kruskal();

private:
    int arcnum;
    int vernum;
    int direction;
    Vnode *ver;
    node *arc;
};
Graph::Graph(int vern, int arcn, int a)
{
    vernum = vern;
    arcnum = arcn;
    direction = a;
    ver = new Vnode[vern];
    arc = new node[arcn];
}
Graph::~Graph()
{
    Arcnode *p;
    for (int i = 0; i < vernum; i++)
    {
        p = ver[i].head1;
        while (p)
        {
            Arcnode *q = p->next;
            delete p;
            p = q;
        }
        p = ver[i].head2;
        while (p)
        {
            Arcnode *q = p->next;
            delete p;
            p = q;
        }
    }
    delete[] ver;
}
void Graph::buildgraph()
{
    for (int i = 0; i < vernum; i++)
    {
        ver[i].name = i;
        ver[i].head1 = new Arcnode();
        ver[i].head2 = new Arcnode();
    }
    for (int i = 0; i < arcnum; i++)
    {
        int j, obj, cost;
        cin >> j >> obj >> cost;
        j--;
        obj--;
        Arcnode *p = new Arcnode(obj, cost);
        Arcnode *q = ver[j].head1;
        while (q->next != NULL)
        {
            if (q->next->veradj > p->veradj)
                break;
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
        //arc[i].head=j;
        //arc[i].tail=obj;
        //arc[i].cost=cost;
        Arcnode *z = new Arcnode(j, cost);
        z->next = ver[obj].head2->next;
        ver[obj].head2->next = z;
        if (direction == 0)
        {
            Arcnode *a = new Arcnode(obj, cost);
            a->next = ver[j].head2->next;
            ver[j].head2->next = p;
            Arcnode *b = new Arcnode(j, cost);
            b->next = ver[obj].head1->next;
            ver[obj].head1->next = q;
        }
    }
}
Vnode *Graph::verlist()
{
    return ver;
}
void Graph::dfs()
{
    int *visited = new int[vernum]();
    for (int i = 0; i < vernum; i++)
        if (visited[i] == 0)
            dfs(i, visited);
    delete[] visited;
}
void Graph::dfs(int t)
{
    int *visited = new int[vernum]();
    dfs(t, visited);
    delete[] visited;
}
void Graph::dfs(int t, int *visited)
{
    cout << ver[t].name << ' ';
    visited[t] = 1;
    Arcnode *p = ver[t].head1->next;
    while (p != NULL)
    {
        if (visited[p->veradj] != 1)
            dfs(p->veradj, visited);
        p = p->next;
    }
}
void Graph::bfs(int t)
{
    int *visited = new int[vernum]();
    bfs(t, visited);
    delete[] visited;
}
void Graph::bfs(int t, int *visited)
{
    cout << ver[t].name << ' ';
    visited[t] = 1;
    queue<int> q;
    q.push(t);
    while (!q.empty())
    {
        int p = q.front();
        Arcnode *m = ver[p].head1->next;
        q.pop();
        while (m != NULL)
        {
            if (visited[m->veradj] == 0)
            {
                cout << ver[m->veradj].name << ' ';
                visited[m->veradj] = 1;
                q.push(m->veradj);
            }
            m = m->next;
        }
    }
}
int Graph::indegree(int t)
{
    int i = 0;
    Arcnode *p = ver[t].head2->next;
    while (p)
    {
        p = p->next;
        i++;
    }
    return i;
}
int Graph::outdegree(int t)
{
    int i = 0;
    Arcnode *p = ver[t].head1->next;
    while (p)
    {
        p = p->next;
        i++;
    }
    return i;
}
void Graph::delarc(int a, int b)
{
    Arcnode *p = ver[a].head1;
    while (p->next != NULL)
    {
        if (p->next->veradj == b)
            break;
        p = p->next;
    }
    Arcnode *del = p->next;
    p->next = del->next;
    delete del;
}
int Graph::topoorder()
{
    int n = vernum;
    int *count = new int[n]();
    for (int i = 0; i < n; i++)
        count[i] = indegree(i);
    int top = -1;
    for (int i = 0; i < n; i++)
        if (count[i] == 0)
        {
            count[i] = top;
            top = i;
        }
    for (int i = 0; i < n; i++)
        if (top == -1)
        {
            cout << "unworkable project" << endl;
            delete[] count;
            return 0;
        }
        else
        {
            int j = top;
            top = count[top];
            //cout<<ver[j].name<<' ';
            aa[jcount] = ver[j].name;
            jcount++;
            Arcnode *p = ver[j].head1->next;
            while (p)
            {
                int k = p->veradj;
                if (--count[k] == 0)
                {
                    count[k] = top;
                    top = k;
                }
                p = p->next;
            }
        }
    delete[] count;
    return 1;
}
void Graph::criticalpath()
{
    int k, e, l;
    int *ve = new int[vernum]();
    int *vl = new int[vernum]();
    for (int i = 0; i < vernum; i++)
    {
        Arcnode *p = ver[aa[i]].head1->next;
        while (p != NULL)
        {
            k = p->veradj;
            if (ve[aa[i]] + p->weight > ve[k])
                ve[k] = ve[aa[i]] + p->weight;
            p = p->next;
        }
    }
    for (int i = 0; i < vernum; i++)
        vl[i] = ve[aa[vernum - 1]];
    for (int i = vernum - 2; i >= 0; i--)
    {
        Arcnode *p = ver[aa[i]].head1->next;
        while (p != NULL)
        {
            k = p->veradj;
            if (vl[k] - p->weight < vl[aa[i]])
                vl[aa[i]] = vl[k] - p->weight;
            p = p->next;
        }
    }
    cout << ve[aa[vernum - 1]] << endl;
    for (int i = 0; i < vernum; i++)
    {
        Arcnode *p = ver[i].head1->next;
        while (p != NULL)
        {
            k = p->veradj;
            e = ve[i];
            l = vl[k] - p->weight;
            if (e == l)
                cout << i + 1 << "->" << k + 1 << endl;
            p = p->next;
        }
    }
}
void Graph::shortestpath(int t)
{
    int u, k;
    int n = vernum;
    int *path = new int[n];
    int *dis = new int[n];
    int *s = new int[n];
    for (int i = 0; i < n; i++)
    {
        path[i] = -1;
        dis[i] = 10000;
        s[i] = 0;
    }
    dis[t] = 0;
    s[t] = 1;
    Arcnode *p = ver[t].head1->next;
    u = t;
    for (int j = 0; j < n; j++)
    {
        while (p != NULL)
        {
            k = p->veradj;
            if (s[k] != 1 && dis[u] + p->weight < dis[k])
            {
                dis[k] = dis[u] + p->weight;
                path[k] = u;
            }
            p = p->next;
        }
        int ldis = 10000;
        for (int i = 0; i < n; i++)
            if (dis[i] > 0 && dis[i] < ldis && s[i] == 0)
            {
                ldis = dis[i];
                u = i;
            }
        if (ldis == 10000)
            break;
        s[u] = 1;
        p = ver[u].head1->next;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == t || dis[i] == 10000)
            ;
        else
            cout << dis[i] << ' ';
    }
    delete[] path;
    delete[] dis;
    delete[] s;
}
void Graph::kruskal()
{
    node *te = new node[vernum];
    for (int i = 0; i < arcnum - 1; i++)
        for (int j = 0; j < arcnum - i - 1; j++)
        {
            if (arc[j].cost > arc[j + 1].cost)
            {
                int nhead = arc[j].head;
                int ntail = arc[j].tail;
                int ncost = arc[j].cost;
                arc[j].head = arc[j + 1].head;
                arc[j].tail = arc[j + 1].tail;
                arc[j].cost = arc[j + 1].cost;
                arc[j + 1].head = nhead;
                arc[j + 1].tail = ntail;
                arc[j + 1].cost = ncost;
            }
        }
    unionfindset ufs(vernum);
    for (int i = 0; i < vernum; i++)
    {
        ufs.makeset(i);
    }
    int T = vernum;
    int j = 0;
    int count = 0;
    int ans = 0;
    int real1 = 0;
    while (T > 1)
    {
        int vex1 = arc[j].head;
        int vex2 = arc[j].tail;
        int cost = arc[j].cost;
        if (ufs.find(vex1) != ufs.find(vex2))
        {
            te[count].head = vex1;
            te[count].tail = vex2;
            te[count].cost = cost;
            count++;
            ans += cost;
            ufs.Union(vex1, vex2);
            T--;
        }
        j = j + 1;
        if (j == arcnum && T > 1)
        {
            cout << "There is no minimum spanning tree.";
            real1 = 1;
            break;
        }
    }
    //for(int i=0;i<vernum-1;i++){
    //cout<<"("<<te[i].head<<","<<te[i].tail<<","<<te[i].cost<<")"<<endl;
    //}
    if (real1 == 0)
        cout << ans;
}
int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        jcount = 0;
        Graph g(a, b, 1);
        g.buildgraph();
        if (g.topoorder())
            g.criticalpath();
    }
}