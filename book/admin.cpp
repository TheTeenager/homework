#include "admin.h"
#include <stdio.h>
#include "database.h"

Admin::Admin(string name, string passwd)
{
	m_strName = name;
	m_strPasswd = passwd;
}


char Admin::adminFace()
{
	cout << "欢迎管理员 " << m_strName << " 的登录使用\n" << endl;
	cout << "对图书的操作:" << endl;
	cout << "1.查看图书信息" << endl;
	cout << "2.增加图书信息" << endl;
	cout << "3.修改图书信息" << endl;
	cout << "4.删除图书信息\n" << endl;

	cout << "对会员的操作:" << endl;
	cout << "5.增加新的会员" << endl;
	cout << "6.查看所有会员的购买记录\n" << endl;

	cout << "对自己的操作:" << endl;
	cout << "7.修改用户名" << endl;
	cout << "8.修改密码\n" << endl;
	cout << "0.退出\n\n" << endl;

	char choose = '\0';
	cout << "请输入你的选择:";
	cin >> choose;
	while(getchar() != '\n');
	return choose;

}


void Admin::work()
{
	while(1)
	{
		char choose = adminFace();
		switch(choose)
		{
			case '1'://check book
				checkBookInfo();
				break;
			case '2'://add book
				addBookInfo();
				break;
			case '3'://modify book
				modifyBookInfo();
				break;
			case '4'://drop book
				dropBookInfo();
				break;
			case '5'://add member
				addMemberInfo();
				break;
			case '6'://check purchase records
				checkPurchaseRecords();
				break;
			case '7'://modify name
				modifyName();
				break;
			case '8'://modify passwd
				modifyPasswd();
				break;
			case '0'://quit
				return;
				break;
			default:
				break;
		}
	}
}




//查看图书信息
void Admin::checkBookInfo()
{
}

//添加图书信息
void Admin::addBookInfo()
{
	
}

//更改图书信息
void Admin::modifyBookInfo()
{
	string bookName = "  ";
	cout << "请输入你要修改图书的名字:";
	cin >> bookName;
	//查询是否存在
	while(getchar()!='\n');
	cout << "0.修改全部信息" << endl;
	cout << "1.修改书名" << endl;
	cout << "2.修改作者" << endl;
	cout << "3.修改出版社" << endl;
	cout << "4.修改价格\n" << endl;
	
	cout << "请输入你的选择:";
	char choose = '\0';
	cin >> choose;
	while(getchar()!='\n');
	switch(choose)
	{
		case '0':
			{//all
			}
			break;
		case '1':
			{//name
			}
			break;
		case '2':
			{//author
			}
			break;
		case '3':
			{//publishing
			}
			break;
		case '4':
			{//price
			}
			break;
		default:
			break;
	}

}

//删除图书信息
void Admin::dropBookInfo()
{
}


//增加会员信息
void Admin::addMemberInfo()
{
	cout << "请输入新会员姓名:";
	string name = "  ";
	cin >> name;
	while(getchar() != '\n');

	cout << "请输入级别:1.regular 2.vip 其他键.取消";
	char level = '\0';
	string strLevel = "  ";
	cin >> level;
	while(getchar() != '\n');
	if('1' == level )
	{
		strLevel = "regular";
	}
	else if('2' == level)
	{
		strLevel = "vip";
	}
	else
	{
		return;
	}

	cout << "请输入电话:";
	string phone = "  ";
	cin >> phone;
	while(getchar() != '\n');

	cout << "请输入邮箱:";
	string mailAddress = "  ";
	cin >> mailAddress;
	while(getchar() != '\n');

	Data
}

//查看用户购买记录
void Admin::checkPurchaseRecords()
{
}

//更改用户名
void Admin::modifyName()
{
	string name = "  ";
	cout << "请输入新的用户名:";
	cin >> name;
	while(getchar() != '\n');
	cout << "你确定要使用 " << name << " 作为新的用户名吗？" << endl;
	cout << "1.确定　　其他键.取消";
	char choose = '\0';
	cin >> choose;
	while(getchar() != '\n');
	if('1' == choose)
	{
		char buffer[200] = {'\0'};
		const char *pName = name.c_str();
		const char *pStrName = m_strName.c_str();
		sprintf(buffer, "update admin set name = '%s' where name = '%s';", pName, pStrName);
		Database::getInstance().sendExeCommand(buffer);
		m_strName = name;
	}
	
}


//修改管理员密码
void Admin::modifyPasswd()
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
			char buffer[200] = {'\0'};
			const char *pStrName = m_strName.c_str();
			const char *pPasswd = newPasswd.c_str();
			sprintf(buffer, "update admin set passwd = '%s' where name = '%s';", pPasswd, pStrName);
			Database::getInstance().sendExeCommand(buffer);
			m_strPasswd = newPasswd;
			cout << "修改密码成功!　按回车键继续";
			while(getchar()!='\n');
		}
	}

}






