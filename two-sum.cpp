//����һ���������飬�����������ҳ���������������Ŀ��ֵ������������ĺ���twoSum ��Ҫ�������������ֵ��±꣨index1��index2������Ҫ���� index1 С��
//index2.��ע�⣺�±��Ǵ�1��ʼ��.���������������ֻ����Ψһ��
//��Դ�����ۣ�LeetCode��
//���ӣ�https://www.nowcoder.com/practice/20ef0972485e41019e39543e8e895b7f?tpId=46&&tqId=29177&rp=1&ru=/activity/oj&qru=/ta/leetcode/question-ranking
#include <unordered_map>
class Solution {
public:
	/**
	*
	* @param numbers int����vector
	* @param target int����
	* @return int����vector
	*/
	vector<int> twoSum(vector<int>& numbers, int target) {
		// write code here
		/*vector<int> res(2,0);
		for(int i = 0;i < numbers.size();++i)
		{
		for(int j = i + 1;j < numbers.size();++j)
		{
		if(target - numbers[i] == numbers[j])
		{
		res[0] = i + 1;
		res[1] = j + 1;
		}
		}
		}
		return res;
		*/
		unordered_map<int, int> unmp;
		vector<int> res(2, 0);
		for (int i = 0; i < numbers.size(); ++i)
		{
			int number = target - numbers[i];
			if (unmp.find(number) != unmp.end())
			{
				res[0] = unmp[number] + 1;
				res[1] = i + 1;
				break;
			}
			else
				unmp[numbers[i]] = i;
		}
		return res;
	}
};