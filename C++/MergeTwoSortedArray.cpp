#include <iostream>
using namespace std;
//merge function
void merge(int f[],int s[],int u1, int v1)
{
 int i=0;
 int j=0;
 while(i<u1&&j<v1)
  {
   if(f[i]<s[j])
    {
        cout<<f[i++]<<" ";
    }
    else
      {
          cout<<s[j++]<<" ";
      }
 
  }
 while(i<u1){cout<<f[i++]<<" "; }
  while(j<v1){cout<<s[j++]<<" "; }
}
//main function
int main() {
    
    int s1=4;
    int s2=5;
    int first[]={11,16,21,45};
    int second[]={6,8,8,11,16};
	merge(first,second,s1,s2);
	return 0;
	
}
