class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }


        bool sign = (dividend > 0) == (divisor > 0);

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long quotient = 0;
        
       
        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt += 1;
            }
            quotient += 1LL << cnt;
            n -= d << cnt;
        }


        if (!sign) {
            quotient = -quotient;
        }

 
        return (int)quotient;
    }
};
