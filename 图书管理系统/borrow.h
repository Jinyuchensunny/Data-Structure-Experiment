#pragma once
#ifndef BORROW_H
#define BORROW_H
#include<iostream>//使用标准输入输出流
#include<sstream>//使用string流
#include<iomanip>//格式输出
#include <fstream>
#define NULLID "0"//宏定义
using namespace std;//使用名空间
class borrow
{
private:
	string outDate;//借阅时间
	string inDate;//还书时间
	int deadline;//借阅期限
	string number;//读者号
	string bookISBN;//图书ISBN码

public:
	borrow();//构造函数
	string getName()const;//获得读者号
    string getBookISBN()const;//获得ISBN
	string getOutDate()const;//获得借书时间
	string getInDate()const;//获得还书时间
	int getDeadline()const;//获得借书期限
	
	void setName(string a);//设定书名
	void setISBN(string b);//设定ISBN码
	void setOutDate(string c);//设定借书时间
	void setInDate(string d);//设定还书时间
	void setDeadline(int e);//设定借书期限

	void addBorrow(string isbn, string number);//向借阅登记表中新增借阅记录
	void printBorrowInfo();//输出借阅信息函数
	void searchInfo(string number);//查找读者的所有借阅信息
	void updateInfo(string isbn,string number);//修改借阅信息
	void searchInfobybook(string isbn);//根据书号查询书籍借阅信息

	~borrow();//析构函数
	
};
#endif