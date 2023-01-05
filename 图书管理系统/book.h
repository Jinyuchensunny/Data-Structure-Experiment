#pragma once
#ifndef BOOK_H
#define BOOK_H
#include<iostream>//使用标准输入输出流
#include<sstream>//使用string流
#include<iomanip>//格式输出
#define NULLID "0"//宏定义
using namespace std;//使用名空间
class book
{
private:
	string bookName;//书名
	string bookAuthor;//作者
	string bookISBN;//ISBN码
	string type;//类别
	int bookStatue;//书籍状态
	string bookPress;//出版社
	float bookPrice;//价格
	int bookNum;//现有库存
	int allbookNum;//总库存

public:
	book();//构造函数
	string getName()const;//获得书名
	string getbookAuthor()const;//获得作者  
    string getbookISBN()const;//获得ISBN
	string gettype()const;//获得类型
	string getbookPress()const;//获得出版社
	float getbookPrice()const;//获得价格
	int getbookNum()const;//获取现有库存量
	int getallbookNum()const;//获取总库存量
	
	void setName(string a);//设定书名
	void setAuthor(string b);//设定作者
	void setISBN(string c);//设定ISBN码
	void settype(string d);//设定书项
	void setPress(string e);//设定出版社
	void setPrice(float i);//设定价格
	void setbookNum(int g);//获取现有库存量
	void setallbookNum(int h);//获取总库存量

	void readBookInformation();//读入书籍信息函数	
	void printBookInformation();//输出书籍信息函数
	void addbookNum();//增加两个库存(现有库存和总库存)
	void addrbookNum();//用户还书，加现有库存
	void subrbookNum();//用户借书，减现有库存
	
	~book();//析构函数
	
};
#endif



