#include "member.h"
#include <stdio.h>

Member::Member(string name, uint level, string phone, string mailAddress)
{
	m_uiId = m_suiId++;
	m_strName = name;
	m_strPasswd = 123;
	m_uiLevel = level;
	m_strPhone = phone;
	m_strMailAddress = mailAddress;
}

void Member::work()
{
	while(1)
	{
		char choose = memberFace();
		switch(choose)
		{
			case '1'://买书
				buyBook();
				break;
			case '2'://查看购买记录
				checkPurchaseRecords();
				break;
			case '3'://修改密码
				modifyPasswd();
				break;
			case '0': //quit
				return;
				break;
			default:
				break;
		}
	}
}

//会员界面
char Member::memberFace()
{
	cout << "欢迎会员 " << m_strName << " 的登录使用\n" << endl;
	cout << "1.买书" << endl;
	cout << "2.查看购买记录\n" << endl;
	cout << "3.修改密码\n" << endl;
	cout << "0.退出\n\n" << endl;

	char choose = '\0';
	cout << "请输入你的选择:";
	cin >> choose;
	while(getchar() != '\n');
	return choose;
}

//买书
void Member::buyBook()
{
}

//查看购买记录
void Member::checkPurchaseRecords()
{
}

//修改密码
void Member::modifyPasswd()
{
	string passwd = "  ";
	cout << "请输入原来的密码(初始密码123):" << endl;
	cin >> passwd;
	while(getchar()!='\n');
	if(passwd != m_strPasswd)
	{
		cout << "密码输入有误...按回车键继续";
		while(getchar()!='\n');
	}
	else
	{
		string newPasswd = "  ";
		string rePasswd = "  ";
		cout << "请输入新密码:" << endl;
		cin >> newPasswd;
		while(getchar()!='\n');
		cout << "请再次输入密码:";
		cin >> rePasswd;
		while(getchar()!='\n');
		if(newPasswd != rePasswd)
		{
			cout << "两次输入不一致...按回车键继续";
			while(getchar()!='\n');
		}
		else
		{
			m_strPasswd = newPasswd;
			cout << "修改密码成功!　按回车键继续";
			while(getchar()!='\n');
		}
	}

}

uint Member::m_suiId = 1000;






