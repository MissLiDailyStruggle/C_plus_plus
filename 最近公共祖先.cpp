//���ӣ�https://www.nowcoder.com/questionTerminal/70e00e490b454006976c1fdf47f155d9
//��Դ��ţ����
//��һ���������������������㰴�����һ��һ��ش����������α�ţ��������Ϊ1���������������a��b�������һ���㷨��
//���a��b�������������ȵı�š���������int a, b��Ϊ�������ı�š��뷵��a��b������������ȵı�š�ע�������㱾��
//Ҳ����Ϊ�������ȡ�
class LCA {
public:
	int getLCA(int a, int b) {
		if (a == 0 || b == 0)
			return 0;
		while (a != b)
		{
			if (a < b)
				b = b / 2;
			else
				a = a / 2;
		}
		return a;
	}
};