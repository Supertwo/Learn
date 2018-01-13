#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define width 6
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))


void matPrint(double A[width][width]);
int match(double A[width][width], double B[width][width]);

int Rc(double A[width], double B[width], double C[width]);
int Rs(double A[width], double B[width], double C[width]);
int Rg(double A[width], double B[width], double C[width]);
int Rsg(double A[width], double B[width], double C[width]);
int Rgg(double A[width], double B[width], double C[width]);
int Rgs(double A[width], double B[width], double C[width]);
int Rss(double A[width], double B[width], double C[width]);
int Rb(double A[width], double B[width], double C[width]);
int Rstar(double A[width], double B[width], double C[width]);
int Ro(double A[width], double B[width], double C[width]);



void main()
{
	int i = 0;
	int j = 0;
	int rc,rs,rg,rsg,rgg,rgs,rss,rb,rstar,ro;
	double F[] = { 1,0.8,0.5,0.4,0.1,0 };
	double G[] = { 0,0.1,0.2,0.4,0.6,0.8 };
	double H[] = { 0,0,0.2,0.5,0.8,1 };
	double oneMatrix[width][width];
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			oneMatrix[i][j] = 1;
		}
	}
	rc = Rc(F, G, H);
	rs = Rs(F, G, H);
	rg = Rg(F, G, H);
	rsg = Rsg(F, G, H);
	rgg = Rgg(F, G, H);
	rgs = Rgs(F, G, H);
	rss = Rss(F, G, H);
	rb = Rb(F, G, H);
	rstar = Rstar(F, G, H);
	printf("rc = %d\nrs = %d\nrg = %d\nrsg = %d\nrgg = %d\nrgs = %d\nrss = %d\nrb = %d\nrstar = %d\n", rc,rs,rg,rsg,rgg,rgs,rss,rb,rstar);
}

void matPrint(double A[width][width])
{
	int i = 0;
	int j = 0;
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			printf("%.1f\t", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int match(double A[width][width], double B[width][width])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (A[i][j] != B[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}

int Rc(double A[width], double B[width], double C[width])
{
	int i = 0;
	int j = 0;
	double fg[width][width];
	double gh[width][width];
	double fh[width][width];
	double fgh[width][width];
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			fg[i][j] = Min(A[i], B[j]);
			gh[i][j] = Min(B[i], C[j]);
			fh[i][j] = Min(A[i], C[j]);
		}
	}
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			fgh[i][j] = Max(Max(Max(Min(fg[i][0], gh[0][j]), Min(fg[i][1], gh[1][j])), Max(Min(fg[i][2], gh[2][j]), Min(fg[i][3], gh[3][j]))), Max(Min(fg[i][4], gh[4][j]), Min(fg[i][5], gh[5][j])));
		}
	}
	matPrint(fg);
	matPrint(gh);
	matPrint(fh);
	matPrint(fgh);
	return	match(fh, fgh);
}

int Rs(double A[width], double B[width], double C[width])
{
	int i = 0;
	int j = 0;
	double fg[width][width];
	double gh[width][width];
	double fh[width][width];
	double fgh[width][width];
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			fg[i][j] = (A[i]>B[j]) ? 0 : 1;
			gh[i][j] = (A[i]>B[j]) ? 0 : 1;
			fh[i][j] = (A[i]>B[j]) ? 0 : 1;
		}
	}
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			fgh[i][j] = Max(Max(Max(Min(fg[i][0], gh[0][j]), Min(fg[i][1], gh[1][j])), Max(Min(fg[i][2], gh[2][j]), Min(fg[i][3], gh[3][j]))), Max(Min(fg[i][4], gh[4][j]), Min(fg[i][5], gh[5][j])));
		}
	}
	matPrint(fg);
	matPrint(gh);
	matPrint(fh);
	matPrint(fgh);
	return	match(fh, fgh);
}

int Rg(double A[width], double B[width], double C[width])
{
	int i = 0;
	int j = 0;
	double fg[width][width];
	double gh[width][width];
	double fh[width][width];
	double fgh[width][width];
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			fg[i][j] = (A[i]>B[j]) ? B[j] : 1;
			gh[i][j] = (B[i]>C[j]) ? C[j] : 1;
			fh[i][j] = (A[i]>C[j]) ? C[j] : 1;
		}
	}
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			fgh[i][j] = Max(Max(Max(Min(fg[i][0], gh[0][j]), Min(fg[i][1], gh[1][j])), Max(Min(fg[i][2], gh[2][j]), Min(fg[i][3], gh[3][j]))), Max(Min(fg[i][4], gh[4][j]), Min(fg[i][5], gh[5][j])));
		}
	}
	matPrint(fg);
	matPrint(gh);
	matPrint(fh);
	matPrint(fgh);
	return	match(fh, fgh);
}

int Rsg(double A[width], double B[width], double C[width])
{
	int i = 0;
	int j = 0;
	double fg[width][width];
	double gh[width][width];
	double fh[width][width];
	double fgh[width][width];
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			fg[i][j] = Min(A[i] > B[j] ? 0 : 1, (1 - A[i]) > (1 - B[j]) ? (1 - B[j]) : 1);
			gh[i][j] = Min(B[i] > C[j] ? 0 : 1, (1 - B[i]) > (1 - C[j]) ? (1 - C[j]) : 1);
			fh[i][j] = Min(A[i] > C[j] ? 0 : 1, (1 - A[i]) > (1 - C[j]) ? (1 - C[j]) : 1);
		}
	}
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			fgh[i][j] = Max(Max(Max(Min(fg[i][0], gh[0][j]), Min(fg[i][1], gh[1][j])), Max(Min(fg[i][2], gh[2][j]), Min(fg[i][3], gh[3][j]))), Max(Min(fg[i][4], gh[4][j]), Min(fg[i][5], gh[5][j])));
		}
	}
	matPrint(fg);
	matPrint(gh);
	matPrint(fh);
	matPrint(fgh);
	return	match(fh, fgh);
}

