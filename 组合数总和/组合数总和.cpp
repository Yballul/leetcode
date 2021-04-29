#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int>candidate;
vector<int>path;
vector<vector<int> >allpath;
int target = 0;
int sum = 0;
void dfs();
void same();
int main()
{
	int a;
	int b;
	cout << "你所需要输入的目标和：" << endl;
	cin >> target;
	cout << "你所需要输入的数组：" << endl;
	while (cin >> a)
	{
		candidate.push_back(a);
	}
	for (int i = 0;i < candidate.size();++i)
	{
		cout << candidate[i];
		if (i != candidate.size() - 1)
		{
			cout << "，";
		}
	}
	cout << endl;
	dfs();
	same();
}
void dfs()
{
	for (int i = 0;i < candidate.size();++i)
	{
		if (sum > target)
		{
			break;
		}
		sum += candidate[i];
		if (sum < target)
		{
			path.push_back(candidate[i]);
			dfs();
			path.pop_back();
		}
		if (sum == target)
		{
			path.push_back(candidate[i]);
			allpath.push_back(path);
			path.pop_back();
		}
		sum -= candidate[i];
	}
}
void same()
{
	for (int i = 0;i < allpath.size();++i)
	{
		sort(allpath[i].begin(),allpath[i].end());
	}
	for (int i = 0;i < allpath.size();++i)
	{
		for (int j = 0;j < allpath.size();++j)
		{
			if (i != j&&allpath[i]==allpath[j])
			{
				allpath.erase(allpath.begin() + j);
			}
		}
	}
	for (int i = 0;i < allpath.size();++i)
	{
		for (int j = 0;j < allpath[i].size();++j)
		{
			cout << allpath[i][j];
			if (j != allpath[i].size() - 1)
			{
				cout << ",";
			}
		}
		cout << endl;
	}
}
