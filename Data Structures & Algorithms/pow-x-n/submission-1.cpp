class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1; 
        x = n>0 ? x : 1/x;
        double res = 1;
        for (int i = 1 ; i<=abs(n) ; i++){
            res*=x;
        }
        return res;
    }
};
