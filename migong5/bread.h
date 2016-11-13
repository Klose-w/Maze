#ifndef BREAD_H_INCLUDED
#define BREAD_H_INCLUDED
#include<iostream>
#include <cstdlib>
#include<queue>
#include <fstream>
int  *lujin;
using namespace std;

struct WAY
{
    int x,y;
};
struct node
{
    int   left;
    int  right;
    node *turn;
    node(int data1=1,int data2=0)
    {
        left=data1;
        right=data2;
        turn =NULL;
    }
};
class BFS
{
    node *root;
    int **mg;
    int no,mo;

    node *E,*p,*w;
      int pace;
public:
    BFS(int **a,int n1,int m1)
    {
        root =new node();
        mg=a;
        no=n1;
        mo=m1;
        E=NULL;
        pace=0;

    }
    ~BFS()
    {}
    void searchShort(int eleft=1,int eright=0)
    {
        queue<node*> Q;
        node *ptr=root;
        Q.push(ptr);
        while(!Q.empty())
        {
            int t=Q.size();
            for(int i=0; i<t; i++)
            {
                if(mg[ptr->left+1][ptr->right]==0&&ptr->left+1<no)
                {
                    node *newnode=new node(ptr->left+1,ptr->right);
                    mg[ptr->left+1][ptr->right]=-1;
                    newnode->turn=ptr;
                    Q.push(newnode);
                    if(newnode->left==eleft&&newnode->right==eright)
                    {
                        E=newnode;
                        p=E;w=p;
                        break;
                    }
                }
                if(mg[ptr->left][ptr->right+1]==0&&ptr->right+1<mo)
                {
                    node *newnode=new node(ptr->left,ptr->right+1);
                    mg[ptr->left][ptr->right+1]=-1;
                    newnode->turn=ptr;
                    Q.push(newnode);
                    if(newnode->left==eleft&&newnode->right==eright)
                    {
                        E=newnode;
                        p=E;w=p;
                        break;
                    }
                }
                if(mg[ptr->left-1][ptr->right]==0&&ptr->left-1>=0)
                {
                    node *newnode=new node(ptr->left-1,ptr->right);
                    mg[ptr->left-1][ptr->right]=-1;
                    newnode->turn=ptr;
                    Q.push(newnode);
                    if(newnode->left==eleft&&newnode->right==eright)
                    {
                    E= newnode;
                        p=E;w=p;
                        break;
                    }
                }
                if(mg[ptr->left][ptr->right-1]==0&&ptr->right-1>=0)
                {
                    node *newnode=new node(ptr->left,ptr->right-1);
                    mg[ptr->left][ptr->right-1]=-1;
                    newnode->turn=ptr;
                    Q.push(newnode);
                    if(newnode->left==eleft&&newnode->right==eright)
                    {
                        E=newnode;
                        p=E;w=p;
                        break;
                    }
                }
                Q.pop();
                ptr=Q.front();
            }
        }
        ofstream outputfile("short.txt");
        outputfile<<"路径步骤（从尾到头）："<<endl;
        while(E!=NULL)
        {
            outputfile<<E->left<<","<<E->right<<endl;
            pace++;
            E=E->turn;
        }
        outputfile<<"迷宫步数为："<<pace;
    }
    void getfile()
    {
        ifstream infile("short.txt");
        string s;
        while(getline(infile, s))
        {
               // cout<<s;
               //cout<<endl;
        }
    }


    void out()
    {
        while(p)
        {
            mg[p->left][p->right]=2;
            p=p->turn;
        }
    for(int i=no-1;i>-1;i--)
    {
        for(int j=mo-1;j>-1;j--)
        {

          if(i==1&&j==0)
                cout<<"S";
                else if(i==no-2&&j==mo-1)
                        cout<<"E";
                else if(mg[i][j]==1)
                    cout<<"1";
                    else if(mg[i][j]==2)
                    cout<<"*";
                else cout<<" ";
        }
       cout<<endl;
    }
    }

    int* returnway()
    {
       lujin=new int[2*pace];
       for(int i=pace-1;i>-1;i--)
       {

           lujin[2*i]=w->left;
           lujin[2*i+1]=w->right;
           w=w->turn;
       }
       return lujin;
    }
    int  returnpace()
    {
        return pace;
    }

};
#endif // BREAD_H_INCLUDED
