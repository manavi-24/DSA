class Solution {
public:
    int divide(int dividend, int divisor) {
        // Edge case: If dividend is INT_MIN and divisor is -1, return INT_MAX
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the result
        bool sign = (dividend > 0) == (divisor > 0);

        // Convert to long to handle overflow and take absolute values
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long quotient = 0;
        
        // Subtract the divisor from the dividend by shifting left (multiplying by powers of 2)
        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt += 1;
            }
            quotient += 1LL << cnt;
            n -= d << cnt;
        }

        // Apply the sign to the quotient
        if (!sign) {
            quotient = -quotient;
        }

        // Return the result as an int
        return (int)quotient;
    }
};
