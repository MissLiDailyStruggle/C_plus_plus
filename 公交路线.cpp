//我们有一系列公交路线。每一条路线 routes[i] 上都有一辆公交车在上面循环行驶。例如，有一条路线 routes[0] = [1, 5, 7]，表示第一辆(下标为0) 公交车会一直按照
//1->5->7->1->5->7->1->... 的车站路线行驶。假设我们从 S 车站开始（初始时不在公交车上），要去往 T 站。 期间仅可乘坐公交车，求出最少乘坐的公交车数量。返回
//- 1 表示不可能到达终点车站。
//链接：https ://leetcode-cn.com/problems/bus-routes
class Solution {
public:
	int numBusesToDestination(vector<vector<int>>& routes, int S, int T)
	{
		if (S == T)
			return 0;
		queue<int> myqueue;
		myqueue.push(S);
		int min_steps = 1;
		vector<bool>have_gone(routes.size(), false);
		unordered_map<int, vector<int>>map;
		for (int i = 0; i < routes.size(); i++)
		{
			for (auto& e : routes[i])
				map[e].push_back(i);
		}
		while (!myqueue.empty())
		{
			for (int i = myqueue.size(); i > 0; i--)
			{
				int front_station = myqueue.front();
				myqueue.pop();
				for (auto& route_index : map[front_station])
				{
					if (!have_gone[route_index])
					{
						have_gone[route_index] = true;
						for (auto& station : routes[route_index])
						{
							if (station == T)
								return min_steps;
							myqueue.push(station);
						}
					}
				}
			}
			++min_steps;
		}
		return -1;
	}
};