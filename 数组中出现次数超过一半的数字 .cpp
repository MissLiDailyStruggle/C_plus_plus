//链接：https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163
//来源：牛客网
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

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