#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int>target = { 2,1,5,6,2,3 };
stack<int>solution;
int max = 0;


int main()
{
	int i = 0;
	int j = target.size();
	int area = 0;
	while (i != target.size())
	{
		if (solution.empty() || target[i] >= target[solution.top()])
		{
			solution.push(i);
		}
		else
		{
			while (!solution.empty()&& target[solution.top()] > target[i])
			{
				area = target[solution.top()] * (i - solution.top());
				cout << area << endl;
				solution.pop();
				if (area > max)
				{
					max = area;
				}
			}
			solution.push(i);
		}
		i++;
	}
	while (!solution.empty())
	{

		area = target[solution.top()] * (j - solution.top());
		solution.pop();
		if (area > max)
		{
			max = area;
		}
	}
	cout << max;
}