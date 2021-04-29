#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*将一个普通的中缀表达式转换为逆波兰表达式的一般算法是：
首先需要分配2个栈，一个作为临时存储运算符的栈S1（含一个结束符号），一个作为存放结果（逆波兰式）的栈S2（空栈），S1栈可先放入优先级最低的运算符#，注意，中缀式应以此最低优先级的运算符结束。可指定其他字符，不一定非#不可。从中缀式的左端开始取字符，逐序进行如下步骤：
（1）若取出的字符是操作数，则分析出完整的运算数，该操作数直接送入S2栈。
（2）若取出的字符是运算符，则将该运算符与S1栈栈顶元素比较，如果该运算符(不包括括号运算符)优先级高于S1栈栈顶运算符（包括左括号）优先级，则将该运算符进S1栈，否则，将S1栈的栈顶运算符弹出，送入S2栈中，直至S1栈栈顶运算符（包括左括号）低于（不包括等于）该运算符优先级时停止弹出运算符，最后将该运算符送入S1栈。
（3）若取出的字符是“（”，则直接送入S1栈顶。
（4）若取出的字符是“）”，则将距离S1栈栈顶最近的“（”之间的运算符，逐个出栈，依次送入S2栈，此时抛弃“（”。
（5）重复上面的1~4步，直至处理完所有的输入字符。
（6）若取出的字符是“#”，则将S1栈内所有运算符（不包括“#”），逐个出栈，依次送入S2栈。
完成以上步骤，S2栈便为逆波兰式输出结果。不过S2应做一下逆序处理。便可以按照逆波兰式的计算方法计算了！*/
string expression;
int num = 0;
int sum = 0;
void toBoLan();
void calculate();
vector<char>v1;
vector<char>v2;
vector<int>v3;
int main() {
	cout << "你所需要输入的表达式：";
	cin >> expression;
	toBoLan();
	calculate();
}
void toBoLan() {
	for (int i = 0;i < expression.size();i++)
	{
		if (isdigit(expression[i]))
		{
			num = num * 10 + (expression[i] - '0');
			if (expression[i + 1] != ' ' && !isdigit(expression[i + 1]))
			{
				v2.push_back(num + '0');
			}
		}
		else if (expression[i] == ' ')
		{
			continue;
		}
		else {
			switch(expression[i])
			{
			case '+':
			{
				if (v2[v2.size() - 1] == '(')
				{
					v1.push_back(expression[i]);
				}
				else
				{
					v2.push_back(expression[i]);
				}
				break;
			}
			case '-':
			{
				if (v2[v2.size() - 1] == '(')
				{
					v1.push_back(expression[i]);
				}
				else
				{
					v2.push_back(expression[i]);
				}
				break;
			}
			case '*':
			{
				if (v2[v2.size() - 1] == '('|| v2[v2.size() - 1] == '+'|| v2[v2.size() - 1] == '-')
				{
					v1.push_back(expression[i]);
				}
				else
				{
					v2.push_back(expression[i]);
				}
				break;
			}
			case '/':
			{
				if (v2[v2.size() - 1] == '(' || v2[v2.size() - 1] == '+' || v2[v2.size() - 1] == '-')
				{
					v1.push_back(expression[i]);
				}
				else
				{
					v2.push_back(expression[i]);
				}
				break;
			}
			case '(':
			{
				v1.push_back(expression[i]);
				break;
			}
			case ')':
			{
				v2.push_back(expression[i]);
				v1.pop_back();
				v1.pop_back();
				break;
			}
			default:
				break;
			}
			num = 0;
		}
	}
	num = 0;
}
void calculate() {
	for (int i = 0;i < v2.size();i++)
	{
		if (isdigit(v2[i]))
		{
			v3.push_back(v2[i] - '0');
		}
		else {
			switch (v2[i])
			{
			case '+':
			{
				num = v3[v3.size() - 1] + v3[v3.size() - 2];
				v3.pop_back();
				v3.pop_back();
				v3.push_back(num);
				break;
			}
			case '-':
			{
				num = v3[v3.size() - 2] - v3[v3.size() - 1];
				v3.pop_back();
				v3.pop_back();
				v3.push_back(num);
				break;
			}
			case '*':
			{
				num = v3[v3.size() - 1] * v3[v3.size() - 2];
				v3.pop_back();
				v3.pop_back();
				v3.push_back(num);
				break;
			}
			case '/':
			{
				num = v3[v3.size() - 2] / v3[v3.size() - 1];
				v3.pop_back();
				v3.pop_back();
				v3.push_back(num);
				break;
			}
			default:
				break;
			}
			num = 0;
		}
	}
	for (int i = 0;i < v3.size();i++)
	{
		sum += v3[i];
	}
	cout << endl << "结果是：" << sum;
}