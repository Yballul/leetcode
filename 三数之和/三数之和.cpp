#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>number;
vector<int>path;
vector<vector<int> >allpath;
int sum = 0;
void dfs(vector<int>m,int step);
int main()
{
	cout << "请输入一个数组：" << endl;
	int a;
	while (cin >> a)
	{
		number.push_back(a);
	}
	for (int i = 0;i < number.size();++i)
	{
		cout << number[i];
		if (i != number.size() - 1)
		{
			cout << ",";
		}
		
	}
	cout << endl;
	dfs(number, 1);
	for (int i = 0;i < allpath.size();++i)
	{
		sort(allpath[i].begin(), allpath[i].end());
	}
	for (int i = 0;i < allpath.size();++i)
	{
		for (int j = 0;j < allpath.size();++j)
		{
			if (j != i&&allpath[i]==allpath[j])
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
void dfs(vector<int>m, int step)
{
	for (int i = 0;i < m.size();++i)
	{
		sum += m[i];
		if (step != 3)
		{
			vector<int>n;
			n = m;
			n.erase(n.begin(), n.begin() + i+1);
			path.push_back(m[i]);
			dfs(n, step + 1);
			path.pop_back();
		}
		if (step == 3&&sum==0)
		{
			path.push_back(m[i]);
			allpath.push_back(path);
			path.pop_back();
		}
		sum -= m[i];
	}
}