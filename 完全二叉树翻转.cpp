#include <iostream>
#include <vector>

using namespace std;

void rever(vector<int>& arr, int x, int left, int right)
{
if (left > x || right > x)
return;
int left_left = left * 2;
int right_left = right * 2;
int left_right = left * 2 + 1;
int right_right = right * 2 + 1;
//×óÓÒÔªËØ½»»»
arr[left - 1] = right;
arr[right - 1] = left;

rever(arr, x, left_left, right_left);
rever(arr, x, left_right, right_right);
}
int main()
{
int n, m;
cin >> n >> m;
int x = pow(2,n) - 1 ;
vector<int>arr(x, 0);
for (int i = 0; i < x; ++i)
arr[i] = i + 1;
int left = 2 * m;
int right = 2 * m + 1;
rever(arr, x, left, right);
for (int i = 0; i < x; ++i)
cout << arr[i] << endl;
system("pause");
return 0;
}