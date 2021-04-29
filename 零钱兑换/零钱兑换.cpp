#include<iostream>
#include<vector>
using namespace std;
vector<int>coins = { 1,2,5 };
int amount = 31;
int minvalue = INT_MAX;
vector<int>dp(amount + 1);

int main()
{
	int i = 0;
	while (i < coins.size())
	{
		for (int j = coins[i];j <=amount;j++)
		{
			dp[j] = dp[j - coins[i]] + 1;
			if (j == amount)
			{
				if (dp[amount] < minvalue)
				{
					minvalue = dp[amount];

				}
				dp[amount] = 0;
			}
		}
		i++;
	}
	cout << minvalue;
}