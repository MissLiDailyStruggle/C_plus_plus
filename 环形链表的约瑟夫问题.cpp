//链接：https://www.nowcoder.com/questionTerminal/41c399fdb6004b31a6cbb047c641ed8a
//来源：牛客网
//据说著名犹太历史学家 Josephus 有过以下故事：在罗马人占领乔塔帕特后，39 个犹太人与 Josephus 及他的朋友躲到一个洞中，39 个犹太人决定宁愿死也不
//要被敌人抓到，于是决定了一种自杀方式，41 个人排成一个圆圈，由第 1 个人开始报数，报数到 3 的人就自杀，然后再由下一个人重新报 1，报数到 3 的人
//再自杀，这样依次下去，直到剩下最后一个人时，那个人可以自由选择自己的命运。这就是著名的约瑟夫问题。现在请用单向环形链表得出最终存活的人的编号
//。n 表示环形链表的长度， m 表示每次报数到 m 就自杀。
class Solution {
public:
	/**
	*
	* @param n int整型
	* @param m int整型
	* @return int整型
	*/
	int ysf(int n, int m) {
		// write code here
		vector<bool> flags(n + 1, 0);
		int flag = 0;
		for (int i = 1;; i++)
		{
			if (i > n)
				i = i % n;
			if (flags[i] == 0)
				flag++;
			if (flag % m == 0)
			{
				flag = 0;
				flags[i] = 1;
			}
		}
	}
};
/*
class Solution {
public:
    /**
     * 
     * @param n int整型 
     * @param m int整型 
     * @return int整型
     */
    /*int ysf(int n, int m) {
        // write code here
        queue<int>q;
        for(int i = 1;i <= n;++i)
            q.push(i);
        while(q.size() != 1)
        {
            for(int i = 1;i < m;i++)
            {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};*/