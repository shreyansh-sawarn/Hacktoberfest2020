/* Problem Introduction
The least common multiple of two positive integers 𝑎 and 𝑏 is the least positive
integer 𝑚 that is divisible by both 𝑎 and 𝑏.
Problem Description
Task. Given two integers 𝑎 and 𝑏, find their least common multiple.
Input Format. The two integers 𝑎 and 𝑏 are given in the same line separated by space.
Constraints. 1 ≤ 𝑎, 𝑏 ≤ 107.
Output Format. Output the least common multiple of 𝑎 and 𝑏.
*/

#include <iostream>
using namespace std;

//naive algorithm
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

//fast algorithm
long long lcm_fast(int a, int b){
	long long c=(long long)(a)*(long long)(b);
	if(b>a){
		int temp= a;
		a=b;
		b=temp;
	}
	while(b!=0){
		int temp=a;
		a=b;
		b=temp%b;
	}
	return c/a;
}

int main() {
  int a, b;
  cin >> a >> b;
//cout << lcm_naive(a, b) << endl;
  cout << lcm_fast(a, b) << endl;
  return 0;
}
