#ifndef UFSET_H_INCLUDED
#define UFSET_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <fstream>
#include <windows.h>
using namespace std;
#define DEFAULT_SIZE 100
#define DEFAULT_NUM_VERTEX 100
#define DEFAULT_WEIGHT 0
#define MAX_WEIGHT 0x7fffffff
#include "minheap.h"
#include "graph.h"

struct Node
{
    int x;
    int y;
    Node *next;
    Node(int xx,int yy,Node *ptr=NULL)
    {
        x=xx;
        y=yy;
        next=ptr;
    }
};
class UFSets
{
private:
    Node *first;
    int *parent;
    int Size;
public:
    int xx;
    int yy;
    Node *ptr;
    UFSets(int sz);
    ~UFSets()
    {
        delete  []parent;
    }
    void Union(int Root1,int Root2);
    void Sets(int sz);
    int Find(int x);
    void WeightedUnion(int Root1,int Rood2);
    int Random(int n);
    void putout();
    void charu(int x,int y);
    void shanchu(int n);
    void chongzhi()
    {
        first=NULL;
    }

};

void UFSets::shanchu(int n)
{
    Node *ptr,*ptr1,*del;
    ptr=first;
    ptr1=ptr->next;
    if(n==1)
    {
        xx=ptr->x;
        yy=ptr->y;
        first=ptr->next;
        delete ptr;
    }
    else
    {
        for(int i=2;i<n;i++)
        {
           ptr=ptr->next;
           ptr1=ptr1->next;
        }
        xx=ptr1->x;
        yy=ptr1->y;
        del=ptr1;
        ptr->next=ptr1->next;
        delete del;
    }
}
void UFSets::charu(int x,int y)
{
    Node *newNode;
    newNode=new Node(x,y);
    newNode->next=first;
    first=newNode;
}

int UFSets::Random(int n)
{

    int x;
    x=rand()%n+1;
    return x;
}
UFSets::UFSets(int sz)
{
    first=NULL;
    Size=sz;
    parent=new int[Size];
    for(int i=0; i<Size; i++)
    {
        parent[i]=-1;
    }
}
int UFSets::Find(int x)
{
    //int k1=x;
    while(parent[x]>=0)
    {
        x=parent[x];
    }
    //parent[k1]=x;
    return x;
}
void UFSets::Union(int Root1,int Root2)
{
    parent[Root1]+=parent[Root2];
    parent[Root2]=Root1;

}

#endif // UFSET_H_INCLUDED
