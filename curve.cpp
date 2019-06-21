/*
# PROGRAM : PROGRAM FOR BEZIER CURVE
# NAME : SHARVARI  S. WAGH
# SE-(A) ROLL NO : 73
#----------------------------------------------------------
Write a C++ program to draw any objects such as flower,waves using
curve generation technique.
*/
#include<iostream>
#include<graphics.h>
using namespace std;

void generate_curve(int x[],int y[],int colour)
{
	int px,py;
	double t;
	for(t=0;t<=1;t=t+0.0005)
	{
		px=x[0]*(1-t)*(1-t)*(1-t)+3*x[1]*t*(1-t)*(1-t)+3*x[2]*(1-t)*t*t+x[3]*t*t*t;
		py=y[0]*(1-t)*(1-t)*(1-t)+3*y[1]*t*(1-t)*(1-t)+3*y[2]*(1-t)*t*t+y[3]*t*t*t;
		putpixel(px,py,colour);
	}
	
}

int main()
{
	int x[4],y[4],i;
	char ch;
	int gm,gd;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	
	do
	{
		cout<<"\nEnter the four control points : ";
		for(int i=0;i<4;i++)
		{
			cin>>x[i];
			cin>>y[i];
		}
		generate_curve(x,y,GREEN);
		cout<<"\nDo you want to continue?(y/n) : ";
		cin>>ch;
	}while(ch!='n');
	closegraph();
	return 0;
}