int Rgg(double A[width], double B[width], double C[width])
{
	int i = 0;
	int j = 0;
	double fg[width][width];
	double gh[width][width];
	double fh[width][width];
	double fgh[width][width];
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			fg[i][j] = Min(A[i] > B[j] ? B[j] : 1, (1 - A[i]) >(1 - B[j]) ? (1 - B[j]) : 1);
			gh[i][j] = Min(B[i] > C[j] ? C[j] : 1, (1 - B[i]) > (1 - C[j]) ? (1 - C[j]) : 1);
			fh[i][j] = Min(A[i] > C[j] ? C[j] : 1, (1 - A[i]) > (1 - C[j]) ? (1 - C[j]) : 1);
		}
	}
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			fgh[i][j] = Max(Max(Max(Min(fg[i][0], gh[0][j]), Min(fg[i][1], gh[1][j])), Max(Min(fg[i][2], gh[2][j]), Min(fg[i][3], gh[3][j]))), Max(Min(fg[i][4], gh[4][j]), Min(fg[i][5], gh[5][j])));
		}
	}
	matPrint(fg);
	matPrint(gh);
	matPrint(fh);
	matPrint(fgh);
	return	match(fh, fgh);
}

int Rgs(double A[width], double B[width], double C[width])
{
	int i = 0;
	int j = 0;
	double fg[width][width];
	double gh[width][width];
	double fh[width][width];
	double fgh[width][width];
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			fg[i][j] = Min(A[i] > B[j] ? B[j] : 1, (1 - A[i]) >(1 - B[j])  ? 0 : 1);
			gh[i][j] = Min(B[i] > C[j] ? C[j] : 1, (1 - B[i]) > (1 - C[j]) ? 0 : 1);
			fh[i][j] = Min(A[i] > C[j] ? C[j] : 1, (1 - A[i]) > (1 - C[j]) ? 0 : 1);
		}
	}
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			fgh[i][j] = Max(Max(Max(Min(fg[i][0], gh[0][j]), Min(fg[i][1], gh[1][j])), Max(Min(fg[i][2], gh[2][j]), Min(fg[i][3], gh[3][j]))), Max(Min(fg[i][4], gh[4][j]), Min(fg[i][5], gh[5][j])));
		}
	}
	matPrint(fg);
	matPrint(gh);
	matPrint(fh);
	matPrint(fgh);
	return	match(fh, fgh);
}

int Rss(double A[width], double B[width], double C[width])
{
	int i = 0;
	int j = 0;
	double fg[width][width];
	double gh[width][width];
	double fh[width][width];
	double fgh[width][width];
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			fg[i][j] = Min(A[i] > B[j] ? 0 : 1, (1 - A[i]) > (1 - B[j]) ? 0 : 1);
			gh[i][j] = Min(B[i] > C[j] ? 0 : 1, (1 - B[i]) > (1 - C[j]) ? 0 : 1);
			fh[i][j] = Min(A[i] > C[j] ? 0 : 1, (1 - A[i]) > (1 - C[j]) ? 0 : 1);
		}
	}
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			fgh[i][j] = Max(Max(Max(Min(fg[i][0], gh[0][j]), Min(fg[i][1], gh[1][j])), Max(Min(fg[i][2], gh[2][j]), Min(fg[i][3], gh[3][j]))), Max(Min(fg[i][4], gh[4][j]), Min(fg[i][5], gh[5][j])));
		}
	}
	matPrint(fg);
	matPrint(gh);
	matPrint(fh);
	matPrint(fgh);
	return	match(fh, fgh);
}

int Rb(double A[width], double B[width], double C[width])
{
	int i = 0;
	int j = 0;
	double fg[width][width];
	double gh[width][width];
	double fh[width][width];
	double fgh[width][width];
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			fg[i][j] = Max(1 - A[i], B[j]);
			gh[i][j] = Max(1 - B[i], C[j]);
			fh[i][j] = Max(1 - A[i], C[j]);
		}
	}
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			fgh[i][j] = Max(Max(Max(Min(fg[i][0], gh[0][j]), Min(fg[i][1], gh[1][j])), Max(Min(fg[i][2], gh[2][j]), Min(fg[i][3], gh[3][j]))), Max(Min(fg[i][4], gh[4][j]), Min(fg[i][5], gh[5][j])));
		}
	}
	matPrint(fg);
	matPrint(gh);
	matPrint(fh);
	matPrint(fgh);
	return	match(fh, fgh);
}

int Rstar(double A[width], double B[width], double C[width])
{
	int i = 0;
	int j = 0;
	double fg[width][width];
	double gh[width][width];
	double fh[width][width];
	double fgh[width][width];
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			fg[i][j] = 1 - A[i] + A[i] * B[j];
			gh[i][j] = 1 - B[i] + B[i] * C[j];
			fh[i][j] = 1 - A[i] + A[i] * C[j];
		}
	}
	for (i = 0; i<width; i++)
	{
		for (j = 0; j<width; j++)
		{
			fgh[i][j] = Max(Max(Max(Min(fg[i][0], gh[0][j]), Min(fg[i][1], gh[1][j])), Max(Min(fg[i][2], gh[2][j]), Min(fg[i][3], gh[3][j]))), Max(Min(fg[i][4], gh[4][j]), Min(fg[i][5], gh[5][j])));
		}
	}
	matPrint(fg);
	matPrint(gh);
	matPrint(fh);
	matPrint(fgh);
	return	match(fh, fgh);
}