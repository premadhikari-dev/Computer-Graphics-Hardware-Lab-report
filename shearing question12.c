#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main(){
	int gd=DETECT, gm, i;
	int x1=50, y1=50, x2=100, y2=50;
	int x3=100, y3=100, x4=50, y4=100;
	int shx=2, shy=2;
	initgraph(&gd, &gm, "C:\\Turboc3\\bgi");
	
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x4,y4);
	line(x4,y4,x1,y1);
	getch();
	
	//shearing along x-axis
	setcolor(2);
	x1=x1+shx*y1;
	x2=x2+shx*y2;
	x3=x3+shx*y3;
	x4=x4+shx*y4;
	
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x4,y4);
	line(x4,y4,x1,y1);
	
	getch();
	
	//shearing along y-axis
	setcolor(3);
	y1=y1+shy*x1;
	y2=y2+shy*x2;
	y3=y3+shy*x3;
	y4=y4+shy*x4;
	
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x4,y4);
	line(x4,y4,x1,y1);
	getch();
	
	
	
}
