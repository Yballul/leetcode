//给定一个包含正整数、加(+)、减(-)、乘(*)、除(/ )的算数表达式(括号除外)，计算其结果。
//
//表达式仅包含非负整数， + ， - ， * ， / 四种运算符和空格  。 整数除法仅保留整数部分。
//
//示例 1 :
//
//输入: "3+2*2"
//输出 : 7
//示例 2 :
//
//	输入 : " 3/2 "
//	输出 : 1
//	示例 3 :
//
//	输入 : " 3+5 / 2 "
//	输出 : 5
//	说明：
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/calculator-lcci
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include<iostream>
#include<string>
#include<stack>
using namespace std;

string expression;//要计算的表达式
char ope = '+';
stack<int>middle;
int result=0;
int num=0;//储存中间数

//如果是+-，那么直接进栈
//如果是*/,因为符号是在现有的num的前面的，所以和栈顶元素相乘除，然后出栈，再把num进栈
//注意ope=expression【i】，本次循环对应的序号
int main()
{
	cout << "你所输入的表达式：";
	getline(cin, expression);
	for (int i = 0;i < expression.size();++i)
	{
		if (isdigit(expression[i]))
		{
			num = num * 10 + (expression[i] - '0');//这段是读到有数字的 如果是一个数字 那么num=那个数字 如果两个数字意味着两位数 则num*10+下一个数
		}
		else if (isspace(expression[i]))
		{
			continue;
		}
		else
		{
			switch (ope)
			{
			case '+':
				middle.push(num);
				break;
			case '-':
				middle.push((-1) * num);
				break;
			case '*':
				num *= middle.top();
				middle.pop();
				middle.push(num);
				break;
			case'/':
				num = middle.top() / num;
				middle.pop();
				middle.push(num);
			default:
				break;
			}
			num = 0;
			ope = expression[i];
		}
	}
	while (!middle.empty())
	{
		result += middle.top();
		middle.pop();
	}
	result += num;//最后一个num是没有进栈的
	cout << endl << "结果是:" << result;

}