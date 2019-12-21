//链接：https://www.nowcoder.com/questionTerminal/abc3fe2ce8e146608e868a70efebf62e
//来源：牛客网
//在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组
//和一个整数，判断数组中是否含有该整数。
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int rows = array.size();
		int cols = array[0].size();
		int row = 0;
		int col = cols - 1;
		while (row < rows && col >= 0)
		{
			if (array[row][col] == target)
				return true;
			else if (array[row][col] > target)
				--col;
			else
				++row;
		}
		return false;
	}
};