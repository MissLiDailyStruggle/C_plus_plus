//����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸���������ֻ�������һ�ʽ��ף������������һ֧��Ʊһ�Σ������һ���㷨�����������ܻ�ȡ��
//�������ע�⣺�㲻���������Ʊǰ������Ʊ��
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return NULL;
		int max_profit = 0;
		int min_price = prices[0];
		for (int i = 0; i < prices.size(); i++)
		{
			if (prices[i] < min_price)
				min_price = prices[i];
			if (prices[i] - min_price > max_profit)
				max_profit = prices[i] - min_price;
		}
		return max_profit;
	}
};