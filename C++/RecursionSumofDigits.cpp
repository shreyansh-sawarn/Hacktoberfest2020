#include <iostream>
using namespace std;

int recursionfun(int n)
{
if(n<10)
return n;
return recursionfun(n/10)+n%10;
}
int main()
{
    int i=2323;
    int j=recursionfun(i);
    std::cout <<"sum of digit="<<j<< std::endl;
    return 0;
}
