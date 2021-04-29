#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int>target = {8,2,4,7};
int maxvalue, minvalue;
int i = 0;
int j = 0;
int length = 0;
int limit = 4;
int main()
{
	maxvalue = target[0];
	minvalue = target[0];
	while (j < target.size())
	{
		if (maxvalue < target[j])
			maxvalue = target[j];
		if (minvalue > target[j])
			minvalue = target[j];
		if (abs(maxvalue - minvalue) <= limit)
		{
			if (length < j - i)
			{
				length = j - i;
			}
		}
		else
		{
			maxvalue = target[i + 1];
			minvalue = target[i + 1];
			while (maxvalue - minvalue > limit&&i<j)
			{
				i++;
				//注意这里求最大值跟最小值的方法跟前面不一样的，因为这时候i到j之间的数字会小于等于max，所以可能新的最大值是比原来max小的
				for (int k = i;k <= j;k++)
				{
					if (maxvalue < target[k])
						maxvalue = target[k];
					if (minvalue > target[k])
						minvalue = target[k];
				}
				
			}
		}
		j++;
	}
	cout << length;
}