#ifndef _BOOK_H_
#define _BOOK_H_

#include <iostream>
#include <string>

using namespace std;

class Book
{
public:
	Book(string name = "name", string author = "author", string publishing = "publishing", float price = 9.9f);

	~Book();

	const string &getName() const
	{
		return m_strName;
	}

	const string &getAuthor() const
	{
		return m_strAuthor;
	}

	const string &getPublishing() const
	{
		return m_strPublishing;
	}

	const float &getPrice() const
	{
		return m_fPrice;
	}

	//修改名字
	void setName(string name)
	{
		m_strName = name;
	}

	//修改作者
	void setAuthor(string author)
	{
		m_strAuthor = author;
	}

	//修改出版社
	void setPublishing(string publishing)
	{
		m_strPublishing = publishing;
	}

	//修改价格
	void setPrice(float price)
	{
		m_fPrice = price;
	}
private:
	string m_strName;
	string m_strAuthor;
	string m_strPublishing;
	float m_fPrice;
};




#endif
