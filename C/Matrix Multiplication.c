#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    printf("Enter the number of rows in 1st matrix :");
    scanf("%d",&a);
    printf("Enter the number of columns in 1st matrix :");
    scanf("%d",&b);
    printf("The number of rows in 2nd matrix :%d\n",b);
    printf("Enter the number of columns in 2nd matrix :");
    scanf("%d",&c);

    int array[a][b];
    printf("Enter the values for 1st matrix-\n");
    for(int i=0;i<a;i++)
    {for(int j=0;j<b;j++)
      {printf("A[%d][%d] : ",i+1,j+1);
      scanf("%d",&array[i][j]);}}

    int array_[b][c];
    printf("Enter the values for 2nd matrix-\n");
    for(int i=0;i<b;i++)
    {for(int j=0;j<c;j++)
      {printf("B[%d][%d] : ",i+1,j+1);
      scanf("%d",&array_[i][j]);}}

    printf("\n\nThe resultant matrix AB on multiplication is of order :[%d][%d]\n\n",a,c);
    printf("The resultant matrix AB on multiplication is :\n\n");
    for(int i=0;i<a;i++)
  {
    for(int i_=0;i_<c;i_++)
    {int sum=0;
     for(int j=0;j<b;j++)
     {int a=array[i][j]*array_[j][i_];

     sum=sum+a;}
     {printf("   %d   ",sum);}
    }
    printf("\n");
  }
    return 0;
}
