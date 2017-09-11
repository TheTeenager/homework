#include <string.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <winsock2.h> 
#include <mysql/mysql.h>
#pragma comment(lib,"libmysql") 
 
#define HOST "localhost" 
#define USERNAME "root" 
#define PASSWORD "123456" 
#define DATABASE "test" 

/*这个函数用来执行传入的sql語句*/ 
void exe_sql(char* sql) 
{ 
	MYSQL my_connection; 
	int res; 

	mysql_init(&my_connection); 

	if (mysql_real_connect(&my_connection, HOST, USERNAME, PASSWORD, DATABASE, 0, NULL, CLIENT_FOUND_ROWS)) 
	{
		printf("数据库执行exe_sql连接成功！n"); 
		mysql_query(&my_connection, "set names utf8");
	
		res = mysql_query(&my_connection, sql); 
		if (res) 
		{
			printf("Error： mysql_query !\n"); 
			mysql_close(&my_connection); 
		} 
		else 
		{
			printf("%d 行受到影响！\n", 
			mysql_affected_rows(&my_connection)); 
			mysql_close(&my_connection); 
		} 
	} 
	else 
	{ 
		printf("数据库执行exe_sql连接失败！\n"); 
	} 
}

/*这个函数用来执行传入的sql語句，并打印出查询結果*/ 
void query_sql(char* sql) 
{ 
	MYSQL my_connection; 
	int res; 
	MYSQL_RES *res_ptr; /*指向查询结果的指针*/ 
	MYSQL_FIELD *field; /*字段结构指针*/ 
	MYSQL_ROW result_row; /*按行返回的查询信息*/ 
	int row, column; /*查询返回的行数和列数*/ 
	int i, j; 
	mysql_init(&my_connection); 
	if (mysql_real_connect(&my_connection, HOST, USERNAME, PASSWORD, 
	DATABASE, 0, NULL, CLIENT_FOUND_ROWS)) 
	{
		printf("数据库查询query_sql连接成功！\n"); 
		mysql_query(&my_connection, "set names utf8"); 
		res = mysql_query(&my_connection, sql); 
		if (res) 
		{ 
			printf("Error： mysql_query !\n"); 
			mysql_close(&my_connection); 
		} 
		else 
		{  
			res_ptr = mysql_store_result(&my_connection); 
			if (res_ptr) 
			{ 
				column = mysql_num_fields(res_ptr); 
				row = mysql_num_rows(res_ptr) + 1; 
				printf("查询到 %lu 行 \n", row); 
				/*输出結果的字段名*/ 
				for (i = 0; field = mysql_fetch_field(res_ptr); i++) 
				printf("%st", field->name); 
				printf("\n"); 
				/*按行输出結果*/ 
				for (i = 1; i < row; i++) 
				{ 
					result_row = mysql_fetch_row(res_ptr); 
					for (j = 0; j < column; j++) 
					printf("%st", result_row[j]); 
					printf("\n"); 
				} 
			} 
			mysql_close(&my_connection); 
		}		 
	} 
} 

int main(int argc, char *argv[]) 
{ 
	/*测试下向里面插入数据*/ 
	char *query; 
	char *exe = "insert into student values('lala','hahhahah!');"; 
	exe_sql(exe); 
	query="select * from student;"; 
	query_sql(query); 
	return 0; 
} 
