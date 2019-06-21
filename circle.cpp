/*
# PROGRAM : PROGRAM FOR CIRCLE DRAWING USING BRESENHEM
# NAME : SHARVARI  S. WAGH
# SE-(A) ROLL NO : 73
#----------------------------------------------------------
#Write a C++ program to draw circle using Bresenham’s algorithm.Inherit pixel class.
*/

#include<iostream>
#include<graphics.h>
#include<cstdlib>

using namespace std;

class Pixel
{
	public:
		void setpixel(int x1,int y1,int color)
		{
			putpixel(x1,y1,color);
		}
};

class Bresenhem_circle : public Pixel
{
	public:
		int xi,yi,s,di;
		void display();
		void B_circle(int ,int ,int );
		void mh();
		void mv();
		void md();
};

void Bresenhem_circle :: display()
{
	float maxx,maxy;
	
	maxx=getmaxx();
	maxy=getmaxy();
	maxx=maxx/2;
	maxy=maxy/2;
	
	setcolor(GREEN);
	line(0,maxy,maxx*2,maxy);
	line(maxx,0,maxx,maxy*2);
	
}

void Bresenhem_circle :: mh()
{
	xi=xi+1;	
	di=di+2*xi+1;
}

void Bresenhem_circle :: mv()
{
	yi=yi-1;	
	di=di-2*yi+1;
}

void Bresenhem_circle :: md()
{
	xi=xi+1;
	yi=yi-1;	
	di=di+2*xi-2*yi+2;
}

void Bresenhem_circle :: B_circle(int xc,int yc,int r)
{
	int limit=0;
	di=2*(1-r);
	xi=0;
	yi=r;


	float maxx,maxy;
	
	maxx=getmaxx();
	maxy=getmaxy();
	maxx=maxx/2;
	maxy=maxy/2;
	
	while(yi>=limit)
	{
		delay(5);
		setpixel((xi+xc)+maxx,maxy-(yc+yi),15);		//from -y to x
		delay(5);
		setpixel((xc-xi)+maxx,maxy-(yc-yi),15);
		delay(5);
		setpixel((xc+xi)+maxx,maxy-(yc-yi),15);
		delay(5);
		setpixel((xc-xi)+maxx,maxy-(yc+yi),15);
		
		if(di<0)
		{
			s=2*di+2*yi-1;
			if(s<=0)
			mh();
		
			else 
			md();
		}
		else
		{
			if(di>0)
			{
				s=2*di-2*xi-1;
				if(s<=0)
					md();
				else 
					mv();
			}
			else
				if(di==0)
				md();
		}
	}//end of while
}

int main()
{
	Bresenhem_circle b;
	float x,y,r;
	cout<<"\n======================================";
	cout<<"\n  BRESENHEM CIRCLE DRAWING ALGORITHM";
	cout<<"\n======================================\n\n";
	cout<<"\nEnter the co-ordinates :";
	cout<<"\nX co-ordinate : ";
	cin>>x;	
	cout<<"\nY co-ordinate : ";
	cin>>y;	
	cout<<"\nEnter the radius :";
	cin>>r;
	cout<<"\n--------------------------------------";
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	b.display();
	delay(20);
	b.B_circle(x,y,r);
	delay(10000);
	closegraph();
	return 0;

}
