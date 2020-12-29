#include<bits/stdc++.h>
using namespace std;
class unionfindset{
public:
  unionfindset();
  void makeset(int x);
  void Union(int x,int y);
  int find(int x);

private:
   int num;
   int *father;
};
unionfindset::unionfindset(){
    num=0;
    father=NULL;
}
void unionfindset::makeset(int x){
    father[x]=0;
}
int unionfindset::find(int x){
    if(father[x]<=0)
    return x;
    return father[x]=find(father[x]);
}
void unionfindset::Union(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx==fy)return;
    if(father[fx]<father[fy])
    father[fy]=fx;
    else{
        if(father[fx]==father[fy])
        father[fy]--;
        father[fx]=fy;
    }
}
int main(){
    
}