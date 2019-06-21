/*
# PROGRAM : PROGRAM FOR COLOUR FILLING USING SCANLINE
# NAME : SHARVARI  S. WAGH
# SE-(A) ROLL NO : 73
#----------------------------------------------------------
Write a C++ program to fill polygon using scanline /flood fill/boundary fill algorithm
*/

#include<iostream>
#include<graphics.h>

using namespace std;

void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

class Polygon
{
	public:
		void initialize()
		{
			int gd,gm;
			gd=DETECT;
			initgraph(&gd,&gm,NULL);
		}
		void Scanline(int xx[20],int yy[20],int n)
		{
			int i,k,inter_x[50],temp,y,ymax=0,ymin=480,cnt;
			float m[50],dx,dy;
			
			for(int i=0;i<=n;i++)	
			{
				if(yy[i]>=ymax)
				{
					ymax=yy[i];
				}
				if(yy[i]<=ymin)
				{
					ymin=yy[i];
				}
				dx=xx[i+1]-xx[i];
				dy=yy[i+1]-yy[i];
				
				if(dx==0)
				{
					m[i]=0;
				}
				if(dy==0)
				{
					m[i]=1;
				}
				
				if(dx!=0 && dy!=0)
				m[i]=dy/dx;	
			}	
			for(y=ymax;y>=ymin;y--)  
			{
				cnt=0;
				for(int i=0;i<n;i++)
				{
					if((yy[i]>y && yy[i+1]<=y) || (yy[i]<=y && yy[i+1]>y))
					{
						inter_x[cnt]=(xx[i]+(m[i]*(y-yy[i])));
						cnt++;
					}
				}
				
				for(int k=0;k<cnt-1;k++)
				{
					for(int i=0;i<cnt-1;i++)
					{
						if(inter_x[i]>inter_x[i+1])
						{
							swap(inter_x[i],inter_x[i+1]);
						}
					}
				}
				
				for(int i=0;i<cnt-1;i++)
				{
					line(inter_x[i],y,inter_x[i+1],y);
					delay(100);
				}
			}
			
		}	
};

int main()
{
	Polygon p;
	int n,x[10],y[10];
	p.initialize();
	cout<<"\nEnter the number of vertices of the polygon : ";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter the co-ordinate of vertex "<<i+1<<" : ";
		cout<<"\nx co-ordinate : ";
		cin>>x[i];
		cout<<"\ny co-ordinate : ";
		cin>>y[i];
	}
	line(x[0],y[0],x[1],y[1]);
	for(int i=1;i<n-1;i++)
	{
		line(x[i],y[i],x[i+1],y[i+1]);
	}
	line(x[0],y[0],x[n-1],y[n-1]);
	p.Scanline(x,y,n);
	delay(1000);
	return 0;
}
