//����һ���Ǹ��������� A������һ�����飬�ڸ������У� A ������ż��Ԫ��֮�������������Ԫ�ء�
//���ӣ�https://leetcode-cn.com/problems/sort-array-by-parity/
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