//���ӣ�https://www.nowcoder.com/practice/47e1687126fa461e8a3aff8632aa5559?tpId=117&&tqId=34935&rp=1&ru=/ta/job-code-high&qru=/ta/job-code-high/question-ranking
//��Դ��ţ����
//����һ�������������ظö�������֮���β������������һ��������ң���һ���������һֱ�������棩
/**
* struct TreeNode {
*	int val;
*	struct TreeNode *left;
*	struct TreeNode *right;
* };
*/

class Solution {
public:
	/**
	*
	* @param root TreeNode��
	* @return int����vector<vector<>>
	*/
	vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
		// write code here
		vector<vector<int>> arr;
		if (!root)
			return arr;
		queue<TreeNode*> deq;
		int flag = true;
		deq.push(root);
		while (!deq.empty())
		{
			int len = deq.size();
			vector<int> temp;
			for (int i = 0; i < len; i++)
			{
				TreeNode* node = deq.front();
				deq.pop();
				if (node->left)
					deq.push(node->left);
				if (node->right)
					deq.push(node->right);
				temp.push_back(node->val);
			}
			if (flag)
				arr.push_back(vector<int>(temp.begin(), temp.end()));
			else
				arr.push_back(vector<int>(temp.rbegin(), temp.rend()));
			flag = !flag;
		}
		return arr;
	}
};