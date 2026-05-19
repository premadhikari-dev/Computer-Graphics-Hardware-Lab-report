#include <stdio.h>
#include <math.h>
#include <graphics.h>

void main() {
    int rcode1[4] = {0,0,0,0}, rcode2[4] = {0,0,0,0}, rcode[4];
    int wxmax, wymax, wxmin, wymin;
    int x, y, x1, y1, i;
    float slope;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("\nNow, Enter X-Min, Y-Min: ");
	scanf("%d %d", &wxmin, &wymin);
	printf("\nNow Enter X-Max, Y-Max: ");
	scanf("%d %d", &wxmax, &wymax);
	printf("\nNow, Enter initial points x and y: ");
	scanf("%d %d", &x, &y);
	printf("\nNow, Enter final points x1 and y1: ");
	scanf("%d %d", &x1, &y1);

    cleardevice();
    rectangle(wxmin, wymin, wxmax, wymax);
    line(x, y, x1, y1);

    // Assign region codes
    if(y > wymax) rcode1[0] = 1; // Top
    if(y < wymin) rcode1[1] = 1; // Bottom
    if(x > wxmax) rcode1[2] = 1; // Right
    if(x < wxmin) rcode1[3] = 1; // Left

    if(y1 > wymax) rcode2[0] = 1;
    if(y1 < wymin) rcode2[1] = 1;
    if(x1 > wxmax) rcode2[2] = 1;
    if(x1 < wxmin) rcode2[3] = 1;

    // Trivial reject
    for(i = 0; i < 4; i++) {
        rcode[i] = rcode1[i] && rcode2[i];
        if(rcode[i] == 1) {
            printf("\nLine is completely outside the window.");
            getch();
            closegraph();
            return;
        }
    }

    // Calculate slope safely
    if(x1 != x)
        slope = (float)(y1 - y) / (x1 - x);
    else
        slope = 99999; // vertical line

    // Clip first point
    if(rcode1[3]) { y = y + (wxmin - x) * slope; x = wxmin; }
    if(rcode1[2]) { y = y + (wxmax - x) * slope; x = wxmax; }
    if(rcode1[0]) { x = x + (wymax - y) / slope; y = wymax; }
    if(rcode1[1]) { x = x + (wymin - y) / slope; y = wymin; }

    // Clip second point
    if(rcode2[3]) { y1 = y1 + (wxmin - x1) * slope; x1 = wxmin; }
    if(rcode2[2]) { y1 = y1 + (wxmax - x1) * slope; x1 = wxmax; }
    if(rcode2[0]) { x1 = x1 + (wymax - y1) / slope; y1 = wymax; }
    if(rcode2[1]) { x1 = x1 + (wymin - y1) / slope; y1 = wymin; }

    // Draw clipped line
    getch();
    clearviewport();
    rectangle(wxmin, wymin, wxmax, wymax);
    setcolor(RED);
    line(x, y, x1, y1);
    getch();
    closegraph();
}

