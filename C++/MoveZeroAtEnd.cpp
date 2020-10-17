#include <iostream>
using namespace std;
void ZeroAtEnd(int a1[],int s1)
{
    int cou=0;
    for(int j=0;j<s1;j++)
    {
        if(a1[j]!=0)
        {
            swap(a1[cou++],a1[j]);
        }
    }
}
 void print(int array[],int s)
 {
     for(int i=0;i<s;i++)
     cout<<array[i]<<" ";
 }
int main(){
    int array1[]={0,11,0,9,12,0,15};
    int size=sizeof(array1)/sizeof(array1[0]);
    print(array1,size);//original input
      cout<<"\n";
    ZeroAtEnd(array1,size);
    print(array1,size);//changed array
	return 0;
}
