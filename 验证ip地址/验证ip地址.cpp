
//编写一个函数来验证输入的字符串是否是有效的 IPv4 或 IPv6 地址。
//IPv4 地址由十进制数和点来表示，每个地址包含4个十进制数，其范围为 0 - 255， 用(".")分割。比如，172.16.254.1；
//
//同时，IPv4 地址内的数不会以 0 开头。比如，地址 172.16.254.01 是不合法的。
//
//IPv6 地址由8组16进制的数字来表示，每组表示 16 比特。这些组数字通过(":")分割。比如, 2001:0db8 : 85a3 : 0000 : 0000 : 8a2e : 0370 : 7334 是一个有效的地址。而且，我们可以加入一些以 0 开头的数字，字母可以使用大写，也可以是小写。所以， 2001 : db8 : 85a3 : 0 : 0 : 8A2E : 0370 : 7334 也是一个有效的 IPv6 address地址(即，忽略 0 开头，忽略大小写)。
//
//然而，我们不能因为某个组的值为 0，而使用一个空的组，以至于出现(::) 的情况。 比如， 2001 : 0db8 : 85a3::8A2E : 0370 : 7334 是无效的 IPv6 地址。
//
//同时，在 IPv6 地址中，多余的 0 也是不被允许的。比如， 02001 : 0db8 : 85a3 : 0000 : 0000 : 8a2e : 0370 : 7334 是无效的。
//
//说明 : 你可以认为给定的字符串里没有空格或者其他特殊字符。
#include<iostream>
#include<string>
using namespace std;
string ip;
int startpos = 0;
int endpos = 0;
void ifipv4();
void ifipv6();
int num = 0;

int main()
{
	cout << "你输入的ip地址";
	cin >> ip;
	for (int i = 0;i < ip.size();++i)
	{
		endpos = ip.find('.');
		if (endpos== ip.npos)
		{
			ifipv6();
			break;
		}
		else
		{
			ifipv4();
			break;
		}
	}
};
void ifipv4()
{
	while (endpos != ip.npos)
	{
		for (int i = startpos;i < endpos;i++)
		{
			num = num * 10 + (ip[i] - '0');
		}
		if (num > 255)
		{
			cout << endl << "不是ipv4也不是ipv6";
			return;
		}
		startpos = endpos + 1;
		endpos = ip.find('.', endpos + 1);
		cout << num << endl;
		num = 0;
	}
	for (int i = startpos;i <ip.size();i++)
	{
		num = num * 10 + (ip[i] - '0');
	}
	cout << num << endl;
	if (num > 255)
	{
		cout << endl << "不是ipv4也不是ipv6";
		return;
	}
	
	cout << "是ipv4";

}
void ifipv6()
{
	endpos = ip.find(':');
	while (endpos != ip.npos)
	{
		if (ip[startpos] =='0'||ip[endpos+1]==':')
		{
			cout << "不是ipv6也不是ipv4";
			return;
		}
		startpos = endpos + 1;
		endpos = ip.find(':', endpos + 1);
	}
	cout << "是ipv6";
}