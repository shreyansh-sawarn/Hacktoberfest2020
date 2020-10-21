#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

float f(vector<float>v,int n)
{
    float res;
    if(n>2)
    {
        float sum=0;
        float c=1;
        for(int k=0;k<n;k++)
        {

            vector<float>v1;
            for(int i=1;i<n;i++)
                for(int j=0;j<n;j++)
                    if(j!=k)
                    {
                        v1.push_back(v[i*n+j]);
                    }
            sum+=c*v[k]*f(v1,n-1);
            c*=(-1);
        }
        return sum;
    }
    else if(n==2)
    {
        res=v[0]*v[3]-v[1]*v[2];
    }
    return res;
}

float *f1(vector<float>v,int n)
{
    static float r[144];
    if(n>2)
    {
        for(int k=0;k<n;k++)
            for(int l=0;l<n;l++)
            {
                vector<float>v1;
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                        if(j!=l && i!=k)
                        {
                            v1.push_back(v[i*n+j]);
                        }
                r[k*n+l]=f(v1,n-1);
            }
    }
    else if(n==2)
    {
        for(int i=0;i<4;i++)
            r[i]=v[3-i];
    }
    return r;
}

int main()
{
   int n;
   cout<<"Enter the order of the square matrix: ";
   cin>>n;
   float a[n][n];
   vector<float>v;
   for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        cout << "Enter a["<<i+1<<"]["<<j+1<<"]: ";
        cin >> a[i][j];
        v.push_back(a[i][j]);
    }
    cout<<"\nGiven matrix is:\n";
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
    float det=f(v,n);
    if(det==0)
    {
        cout<<"\nInverse of the matrix does not exist.\nMatrix is singular.\n";
    }
    else
    {
        float *p=f1(v,n);
        cout<<"\nInverse of the matrix is :\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cout<<pow(-1,i+j)*p[j*n+i]/det<<"  ";
            cout<<endl;
        }
    }
    return 0;
}
