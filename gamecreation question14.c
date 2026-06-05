#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void drawHouse(){
    rectangle(200,200,300,300);
    line(200,200,250,150);
    line(250,150,300,200);
    rectangle(230,250,270,300);
}

void drawCharacter(int x,int y){
    setcolor(WHITE);
    circle(x,y,10);
    line(x,y+10,x,y+30);
    line(x,y+30,x-10,y+40);
    line(x,y+30,x+10,y+40);
    line(x,y+15,x-10,y+20);
    line(x,y+15,x+10,y+20);
}

void clearCharacter(int x,int y){
    setcolor(BLACK);
    circle(x,y,10);
    line(x,y+10,x,y+30);
    line(x,y+30,x-10,y+40);
    line(x,y+30,x+10,y+40);
    line(x,y+15,x-10,y+20);
    line(x,y+15,x+10,y+20);
}

// obstacles
void drawObstacles(){
    setcolor(RED);
    rectangle(120,120,160,160);
    rectangle(350,220,390,260);
    rectangle(80,300,120,340);
}

void main(){
    int gd=DETECT,gm;
    int x=100,y=250;
    char key;

    initgraph(&gd,&gm,"C:\\TURBOC3\\bgi");

    drawHouse();
    drawObstacles();
    drawCharacter(x,y);

    while(1){
        if(kbhit()){
            key=getch();

            clearCharacter(x,y);

            // movement fix
            if(key==72) y-=10; // up
            if(key==80) y+=10; // down
            if(key==75) x-=10; // left
            if(key==77) x+=10; // right

            drawCharacter(x,y);

            // ? collision with obstacles ? GAME OVER
            if((x>120 && x<160 && y>120 && y<160) ||
               (x>350 && x<390 && y>220 && y<260) ||
               (x>80  && x<120 && y>300 && y<340)){
                setcolor(RED);
                outtextxy(200,350,"GAME OVER!");
                break;
            }

            // ?? win condition (enter house)
            if(x>200 && x<300 && y>200 && y<300){
                setcolor(GREEN);
                outtextxy(180,350,"CONGRATULATIONS! YOU ENTERED THE HOUSE");
                break;
            }
        }
    }

    getch();
    closegraph();
}
