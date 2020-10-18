#include <iostream>
using namespace std;
void ReverseArray(int a1[],int s1)
{
    int lo=0,hi=s1-1;
    while(lo<hi)
    {
        int t=a1[lo];
        a1[lo]=a1[hi];
        a1[hi]=t;
        lo++;
        hi--;
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
    ReverseArray(array1,size);
    print(array1,size);//changed array
	return 0;
}
