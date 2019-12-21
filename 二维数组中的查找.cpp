//���ӣ�https://www.nowcoder.com/questionTerminal/abc3fe2ce8e146608e868a70efebf62e
//��Դ��ţ����
//��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά����
//��һ���������ж��������Ƿ��и�������
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int rows = array.size();
		int cols = array[0].size();
		int row = 0;
		int col = cols - 1;
		while (row < rows && col >= 0)
		{
			if (array[row][col] == target)
				return true;
			else if (array[row][col] > target)
				--col;
			else
				++row;
		}
		return false;
	}
};