#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <windows.h>
#include <graph2d.h>
#include <time.h>
#include "minheap.h"
#include "graph.h"
#include "shortest.h"
#include "ufset.h"
#include "ifstream.h"
#include "bread.h"
using namespace std;
using namespace graph;
time_t St,Ed;
int G_imaID;
int g_font[5];
int Root1;
int Root2;
bool g_bSolid=false;
int maze1[1000][1000];
double L_x;
double L_y;
double R_x;
double R_y;
int bushu=0;
int SS=0;
int g_x;
int g_y;
double g_r;
int nx;
int ny;
double mixX;
double mixY;
int n=101;
int m=101;
int p=0;
double xst=getWinWidth()+100;
double yst=getWinHeight()-80;
char cg[4];
char cg1[5];
char cg2[4];
char cg3[4];
char cg4[6];
char cg5[5];
char cg6[6];
clock_t T1,T2,T3,T4;
void chang(unsigned long s,unsigned long e)
{
    int k=(int)(e-s);
    itoa(k,cg,10);
    itoa(p,cg1,10);
    itoa(nx,cg2,10);
    itoa(ny,cg3,10);
}
void change(unsigned long s,unsigned long e)
{
    int k=(int)(e-s);
    itoa(k,cg4,10);
    itoa(bushu,cg5,10);
}
void change1(unsigned long s,unsigned long e)
{
    int k=(int)(e-s);
    itoa(k,cg6,10);

}

