#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
int lujing[10000];
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
template<typename W>
struct edge_node
{
    int to;
    W weight;
    edge_node<W>* next;
    edge_node(int _to,W _weight=1,edge_node<W>* _next=NULL)
    {
        to = _to;
        weight = _weight;
        next = _next;
    }
};
template<typename T,typename W>
struct vertex_node
{
    T v1;
    T v2;
    int x;int y;
    edge_node<W>* next;
    vertex_node(T _v1,T _v2,edge_node<W>* nt=NULL)
    {
        v1 = _v1;
        v2 = _v2;
        next = nt;
    }

    vertex_node(edge_node<W>* nt=NULL)
    {
        next = nt;
    }
};

template<typename T,typename W>
class graph_LIST
{
private:
    vertex_node<T,W>* vertex_list;
    int max_vertex;
    int num_vertex;
    int num_edge;
    void re_size(int sz)
    {
        if(sz<=max_vertex)
        {
            cout << "error" << endl;
            exit(1);
        }

        max_vertex = sz;
        vertex_node<T,W>* _vertex_list;
        _vertex_list = new vertex_node<T,W>[max_vertex];

        for(int i=0; i<num_vertex; i++)
        {
            _vertex_list[i].v1=vertex_list[i].v1;
            _vertex_list[i].v2=vertex_list[i].v2;
            _vertex_list[i].next=vertex_list[i].next;
        }

        delete []vertex_list;
        vertex_list = _vertex_list;
        return;
    }
public:
    graph_LIST(int sz=DEFAULT_NUM_VERTEX)
    {
        max_vertex = sz;
        num_vertex = 0;
        num_edge = 0;

        vertex_list = new vertex_node<T,W>[max_vertex];
    }
    ~graph_LIST()
    {
        for(int i=0; i<num_vertex; i++)
        {
            del_edge_list(vertex_list[i].next);
        }
        delete []vertex_list;
    }
    void del_edge_list(edge_node<W>* Enode)
    {
        edge_node<W>* tp;
        while(Enode)
        {
            tp=Enode;
            Enode=Enode->next;
            delete tp;
        }
    }

    int get_num_vertex()
    {
        return num_vertex;
    }
    int get_first_neighbor(int v)
    {
        if(v!=-1)
        {
            edge_node<W>* tp;
            tp = vertex_list[v].next;
            if(tp)
            {
                return tp->to;
            }
        }
        return -1;
    }
    int get_next_neighbor(int v,int w)
    {
        if(v!=-1&&w!=-1)
        {
            edge_node<W>* iter;
            iter = vertex_list[v].next;
            for(; iter; iter=iter->next)
            {
                if(iter->to==w)
                {
                    if(iter->next)
                    {
                        return iter->next->to;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return -1;
    }
    void insert_vertex(const T& _v1,const T& _v2)
    {
        if(num_vertex==max_vertex)
        {
            re_size((int)(max_vertex*1.1));
        }
        vertex_list[num_vertex].v1=_v1;
        vertex_list[num_vertex].v2=_v2;
        num_vertex++;
        return;
    }
    void insert_edge(int from,int to)
    {
        edge_node<W>* new_node = new edge_node<W>(to);
        if(vertex_list[from].next)
        {
            new_node->next = vertex_list[from].next;
            vertex_list[from].next = new_node;
        }
        else
        {
            vertex_list[from].next = new_node;
        }
    }
    int get_index(const T& _v1,const T& _v2)
    {
        for(int i=0; i<num_vertex; i++)
        {
            if(vertex_list[i].v1==_v1&&vertex_list[i].v2==_v2)
            {
                return i;
            }
        }
        return -1;
    }
    void print_path( int* path,int start,void(*Print)(const vertex_node<T,W>* Vnode))
    {
        int sort_ary[num_vertex];
        int i=0;
        int temp = start;
        while(temp!=-1)
        {
            sort_ary[i++]=temp;
            temp=path[temp];
        }
        while(i>0)
        {
            Print(&vertex_list[sort_ary[--i]]);
        }
        return ;
    }
    int output( int* path,int start)
    {

        int sort_ary[num_vertex];
        int i=0;
        int temp = start;
        while(temp!=-1)
        {
            sort_ary[i++]=temp;
            temp=path[temp];
        }
        int number = i*2;
        int j = 0;
        while(i>0)
        {
            lujing[j] = vertex_list[sort_ary[--i]].v1;
            j=j+1;
            lujing[j] = vertex_list[sort_ary[i]].v2;
            j++;
        }
        ofstream outfile;
        outfile.open("out.txt");
        for(int i=0;i<number;i = i+2)
            outfile<<lujing[i]<<" "<<lujing[i+1]<<endl;
        outfile.close();
        return number;
    }
};


#endif // GRAPH_H_INCLUDED
