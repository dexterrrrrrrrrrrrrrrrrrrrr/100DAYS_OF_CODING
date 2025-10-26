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

