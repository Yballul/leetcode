#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

map<char, int>compare;
map<char, int>compare1;
vector<string>target = { "eat", "tea", "tan", "ate", "nat", "bat" };
vector<string>middle;
vector<vector<string> >res;
vector<bool>selected(target.size());
int beforesize = 0;
//这是在不使用自带sort的前提下的解题方法

int main()
{
	for (int i = 0;i < target.size();i++)
	{
		if (!selected[i])
		{
			selected[i] = true;
			middle.push_back(target[i]);
			for (int j = 0;j < target[i].size();j++)
				compare.insert(pair<char, int>(target[i][j], 1));
			beforesize = compare.size();
			compare1 = compare;
			for (int j = i + 1;j < target.size();j++)
			{
				for (int k = 0;k < target[j].size();k++)
				{
					compare.insert(pair<char, int>(target[j][k], 1));
				}
				if (beforesize == compare.size())
				{
					middle.push_back(target[j]);
					selected[j] = true;
				}
				compare = compare1;//要换回来才行，不然覆盖了原来的map
			}
			res.push_back(middle);
			middle.clear();
			compare.clear();		
		}
		else
		{
			continue;
		}
	}
	for (int i = 0;i < res.size();i++)
	{
		for (int j = 0;j < res[i].size();j++)
		{
			cout << res[i][j];
			if (j != res[i].size() - 1)
			{
				cout << "，";
			}
		}
		cout << endl;
	}
}