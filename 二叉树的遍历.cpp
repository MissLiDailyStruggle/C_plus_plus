//链接：https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking
//来源：牛客网
//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 例如如下的先序遍历字符串： ABC##DE#G##F### 
//其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。
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