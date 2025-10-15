class Solution {
public:
    int trailingZeroes(int n) {
        long  five = 5;
        int ans = 0;
        while(n>0){
            n=n/5;
            ans+=n;
        }
        return (int)ans;
    }
};
