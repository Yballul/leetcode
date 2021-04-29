#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;
vector<int>a = { 1,3,15,11,2 };
vector<int>b = { 23,127,235,19,8 };
int minvalue = 10000;
int i = 0;
int j = b.size() - 1;

int main()
{
	//先排序
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	while (i != a.size()-1 || j != 0)
	{
		if (a[i] - b[j]>=0)
		{
			if ((i == 0 && j == b.size() - 1)||a[i]-b[j]==0)
			{
				minvalue = a[i] - b[j];
				break;
			}
			else 
			{
				if (minvalue > abs(a[i] - b[j]))
					minvalue = abs(a[i] - b[j]);
				if (i < a.size() - 1)
					i++;
				else
					j--;
			}			
		}
		else
		{
			if (minvalue > abs(a[i] - b[j]))
				minvalue = abs(a[i] - b[j]);
			if (j > 0)
				j--;
			else
				i++;
		}
	}
	if (minvalue > abs(a[a.size()-1] - b[0]))
		minvalue = abs(a[a.size()-1] - b[0]);
	cout << minvalue;
}