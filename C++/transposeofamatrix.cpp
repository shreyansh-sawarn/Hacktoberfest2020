#include<iostream.h>
#include<conio.h>
#include<stdio.h>

int main()
{
    int a[10][10],transpose[10][10],row,column,i,j;
    cout<<"enter the number of rows and columns:";
    cin>>row>>column;
    cout<<"\nenter the rows and columns of matrix:" <<endl;
//ENTERING THE MATRIX
for(i=0; i<row; ++i)
{
    for(j=0;j<column;++j)
    {
        cout<< " enter element a" <<i+1<<j+1<<":";
        cin>>a[i][j];
    }
}
//DISPLAYING THE ENTERED MATRIX
cout<<"entered matrix:" <<endl;
for(int i=0; i<row; ++i)
{
    for(j=0;j<column;++j)
    {
      cout<< " "<<a[i][j];
      if(j==column-1)
      cout<<endl<<endl;
    }
}
//TRANSPOSE OF THE ROWS AND COLUMNS
for(i=0;i<row;++i)
{
    for(j=0;j<column;++j)
    {
    transpose[j][i]= a[i][j];
    }
}
//DISPLAYING THE TRANSPOSE
cout<<"transpoe of matrix:";
for( i=0;i<row;++i)
{
for(j=0;j<column;++j)
{
    cout<< " "<<transpose[i][j];
    if(j == row-1)
    cout<< endl <<endl;
}
}
return 0;
