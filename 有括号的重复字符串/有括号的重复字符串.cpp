#include<iostream>
#include<vector>
#include<string>
using namespace std;

string target = "3[ac2[ad]]aaa";
string res = "";
string temp = "";
int times = 1;
int index;
void solution(int,int);
int main()
{
	solution(1, 0);
	cout << res;
}
void solution(int num, int start)
{
	//for (int i = 0;i < num;i++)
	//{
	//	for (int j = start;j < target.size();j++)
	//	{
	//		if (isdigit(target[j]))
	//		{
	//			solution(target[j] - '0', j + 2,++times);
	//		}
	//		else if (target[j] == ']')
	//		{
	//			if (times == 1)
	//			{
	//				index = j + 1;
	//			}
	//			break;
	//		}
	//		else
	//		{
	//			res.push_back(target[j]);
	//		}
	//	}
	//}
	int i = start;
	while (i!=target.size()-1)
	{
		if (isdigit(target[i]))
		{
			solution(target[i] - '0', i + 2);
			i = index;
		}
		else if (target[i] == ']')
		{
			index = i;
			break;
		}
		else
		{
			temp.push_back(target[i]);
			i++;
		}
	}
	for (int i = 0;i < num;i++)
	{
		res.append(temp);
	}
}

