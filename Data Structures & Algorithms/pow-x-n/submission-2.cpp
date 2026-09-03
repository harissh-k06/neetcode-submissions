class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return 1.0;
        double res = 1;
        x = (n>0) ? x : 1/x;
        n = abs(n);
        int pow = 0;
        while (n > 0){
            if (n %2 == 1){
                res = res * x;
            }

            n/=2;
            x*=x;

        }
        return res;
    }
};
