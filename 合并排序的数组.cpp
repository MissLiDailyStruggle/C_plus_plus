//������������������ A �� B������ A ��ĩ�����㹻�Ļ���ռ����� B�� ��дһ���������� B �ϲ��� A �����򡣳�ʼ�� A �� B ��Ԫ�������ֱ�Ϊ m �� n��
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/sorted-merge-lcci
/*class Solution {
public:
void merge(vector<int>& A, int m, vector<int>& B, int n) {
int j = 0;
for(int i = m;i < m + n;++i)
{
A[i] = B[j++];
}
sort(A.begin(),A.end());

}
};*/
class Solution {
public:
	void merge(vector<int>& A, int m, vector<int>& B, int n) {
		int i = m - 1;
		int j = n - 1;
		int index = n + m - 1;
		while (i >= 0 && j >= 0)
		{
			if (A[i] > B[j])
			{
				A[index] = A[i];
				i--;
			}
			else
			{
				A[index] = B[j];
				j--;
			}
			index--;
		}
		while (i >= 0)
		{
			A[index] = A[i];
			i--;
			index--;
		}
		while (j >= 0)
		{
			A[index] = B[j];
			j--;
			index--;
		}
	}
};