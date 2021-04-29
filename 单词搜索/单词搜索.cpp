#include<iostream>
#include<string>
#include<vector>
using namespace std;

int times = 0;
vector<vector<char> >board = { {'A','B','C','E'} ,
  {'S','F','C','S'},
{'A','D','E','E'} };
vector<vector<bool> >ifarrive;
//string word1 = "ABCCED";
//string word2 = "SEE";
string word = "ABCCED";
void dfs(int,int,int);
bool valid(int,int);
bool can=false;
int main()
{
	//先找到单词的首字母所在的位置
	
	vector<bool>a(board[0].size());
	for (int i = 0;i < board.size();i++)
	{
		ifarrive.push_back(a);
	}
		for (int i = 0;i < board.size();i++)
		{
			for (int j = 0;j < board[i].size();j++)
			{
				if (board[i][j] == word[0])
				{
					dfs(j, i, times);
				}
			}
		}
		if (can)
		{
			cout << "找到";
		}
		else
		{
			cout << "没找到";
		}
}
void dfs(int x,int y,int time)
{
	if (board[y][x] != word[time])
	{
		return;
	}
	ifarrive[y][x] = true;
	if (time == word.size()-1)
	{
		can = true;
	}
	for (int i = 0;i < 4;i++)
	{
		if (i == 0)
		{
			//向上走
			if (valid(x, y - 1))
			{
				dfs(x, y - 1,time + 1);
			}
		}
		if (i == 1)
		{
			//向下走
			if (valid(x, y +1))
			{
				dfs(x, y + 1, time + 1);
			}
		}
		if (i == 2)
		{
			//向左走
			if (valid(x-1, y))
			{
				dfs(x-1, y , time + 1);
			}
		}
		if (i == 3)
		{
			//向右走
			if (valid(x+1, y))
			{
				dfs(x + 1, y, time + 1);
			}
		}
	}
}
bool valid(int x, int y)
{
	if (x<0 || x>board[0].size() - 1 || y<0 || y>board.size()-1||ifarrive[y][x])
	{
		return false;
	}
	else
	{
		return true;
	}
}