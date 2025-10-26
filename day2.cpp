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

int main() {
    int num;
    cout << "Enter number: ";
    cin >> num;

    Solution1 sol1;
    if (sol1.isPalindrome(num))
        cout << num << " is a palindrome." << endl;
    else
        cout << num << " is not a palindrome." << endl;

    Solution2 sol2;
    int revnum = sol2.reverse(num);
    if (revnum != 0)
        cout << "Reversed number: " << revnum << endl;
    else
        cout << "Reversed number overflows 32-bit integer." << endl;

    return 0;
}