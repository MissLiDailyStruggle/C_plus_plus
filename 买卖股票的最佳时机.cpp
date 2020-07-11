//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的
//最大利润。注意：你不能在买入股票前卖出股票。
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
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