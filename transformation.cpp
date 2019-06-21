/*
# PROGRAM : TO PERFORM 2-D TRANSFORMATIONS
# NAME : SHARVARI  S. WAGH
# SE-A (73)
#----------------------------------------------------------
#3.Write a C++ program to draw 2-D object and perform following basic transformations.
a.)Scaling
b.)Translation
c.)Rotation
use operator overloading
*/
#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

void display(int n,float c[][3])
{
	float maxx,maxy;
	int i=0;
	maxx=getmaxx();
	maxy=getmaxy();
	maxx=maxx/2;
	maxy=maxy/2;

	//draw polygon
	while(i<n-1)
	{
		line(maxx+c[i][0],maxy-c[i][1],maxx+c[i+1][0],maxy-c[i+1][1]);
		i++;
	}
	i=n-1;
	line(maxx+c[i][0],maxy-c[i][1],maxx+c[0][0],maxy-c[0][1]);

	//draw X-Y axis
	setcolor(WHITE);
	line(0,maxy,maxx*2,maxy);
	line(maxx,0,maxx,maxy*2);
	setcolor(WHITE);
}

void mult(int n,float b[][3],float c[][3],float a[][3])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			a[i][j]=0;
		}
	}
		

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				a[i][j]+=(c[i][k]*b[k][j]);
			}
		}
	}
}

void translation(int n,float c[][3],float tx,float ty)
{
	float b[10][3], a[10][3];
	int i=0,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			b[i][j]=0;
		}
	}
	b[0][0]=1;
	b[1][1]=1;
	b[2][0]=tx;
	b[2][1]=ty;
	b[2][2]=1;
	mult(n,b,c,a);
	setcolor(RED);
	display(n,a);
}

void scaling(int n,float c[][3],float sx,float sy)
{
	float b[10][3],a[10][3];
	int i=0,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			b[i][j]=0;
		}
	}
	b[0][0]=sx;
	b[1][1]=sy;
	b[2][2]=1;
	mult(n,b,c,a);
	setcolor(RED);
	display(n,a);
}

void rotation(int n,float c[][3], float ra)
{
	int i=0,j;
	float A;
	float b[10][3], xp,yp,a[10][3];
	xp=c[0][0];
	yp=c[0][1];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			b[i][j]=0;
		}
	}

	A=(ra*3.14)/180;
	b[0][0]=b[1][1]=cos(A);
	b[0][1]=sin(A);
	b[1][0]=-sin(A);
	b[2][0]=(-xp * cos(A)) + (yp * sin(A)) + xp;
	b[2][1]=(-xp * sin(A)) - (yp * cos(A)) + yp;
	b[2][2]=1;
	mult(n,b,c,a);
	setcolor(RED);
	display(n,a);
}

int get_polygon(float c[][3])
{
	int n;
	cout<<"\nEnter the number of vertices : ";
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cout<<"Enter the co-ordinates of vertex "<<i+1<<":";
		cin>>c[i][0]>>c[i][1];
		c[i][2]=1;
	}
	return n;
}

int main()
{
	cout<<"\n================================";
	cout<<"\n   2-D TRANSFORMATIONS";
	cout<<"\n================================";
	int i,iChoice,n,gd,gm;
	gd=DETECT;
	float c[10][3],tx,ty,sx,sy,fRadius;
	initgraph(&gd,&gm,NULL);
	n=get_polygon(c);

	do
	{
		cout<<"\n-------------------------";
		cout<<"\n\tMENU";
		cout<<"\n-------------------------";
		cout<<"\n1.Translation\n2.Scaling\n3.Rotation\n4.Exit";
		cout<<"\n-------------------------";
		cout<<"\nEnter your choice : ";
		cin>>iChoice;
		switch(iChoice)
		{
			case 1: cout<<"\nEnter Translation factors tx and ty :";
				cin>>tx>>ty;
				setcolor(BLUE);
				display(n,c);
				translation(n,c,tx,ty);
				break;

			case 2: cout<<"\nEnter the scaling factors sx and sy :";
				cin>>sx>>sy;
				setcolor(BLUE);
				display(n,c);
				scaling(n,c,sx,sy);
				break;

			case 3: cout<<"\nEnter the angle for rotation: ";
				cin>>fRadius;
				setcolor(BLUE);
				display(n,c);
				rotation(n,c,fRadius);
				break;

			case 4: exit(0);
			
			default:cout<<"\nEnter valid choice !";
				break;
		}

	}while(iChoice!=4);
	return 0;
}






