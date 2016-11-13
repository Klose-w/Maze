#ifndef MINHEAP_H_INCLUDED
#define MINHEAP_H_INCLUDED

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

template<typename T>
class normalqueue
{
private:
    T* data;
    int current_size;
    int queue_size;
public:
    normalqueue(int sz=DEFAULT_SIZE)
    {
        queue_size=sz;
        data=new T[queue_size];
        if(!data)
        {
            cerr << "error" << endl;
            exit(1);
        }
        current_size=0;
    }
    normalqueue(T* ary,int n)
    {
        queue_size=(DEFAULT_SIZE>n)?DEFAULT_SIZE:n;
        data = new T[queue_size];
        if(!data)
        {
            cerr << "error" << endl;
            exit(1);
        }
        for(int i=0; i<n; i++)
        {
            data[i]=ary[i];
        }
        current_size=n;
    }
    void reSize(int n)
    {
        if(empty())
        {
            delete []data;
            queue_size=n;
            data = new T[queue_size];
            return;
        }
        else
        {
            T* _data;
            _data = new T[n];
            for(int i=0; i<current_size; i++)
            {
                _data[i]=data[i];
            }
            delete []data;
            queue_size=n;
            data=_data;
            return;
        }
    }
    bool empty()
    {
        return current_size==0;
    }
    bool full()
    {
        return current_size==queue_size;
    }
    void insert(const T& x)
    {
        if(full())
        {
            reSize(queue_size*2);
        }
        data[current_size]=x;
        current_size++;
        return;
    }
    bool remove(T& x)
    {
        if(empty())
        {
            return false;
        }
        x=data[0];
        data[0]=data[current_size-1];
        current_size--;
        return true;
    }
    ~normalqueue()
    {
        delete []data;
    }

};

#endif // MINHEAP_H_INCLUDED
