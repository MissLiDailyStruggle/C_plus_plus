//���ӣ�https://www.nowcoder.com/questionTerminal/41c399fdb6004b31a6cbb047c641ed8a
//��Դ��ţ����
//��˵������̫��ʷѧ�� Josephus �й����¹��£���������ռ���������غ�39 ����̫���� Josephus ���������Ѷ㵽һ�����У�39 ����̫�˾�����Ը��Ҳ��
//Ҫ������ץ�������Ǿ�����һ����ɱ��ʽ��41 �����ų�һ��ԲȦ���ɵ� 1 ���˿�ʼ������������ 3 ���˾���ɱ��Ȼ��������һ�������±� 1�������� 3 ����
//����ɱ������������ȥ��ֱ��ʣ�����һ����ʱ���Ǹ��˿�������ѡ���Լ������ˡ������������Լɪ�����⡣�������õ���������ó����մ����˵ı��
//��n ��ʾ��������ĳ��ȣ� m ��ʾÿ�α����� m ����ɱ��
class Solution {
public:
	/**
	*
	* @param n int����
	* @param m int����
	* @return int����
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
     * @param n int���� 
     * @param m int���� 
     * @return int����
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