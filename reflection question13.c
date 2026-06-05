#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
	int gd=DETECT, gm, i;
	int x1=100, y1=100;
	int x2=100, y2=200, x3=200, y3=100;
	initgraph(&gd, &gm, "C:\\Turboc3\\bgi");
	line(getmaxx()/2,0, getmaxx()/2,getmaxy());
	line(0, getmaxy()/2, getmaxx(),getmaxy());
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
	getch();
	//Reflection about the origin
	setcolor(1);
	line(getmaxx()-x1,getmaxy()-y1,getmaxx()-x2,getmaxy()-y2);
	line(getmaxx()-x2,getmaxy()-y2,getmaxx()-x3,getmaxy()-y3);
	line(getmaxx()-x3,getmaxy()-y3,getmaxx()-x1,getmaxy()-y1);
	getch();
	//reflection along y-axis
	setcolor(2);
	line(getmaxx()-x1,y1,getmaxx()-x2,y2);
	line(getmaxx()-x2,y2,getmaxx()-x3,y3);
	line(getmaxx()-x3,y3,getmaxx()-x1,y1);
	getch();
	//reflection along x-axis
	setcolor(3);
	line(x1,getmaxy()-y1,x2,getmaxy()-y2);
	line(x2,getmaxy()-y2,x3,getmaxy()-y3);
	line(x3,getmaxy()-y3,x1,getmaxy()-y1);
	getch();
	closegraph();
}
