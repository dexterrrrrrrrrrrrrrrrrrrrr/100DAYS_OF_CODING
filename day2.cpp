/* to print a number 
which is palindrome */

#include<iostream>
#include<climits>
using namespace std;

class Solution1 {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false; // negative numbers are not palindromes

        int dup = x;     // store original number
        long rev = 0;    // use long to handle overflow

        while (x != 0) {
            int ld = x % 10;
            rev = (rev * 10) + ld;
            x = x / 10;
        }

        return rev == dup;
    }
};


/* to reverse a number */
class Solution2 {
public:
    int reverse(int x) {
        long rev = 0;
        while(x!=0){
            int ld = x%10;
            rev = (rev*10)+ld;
            x = x/10;
        }
         if (rev > INT_MAX || rev < INT_MIN) return 0;
         return rev;
    }
    
};


/* to check armstrong number */
class Solution3 {
public:
    bool armstrong(int x) {
        int dup = x;
        int sum = 0;
        while(x!=0){
            int ld = x%10;
            sum = sum + (ld*ld*ld);
            x = x/10;
        }
        return sum == dup;
    }
};


int main() {
    int num;
    int num2;
    int num3;
    cout << "Enter number: ";
    cin >> num;
    cin >> num2;
    cin >> num3;

    Solution1 sol1;
    if (sol1.isPalindrome(num))
        cout << num << " is a palindrome." << endl;
    else
        cout << num << " is not a palindrome." << endl;

    Solution2 sol2;
    int revnum = sol2.reverse(num2);
    if (revnum != 0)
        cout << "Reversed number: " << revnum << endl;
    else
        cout << "Reversed number overflows 32-bit integer." << endl;

    Solution3 sol3;
    if (sol3.armstrong(num3))    
        cout << num3 << " is an Armstrong number." << endl;
    else
        cout << num3 << " is not an Armstrong number." << endl;

    return 0;
}