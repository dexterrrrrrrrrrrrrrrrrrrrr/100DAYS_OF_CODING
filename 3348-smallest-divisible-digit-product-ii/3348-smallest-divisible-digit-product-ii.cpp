class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    string smallestNumber(string num, long long t) {
        // Check if t has any prime factor other than 2,3,5,7
        long long remainingFactor = t;

        for (int digit = 2; digit <= 9; digit++) {
            while (remainingFactor % digit == 0) {
                remainingFactor /= digit;
            }
        }

        if (remainingFactor > 1)
            return "-1";

        int n = num.size();

        vector<long long> requiredFactor(n + 1);
        requiredFactor[0] = t;

        int firstZeroIndex = n - 1;

        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                firstZeroIndex = i;
                break;
            }

            int digit = num[i] - '0';

            requiredFactor[i + 1] =
                requiredFactor[i] / gcd(requiredFactor[i], digit);
        }

        // Already satisfies product condition
        if (requiredFactor[n] == 1)
            return num;

        // Try increasing digits from right to left
        for (int i = firstZeroIndex; i >= 0; i--) {

            while (++num[i] <= '9') {

                int digit = num[i] - '0';

                long long currentNeed =
                    requiredFactor[i] /
                    gcd(requiredFactor[i], digit);

                int largestDigit = 9;

                // Fill suffix greedily
                for (int j = n - 1; j > i; j--) {

                    while (largestDigit > 1 &&
                           currentNeed % largestDigit != 0) {
                        largestDigit--;
                    }

                    if (largestDigit == 1) {
                        num[j] = '1';
                    } else {
                        num[j] = char('0' + largestDigit);
                        currentNeed /= largestDigit;
                    }
                }

                if (currentNeed == 1)
                    return num;
            }

            // Restore digit if needed
            num[i] = '0';
        }

        // Same length not possible
        string answer = "";
        long long remaining = t;

        for (int digit = 9; digit > 1; digit--) {
            while (remaining % digit == 0) {
                answer += char('0' + digit);
                remaining /= digit;
            }
        }

        // Pad with leading 1s
        while (answer.size() < n + 1)
            answer += '1';

        reverse(answer.begin(), answer.end());

        return answer;
    }
};