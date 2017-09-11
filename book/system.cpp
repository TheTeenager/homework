#include "system.h"
#include <stdlib.h>
#include <stdio.h>

System::System()
{
	Database::getInstance().init();
}

System::~System()
{
	Database::getInstance().closeDatabase();
}


System &System::getInstance()
{
	static System sys;
	return sys;
}


char System::loginFace()
{
//	Database::getInstance().sendQueryCommand("select * from member;");
	cout << "登录界面\n" << endl;
	cout << "1.图书管理员" << endl;
	cout << "2.会员\n" << endl;
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

		uint id = 56;
		string name = "  ";
		string passwd = "  ";
		switch(choose)
		{
	
			case '1'://admin
				{
					cout << "请输入用户名：";
					cin >> name;
					while(getchar()!='\n');
					cout << "请输入密码：";
					cin >> passwd;
					while(getchar()!='\n');
					Admin* adm  = Database::getInstance().loginCompareAdmin(name, passwd);
					if(NULL != adm)
					{
						adm->work();
					}
					else
					{
						cout << "用户名与密码不匹配..\n错误三次将退出系统..按回车键继续...";
						count++;
						while(getchar() != '\n');
					}
				}
				break;
			case '2'://member
				{
					cout << "请输入账号：";
					cin >> id;
					while(getchar()!='\n');
					cout << "请输入密码：";
					cin >> passwd;
					while(getchar()!='\n');
					Member *mem = Database::getInstance().loginCompareMember(id, passwd);
					if(NULL != mem)
					{
						mem->work();
					}
					else
					{
						cout << "用户名与密码不匹配..\n错误三次将退出系统..按回车键继续...";
						count++;
						while(getchar() != '\n'); 
					}
				}
				break;
			case '0':
				exit(0);
				break;
			default:
					break;
				
		}
	}
}




