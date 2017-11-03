A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.

题意：输出array中数列的个数

思路：求出差序列；统计序列中大于2的子串个数，并相加

Me:
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int cnt, dx;
        int ans = 0;
        vector<int> delta;
        if(A.size() <= 2)
            return ans;
        for(int i=0;i<A.size()-1;i++)
            delta.push_back(A[i]-A[i+1]);
        for(int i=0;i<delta.size();i++){
            if(i == 0){
                dx = delta[i];
                cnt = 1;
            }else if (delta[i] == dx)
                cnt ++;
            else if (delta[i] != dx){
                for(int j = 1; j<=cnt-1;j++){
                    ans += j;
                }
                cnt = 1;
                dx = delta[i];
            }
        }
        for (int j = 1; j <= cnt - 1; j++){
		    ans += j;
	    }
        return ans;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3) return 0;
        vector<int> l;
        int d=A[1]-A[0], cnt=2;
        for (int i = 2; i<A.size(); i++){
            if(A[i]-A[i-1] == d) cnt++;
            else{
                if (cnt>=3) l.push_back(cnt);
                cnt = 2;
                d = A[i]-A[i-1];
            }
        }
        if (cnt>=3) l.push_back(cnt);
        int res=0;
        for (int i: l) res+= (i-1)*(i-2)/2;
        return res;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;
        vector<int> dp(n, 0); // dp[i] means the number of arithmetic slices ending with A[i]
        if (A[2]-A[1] == A[1]-A[0]) dp[2] = 1; // if the first three numbers are arithmetic or not
        int result = dp[2];
        for (int i = 3; i < n; ++i) {
            // if A[i-2], A[i-1], A[i] are arithmetic, then the number of arithmetic slices ending with A[i] (dp[i])
            // equals to:
            //      the number of arithmetic slices ending with A[i-1] (dp[i-1], all these arithmetic slices appending A[i] are also arithmetic)
            //      +
            //      A[i-2], A[i-1], A[i] (a brand new arithmetic slice)
            // it is how dp[i] = dp[i-1] + 1 comes
            if (A[i]-A[i-1] == A[i-1]-A[i-2]) 
                dp[i] = dp[i-1] + 1;
            result += dp[i]; // accumulate all valid slices
        }
        return result;
    }
};
