#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <iostream>
#include <string>
#include "admin.h"
#include "member.h"
#include "book.h"
#include "database.h"

using namespace std;

class System
{
public:
	System();

	virtual ~System();

	static System &getInstance();

	void work();

	char loginFace();//登录界面
	

};




#endif
