#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int number;//用户指定的n
vector<vector<int> >solution;//方法
vector<int>column;//列
void dfs(int);//回溯
bool ifvalid();//合法吗
void createsolution();
int main()
{
	cout << "你所需要的n:";
	cin >> number;
	dfs(1);
}
void dfs(int time)
{
	for (int i = 0;i < number;i++)
	{
		column.push_back(i);//先压进
		if (ifvalid())
		{
			if (time == number)
			{
				createsolution();
			}
			else {
				dfs(time + 1);
			}
		}
		column.pop_back();//要弹出
	}
}
bool ifvalid()
{
	vector<int>test;
	test = column;
	for (int i = 0;i < column.size();i++)
	{
		for (int j = i + 1;j < column.size();j++)
		{
			if((abs(column[i] - column[j]) == abs(i - j))||column[i]==column[j])
			{
				return false;
			}
		}
	}
	return true;
}
void createsolution()
{
	for (int i = 0;i < number;i++)
	{
		vector<int>middle(number);
		middle[column[i]] = 1;
		solution.push_back(middle);
	}
	cout << endl;
	cout << "方法：" << endl;
	for (int i = 0;i < number;i++)
	{
		for (int j = 0;j < number;j++)
		{
			cout << solution[i][j];
		}
		cout << endl;
    }
	solution.clear();
}