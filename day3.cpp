#include <iostream>
using namespace std;

/* to print divisors */

void printDivisors(int n) {
    cout << "The divisors of " << n << " are: ";
    for(int i = 1; i <= n; ++i){
        if(n % i == 0)
            cout << i << " ";
    }
    cout << endl;
}

/* to check if prime */

bool isPrime(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++){
        if (n % i == 0){
            count++;
            if (i * i != n) count++;
        }
    }
    return count == 2;
}


int main(){
    int n, choice;
    cout << "Enter a positive integer: ";
    cin >> n;

    cout << "Choose an option:\n1. Print all divisors\n2. Check if prime\n";
    cin >> choice;

    if (choice == 1)
        printDivisors(n);
    else if (choice == 2)
        cout << (isPrime(n) ? "Prime" : "Not prime") << endl;
    else
        cout << "Invalid choice!" << endl;
}