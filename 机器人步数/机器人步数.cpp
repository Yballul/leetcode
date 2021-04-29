#include<iostream>
#include<vector>
using namespace std;

int m;//行
int n;//列
int k;//限制
int can;//可达格子数
int goali;//目标i
int goalj;//目标j
int max;
vector<vector<int> >arrive;//记录可以移动到的格子
vector<vector<int> >invalid;//记录不可走到的方格
bool validmove(int, int);//检测移动是否合法
bool validposition(int, int,int);//检测是否是合法的坐标
int sum(int);//计算数位数字和
void dfs(int, int, int);

int main()
{   

	cout << "请输入m行" << endl;
	cin >> m;
	cout << "请输入n列" << endl;
	cin >> n;
	cout << "请输入k值" << endl;
	cin >> k;

	for (int i = 0;i < m;++i)
	{
		for (int j = 0;j < n;++j)
		{
			if (!validposition(i, j,k))
			{
				vector<int>add;
				add.push_back(i);
				add.push_back(j);
				invalid.push_back(add);
			}
		}
	}
	cout << "非法的格子" << endl;
	for (int i = 0;i < invalid.size();++i)
	{
		cout << "(" << invalid[i][0] << "," << invalid[i][1] << ")";
		if (i != invalid.size() - 1)
		{
			cout << ",";
		}	
	}
	cout << endl;

	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			bool need = true;
			for (int z = 0;z < invalid.size();z++)
			{
				if (invalid[z][0] == i && invalid[z][1] == j)
				{
					need = false;
					break;
				}
			}
			if (need)
			{
				goali = i;
				goalj = j;
				max = (i + 1) * (j + 1);
				dfs(0, 0, 0);
			}			
		}
	}

	can = arrive.size();
	cout << "可达到的格子数:" << endl << can << endl;
	cout << "它们分别是" << endl;
	
	for (int i = 0;i < arrive.size();++i)
	{
		cout << "(" << arrive[i][0] << "," << arrive[i][1] << ")";
		if (i != arrive.size() - 1)
		{
			cout << ",";
		}
	}
}
void dfs(int i, int j, int step)
{
	
	if (i == goali && j == goalj)
	{
		if (arrive.size() != 0)
		{
			for (int h = 0;h < arrive.size();++h)
			{
				if (arrive[h][0] == goali && arrive[h][1] == goalj)
				{
					return;
				}
			}
		}
		vector<int>a;
		a.push_back(goali);
		a.push_back(goalj);
		arrive.push_back(a);
		return;
	}
	if (step>10000)
	{
		return;
	}
	for (int a = 0;a < 2;++a)
	{
	
		if (a == 1)//向下走
		{
			if (validmove(i + 1,j))
			{
				dfs(i + 1, j, ++step);
			}
		}

		if (a == 0)//向右走
		{
			if (validmove(i , j+1))
			{
				dfs(i , j+1, ++step);
			}
		}
	}
}
bool validmove(int i, int j)
{
	bool valid = true;
	for (int a = 0;a < invalid.size();++a)
	{
		if (i==invalid[a][0] && j ==invalid[a][1])
		{
			valid = false;//看看是否走到了非法格子
		}
	}
	if (i<0 || i>m - 1 || j<0 || j>n - 1)
	{
		valid = false;//看是否越界
	}
	return valid;
}
bool validposition(int i, int j,int k)
{
	int sum1 = sum(i) + sum(j);
	if (sum1 > k)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int sum(int a)
{
	int board = 1;
	while (board <= a)
	{
		board *= 10;
	}
	board /= 10;
	int sum = 0;
	for (int i = board;i >= 1;i /= 10)
	{
		int b = a / i;
		a = a % i;
		sum += b;
	}
    
	return sum;
}

