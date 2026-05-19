#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main(){
	int gd = DETECT, gm;
	int error, x1, y1, x2, y2;
	int x, y, p, dx, dy;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	
	printf("Enter co-ordinates of first point: ");
	scanf("%d %d",&x1, &y1);
	printf("Enter co-ordinates of second point: ");
	scanf("%d %d",&x2, &y2);
	
	dx = x2 - x1;
	dy = y2 - y1;
	
	x = x1;
	y = y1;
	
	p = 2 * dy - dx;
	
	while(x<x2){
		delay(10);
		putpixel(x,y,15);
		x++;
		if(p<0){
			p = p + 2*dy;
		}else{
			p = p + 2*dy - 2*dx;
			y++;
		}
	}
	getch();
	closegraph();
}
