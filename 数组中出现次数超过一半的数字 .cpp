//���ӣ�https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163
//��Դ��ţ����
//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }��
//��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		int count = 1;
		int mid = numbers.size() / 2;
		if (numbers.size() == 1)
			return numbers[0];
		for (int i = 1; i < numbers.size(); i++)
		{
			if (numbers[i - 1] == numbers[i])
			{
				count++;

			}
			else
			{
				count = 1;
			}
			if (count > mid)
				return numbers[i];
		}
		return 0;
	}
};