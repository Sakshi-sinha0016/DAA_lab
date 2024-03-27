#include<stdio.h>
int PutPar(int s[][6],int i,int j,int* p)
{
	if(i==j)
	{
		printf("%d",p[i]);
	}
	else
	{
		printf("(");
		PutPar(s,i,s[i][j],p);
		PutPar(s,s[i][j]+1,j,p);
		printf(")");
	}
}
int main()
{
	int p[100],no,n,m[6][6],s[6][6],l,j,k,i,q;
	printf("enter no i.e length of array");
	scanf("%d",&no);
	printf("Enter numbers in to array");
	for(int i=0;i<=no;i++)
	{
		scanf("%d",&p[i]);
	}
	printf("Array is:\n");
	for(i=0;i<=no;i++)
	{
		printf("%d \t",p[i]);
	}
	printf("\n");
	n=no;
	for(i=1;i<=n;i++)
	{
		m[i][i]=0;
	}
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=(n-1+1);i++)
		{
			j=i+l-1;
			m[i][j]=9999999;
			for(k=i;k<j;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q< m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	printf("optimal solution is:");
	PutPar(s,1,n,p);
	printf("\n");
	return 0;
}
