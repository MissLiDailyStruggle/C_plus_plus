//���ӣ�https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking
//��Դ��ţ����
//��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� �������µ���������ַ����� ABC##DE#G##F### 
//���С�#����ʾ���ǿո񣬿ո��ַ����������������˶������Ժ��ٶԶ������������������������������
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
}BTNode;

BTNode* BTCreat(string& str, int* i)
{
	if (str[*i] == '#')
		return nullptr;
	BTNode* cur = (BTNode*)malloc(sizeof(BTNode));
	cur->_data = str[*i];
	(*i)++;
	cur->left = BTCreat(str, i);
	(*i)++;
	cur->right = BTCreat(str, i);
	return cur;
}
void BTInOrder(BTNode* root)
{
	if (root == nullptr)
		return;
	BTInOrder(root->left);
	cout << root->_data << " ";
	BTInOrder(root->right);
}
int main()
{
	string str;
	cin >> str;
	int i = 0;
	BTNode* root = BTCreat(str, &i);
	BTInOrder(root);
	cout << endl;
	return 0;
}