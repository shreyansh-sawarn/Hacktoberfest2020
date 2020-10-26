#include <iostream>

using namespace std;

int main()
{
    int num,d;
    int rev = 0;
    cout << "Enter a number: " << endl;
    cin >> num;
    int n = num;

    while(num!=0){
        d = num%10;
        rev = (rev*10) + d;
        num = num/10;
    }

    if(rev == n){
        cout << "It is a palindrome number";
    }
    else {
        cout << "It is not a palindrome number";
    }
    return 0;
}