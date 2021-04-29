#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int>nums = { 1, 2, 3, 2, 1, 0, 2, 3, 1 };
stack<int>solution;
int flag = 1;
int maxvalue = 0;
int i = 0;
bool can = false;

int main()
{
	while (i < nums.size())
	{
		if (solution.empty())
		{
			solution.push(nums[i]);
			continue;
		}
		if (flag == 1)
		{
			//维护递增
			if (nums[i] > nums[solution.top()])
			{
				solution.push(i);
				can = true;
			}
			else
			{
				if (nums[i] < nums[solution.top()] && can)
				{
					solution.push(i);
					flag = 2;
			    }
				else
				{
					solution.pop();
					solution.push(i);
				}
				can = false;
			}
		}
		else
		{
			//维护递减
			if (nums[i] < nums[solution.top()])
			{
				solution.push(i);
				
			}
			else {
				while (!solution.empty())
				{
					solution.pop();
					if (solution.size() == 1)
					{
						maxvalue = maxvalue > (i - solution.top()) ? maxvalue : (i - solution.top());
					}
				}
				if(nums[i]!=nums[i-1])
				solution.push(i - 1);
				solution.push(i);
				flag = 1;
			}
		}
		i++;
	}
	cout << maxvalue;
}
//public int longestMountain(int[] A) {
//	if (A == null || A.length <= 2) {
//		return 0;
//	}
//	int res = 0;
//	for (int i = 1; i < A.length - 1; i++) {
//		if (A[i - 1] < A[i] && A[i + 1] < A[i]) {
//			int l = i - 1;
//			int r = i + 1;
//			while (l > 0 && A[l - 1] < A[l]) {
//				l--;
//			}
//			while (r < A.length - 1 && A[r + 1] < A[r]) {
//				r++;
//			}
//			res = Math.max(res, (r - l + 1));
//		}
//	}
//	return res;
//}
//这种方法比较好，先找到那个比两边大的数字，然后再用双指针
