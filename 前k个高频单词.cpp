//给一非空的单词列表，返回前 k 个出现次数最多的单词。返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。
//链接：https://leetcode-cn.com/problems/top-k-frequent-words/
class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int>count;
		multimap<int, string, greater<int>>sort;
		vector<string>topkwords;
		for (auto e : words)
		{
			count[e]++;
		}
		for (auto e : count)
		{
			sort.insert({ e.second, e.first });
		}
		for (auto e : sort)
		{
			if (k == 0)
				break;
			topkwords.push_back(e.second);
			k--;
		}
		return topkwords;
	}
};