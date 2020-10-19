/*Problem Description
Task. Given an integer 𝑛, find the 𝑛th Fibonacci number 𝐹𝑛.
Input Format. The input consists of a single integer 𝑛.
Constraints. 0 ≤ 𝑛 ≤ 45.
Output Format. Output 𝐹𝑛.
*/

#include <iostream>
#include <cassert>

using namespace std;

//naive algorithm
int fibonacci_naive(int n) {
    if (n <= 1)
        return n;
        
    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

//fast algorithm
int fibonacci_fast(int n) {
    int ar[n];
    if(n<=1){
    	return n;
	}
	ar[0]=1;
	ar[1]=1;
	for(int i=2;i<n;i++){
		ar[i]= ar[i-1]+ar[i-2];
	}
    return ar[n-1];
}

//comparing the results by both algorithm for the range naive algorithm is valid
void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    cin >> n;

  //cout << fibonacci_naive(n) << '\n';
  //test_solution();
    cout << fibonacci_fast(n) << '\n';
    return 0;
}
