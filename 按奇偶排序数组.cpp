//给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。
//链接：https://leetcode-cn.com/problems/sort-array-by-parity/
class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int left = 0;
		int right = A.size() - 1;
		while (right > left)
		{
			while ((A[left] % 2 == 0) && right > left)
				left++;
			while ((A[right] % 2 != 0) && right > left)
				right--;
			swap(A[left], A[right]);
			left++;
			right--;
		}
		return A;
	}
};