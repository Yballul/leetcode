#include<iostream>
#include<string>
#include<vector>
using namespace std;
void tonumber();
string number;
vector<int>num;
vector<int>output;
void dfs(vector<int>,int);
int sum;
int valid(vector<int>);
int main()
{
	cout << "你所需要输入的一串数字：" << endl;
	cin >> number;
	tonumber();
	sum = 0;
	if (num.size() < 4 || num.size() > 12)
	{
		cout << "不可翻译成ip地址" << endl;
		return 0;
	}
	dfs(num, 1);
}
void tonumber()
{
	long a = stol(number);
	cout << a << endl;
	int counter = 1;
	while (counter <= a)
	{
		counter *= 10;
	}
	counter /= 10;
	for (int i = counter;i >= 1;i /= 10)
	{
		num.push_back(a / i);
		a %= i;
	}
	for (int i = 0;i < num.size();++i)
	{
		cout << num[i];
	}
	cout << endl;
}
 
void dfs(vector<int>m, int step)
{
	for (int i = 1;i <= 3;++i)
	{
		vector<int>num1;
		vector<int>num2;
		int n;
		if (i <= m.size())
		{
			for (int j = 0;j < i;++j)
			{
				num1.push_back(m[j]);
			}
		}
		n = valid(num1);
		if (step!=4)
		{
			sum += i;
			if (n <= 255&&sum<num.size())
			{
				num2 = m;
				if (i < num2.size())
				{
					num2.erase(num2.begin(), num2.begin() + i);
					output.push_back(n);
					dfs(num2, step + 1);
					output.pop_back();
				}
				
			}
			sum -= i;
		}

		if (step == 4)
		{
			sum += i;
			if (n <= 255&&sum==number.size())
			{
				output.push_back(n);
				for (int j = 0;j < 4;++j)
				{
					cout << output[j];
					if (j != 3)
					{
						cout << ".";
					}
					else
					{
						cout << endl;
					}
					
				}
				output.pop_back();
			}
			sum -= i;

		}
		
	}
}

int valid(vector<int>m)
{
	int s = 0;
	int counter = 1;
	for (int i = 1;i <= m.size();i++)
	{
		counter *= 10;
	}
	counter /= 10;
	for (int i = 0;i < m.size();++i)
	{
		s += counter * m[i];
		counter /= 10;
	}
	return s;
}