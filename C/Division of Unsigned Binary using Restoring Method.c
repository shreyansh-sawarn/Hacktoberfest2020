#include <stdio.h>
void sum(int a1[9],int a2[9])
{
    int carry=0,temp=0;;
    for(int i=0;i<9;i++)
    {
        temp=a1[i]+a2[i]+carry;
        a1[i]=(temp)%2;
        carry=(temp)/2;
    }
}
void com(int a[9])
{
    for(int i=0;i<9;i++)
        if(a[i]==0)
            a[i]=1;
        else
            a[i]=0;
}
int bin_to_dec(int a[8])
{
    int sum=0;
    int temp=1;
    for(int i=0;i<8;i++)
    {
        sum+=temp*a[i];
        temp*=2;
    }
    return sum;
}
int main()
{
    int n1;
    int n2;
    int Q[8]={0};
    int M[9]={0};
    int A[9]={0};
    int one[9]={1,0,0,0,0,0,0,0,0};
    printf("Enter Dividend:");
    scanf("%d",&n1);
    printf("Enter Divisor:");
    scanf("%d",&n2);
    int i=0;
    int j=0;
    while(n1>0)
    {
        Q[i]=n1%10;
        n1=n1/10;
        i++;
    }
    int n=i;
    while(n2>0)
    {
        M[j]=n2%10;
        n2=n2/10;
        j++;
    }
    int A_t[9];
    com(M);
    sum(M,one);
    for(int num=0;num<n;num++)
    {
        for(int i=8;i>0;i--)
            A[i]=A[i-1];
        A[0]=Q[n-1];
        for(int i=0;i<9;i++)
            A_t[i]=A[i];
        for(int i=n-1;i>0;i--)
            Q[i]=Q[i-1];
        sum(A,M);
        if(A[8]==1)
            Q[0]=0;
        else
            Q[0]=1;
        if(A[8]==1)
            for(int i=0;i<9;i++)
                A[i]=A_t[i];
    }
    printf("Quotient in binary:");
    for(int i=0;i<8;i++)
        printf("%d",Q[7-i]);
    printf("\nQuotient in Decimal: %d ",bin_to_dec(Q));
    printf("\nRemainer in binary:");
    for(int i=0;i<8;i++)
        printf("%d",A[7-i]);
    printf("\nRemainer in Decimal: %d ",bin_to_dec(A));
}
