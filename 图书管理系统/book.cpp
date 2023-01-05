#include "book.h"
book::book()//构造函数
	{ 
	    bookName="未赋值";
	    bookISBN=NULLID;
	}

string book::getName()const//获得书名
{
	return bookName;
}

string book::getbookAuthor()const//获得作者
	{
		return bookAuthor;
    }

string book::getbookISBN()const//获得ISBN
	{
		return bookISBN;
	}

string book::gettype()const//获得类型
	{
		return type;
	}

string book::getbookPress()const//获得出版社
	{
		return bookPress;
	}

float book::getbookPrice()const//获得单价
	{
		return bookPrice;
	}

int book::getbookNum()const//获得现有库存
	{
		return bookNum;
	}

int book::getallbookNum()const//获得总库存
	{
		return allbookNum;
	}

void book::setName(string a)//设定书名
	{
		bookName=a;
	}



void book::setAuthor(string b)//设定作者
	{
		bookAuthor=b;
	}

void book::setISBN(string c)//设定ISBN码
	{
		bookISBN=c;
    }

void book::settype(string d)//设定书项
	{
		type=d;
	}

void book::setPress(string e)//设定出版社
	{
		bookPress=e;
	}

void book::setPrice(float i)//设定出版社
	{
		bookPrice=i;
	}

void book::setbookNum(int g=0)//设定现有库存
	{
		bookNum=g;
	}

void book::setallbookNum(int h=0)//设定总库存
	{
		allbookNum=h;
	}
	
void book::readBookInformation()//读入书籍信息函数
	{
    cout<<"请输入书名："<<endl;//读入书名
	cin>>bookName;
	
    cout<<"请输入作者名："<<endl;//读入作者名
    cin>>bookAuthor;

	cout<<"请输入ISBN码："<<endl;//读入ISBN码
	cin>>bookISBN;

	cout<<"请输入类别："<<endl;//读入类别
	cin>>type;

	cout<<"请输入出版社："<<endl;//读入出版社
	cin>>bookPress;

	cout<<"请输入单价："<<endl;//读入单价
	cin>>bookPrice;

	cout<<"请输入库存书数量："<<endl;//读入新增数
	cin>>allbookNum;

	bookNum=allbookNum;
	}

void book::printBookInformation()//输出书籍信息函数
	{
		cout<<"书名："<<bookName<<endl;//输出书名
		cout<<"作者："<<bookAuthor<<endl;//输出作者
		cout<<"ISBN码："<<bookISBN<<endl;//输出ISBN码
		cout<<"类别："<<type<<endl;//输出类别
		cout<<"出版社："<<bookPress<<endl;//输出出版社
		cout<<"单价："<<bookPrice<<endl;//输出单价
		cout<<"现库存余量："<<bookNum<<endl;//输出现库存余量
		cout<<"总库存量："<<allbookNum<<endl;//输出库存量
	}

void book::addbookNum()//判断状态
{
	bookNum++;
	allbookNum++;
}

void book::addrbookNum(){

}

void book::subrbookNum(){

}


book::~book(){

}