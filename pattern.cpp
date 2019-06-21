/*
# PROGRAM : PROGRAM FOR PATTERN DRAWING
# NAME : SHARVARI  S. WAGH
# SE-(A) ROLL NO : 73
#----------------------------------------------------------
Write a C++ program to draw the following pattern using any line drawing algorithms
*/

#include<iostream>
#include<graphics.h>
#include<cmath>

using namespace std;

class Pixel
{
	public:
		float fX,fY;
		int iColor;
		void setpixel(float a,float b)
		{
			fX=a;
			fY=b;
		}
		void setcolor(int c)
		{
			iColor=c;
		}
		void plot()
		{
			putpixel(fX,fY,iColor);
		}
		void plot(float a,float b,int c)
		{
			setcolor(c);
			setpixel(a,b);
			plot();
		}
};

class Line : public Pixel
{
	public:
		void DDA_line(float fX1,float fY1,float fX2,float fY2,int iColor)
		{

			float fDx,fDy,fLength,fX,fY;
			fDx=abs(fX2-fX1);
			fDy=abs(fY2-fY1);
		
			if(fDx>fDy)
			{
				fLength=fDx;
			}
			else
			{
				fLength=fDy;
			}
		
			fX=(fX2-fX1)/fLength;
			fY=(fY2-fY1)/fLength;
		
			for(int i=0;i<fLength;i++)
			{
				plot(floor(fX1),floor(fY1),iColor);
				delay(5);
				fX1=fX1+fX;
				fY1=fY1+fY;
			}
			delay(10);      
		}//end of dda
};

int main()
{
	Line m;
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);

	m.DDA_line(100,100,300,100,BLUE);			
	delay(500);
	m.DDA_line(300,100,300,300,BLUE);
	delay(500);
	m.DDA_line(300,300,100,300,BLUE);
	delay(500);
	m.DDA_line(100,300,100,100,BLUE);

	m.DDA_line(200,100,100,200,CYAN);
	delay(500);
	m.DDA_line(100,200,200,300,CYAN);		
	delay(500);
	m.DDA_line(200,300,300,200,CYAN);
	delay(500);
	m.DDA_line(300,200,200,100,CYAN);
	delay(1000);

	m.DDA_line(150,150,250,150,GREEN);
	delay(500);
	m.DDA_line(250,150,250,250,GREEN);		
	delay(500);
	m.DDA_line(250,250,150,250,GREEN);
	delay(500);
	m.DDA_line(150,250,150,150,GREEN);
	delay(1000);
	
	circle(200,200,141);
	delay(2000);

	return 0;
	
}
