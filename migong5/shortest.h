#ifndef SHORTEST_H_INCLUDED
#define SHORTEST_H_INCLUDED
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
template<typename W>
struct node_in
{
    int to;
    W distance;
    node_in() {}
    node_in(int _to, W& weight=1)
    {
        to = _to;
        distance = weight;
    }
};
template<typename T,typename W>
void shortest_path(graph_LIST<T,W>& graph,int start,W* dist,int* path)
/****graph为邻接链表 u为起点 dist为标记数组，记录到起点的路径长度
     path存放节点的访问顺序，当前节点存放上一节点的下标****/
{
    int v,u;
    int n;
    int* visited;
    node_in<W> out_node;
    normalqueue<node_in<W> > pri_queue;

    n = graph.get_num_vertex();
    visited = new int[n];
    memset(visited,0,sizeof(int)*n);

    path[start] = -1;
    dist[start] = 0;
    node_in<W> first_node(start,dist[start]);
    pri_queue.insert(first_node);

    while(!pri_queue.empty())
    {
        pri_queue.remove(out_node);
        u = out_node.to;
        //cout << "out_node->distance: " << out_node.distance << endl;



            visited[u]=1;
            v = graph.get_first_neighbor(u);

            for(; v!=-1; v=graph.get_next_neighbor(u,v))
            {
                if(dist[v] > dist[u]+1)
                {
                    dist[v] = dist[u]+1;
                    pri_queue.insert(node_in<W>(v,dist[v]));
                    path[v] = u;
                }
            }

    }
    delete []visited;
}
template<typename T,typename W>
void Print(const vertex_node<T,W>* Vnode)
{
    cout << Vnode->v1 << " " << Vnode->v2 << " " <<endl;
}


#endif // SHORTEST_H_INCLUDED
