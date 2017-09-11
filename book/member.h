#ifndef _MEMBER_H_
#define _MEMBER_H_

#include <iostream>
#include <string>

using namespace std;

typedef unsigned int uint;
enum ENUM_MEMBER_LEVEL
{
	ENUM_MEMBER_LEVEL_MIN = 0,
	regular,  //普通会员
	vip,//vip会员
	ENUM_MEMBER_LEVEL_MAX = 0x00ffffff
};

class Member
{
public:
	Member(string name = "new", 
			uint level= regular,
			string phone = "13388889999",
			string mailAddress = "17886610699@qq.com"
			);

	void work();

	//会员界面
	char memberFace();

	//买书
	void buyBook();

	//查看购买记录
	void checkPurchaseRecords();

	//修改密码
	void modifyPasswd();


private:
	static uint m_suiId;
	uint m_uiId;
	string m_strName;
	string m_strPasswd;
	uint m_uiLevel;
	string m_strPhone;
	string m_strMailAddress;
};


#endif
