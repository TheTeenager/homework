#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <iostream>
#include <string>

using namespace std;

class System
{
public:
	System();

	virtual ~System();

	static System &getInstance();

	void work();

	char loginFace();

//	template<typename T>
//	T login(uint uiId, const string &strPwd, map<uint, T>& container);

};
/*
template<typename T>
T Company::login(uint uiId, const string &strPwd, map<uint, T> & container)
{
	typename map<uint, T>::iterator iter = container.find(uiId);
	if(iter != container.end())
	{
		if(strPwd == iter->second->getPasswd())
		{
			T reval = iter->second;
		}
	}
	return reval;
}

*/




#endif
