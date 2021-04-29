#include<iostream>
#include<vector>


using namespace std;
int sum;
vector<int>number;
vector<int>path;
void all(vector<int>m,int);
int main()
{   
	sum = 0;
	int num;
	int counter;
	cout << "你所需要输入的数组" << endl;
	while (cin >> num)
	{
		number.push_back(num);
	}
	all(number,1);
	cout << "Ann的值" << endl;
	cout << sum;//这里可以计算Ann的值
}
void all(vector<int>m,int step)
{
	
	for (int i = 0;i < m.size();++i)
	{
		
		if (step == number.size())
		{

			++sum;
			path.push_back(m[i]);
			for (int j = 0;j < path.size();++j)
			{
				cout << path[j];
				if (j == path.size() - 1)
				{
					cout << endl;
				}				
			}
			path.pop_back();
		}
		else
		{	
			vector<int>a = m;
			a.erase(a.begin() + i);//试过一个 删一个
			path.push_back(m[i]);
			all(a,step+1);
			path.pop_back();
		}	
	}
}