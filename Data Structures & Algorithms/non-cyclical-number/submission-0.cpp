class Solution {
public:
    bool isHappy(int n) {
        set<int> seen;
        int temp = n;
        while (true){
            int sum = calculateSq(temp);
            if (sum == 1) return true;
            if (seen.find(sum)!=seen.end()) break;
            else seen.insert(sum);
            temp = sum;
        }
        return false;
    }

private:
    int calculateSq(int n){
        int temp = n , sum = 0;
        while (temp>0){  //12 //1
            int digit = temp%10; //2 // 1
            sum+=digit*digit; //4 // 4
            temp/=10; //1 //0
        }
        return sum;
    }
};
