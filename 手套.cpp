//���ӣ�https://www.nowcoder.com/questionTerminal/365d5722fff640a0b6684391153e58d8
//��Դ��ţ����
//�ڵ����������n����ɫ�����ף����׷������֣�����ÿ����ɫ�����������׸�����һ����ͬ��A��������Ҫ���ţ�������Ҫȥ������ѡ���ס�
//���ǻ谵�ĵƹ������޷��ֱ����׵���ɫ��ֻ�ֱܷ�������֡������������һЩ���ף�Ȼ��ѡ��һ˫��ɫ��ͬ�����������ס����ڵ�������
//��������Ҫ�ö���ֻ����(���ּ�����)�����ܱ�֤һ����ѡ��һ˫��ɫ��ͬ�����ס�������ɫ����n(1��n��13), ͬʱ������������Ϊn������
//left, right, �ֱ����ÿ����ɫ���������׵����������ݱ�֤���ҵ�����������������26����һ����������һ�ֺϷ�������
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int count = 0;
		int leftcount = 0;
		int rightcount = 0;
		int leftmin = 27;
		int rightmin = 27;
		for (int i = 0; i < n; i++)
		{
			if ((left[i] == 0) || (right[i] == 0))
				count += left[i] + right[i];
			else
			{
				leftcount += left[i];
				rightcount += right[i];
				leftmin = min(leftmin, left[i]);
				rightmin = min(rightmin, right[i]);
			}
		}
		if ((leftcount - leftmin + 1) > (rightcount - rightmin + 1))
			count += (rightcount - rightmin + 1 + 1);
		else
			count += (leftcount - leftmin + 1 + 1);
		return count;
	}
};