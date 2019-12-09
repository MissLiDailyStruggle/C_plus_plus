//��һ�ǿյĵ����б�����ǰ k �����ִ������ĵ��ʡ����صĴ�Ӧ�ð����ʳ���Ƶ���ɸߵ������������ͬ�ĵ�������ͬ����Ƶ�ʣ�����ĸ˳������
//���ӣ�https://leetcode-cn.com/problems/top-k-frequent-words/
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