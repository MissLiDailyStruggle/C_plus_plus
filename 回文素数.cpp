#include <iostream>
#include <vector>

using namespace std;

void _swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

bool isprime(int n, vector<int>&arr)
{
	int num = 0;
	for (int i = n - 1; i > 0; --i)
		num = num * 10 + arr[i];
	for (int i = 2; i <= num / 2; ++i)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

bool _plali_prime(int n, vector<int>&arr)
{
	int left = n - 1;
	int right = 1;
	if (arr[left] == 0)
		return false;
	while (right < left)
	{
		if (arr[left--] != arr[right++])
			return false;
	}
	return isprime(n, arr);
}

bool plali_prime(int i)
{
	if (i < 0)
		return false;
	if (i >= 0 && i <= 9)
		return false;
	int temp = i;
	int nums = 0;
	while (temp)
	{
		temp /= 10;
		nums++;
	}
	temp = i;
	vector<int>arr(nums);
	int j = 0;
	while (temp)
	{
		arr[j++] = temp % 10;
		temp /= 10;
	}
	for (j = 0; j < nums; j++)
	{
		_swap(&arr[0], &arr[j]);
		if (_plali_prime(nums, arr))
			return true;
	}
	return false;
}
