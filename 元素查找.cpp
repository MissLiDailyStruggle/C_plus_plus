//��һ���Ź�������飬����n����������������������������һ�����ȵ���λ��
//���磬ԭ����Ϊ[1, 2, 3, 4, 5, 6]��������λ5��λ�ü������[6, 1, 2, 3, 4, 5], 
//���ڶ�����λ������飬��Ҫ����ĳ��Ԫ�ص�λ�á������һ�����Ӷ�Ϊlog������㷨����������
//����һ��int����A��Ϊ��λ������飬ͬʱ���������Сn����Ҫ���ҵ�Ԫ�ص�ֵx���뷵��x��λ��(λ�ô��㿪ʼ)����֤������Ԫ�ػ��졣
//���ӣ�https://www.nowcoder.com/practice/72ff6503455c4a008675e79247ef2a3a?tpId=8&&tqId=11047&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
class Finder {
public:
	int findElement(vector<int> a, int n, int x) {
		int left = 0;
		int right = n - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (a[mid] == x)
				return mid;
			else if (a[mid] > a[left])
			{
				if (x >= a[left] && x < a[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
			else if (a[mid] < a[right])
			{
				if (x > a[mid] && x <= a[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
		}
	}
};