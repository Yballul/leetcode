#include<iostream>
#include<vector>
using namespace std;

int i = 0;
int j = 0;
int k = 3;
int maxvalue = 0;
vector<int>target = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };


int main()
{
	while (j < target.size())
	{
		if (k > 0 && target[j] == 0)
		{
			k--;
		}
		else if (k == 0 && target[j] == 0)
		{
			k--;//因为target【j】是0，那么k也要减，此时一定注意是k=-1
			maxvalue = maxvalue > (j - i ) ? maxvalue : (j - i );
			while (k == -1)
			{
				//直到k等于0了，那么就是说j可以继续向右移动了
				if (target[i] == 0)
					k++;
				i++;
			}
		}
		j++;
	}
	cout << maxvalue;
}