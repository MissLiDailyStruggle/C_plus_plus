/*����һ�����飬���ĵ�?i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�

���һ���㷨�����������ܻ�ȡ�������������Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ����

ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����

��Դ�����ۣ�LeetCode��
���ӣ�https ://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int sum = 0;

		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i - 1]<prices[i])
				sum += (prices[i] - prices[i - 1]);
		}
		return sum;
	}
};