void display()
{
    if(SS==0)
    {
        showImage(G_imaID);
        useFont(g_font[4]);
        setColor(BLACK);
        putText(xst-1050,120,"The kingdom of maze");
        useFont(g_font[1]);
        putText(xst-580,40,"Click the mouse to continue......");

    }
    if(SS!=0)
    {
        mixX=xst/nx;
        mixY=yst/ny;
        setColor(100,240,100);
        fillRectangle(xst+40,yst-285,xst+140,yst-215);
        setColor(50,100,180);
        fillCircle(xst+80,yst-600,35);
        setColor(ORANGE);
        fillCircle(xst+190,yst-600,35);
        setColor(RED);
        fillCircle(xst+190,yst-250,35);
        setColor(GREY);
        fillRectangle(xst+80,yst+50,xst+220,yst+100);
        fillRectangle(xst+80,yst-50,xst+220,yst);
        fillRectangle(xst+80,yst-150,xst+220,yst-100);
        fillRectangle(xst+50,yst-350,xst+130,yst-320);
        fillRectangle(xst+150,yst-350,xst+230,yst-320);
        fillRectangle(xst+50,yst-450,xst+220,yst-400);
        fillRectangle(xst+50,yst-550,xst+220,yst-500);
        useFont(g_font[4]);
        putText(100,yst+50,"Fight!!");
        setColor(RED);
        useFont(g_font[2]);
        putText(500,yst+50,"Click W,A,S,D to control!!!!!!!");
        useFont(g_font[1]);
        char *AAA="Time:";
        Ed=time(NULL);
        putText(xst+45,yst-275,cg6);
        putText(xst+90,yst+60,"Size:");
        putText(xst+90,yst-40,AAA);
        putText(xst+140,yst-40,cg);
        putText(xst+90,yst-140,"Move:");
        putText(xst+150,yst-140,cg1);
        putText(xst+60,yst-340,"NEXT");
        putText(xst+160,yst-340,"LAST");
        chang(St,Ed);
        putText(xst+140,yst+60,cg2);
        putText(xst+185,yst+60,cg3);
        putText(xst+60,yst-440,"T:");
        putText(xst+80,yst-440,cg4);
        putText(xst+60,yst-540,"M:");
        putText(xst+85,yst-540,cg5);
        if(p==0)
        {

            g_x=1;
            g_y=0;
            St=time(NULL);
            cg[0]= {0};
            cg[1]= {0};
            cg[2]= {0};
            if(mixX<mixY)
            {
                g_r=mixX/2;
            }
            else
            {
                g_r=mixY/2;
            }
            //cout<<g_x<<" "<<g_y<<endl;
        }
        for(int i=0; i<nx; i++)
        {
            for(int k=0; k<ny; k++)
            {
                if(maze1[i][k]==1)
                {
                    setColor(180,50,140);
                    L_x=i*mixX+30;
                    L_y=k*mixY+30;
                    R_x=(i+1)*mixX+30;
                    R_y=(k+1)*mixY+30;
                    fillRectangle(L_x,L_y,R_x,R_y);

                }
                else if(maze1[i][k]==-2)
                {
                    setColor(ORANGE);
                    L_x=i*mixX+30;
                    L_y=k*mixY+30;
                    R_x=(i+1)*mixX+30;
                    R_y=(k+1)*mixY+30;
                    fillRectangle(L_x,L_y,R_x,R_y);


                }
                else if(maze1[i][k]==-3)
                {

                    setColor(50,100,180);
                    L_x=i*mixX+30;
                    L_y=k*mixY+30;
                    R_x=(i+1)*mixX+30;
                    R_y=(k+1)*mixY+30;
                    fillRectangle(L_x,L_y,R_x,R_y);


                }
            }
        }
        setColor(RED);
        fillCircle(g_x*mixX+mixX/2+30,g_y*mixY+mixY/2+30,g_r);
        if(g_x==nx-2&&g_y==ny-1)
        {

            useFont(g_font[3]);
            setColor(YELLOW);
            putText(xst-1000,200,"victory");
            //Ed=time(NULL);
        }
    }

}
void mousePress(int message,int x,int y)
{
    int X1;
    int Y1;
    if(message==LEFT_BUTTON_DOWN)
    {
        X1=x;
        Y1=y;
    }
    if(SS==0)
    {
        X1=xst+140;
        Y1=yst-330;
    }
    if(abs(X1-xst-80)<35&&abs(Y1-yst+250)<35)
    {

    }
    else if(abs(X1-xst-190)<35&&abs(Y1-yst+250)<35)
    {
        p=0;
        T1=clock();
        bushu=0;
        change(T1,T1);
        for(int i=0; i<nx; i++)
        {
            for(int k=0; k<ny; k++)
            {
                if(maze1[i][k]!=1)
                {
                    maze1[i][k]=0;
                }
                else
                {

                }

            }

        }
    }
    else if(abs(X1-xst-80)<35&&abs(Y1-yst+600)<35)
    {
        T1=clock();
        int **maze=new int* [nx];
        for(int i=0; i<nx; i++)
        {
            maze[i]=new int[ny];
        }
        for(int i=0; i<nx; i++)
        {
            for(int k=0; k<ny; k++)
            {
                if(maze1[i][k]!=1)
                {
                    maze[i][k]=0;
                }
                else
                {
                    maze[i][k]=maze1[i][k];
                }

            }

        }

        BFS *T=new BFS (maze,nx,ny);
        T->searchShort(nx-2,ny-1);
        int Xx;
        int Yy;
        int *AB=T->returnway();
        int ABC=T->returnpace();
        delete maze;
        for(int i=0; i<ABC; i++)
        {
            Xx=AB[2*i];
            Yy=AB[2*i+1];
            maze1[Xx][Yy]=-3;
        }
        bushu=ABC-1;
        T2=clock();
        change(T1,T2);

    }
    else if(abs(X1-xst-190)<35&&abs(Y1-yst+600)<35)
    {
        T1=clock();
        graph_LIST<int,int> graph;
        int sx,sy;
        int ex,ey;
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<m-1; j++)
            {
                if(maze1[i][j]!=1)
                {
                    graph.insert_vertex(i,j);
                }
            }
        }
        sx = 1;
        sy = 1;
        ex = n-2;
        ey = m-2;
        for(int i=1; i<n-1; i++)
        {
            for(int j=1; j<m-1; j++)
            {
                if(maze1[i][j]!=1)
                {
                    if(maze1[i-1][j]!=1)
                    {
                        graph.insert_edge(graph.get_index(i,j),graph.get_index(i-1,j));
                    }
                    if(maze1[i][j+1]!=1)
                    {
                        graph.insert_edge(graph.get_index(i,j),graph.get_index(i,j+1));
                    }
                    if(maze1[i+1][j]!=1)
                    {
                        graph.insert_edge(graph.get_index(i,j),graph.get_index(i+1,j));
                    }
                    if(maze1[i][j-1]!=1)
                    {
                        graph.insert_edge(graph.get_index(i,j),graph.get_index(i,j-1));
                    }
                }
            }
        }
        int nn=graph.get_num_vertex();
        int dist[nn];
        for(int i=0; i<nn; i++)
        {
            dist[i]=MAX_WEIGHT;
        }
        int path[nn];
        shortest_path(graph,graph.get_index(sx,sy),dist,path);
        //graph.print_path(path,graph.get_index(ex,ey),Print);

        int numb=graph.output(path,graph.get_index(ex,ey));
        int Xx,Yy;
        for(int i=0; i<numb; i+=2)
        {
            Xx=lujing[i];
            Yy=lujing[i+1];
            maze1[Xx][Yy]=-2;
        }
        maze1[1][0]=-2;
        maze1[n-2][m-1]=-2;
        bushu=numb/2+1;
        T2=clock();
        change(T1,T2);
    }
    else if(X1>(xst+50)&&Y1>(yst-350)&&X1<(xst+230)&&Y1<(yst-320))
    {
        T3=clock();
        SS++;
        if(X1<(xst+130))
        {
            n=n+2;
            m=m+2;
        }
        else if(X1>(xst+150))
        {
            n=n-2;
            m=m-2;
        }
        int Size,Size1;
        nx=n;
        ny=m;
        p=0;
        mixX=xst/nx;
        mixY=yst/ny;
        g_x=mixX/2+mixX+30;
        g_y=mixY/2+30;
        if(mixX<mixY)
        {
            g_r=mixX/2;
        }
        else
        {
            g_r=mixY/2;
        }
        Size=(m/2)*(n/2);
        Size1=(m/2)*(n-2)-((n-2)/2+1);
        UFSets *W;
        W=new UFSets(Size1);
        int nu1=2;
        for(int i=0; i<n; i++)
        {
            for(int k=0; k<m; k++)
            {
                if(i==0||k==0||i==n-1||k==m-1)
                {
                    maze1[i][k]=1;
                }
                else if(i&1==1&&k&1==1)
                {
                    maze1[i][k]=nu1;
                    nu1++;
                }
                else if(1==(i+k)%2)
                {
                    int kk=W->Random(5);
                    if(i%2==1)
                    {
                        if(kk<4)
                        {
                            maze1[i][k+1]=nu1;
                            maze1[i][k]=0;
                            Root1=W->Find(maze1[i][k-1]-2);
                            Root2=W->Find(maze1[i][k+1]-2);
                            if(Root1!=Root2)
                            {
                                W->Union(Root1,Root2);
                            }
                            Size1--;
                        }
                        else
                        {
                            W->charu(i,k);
                            maze1[i][k]=1;
                        }

                    }
                    else
                    {
                       /*if(kk<3)
                        {
                            maze1[i+1][k]=maze1[i-1][k]+m-2;
                            maze1[i][k]=0;
                            Root1=W->Find(maze1[i-1][k]-2);
                            Root2=W->Find(maze1[i+1][k]-2);
                            if(Root1!=Root2)
                            {
                                W->Union(Root1,Root2);
                            }
                            Size1--;
                        }
                        else
                        {*/
                            W->charu(i,k);
                            maze1[i][k]=1;
                        //}
                    }
                }
                else
                {
                    maze1[i][k]=1;
                }
            }
        }
        maze1[1][0]=0;
        maze1[n-2][m-1]=0;
        for(;;)
        {
            int sui;
            sui=W->Random(Size1);
            W->shanchu(sui);
            Size1--;
            int num1=W->xx;
            int num2=W->yy;
            int n1=(num1+1)%2;
            int n2=(num2+1)%2;
            int x1=num1+n1;
            int y1=num2+n2;
            int x2=num1-n1;
            int y2=num2-n2;
            int shu1=maze1[x1][y1]-2;
            int shu2=maze1[x2][y2]-2;
            Root1=W->Find(shu1);
            Root2=W->Find(shu2);
            if(Root1!=Root2)
            {
                W->Union(Root1,Root2);
                maze1[num1][num2]=0;

            }
            else
            {

                Root1=W->Find(0);
                Root2=W->Find(Size-1);
                if(Root1!=Root2)
                {
                    if(n1==0)
                    {
                       // maze1[num1][num2]=0;//Â·ÊýÑ¡Ôñ
                    }
                }
                else
                {
                    break;
                }
            }
        }
        W->chongzhi();
        delete W;
        T4=clock();
        change1(T3,T4);

    }
}
void keyboard(unsigned char key)
{

    if(p==0)
    {
        St=time(NULL);
    }
    if(g_x==nx-2&&g_y==ny-1)
    {
        key='h';
    }
    if(g_x==1&&g_y==0)
    {
        if(key=='s')
        {
            key='h';
        }
    }
    if(key=='d')
    {
        if(maze1[g_x+1][g_y]!=1)
        {
            g_x=g_x+1;
            p++;
        }

    }
    else if(key=='a')
    {
        if(maze1[g_x-1][g_y]!=1)
        {
            g_x=g_x-1;
            p++;
        }
        //fillCircle(g_x,g_y,g_r);
    }
    else if(key=='s')
    {
        if(maze1[g_x][g_y-1]!=1)
        {
            g_y=g_y-1;
            p++;
        }
    }
    else if(key=='w')
    {
        if(maze1[g_x][g_y+1]!=1)
        {
            g_y=g_y+1;
            p++;
        }
        //fillCircle(g_x,g_y,g_r);

    }
    else if(key=='z')
    {
        exitFullScreen();
    }
    else {}

}



int main()
{
    SYSTEMTIME sys;
    GetLocalTime( &sys );
    srand(sys.wMilliseconds);
    G_imaID=loadImage(".\\add1.bmp");
    g_font[0]=createFont(35,"Times New Roman",35);
    g_font[1]=createFont(15,"Arial",5);
    g_font[2]=createFont(35,"Times New Roman",40);
    g_font[3]=createFont(300,"Times New Roman",60);
    g_font[4]=createFont(100,"Times New Roman",40);
    setFullScreen();
    setBkColor(100,180,200);
    initGraph(display,keyboard,mousePress);
    system("pause");

}


