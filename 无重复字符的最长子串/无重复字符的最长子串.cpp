#include<iostream>
#include<string>
#include<vector>
using namespace std;
string target="abcdabccc";
int i = 0;
int j = 0;
int k = 0;
int maxvalue = 0;
bool canmove = true;
int main()
{
	while (j < target.size())
	{
		if (i == j)
		{
			j++;
		}
		else
		{
			for (int start = i;start < j;start++)
			{
				if (target[start] == target[j])
				{
					k = start;
					canmove = false;
					maxvalue = maxvalue > (j - i) ? maxvalue : j - i;
					break;
				}
			}
			if (canmove)
			{
				j++;
			}
			else
			{
				i = k + 1;
				canmove = true;
			}
		}
	}
	cout << maxvalue;
}
