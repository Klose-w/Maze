#ifndef IFSTREAM_H_INCLUDED
#define IFSTREAM_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <fstream>
#include <windows.h>

using namespace std;
int* FileOut()
{
    ifstream  OpenFile("out.txt");
    char number;
    int i=0;
    int *path;
    path =new int[10000];
    while(!OpenFile.eof())
    {
        OpenFile.get(number);
        if(number!=13&&number!=' ')
        {
            path[i] = number-'0';
            i++;
        }
    }
    return path;
}


#endif // IFSTREAM_H_INCLUDED
