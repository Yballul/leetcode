#include<iostream>
#include<string>
using namespace std;

string word="abcabcbb";
string text;
int k = word.size();
int j = 0;
bool out = false;
int target1;
int target2;
int main()
{
	for (int i = 0;i < word.size() - 1;i++)
	{
		j = i;
		while (!out)
		{
			text = word.substr(j, k);
			target1 = word.find(word[k]);
			target2 = word.find(word[j]);
			if (target1 == word.npos && target2 == word.npos)
			{
				j++;
				k--;
			}
			else 
			{
				j = target1;
				k = target2;
			}

		}
	}
	
}