//给出一个整数数组，请在数组中找出两个加起来等于目标值的数，你给出的函数twoSum 需要返回这两个数字的下标（index1，index2），需要满足 index1 小于
//index2.。注意：下标是从1开始的.假设给出的数组中只存在唯一解
//来源：力扣（LeetCode）
//链接：https://www.nowcoder.com/practice/20ef0972485e41019e39543e8e895b7f?tpId=46&&tqId=29177&rp=1&ru=/activity/oj&qru=/ta/leetcode/question-ranking
#include <unordered_map>
class Solution {
public:
	/**
	*
	* @param numbers int整型vector
	* @param target int整型
	* @return int整型vector
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