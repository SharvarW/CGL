/*
# PROGRAM : LINE DRAWING ALGORITHMS
# NAME : SHARVARI  S.  WAGH
# SE-A(73)
#----------------------------------------------------------
#Write a C++ program to draw line using DDA and Bresenham’s algorithm Inherit pixel class and use
  function overloading.
*/
#include<iostream>
#include<graphics.h>
#include<cmath>
#include<cstdlib>
using namespace std;

class Pixel
{
        protected:
                int iX,iY,iColor;
                void set_pixel(int iX,int iY,int c)
                {
                        putpixel(iX,iY,c);
                }
        Pixel()
        {
                iX=iY=0;
                iColor=15;
        }      
};

class Line :  public Pixel
{
        public:
                void draw_line(int,int,int,int,int);         //Bresenham
                void draw_line(float,float,float,float,int); //DDA       
                
};

void Line :: draw_line(int iX1,int iY1,int iX2,int iY2,int iColor)
{
	int dx,dy;
	int iX=iX1;
	int iY=iY1;
	int iInterchange;
	int iG,iSx,iSy;
	 
	dx=abs(iX2-iX1);
	dy=abs(iY2-iY1);
	if(dy>dx)
	{
		iInterchange=1;
	}
	else 
	{
		iInterchange=0;
	}					//identify octant
			
	if(iY1>iY2)
		iSy=-1;	
	else
		iSy=+1;
	iG=2*dy-dx;			//initialize error term
			
	if(iX1>iX2)
		iSx=-1;
	else
		iSx=+1;
			
	for(int i=0;i<=dx;i++)
	{
		putpixel(iX,iY,iColor);
		while(iG>0)
		{
			if(iInterchange==1)
				iX=iX+iSx;
			
			else
				iY=iY+iSy;
					iG=iG-2*dx;
		}
		if(iInterchange==1)
			iY=iY+iSy;
		else
			iX=iX+iSx;
		iG=iG+2*dy;
	}
}

void Line :: draw_line(float fX1,float fY1,float fX2,float fY2,int iColor)
{
        float fDx,fDy,fLength,fX,fY;
        fDx=abs(fX2-fX1);
        fDy=abs(fY2-fY1);
        
        if(fDx>fDy)
        {
                cout<<"\nGentle Slope";
                fLength=fDx;
        }
        else
        {
                cout<<"\nSteep slope";
                fLength=fDy;
        }
        
        fX=(fX2-fX1)/fLength;
        fY=(fY2-fY1)/fLength;
        
        for(int i=0;i<fLength;i++)
        {
                set_pixel(floor(fX1),floor(fY1),iColor);
                fX1=fX1+fX;
                fY1=fY1+fY;
        }
        
        delay(1000);      
}

int main()
{
        Line l;
        int iCh,gd,gm;
        int iMidx,iMidy,iMaxx,iMaxy;
        gd=DETECT;
        initgraph(&gd,&gm,"C:\\TC\\BGI");
        iMaxx=getmaxx();
        iMaxy=getmaxy();
        iMidx=iMaxx/2;
        iMidy=iMaxy/2;
        line(iMidx,0,iMidx,iMaxy);
        line(0,iMidy,iMaxx,iMidy);
        float fX1,fX2,fY1,fY2;
	int iX1,iX2,iY1,iY2,iColor=GREEN;
        do
        {
        here:cout<<"\n--------------------";
                cout<<"\n\tMENU";
                cout<<"\n--------------------";
                cout<<"\n1.DDA\n2.Bresenham\n3.Exit";
                cout<<"\n--------------------";
                cout<<"\nEnter your choice: ";
                cin>>iCh;
                switch(iCh)
                {
                        case 1: cleardevice();
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
                                l.draw_line(fX1,fY1,fX2,fY2,iColor);
                                break;
                        
                        case 2: cleardevice();
					cout<<"\nEnter co-ordinates of starting point : ";
				cout<<"\nX co-ordinate : ";
				cin>>iX1;
				cout<<"\nY co-ordinate : ";
				cin>>iY1;
				cout<<"\nEnter co-ordinates of ending point : ";
				cout<<"\nX co-ordinate : ";
				cin>>iX2;
				cout<<"\nY co-ordinate : ";
				cin>>iY2;
                                l.draw_line(iX1,iY1,iX2,iY2,iColor);
                                break;
                                
                        case 3: exit(0);
                        
                        default: goto here;
                                        
                }
        }while(iCh!=3);
        delay(1000);
        closegraph();
return 0;
}
