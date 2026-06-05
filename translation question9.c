#include<stdio.h>
#include<graphics.h>
#include<math.h>

void translate(int, int, int, int, int, int);
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
	translate(x1, y1, x2, y2, x3, y3);
	getch();
}

void translate(int x1, int y1, int x2, int y2, int x3, int y3){
	int tx, ty;
	printf("Enter the translation point: ");
	scanf("%d %d",&tx, &ty);
	
	x1 += tx;
	y1 += ty;
	x2 += tx;
	y2 += ty;
	x3 += tx;
	y3 += ty;
	
	setcolor(RED);
	drawTriangle(x1, y1, x2, y2, x3, y3);
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
}
