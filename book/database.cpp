#include "database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Database &Database::getInstance()
{
	static Database data;
	return data;
}

void Database::init()
{
		char server[20] = "localhost";
		char user[20] = "root"; //用户
		char passwd [20]= "123";//密码
		char database[20] = "library";//数据库名

	conn = mysql_init(NULL);//数据库句柄的初始化

	if(NULL == mysql_real_connect(conn, server, user, passwd, database, 0, NULL, 0)) //连接数据库
	{
		cout << "connect failed\n";
		mysql_close(conn); //关闭数据库
		exit(1);
	}

	mysql_set_character_set(conn, "utf8");//设置字符集
}
#if 0
void Database::sendCommand(const char *command)
{
	if(mysql_query(conn, command)) //发送sql语句
	{
		cout << "send filed" << endl;
		mysql_close(conn); //关闭数据库
		exit(1);
	}
	
	res = mysql_use_result(conn);//获取字符集
	while((row = mysql_fetch_row(res)) != NULL)
	{
		printf("%s\t%s\t%s\t%s\t%s\t%s\n", row[0], row[1], row[2], row[3], row[4], row[5]);
	}

	mysql_free_result(res);//释放结果集
	
}
#endif



void Database::sendExeCommand(const char *command)
{
	if(mysql_query(conn, command))
	{
		cout << "send filed" << endl;
		mysql_close(conn);
		exit(-1);
	}

}


void Database::sendQueryCommand(const char *command)
{
	int iColumn = 0;
	int iRow = 0;
	if(mysql_query(conn, command))
	{
		cout << "send filed" << endl;
		mysql_close(conn); //关闭数据库
		exit(-1);
	}

	res = mysql_store_result(conn);
	iColumn = mysql_num_fields(res);
	iRow = mysql_num_rows(res);
	cout << "查询到 " << iRow  << "行" << endl;
	
	for(int i = 0; i < iColumn; i++)
	{		
		field = mysql_fetch_field(res);
		cout << field->name << "\t";
	}
	cout << endl;
	
	for(int i = 0; i < iRow; i++)
	{
		row = mysql_fetch_row(res);
		for(int j = 0; j < iColumn; j++)
		{
			cout << row[j] << "\t";
		}
		cout << endl;
	}
	
	mysql_free_result(res);//释放结果集
}

void Database::closeDatabase()
{
	mysql_close(conn); //关闭数据库
}


Admin* Database::loginCompareAdmin(string name, string passwd)
{
	const char *pName = name.c_str();
	const char *pPasswd = passwd.c_str();
	if(mysql_query(conn, "select * from admin;")) //发送sql语句
	{
		cout << "send filed" << endl;
		mysql_close(conn); //关闭数据库
		exit(1);
	}
	
	Admin *pAdm = NULL;
	res = mysql_use_result(conn);//获取字符集
	while((row = mysql_fetch_row(res)) != NULL)
	{
		if(0 == strcmp(pName, row[0]) && 0 == strcmp(pPasswd, row[1]))
		{
			pAdm = new Admin(row[0], row[1]);
			break;
		}
	}
	mysql_free_result(res);//释放结果集
	return pAdm;
}

Member* Database::loginCompareMember(uint id, string passwd)
{
	char str[20] = "\0";
	sprintf(str, "%d", id);
	const char *pPasswd = passwd.c_str();
	if(mysql_query(conn, "select * from member;")) //发送sql语句
	{
		cout << "send filed" << endl;
		mysql_close(conn); //关闭数据库
		exit(1);
	}
	
	Member *pMem = NULL;

	res = mysql_use_result(conn);//获取字符集
	while((row = mysql_fetch_row(res)) != NULL)
	{
		if(0 == strcmp(str, row[0]) && 0 == strcmp(pPasswd, row[2]))
		{
			pMem = new Member(row[1], atoi(row[3]), row[4], row[5]);
			break;
		}
	}
	mysql_free_result(res);//释放结果集
	return pMem;
}







