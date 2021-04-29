#include<iostream>
#include<vector>
using namespace std;

int num=0;//记录圈数
int num1 = 0;
vector<vector<int> >target = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20} };
vector<int>result;
vector<int>step;
int turn = 1;
int rowsize;
int columnsize;
int out = false;//判断是否跳出循环

int main()
{
	rowsize = target.size();
	columnsize = target[0].size();
	cout << rowsize << "," << columnsize << endl;
	step.push_back(columnsize);
	step.push_back(rowsize - 1);
	step.push_back(columnsize - 1);
	step.push_back(rowsize - 2);
	for (int i = 0;i < step.size();i++)
	{
		cout << step[i];
	}
	cout << endl;
	while (!out)
	{
		if (turn-1>0?step[turn - 1] > 0&&step[turn-2]:step[turn-1]>0)
		{
			switch (turn)
			{
			case 1:
				for (int i = num;i <= step[turn - 1] + num - 1;i++)
				{
					result.push_back(target[num][i]);
				}
				break;
			case 2:
				for (int i = num + 1;i <= step[turn - 1] + num;i++)
				{
					result.push_back(target[i][columnsize - num - 1]);
				}
				break;
			case 3:
				for (int i = step[turn - 1] + num - 1;i >= num;i--) {
					result.push_back(target[rowsize - num - 1][i]);
				}
				break;
			case 4:
				for (int i = rowsize - num - 2;i >= rowsize - num - 1 - step[turn - 1];i--) {
					result.push_back(target[i][num]);
				}
				break;
			default:
				break;
			}
		}

		if (turn == 4)
		{
			num++;
			turn = 1;
			for (int i = 0;i < step.size();i++) {
				step[i] = step[i] - 2;
				if (step[i] <= 0)
				{
					num1++;
			   }
			}
			if (num1 >=3)
			{
				out = true;
			}
			num1 = 0;
		}
		else
		{
			turn++;
		}
	}
	for (int i = 0;i < result.size();i++)
	{
		
		cout << result[i] << " ";
	}
	
}