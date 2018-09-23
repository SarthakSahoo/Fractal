#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
void pattern(int,int,int,int,int,int,int);
void fill(int x,int y)
{
	int i = getpixel(x,y);
	if(i == 0)
	{
		putpixel(x,y,WHITE);
		fill(x,y+1);
		fill(x,y-1);
		fill(x+1,y);
		fill(x-1,y);
	}
}
void main()
{
	int x1,x2,x3,y1,y2,y3,order;
	int gd=DETECT,gm;
	printf("enter the co-ordinates\n");
	scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
	printf("\n Enter the order:");
	scanf("%d",&order);
	initgraph(&gd,&gm,"");
	setcolor(5);
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
	pattern(x1,y1,x2,y2,x3,y3,order);
	sleep(10);
	closegraph();
}
void pattern(int x1,int y1,int x2,int y2,int x3,int y3,int t)
{
	float x11,x22,y11,y22,x33,y33;
	x11=(x1+x2)/2.0;
	y11=(y1+y2)/2.0;

	x22=(x2+x3)/2.0;
	y22=(y2+y3)/2.0;

	x33=(x1+x3)/2.0;
	y33=(y1+y3)/2.0;

	line(x11,y11,x22,y22);
	line(x22,y22,x33,y33);
	line(x33,y33,x11,y11);
	if(t==1)
	{
		fill((x1+x11+x33)/3,(y1+y11+y33)/3);
		fill((x11+x22+x2)/3,(y11+y22+y2)/3);
		fill((x33+x22+x3)/3,(y33+y22+y3)/3);
		return;
	}
	pattern(x1,y1,x11,y11,x33,y33,t-1);
	pattern(x11,y11,x22,y22,x2,y2,t-1);
	pattern(x33,y33,x22,y22,x3,y3,t-1);
}







