#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <fstream>
#include <windows.h>
#include "shortest.h"
using namespace std;
void FileOut()
{
    ifstream  OpenFile("out.txt");
    char number;int i=0;
    while(!OpenFile.eof())
    {

        OpenFile.get(number);
        cout<<number<<endl;
    }
}
