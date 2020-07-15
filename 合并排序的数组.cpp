//给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。初始化 A 和 B 的元素数量分别为 m 和 n。
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/sorted-merge-lcci
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