/*
# PROGRAM : PROGRAM FOR LINE STYLES
# NAME : SHARVARI  S. WAGH
# SE-(A) ROLL NO : 73
#----------------------------------------------------------
Write a C++ program for line drawing using DDA or Bresenham algorithms with patterns such as
solid ,dotted,dashed,dash dot and thick.
*/


#include<iostream>
#include<graphics.h>

using namespace std;

class Pixel
{
	public:
		int x,y,iColor;
		void display_Pixel(int a,int b,int iC)
		{
			x=a;
			y=b;
			iColor=iC;
			putpixel(x,y,iC);
		}
};

class Line : public Pixel
{
	public:
		void draw_line(float fX1,float  fY1,float fX2,float fY2);	
		void dotted_line(float fX1,float  fY1,float fX2,float fY2);
		void dashed_line(float fX1,float  fY1,float fX2,float fY2);
};

void Line :: draw_line(float fX1,float fY1,float fX2,float fY2)
{
	float dx,dy,x,y;
	int len;
	dx=abs(fX2-fX1);
	dy=abs(fY2-fY1);
	if(dx>dy)
	{
		len=dx;
	}
	else
	{
		len=dy;
	}
	x=dx/len;
	y=dy/len;
	for(int i=0;i<=len;i++)
	{
		display_Pixel(floor(fX1),floor(fY1),10);
		fX1=fX1+x;
		fY1=fY1+y;
	}
	delay(20);
}

void Line :: dotted_line(float fX1,float fY1,float fX2,float fY2)
{
	float dx,dy,x,y;
	int len;
	dx=abs(fX2-fX1);
	dy=abs(fY2-fY1);
	if(dx>dy)
	{
		len=dx;
	}
	else
	{
		len=dy;
	}
	x=dx/len;
	y=dy/len;
	for(int i=0;i<=len;i++)
	{
		if(i%2==0)
		{
			display_Pixel(floor(fX1),floor(fY1),10);
		}
		fX1=fX1+x;
		fY1=fY1+y;
	}
	delay(50);
}

void Line :: dashed_line(float fX1,float fY1,float fX2,float fY2)
{
	float dx,dy,x,y;
	int len;
	dx=abs(fX2-fX1);
	dy=abs(fY2-fY1);
	if(dx>dy)
	{
		len=dx;
	}
	else
	{
		len=dy;
	}
	x=dx/len;
	y=dy/len;
	for(int i=0;i<=len;i++)
	{
		if(i%5!=0)
		{
			display_Pixel(floor(fX1),floor(fY1),10);
		}
		fX1=fX1+x;
		fY1=fY1+y;
	}
	delay(50);
}
                               
int main()
{
	Line l1;
	int gd,gm,iTh;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	float fX1,fY1,fX2,fY2,fWx,fWy;
	int iCh;
	do
	{
	here:	cout<<"\n-----------------------";
		cout<<"\n\tMENU";
		cout<<"\n-----------------------";
		cout<<"\n1.Solid line\n2.Dotted Line\n3.Dashed Line\n4.Thick line\n5.Exit";
		cout<<"\n-----------------------";
		cout<<"\nEnter your choice : ";
		cin>>iCh;
		switch(iCh)
		{
			case 1: cleardevice();
				cout<<"\nSOLID LINE";
				cout<<"\nEnter co-ordinates of starting point : ";
				cout<<"\nX co-ordinate : ";
				cin>>fX1;
				cout<<"\nY co-ordinate : ";
				cin>>fY1;
				cout<<"\nEnter co-ordinates of ending point : ";
				cout<<"\nX co-ordinate : ";
				cin>>fX2;
				cout<<"\nY co-ordinate : ";
				cin>>fY2;
				l1.draw_line(fX1,fY1,fX2,fY2);
				break;

			case 2: cleardevice();
				cout<<"\nDOTTED LINE";
				cout<<"\nEnter co-ordinates of starting point : ";
				cout<<"\nX co-ordinate : ";
				cin>>fX1;
				cout<<"\nY co-ordinate : ";
				cin>>fY1;
				cout<<"\nEnter co-ordinates of ending point : ";
				cout<<"\nX co-ordinate : ";
				cin>>fX2;
				cout<<"\nY co-ordinate : ";
				cin>>fY2;
				l1.dotted_line(fX1,fY1,fX2,fY2);
				break;

			case 3:	cleardevice();
				cout<<"\nDASHED LINE";
				cout<<"\nEnter co-ordinates of starting point : ";
				cout<<"\nX co-ordinate : ";
				cin>>fX1;
				cout<<"\nY co-ordinate : ";
				cin>>fY1;
				cout<<"\nEnter co-ordinates of ending point : ";
				cout<<"\nX co-ordinate : ";
				cin>>fX2;
				cout<<"\nY co-ordinate : ";
				cin>>fY2;
				l1.dashed_line(fX1,fY1,fX2,fY2);
				break;

			case 4: cleardevice();
				cout<<"\nTHICK LINE";
				cout<<"\nEnter co-ordinates of starting point : ";
				cout<<"\nX co-ordinate : ";
				cin>>fX1;
				cout<<"\nY co-ordinate : ";
				cin>>fY1;
				cout<<"\nEnter co-ordinates of ending point : ";
				cout<<"\nX co-ordinate : ";
				cin>>fX2;
				cout<<"\nY co-ordinate : ";
				cin>>fY2;
				cout<<"\nEnter Thickness : ";
				cin>>iTh;
				l1.draw_line(fX1,fY1,fX2,fY2);
				if((fY2-fY1)/(fX2-fX1)<1)
				{
					fWy=(iTh-1)*sqrt(pow((fX2-fX1),2)+pow((fY2-fY1),2))/(2*abs(fX2-fX1));
					for(int i=0;i<fWy;i++)
					{
						l1.draw_line(fX1,fY1-i,fX2,fY2-i);
						l1.draw_line(fX1,fY1+i,fX2,fY2+i);
					}
				}       
				else
				{
					fWx=(iTh-1)*sqrt(pow((fX2-fX1),2)+pow((fY2-fY1),2))/(2*abs(fY2-fY1));
					for(int i=0;i<fWx;i++)
					{
						l1.draw_line(fX1-i,fY1,fX2-i,fY2);
						l1.draw_line(fX1+i,fY1,fX2+i,fY2);
					}
				}
				break;
			
			case 5: exit(0);
		
			default:goto here;
		}	
	}while(iCh!=5);

	delay(5000);
	closegraph();
	return 0;
}

