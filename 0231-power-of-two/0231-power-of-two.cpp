class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long m=n;
        return (m && !(m & m-1));
    }
};