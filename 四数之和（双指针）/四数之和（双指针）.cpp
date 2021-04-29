#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>num = { 1,0,-1,0,-2,2 };
vector<int>answer;
vector<vector<int> >all;
int left1 = 0;
int left2 = 1;
int right1 = num.size() - 1;
int right2 = num.size() - 2;
int sum = 0;
int target = 0;
int judge = 0;

int main()
{
	sort(num.begin(), num.end());
	while (right1 - left1 >= 3)
	{
		
		while (right2 - left2 >= 1)
		{
			if ((left2 > left1 + 1 && num[left2 - 1] == num[left2]) || (right2 < right1 - 1 && num[right2 + 1] == num[right2]))
				continue;
			sum = num[right1] + num[right2] + num[left1] + num[left2];
			if (sum >target)
			{
				right2--;
			}
			else if (sum < target)
			{
				left2++;
			}
			else
			{
				answer.push_back(num[right1]);
				answer.push_back(num[right2]);
				answer.push_back(num[left1]);
				answer.push_back(num[left2]);
				all.push_back(answer);
				answer.clear();
				
				right2--;
			}
			if (right2 - left2==1)
			{
				judge = sum;
			}
		}
		if (judge >= 0)
		{
			right1--;
		}
		else {
			left1++;
		}
		right2 = right1 - 1;
		left2 = left1 + 1;
	}
	for (int i = 0;i < all.size();i++)
	{
		for (int j = 0;j < all[i].size();j++)
		{
			cout << all[i][j];
			if (j != all[i].size() - 1)
			{
				cout << ",";
			}
		}
		cout << endl;
	}
}