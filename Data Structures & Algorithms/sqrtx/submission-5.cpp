class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int low = 1 , high = x/2;
        long long mid = 0;
        while (low<=high){
            mid = low + (high - low)/2;
            if (mid*mid == x || mid*mid < x && (mid+1)*(mid+1)>x) break;
            else if (mid*mid > x ) high = mid-1;
            else low = mid+1;
        }
        return mid;
    }
};