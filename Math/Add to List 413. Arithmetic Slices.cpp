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
