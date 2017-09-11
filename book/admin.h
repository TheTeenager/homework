#ifndef _ADMIN_H_
#define _ADMIN_H_

#include <iostream>
#include <string>

using namespace std;

class Admin
{
public:
	Admin(string name = "admin", string passwd = "123");

	void work();

	//管理员界面
	char adminFace();

	//查看图书信息
	void checkBookInfo();

	//添加图书信息
	void addBookInfo();

	//更改图书信息
	void modifyBookInfo();

	//删除图书信息
	void dropBookInfo();


	//增加会员信息
	void addMemberInfo();

	//查看用户购买记录
	void checkPurchaseRecords();

	//修改用户名
	void modifyName();

	//修改管理员密码
	void modifyPasswd();



private:
	string m_strName;
	string m_strPasswd;
};




#endif
