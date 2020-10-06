#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int rr,cc,rA,cA,rB,cB,z=0,q,w,e,si[5][2],aaa[5][100][100];
int answer[5][100][100],temp[5][100][100],tmp[5][100][100];
int mtwo(int a[][100][100],int b[][100][100],int c[][100][100])
{
  if(cA!=rB)
  {
    printf("The value can't be computed!!!!\n");
    return 0;
  }
  for(int i=0;i<rr;i++)
  {
    for(int j=0;j<cc;j++)
    {
      int k=0;
      for(int x=0;x<cA;x++)
      {
        z++;
        int g=b[w][i][x],h=c[e][x][j];
        //printf("g= %d  h= %d\n",g,h);
        k+=(g*h);
      }
      a[q][i][j]=k;
    }
  }
  return z;
}

int main()
{
  int bb[5],r,c;
  char s[4]={'A','B','C','D'};
  memset(bb,0,sizeof(bb));
  for(int i=0;i<4;i++)
  {
    printf("Enter the number of rows and columns for matrix %c respectively:\n",s[i]);
    scanf("%d%d",&r,&c);
    si[i][0]=r,si[i][1]=c;
    printf("\n");
    printf("Enter the elements of the matrix %c:\n",s[i]);
    for(int j=0;j<r;j++)
    {
      for(int k=0;k<c;k++)
      scanf("%d",&aaa[i][j][k]);
    }
    printf("\n");
  }
  int n=1;
  while(n!=0)
  {
    printf("Press 1 to calculate ABCD:\n");
    printf("Press 2 to calculate (AB)(CD):\n");
    printf("Press 3 to calculate A(BC)D:\n");
    printf("Press 4 to calculate A((BC)D):\n");
    printf("Press 0 to exit and display the result:\n");
    scanf("%d",&n);
    switch(n)
    {
      case 1: rr=si[0][0],cc=si[1][1],rA=si[0][0],cA=si[0][1],rB=si[1][0],cB=si[1][1],q=0,w=0,e=1;
              int xy=mtwo(tmp,aaa,aaa);//A*b
              bb[0]+=xy;
              z=0;
              rr=si[0][0],cc=si[2][1],rA=si[0][0],cA=si[1][1],rB=si[2][0],cB=si[2][1],q=0,w=0,e=2;
              xy=mtwo(temp,tmp,aaa);//A*B*C
              bb[0]+=xy;
              z=0;
              rr=si[0][0],cc=si[3][1],rA=si[0][0],cA=si[2][1],rB=si[3][0],cB=si[3][1],q=0,w=0,e=3;
              xy=mtwo(answer,temp,aaa);//A*B*C*D
              bb[0]+=xy;
              z=0;
              printf("No of computations = %d\n",bb[0]);
              break;
      case 2: rr=si[0][0],cc=si[1][1],rA=si[0][0],cA=si[0][1],rB=si[1][0],cB=si[1][1],q=0,w=0,e=1;
              xy=mtwo(temp,aaa,aaa);//A*B
              bb[1]+=xy;
              z=0;
              rr=si[2][0],cc=si[3][1],rA=si[2][0],cA=si[2][1],rB=si[3][0],cB=si[3][1],q=0,w=2,e=3;
              xy=mtwo(tmp,aaa,aaa);//C*D
              bb[1]+=xy;
              z=0;
              rr=si[0][0],cc=si[3][1],rA=si[0][0],cA=si[1][1],rB=si[2][0],cB=si[3][1],q=1,w=0,e=0;
              xy=mtwo(answer,temp,tmp);//(AB)(CD)
              bb[1]+=xy;
              z=0;
              printf("No of computations = %d\n",bb[1]);
              break;
      case 3: rr=si[1][0],cc=si[2][1],rA=si[1][0],cA=si[1][1],rB=si[2][0],cB=si[2][1],q=0,w=1,e=2;
              xy=mtwo(temp,aaa,aaa);//B*C
              bb[2]+=xy;
              z=0;
              rr=si[0][0],cc=si[2][1],rA=si[0][0],cA=si[0][1],rB=si[1][0],cB=si[2][1],q=0,w=0,e=0;
              xy=mtwo(tmp,aaa,temp);//A*(BC)
              bb[2]+=xy;
              z=0;
              rr=si[0][0],cc=si[3][1],rA=si[1][0],cA=si[2][1],rB=si[3][0],cB=si[3][1],q=2,w=0,e=3;
              xy=mtwo(answer,tmp,aaa);//A(BC)D
              bb[2]+=xy;
              z=0;
              printf("No of computations = %d\n",bb[2]);
              break;
      case 4: rr=si[1][0],cc=si[2][1],rA=si[1][0],cA=si[1][1],rB=si[2][0],cB=si[2][1],q=0,w=1,e=2;
              xy=mtwo(tmp,aaa,aaa);//(BC)
              bb[3]+=xy;
              z=0;
              rr=si[1][0],cc=si[3][1],rA=si[1][0],cA=si[2][1],rB=si[3][0],cB=si[3][1],q=0,w=0,e=3;
              xy=mtwo(temp,tmp,aaa);//((BC)D)
              bb[3]+=xy;
              z=0;
              rr=si[0][0],cc=si[3][1],rA=si[0][0],cA=si[0][1],rB=si[1][0],cB=si[3][1],q=3,w=0,e=0;
              xy=mtwo(answer,aaa,temp);//A((BC)D)
              bb[3]+=xy;
              z=0;
              printf("No of computations = %d\n",bb[3]);
              break;
    }
  }
  char str[4][10]={"ABCD\0","(AB)(CD)\0","A(BC)D\0","A((BC)D)\0"};
  for(int i=0;i<4;i++)
  {
    printf("The value of %s is:\n",str[i]);
    for(int j=0;j<rr;j++)
    {
      for(int k=0;k<cc;k++)
      printf("%d ",answer[i][j][k]);
      printf("\n");
    }
    printf("\n");
    printf("The number of  scalar multiplication computations involved are %d\n",bb[i]);
  printf("\n\n---------------------------------------------------------------------\n\n\n");
  }
  int flag =1;
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<rr;j++)
    {
      for(int k=0;k<cc;k++)
      if(answer[i][j][k]!=answer[i+1][j][k])
      flag=0;
    }
  }
  if(flag)
  {
    printf("Thus from above results we can say that the matrix multiplication is Associative\n");
    int mn=10000000,index=0;
    for(int i=0;i<4;i++)
    {
      if(bb[i]<=mn)
      {
        mn=bb[i];
        index=i;
      }
    }
    printf("The optimal combination involving minimum scalar multiplication computations is %s having %d computations.\n",str[index],bb[index]);
  }
  else
  printf("\nThus from above results we can say that the matrix multiplication is not Associative\n");
return 0;
}
