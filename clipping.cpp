/*
# PROGRAM : PROGRAM FOR LINE CLIPPING
# NAME : SHARVARI  S. WAGH
# SE-(A) ROLL NO : 73
#----------------------------------------------------------
Write a C++ program to implement cohen sutherland line clipping for given window.
*/
#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

static int LEFT=1,RIGHT=2,BOTTOM=4,ABOVE=8;
int code,xl,yl,xh,yh;

int get_code(int x,int y)			//perform bitwise OR to get outcode
{
	int code=0;
	if(y>yh)
		code|=ABOVE;
		
	if(y<yl)
		code|=BOTTOM;
		
	if(x<xl)
		code|=LEFT;
		
	if(x>xh)
		code|=RIGHT;
	
	return code;
}

int main()
{
	int gd,gm;
	gd=DETECT;
	
	initgraph(&gd,&gm,NULL);
	setcolor(BLUE);
	
	cout<<"\nEnter BOTTOM,LEFT,TOP and RIGHT co-ordinates of window\n";
	cin>>xl>>yl>>xh>>yh;
	rectangle(xl,yl,xh,yh);
	int x1,y1,x2,y2;
	
	cout<<"\nEnter the starting point of the line : ";
	cout<<"\nX co-ordinate : ";
	cin>>x1;
	cout<<"\nY co-ordinate : ";
	cin>>y1;
	
	cout<<"\nEnter the ending point of the line : ";
	cout<<"\nX co-ordinate : ";
	cin>>x2;
	cout<<"\nY co-ordinate : ";
	cin>>y2;
	
	line(x1,y1,x2,y2);
	delay(1000);
	
	int outcode1,outcode2;
	outcode1=get_code(x1,y1);
	outcode2=get_code(x2,y2);
	int flag=0;//decides if line is to be drawn
	while(1)
	{
		float m=(float)(y2-y1)/(x2-x1);	//both points inside ,flag line
		
		if(outcode1==0&&outcode2==0)
		{
			flag=1;
			break;
		}
		
		else if((outcode1 & outcode2)!=0)	//ANDof both codes!=0.line is outside .reject line
		{
			break;
		}
		else
		{
			int x,y;
			int temp;
			if(outcode1==0)
			temp=outcode2;
			else
			temp=outcode1;
		 
		 	if(temp&ABOVE)		//line clips top edges
			{
				x=x1+(yh-y1)/m;
				y=yh;
			}
		
			else if(temp&BOTTOM)
			{
				x=x1+(yl-y1)/m;
				y=yh;
			}
		
			if(temp&LEFT)
			{
				x=xl;
				y=y1+(xl-x1)/m;
			}
 		
			if(temp&RIGHT)
			{
				x=xh;
				y=y1+m*(xh-x1);
			}
			
			if(outcode1==temp)
			{
				x1=x;
				y1=y;
				outcode1=get_code(x1,y1);
			}
			else
			{
				x2=x;
				y2=y;
				outcode2=get_code(x2,y2);
			}
		}
	}
	setcolor(WHITE);
	cout<<"\nAfter clipping\n";
	if(flag==1)
	line(x1,y1,x2,y2);
	delay(1000);
	closegraph();
	
	return 0;
}
