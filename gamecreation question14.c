#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void drawHouse(){
	int winx, winy;
	rectangle(200,200,300,300);
	line(200,200,250,150);
	line(250,150,300,200);
	rectangle(230,250,270,300);
	winx=getmax()-40;
	winy=getmax()-40;
	circle(winx, winy,40);
}
void drawCharacter(int x,int y)
{
	setcolor(WHITE);
	circle(x,y,10);
	line(x,y+10,x,y+30);
	line(x,y+30,x-10,y+40);
	line(x,y+30,x+10,y+40);
	line(x,y+15,x-10,y+20);
	line(x,y+15,x+10,y+20);
}
void clearCharacter(int x, int y){
	setcolor(BLACK);
	circle(x,y,10);
	line(x,y+10,x,y+30);
	line(x,y+30,x-10,y+40);
	line(x,y+30,x+10,y+40);
	line(x,y+15,x-10,y+20);
	line(x,y+15,x+10,y+20);
}
void main(){
	int gd=DETECT,gm, i;
	int x=100, y=250;
	char key;
	initgraph(&gd, &gm, "C:\\TURBOC3\\bgi");
	drawHouse();
	drawCharacter(x,y);
	while(1){
		if(kbhit())
		{
			key=getch();
			clearCharacter(x,y);
			if(key==72) y=10; //up arrow
			if(key==80) y+=10; //down arrow
			if(key==75) x=10; //left arrow
			if(key==77) x+=10; //right arrow
			drawCharacter(x,y);
			if(x>200 && x<300 && y>200 && y<300){
				setcolor(RED);
				outtextxy(200,350,"GAME OVER!!!");
				break;
			}
		}
	}
	getch();
	delay(500);
}
