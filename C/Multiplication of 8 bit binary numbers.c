#include <stdio.h>
#include <stdlib.h>
int bin_to_dec(int a[16])
{
 int sum=0;
 int temp=1;
 for(int i=0;i<16;i++)
 {
 sum+=temp*a[i];
 temp*=2;
 }
 return sum;
}

int main(int argc,char *argv[])
{
    int n1;
    int n2;
    int arr1[8]={0};
    int arr2[8]={0};
    printf("Enter 8 bit multiplicand: ");
    scanf("%d",&n1);
    printf("Enter 8 bit multiplicand: ");
    scanf("%d",&n2);
    int i=0;
    int j=0;

    while(n1>0)
    {
        arr1[i]=n1%10;
        n1=n1/10;
        i++;
    }
    while(n2>0)
    {
        arr2[j]=n2%10;
        n2=n2/10;
        j++;
    }
    int mul[16]={0};
    for(int i=0;i<8;i++)
    {
        int par_mul[16]={0};
        for(int j=0;j<8;j++)
        {
            par_mul[i+j]=arr1[j]*arr2[i];
        }
        int res[16]={0};
        int carry=0;
        for(int i=0;i<16;i++)
        {
            res[i]=(mul[i]+par_mul[i]+carry)%2;
            carry=(mul[i]+par_mul[i]+carry)/2;
        }
        for(int i=0;i<16;i++)
            mul[i]=res[i];
    }
    printf("Product in binary: ");
    for(int i=0;i<16;i++)
        printf("%d",mul[16-i-1]);
    printf("\nProduct in Decimal: %d",bin_to_dec(mul));
}
