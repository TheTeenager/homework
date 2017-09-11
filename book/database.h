#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <iostream>
#include <string>
#include <mysql/mysql.h>
#include "admin.h"
#include "member.h"

using namespace std;


class Database
{
public:
	Database()
	{
	}

	static Database &getInstance();

	void init();

	void sendQueryCommand(const char * command);

	void sendExeCommand(const char * command);

	void closeDatabase();


	//管理员登录
	Admin* loginCompareAdmin(string name, string passwd);

	//会员登录
	Member* loginCompareMember(uint id, string passwd);
private:
	MYSQL *conn; //数据库链接句柄
	MYSQL_RES *res; //返回的查询结果,相当于表
	MYSQL_ROW row; //一行数据显示

	MYSQL_FIELD *field;
};






#endif
