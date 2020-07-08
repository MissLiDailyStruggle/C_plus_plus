//链接：https://www.nowcoder.com/practice/57d85990ba5b440ab888fc72b0751bf8?tpId=13&&tqId=33257&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//来源：牛客网
//给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1，m <= n），每段绳子的长度记为k[1], ..., k[m]。请问k[1]x...xk[m]可能的最
//大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
//动态规划
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
//贪心
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