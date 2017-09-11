#include "system.h"
#include <stdlib.h>
#include <stdio.h>

System::System()
{
}

System::~System()
{
}


System &System::getInstance()
{
	static System sys;
	return sys;
}


char System::loginFace()
{
	cout << "登录界面\n" << endl;
	cout << "1.老板登录" << endl;
	cout << "2.销售经理\n" << endl;
	cout << "2.销售人员\n" << endl;
	cout << "2.技术经理\n" << endl;
	cout << "2.技术人员\n" << endl;
	cout << "0.退出系统\n\n" << endl;
	cout << "请输入你的选择:";
	char choose = '\0';
	cin >> choose;
	while(getchar() != '\n');
	return choose;
}


void System::work()
{
	int count = 0; //统计登录次数
	while(1)
	{
		system("clear");
		if(3 == count)
		{
			exit(EXIT_FAILURE);
		}

		char choose = loginFace();

		string userName = "admin1";
	//	int id = 56;
		string passwd = "  ";
		switch(choose)
		{
	
			case '1'://老板
				{
					cout << "请输入用户名：";
					cin >> userName;
					while(getchar()!='\n');
					cout << "请输入密码：";
					cin >> passwd;
					while(getchar()!='\n');
					cout << "admin" << endl;
				}
				break;
			case '2'://销售经理
				{
					cout << "请输入用户名：";
					cin >> userName;
					while(getchar()!='\n');
					cout << "请输入密码：";
					cin >> passwd;
					while(getchar()!='\n');
				}
				break;
			case '0':
				exit(0);
				break;
				/*
			case '5'://技术人员登录
				{
					TecPartTime *pTecPT = loginCompare<TecPartTime *>(uiId, strPwd, DataSet::getInstance().getTecPartMap());
					if (NULL != pTecPT)
					{
						pTecPT->work();
					}
					else
					{
						cout << "用户名与密码不匹配..三次讲退出程序\n按回车键继续.." << endl;
						while(getchar()!='\n');
					}
					break;
					*/
			default:
					break;
				
		}
		count++;
	}
}














