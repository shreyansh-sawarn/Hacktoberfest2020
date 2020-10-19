/*Problem Introduction
   The greatest common divisor GCD(𝑎, 𝑏) of two non-negative integers 𝑎 and 𝑏
  (which are not both equal to 0) is the greatest integer 𝑑 that divides both 𝑎 and 𝑏.
  Your goal in this problem is to implement the Euclidean algorithm for computing
  the greatest common divisor.
  Efficient algorithm for computing the greatest common divisor is an important
  basic primitive of commonly used cryptographic algorithms like RSA.
  GCD(1344, 217)
  =GCD(217, 42)
  =GCD(42, 7)
  =GCD(7, 0)
  =7
Problem Description
  Task. Given two integers 𝑎 and 𝑏, find their greatest common divisor.
  Input Format. The two integers 𝑎, 𝑏 are given in the same line separated by space.
  Constraints. 1 ≤ 𝑎, 𝑏 ≤ 2 · 109.
  Output Format. Output GCD(𝑎, 𝑏)
*/

#include <iostream>
using namespace std;

//naive algorithm
int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

//fast algorithm
int gcd_fast(int a, int b){
  //swapping such that a>b
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
	return a;
}

int main() {
  int a, b;
  cin >> a >> b;
//cout << gcd_naive(a, b) << endl;
  cout << gcd_fast(a, b) << endl;
  return 0;
}
