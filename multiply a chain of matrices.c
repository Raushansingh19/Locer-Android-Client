#include<stdio.h>
#include<stdlib.h>
int n,r1,c1,r2,c2,rr,cc;
void input(int a[rr][cc], int rr,int cc)
{
  printf("Enter the elements of the matrix:\n");
  for(int i=0;i<rr;i++)
  for(int j=0;j<cc;j++)
  scanf("%d",&a[i][j]);
}
void display(int a[rr][rr], int rr, int cc)
{
  printf("The Resultant matrix is:\n");
  for(int i=0;i<rr;i++)
  {
    for(int j=0;j<cc;j++)
    printf("%d ",a[i][j]);
    printf("\n");
  }
}
int mult(int a[rr][cc],int b[r1][c1],int c[r2][c2])
{
  if(c1!=r2)
  {
    printf("The value can't be computed!!!!\n");
    return 0;
  }
  for(int i=0;i < rr;i++)
  {
    for(int j=0;j < cc; j++)
    {
      int k=0;
      for(int x=0;x < c1;x++)
      {
        k+=(b[i][x]*c[x][j]);
      }
      a[i][j]=k;
    }
  }
  if(n==0)
  {
    display(a,rr,cc);
    return 0;
  }
  else
  {
    n--;
    printf("Enter number of rows and columns of the matrix number %d respectively:\n",n+1);
    scanf("%d%d",&r1,&c1);
    rr=r1,cc=c1;
    //int m1[r1][c1];
    input(b,r1,c1);
    r2=rr,c2=c1;
    mult(c,a,b);
  }
}
int main()
{
  printf("Enter the number of matrices to be multiplied:\n");
  scanf("%d",&n);
  n-=2;
  printf("Enter number of rows and columns of the matrix number 1 respectively:\n");
  scanf("%d%d",&r1,&c1);
  rr=r1,cc=c1;
  int m1[r1][c1];
  input(m1,r1,c1);
  printf("Enter number of rows and columns of the matrix number 2 respectively:\n");
  scanf("%d%d",&r2,&c2);
  rr=r2,cc=c2;
  int m2[r2][c2];
  input(m2,r2,c2);
  if(c1==r2)
  {
    rr=r1,cc=c2;
    int ans[rr][cc];
    mult(ans,m1,m2);
  }
  else
  printf("The value can't be computed!!!!\n");
  return 0;
}
