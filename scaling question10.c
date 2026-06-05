#include<stdio.h>
#include<graphics.h>
#include<math.h>

void scale(int, int, int, int, int, int);
void drawTriangle(int, int, int, int, int, int);

void main(){
	int gd = DETECT, gm;
	int x1, y1, x2, y2, x3, y3;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	
	printf("Enter point of first angle of the triangle: ");
	scanf("%d %d",&x1, &y1);
	printf("Enter point of second angle of the triangle: ");
	scanf("%d %d",&x2, &y2);
	printf("Enter point of third angle of the triangle: ");
	scanf("%d %d",&x3, &y3);
	
	drawTriangle(x1, y1, x2, y2, x3, y3);
	scale(x1, y1, x2, y2, x3, y3);
	getch();
}

void scale(int x1, int y1, int x2, int y2, int x3, int y3){
	int sx, sy;
	printf("Enter the scaling point: ");
	scanf("%d %d",&sx, &sy);
	
	x1 *= sx;
	y1 *= sy;
	x2 *= sx;
	y2 *= sy;
	x3 *= sx;
	y3 *= sy;
	
	setcolor(RED);
	drawTriangle(x1, y1, x2, y2, x3, y3);
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
}
