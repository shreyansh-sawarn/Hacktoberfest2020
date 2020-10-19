/*PROBLEM STATEMENT: Maximum Pairwise Product Problem
  Find the maximum product of two distinct numbers in a sequence of non-negative integers.
  Input: A sequence of non-negativeintegers.
  Output: The maximum value that can be obtained by multiplying two different elements from the sequence. 
  Also, I have added code for stress testing with naive algorithm and fast algorithm.
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

//naive algorithm
long long MaxPairwiseProduct(const  vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product =  max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

//fast algorithm
long long MaxPairwiseProduct_fast(const  vector<int>& numbers) {
	int max_ind = -1;
	int max2_ind = -1;
	int n = numbers.size();
	for(int i=0;i<n;i++){
		if(( max_ind == -1) || (numbers[i]>numbers[max_ind])){
			max_ind =i;     //assigning index to max number we find while traversing
		}
	}
	for(int i=0;i<n;i++){
		if((i!=max_ind) && (( max2_ind == -1) || (numbers[i]>numbers[max2_ind]))){
			max2_ind =i;    //finding second max number
		}
	}

	long long result = ((long long)numbers[max_ind]* (long long)numbers[max2_ind]);
	return result;      //product of two largest no.
}

int main() {
/*	while(true){
		//generating array of random no.
		int n = rand() % 100 +2;
		cout<<n<<endl;
		vector <int> m;
		for(int i=0;i<n;i++){
			m.push_back(rand() % 1000000);
		}
    //printing out the array
		for(int i=0;i<n;i++){
			cout<<m[i]<<" ";
		}
		cout<<endl;
    //comparing result with both algorithm
		long long r1=MaxPairwiseProduct(m);
		long long r2=MaxPairwiseProduct_fast(m);
		cout<<r1<<" "<<r2;
		if(r1!=r2){
			cout<< "Wrong ans: "<<r1<<" "<<r2<<endl;
			break;
		}else if(r1==r2)
		cout<<"Ok"<<endl;
	}

*/
	
	
	int n;
    cin>>n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
         cin>>numbers[i];
    }
    cout << MaxPairwiseProduct_fast(numbers)<< "\n";
    return 0;
}
