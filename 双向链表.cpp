#include<bits/stdc++.h>
using namespace std;
template<class T>
struct node{
    T data;
    node<T> *next;
    node<T> *front;
    node(T d):data(d),next(NULL),front(NULL){}
};
template<class T>
class doublelist{
public:
    doublelist();
    void headinsert(T data);//头插数据为data的结点
    void tailinsert(T data);//尾插数据为data的结点
    node<T>* find(int pos);//返回链表中第pos个结点的指针
    void insert(T data,int pos);// 在第pos个位置之后插入数据为data的结点
    void insert(T data,node<T> *p);//在指针p所指结点之后插入数据为data的结点
    void del(int pos);//删除第pos个位置的结点
    void del(node<T> *p);//删除p所指结点
    int length();// 返回链表长度
    void display();//遍历输出链表
    void clear();//清空链表
private:
    node<T> *head;
    node<T> *tail;
    int len;
};
template<class T>
doublelist<T>::doublelist(){
    head=new node<T>(0);
    tail=new node<T>(0);
    head->next=tail;
    tail->front=head;
    len=0;
}
template<class T>
void doublelist<T>::headinsert(T data){
    node<T> *p=new node<T>(data);
    p->next=head->next;
    p->front=head;
    head->next=p;
    p->next->front=p;
    len++;
}
template<class T>
void doublelist<T>::tailinsert(T data){
    node<T> *p=new node<T>(data);
    p->front=tail->front;
    p->next=tail;
    tail->front=p;
    p->front->next=p;
    len++;
}
template<class T>
node<T>* doublelist<T>::find(int pos){
    node<T> *p=head;
    if(pos>len||pos<0)
    return NULL; 
    for(int i=0;i<pos;i++)
    p=p->next;
    return p;
}
template<class T>
void  doublelist<T>::display(){
        node<T> *p=head;
        while(p->next!=tail){
        cout<<p->next->data;
        p=p->next;
   }
}
template<class T>
int  doublelist<T>::length(){return len;}
template<class T>
void  doublelist<T>::insert(T data,int pos){
    node<T> *p=find(pos);
    node<T> *q=new node<T>(data);
    q->next=p->next;
    q->front=p;
    p->next=q;
    q->next->front=q;
    len++;
}
template<class T>
void  doublelist<T>::insert(T data,node<T> *p){
    node<T> *q=new node<T>(data);
    q->next=p->next;
    q->front=p;
    p->next=q;
    q->next->front=q;
    len++;   
}
template<class T>
void  doublelist<T>::del(int pos){
    node<T> *p=find(pos);
    p->front->next=p->next;
    p->next->front=p->front;
    delete p;
    len--;
}
template<class T>
void  doublelist<T>::del(node<T> *p){
    p->front->next=p->next;
    p->next->front=p->front;
    delete p;
    len--;
}
template<class T>
void doublelist<T>::clear(){
  node<T>* p=head;
    while(p){
        node<T> *q=p->next;
        delete p;
        p=q;
    } 
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    doublelist<char> list;
    char b;
    int shuchu=1;
    b=cin.get();
    node<char> *p=list.find(0);
    while(b!='\n'){
    if(b=='['){p=list.find(0);cin.get(b); continue;}
    if(b==']'){p=list.find(list.length());cin.get(b); continue;}
    if(b=='{'){if(p->front!=NULL)p=p->front;cin.get(b); continue;}
    if(b=='}'){if(p->next!=NULL)p=p->next;cin.get(b); continue;}
    if(b=='='){
        if(p->front!=NULL)
        {p=p->front;
        list.del(p->next);
        } 
        cin.get(b);
        continue;}
    if(b=='-'){shuchu=-shuchu;cin.get(b); continue;}
    if(shuchu==1){
        list.insert(b,p);
        p=p->next;}
      else {
        if(p->next==NULL){
            list.insert(b,p);
        p=p->next;
       }
       else{
        p->next->data=b;
        p=p->next;}
 }
 
 cin.get(b);
}
 list.display();
 list.clear();
}