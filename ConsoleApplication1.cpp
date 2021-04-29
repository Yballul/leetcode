#include<iostream>
#include<string>
#include<vector>


using namespace std;

int word;// 用户输入的字符串
vector<int>record;
vector<char>every;
vector<vector<char> >all;
vector<char>solution;
const string allword = "abcdefghijklmnopqrstuvwxyz";
void add(int);
void dfs(int);

int main()
{
	cout << "你所需要输入的组合" << endl;
	cin >> word;
	int counter = 1;
	while (counter <=word)
	{
		counter *= 10;
	}
	counter /= 10;
	while (counter >= 1)
	{

		record.push_back(word / counter);
		word = word % counter;
		counter /= 10;
	}
	for (int i = 0;i < record.size();i++)
	{
		cout << record[i];
	}
	cout << endl;
	for (int i = 0;i < record.size();i++)
	{
		add(record[i]);
	}

	for (int i = 0;i < all.size();i++)
	{
		for (int j = 0;j < all[i].size();j++)
		{
			cout << all[i][j];
		}
		cout << endl;
	}
	dfs(1);

}
void add(int a)
{
	if (a == 1)
	{
		return;
	}
	else if (a < 7)
	{
		for (int i = 3 * (a - 2);i < 3 * (a - 2) + 3;i++)
		{
			every.push_back(allword[i]);
		}
	}
	else if (a == 7)
	{
		for (int i = 15;i < 19;i++)
		{
			every.push_back(allword[i]);
		}
	}
	else if (a == 8)
	{
		for (int i = 19;i < 22;i++)
		{
			every.push_back(allword[i]);
		}
	}
	else if (a == 9)
	{
		for (int i = 22;i < 26;i++)
		{
			every.push_back(allword[i]);
		}
	}
	all.push_back(every);
	every.clear();
}

void dfs(int times)
{
	if (times == all.size() + 1)
	{
		cout << "“";
		for (int i = 0;i < solution.size();i++)
		{
			cout << solution[i];
		}
		cout << "”" << endl;
	}
	else
	{
		for (int i = 0;i < all[times - 1].size();i++)
		{
			solution.push_back(all[times - 1][i]);
			dfs(times + 1);
			solution.pop_back();
		}
	}
}

