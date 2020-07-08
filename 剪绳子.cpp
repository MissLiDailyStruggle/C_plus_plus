//���ӣ�https://www.nowcoder.com/practice/57d85990ba5b440ab888fc72b0751bf8?tpId=13&&tqId=33257&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//��Դ��ţ����
//����һ������Ϊn�����ӣ�������Ӽ�����������m�Σ�m��n����������n>1����m>1��m <= n����ÿ�����ӵĳ��ȼ�Ϊk[1], ..., k[m]������k[1]x...xk[m]���ܵ���
//��˻��Ƕ��٣����磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18��
//��̬�滮
/*class Solution {
public:
int cutRope(int number) {
vector<long>products(number+1,0);
if(number < 2)
return 0;
if(number == 2)
return 1;
if(number == 3)
return 2;
products[1] = 1;
products[2] = 2;
products[3] = 3;
for(int i = 4;i <= number;++i)
{
long max_product = 0;
for(int j = 1;j <= i/2;++j)
{
if(max_product < (products[j] * products[i - j]))
{
max_product = (products[j] * products[i - j]);
}
}
products[i] = max_product;
}
return products[number];
}
};*/
//̰��
class Solution {
public:
	int cutRope(int number) {
		if (number < 2)
			return 0;
		if (number == 2)
			return 1;
		if (number == 3)
			return 2;
		int x = number / 3;
		int y = number % 3;
		if (y == 0)
			return pow(3, x);
		else if (y == 1)
			return 2 * 2 * pow(3, x - 1);
		else
			return 2 * pow(3, x);

	}
};