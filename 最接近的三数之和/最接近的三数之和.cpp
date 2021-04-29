#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
vector<int>number = { -1,2,1,-4 };
int target = 1;
int best = 10000;
int j, k;
int sum = 0;
void judge(int);
int have();
int main()
{
	sort(number.begin(), number.end());
	cout << have();
}
void judge(int a)
{
	best = abs(a - target) < abs(best - target) ? a : best;
}
int have()
{
	for (int i = 0;i < number.size()-2;i++)
	{
		j = i + 1;
		k = number.size() - 1;
		if (i > 0 && number[i] == number[i - 1])
		{
			continue;
		}
		while (j < k)
		{
			sum = number[i] + number[j] + number[k];
			if (sum == target)
			{
				return target;
			}
			judge(sum);
			if (sum < target)
			{
				j++;
			}
			else {
				k--;
			}
		}
	}
	return best;
}