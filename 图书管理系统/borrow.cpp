#include "borrow.h"
#include <string>
#include <stdio.h>
#include <time.h>
using namespace std;//名空间

#define _CRT_SECURE_NO_WARNINGS 1

borrow::borrow()//构造函数
{
}

string borrow::getName() const
{
	return number;
}

string borrow::getBookISBN() const
{
	return bookISBN;
}

string borrow::getOutDate() const
{
	return outDate;
}

string borrow::getInDate() const
{
	return inDate;
}

int borrow::getDeadline() const
{
	return deadline;
}

void borrow::setName(string a)
{
	number = a;
}

void borrow::setISBN(string b)
{
	bookISBN = b;
}

void borrow::setOutDate(string c)
{
	outDate = c;
}

void borrow::setInDate(string d)
{
	inDate = d;
}

void borrow::setDeadline(int e)
{
	deadline = e;
}


void borrow::addBorrow(string isbn,string number)//向借阅登记表中新增借阅记录
{
	ofstream fileout("borrow.txt", ios::app);//打开文件
	if (!fileout)
	{
		cout << "打开文件失败！" << endl;
	}
	else
	{
		int i;
		time_t t = time(NULL);
		char ch[64] = { 0 };
		strftime(ch, sizeof(ch) - 1, "%Y-%m-%d", localtime(&t));     //年-月-日 时-分-秒
		string s(ch);
		if (isbn != " "&& number != " ") {
			setISBN(isbn);
			setName(number);
			setOutDate(s);
			setInDate("1");
			cout << "请输入借阅时长" << endl;
			cin >> i;
			setDeadline(i);
			fileout << getName() << "  " << getBookISBN() << "  " << getOutDate() << "  "
				<< getInDate()<< "  " << getDeadline() << endl;//输出控制台
			cout << getName() << "  " << getBookISBN() << "  " << getOutDate() << "  " << getInDate()
				<< "  " << getDeadline() << endl;//输出控制台
			fileout.close();//关闭文件
		}
	}

}

void borrow::printBorrowInfo()//输出借阅信息函数
{
	ifstream filein("borrow.txt");//打开文件
	if (!filein)
	{
		cout << "打开文件失败！" << endl;
	}
	else
	{
		cout << "读者号"<<setw(10)<<"ISBN码"<<setw(16)<<"借阅时间"<<setw(20)<<"还书时间"<<setw(20)<<"借阅时长" << endl;
		for (string s; getline(filein, s);)//判断读入的书名
		{
			int w;
			string a, x, y,z, u;//定义变量
			istringstream sin(s);//定义sin流
			sin >> x >> y >> z >> u >> w ;//将一行字符串读出	  				
			if (x != "") {
				setName(x);
				setISBN(y);
				setOutDate(z);
				setInDate(u);
				setDeadline(w);
				cout << getName() << setw(10) << getBookISBN() << setw(20) << getOutDate() << setw(20) << getInDate()
				<< setw(15) << getDeadline() << endl;//输出控制台
			}
		}

	}
	filein.close();//关闭文件
}

void borrow::searchInfo(string number)//查找读者的所有借阅信息
{
	ifstream filein("borrow.txt");//打开文件
	if (!filein)
	{
		cout << "打开文件失败！" << endl;
	}
	else
	{
		cout << "读者号"<<setw(10)<<"ISBN码"<<setw(16)<<"借阅时间"<<setw(20)<<"还书时间"<<setw(20)<<"借阅时间" << endl;
		for (string s; getline(filein, s);)//判断读入的书名
		{
			int w;
			string a, x, y, z, u;//定义变量
			istringstream sin(s);//定义sin流
			sin >> x >> y >> z >> u >> w;//将一行字符串读出	  				
			if (x != "") {
				if (x==number) {
					setName(x);
					setISBN(y);
					setOutDate(z);
					setInDate(u);
					setDeadline(w);
					cout << getName() << setw(10) << getBookISBN() << setw(20) << getOutDate() << setw(20) << getInDate()
					<< setw(15) << getDeadline() << endl;//输出控制台
				}
			}
		}

	}
	filein.close();//关闭文件

}

void borrow::searchInfobybook(string isbn)//查找读者的所有借阅信息
{
	ifstream filein("borrow.txt");//打开文件
	if (!filein)
	{
		cout << "打开文件失败！" << endl;
	}
	else
	{
		cout << "读者号"<<setw(10)<<"ISBN码"<<setw(16)<<"借阅时间"<<setw(20)<<"还书时间"<<setw(20)<<"借阅时长" << endl;
		for (string s; getline(filein, s);)//判断读入的书名
		{
			int w;
			string a, x, y, z, u;//定义变量
			istringstream sin(s);//定义sin流
			sin >> x >> y >> z >> u >> w;//将一行字符串读出	  				
			if (x != "") {
				if (y==isbn) {
					setName(x);
					setISBN(y);
					setOutDate(z);
					setInDate(u);
					setDeadline(w);
					cout << getName() << setw(10) << getBookISBN() << setw(20) << getOutDate() << setw(20) << getInDate()
					<< setw(15) << getDeadline() << endl;//输出控制台
				}
			}
		}

	}
	filein.close();//关闭文件

}


void borrow::updateInfo(string isbn,string number)//修改借阅信息（还书）
{
	ifstream filein("borrow.txt");//打开文件
	if (!filein)
	{
		cout << "打开文件失败！" << endl;
	}
	else
	{
		int n = 0;
		time_t t = time(NULL);
		char ch[64] = { 0 };
		strftime(ch, sizeof(ch) - 1, "%Y-%m-%d", localtime(&t));     //年-月-日 时-分-秒
		string str(ch);
		
		do
		{
			int w;
			string a, x, y, z, u;//定义变量
			string s;
			getline(filein, s);//读入每一行
			istringstream sin(s);//定义sin流
			sin >> x >> y >> z >> u >> w;//将一行字符串读出	 
			ofstream fileout("reborrow.txt", ios::app);//写到新文件中去

			if (y != isbn)//判断是否为修改的地方
				fileout << s << endl;//写入数据

			if (y == isbn&&x==number) {
				n = n + 1;
				setName(x);
				setISBN(y);
				setOutDate(z);
				setInDate(str);
				setDeadline(w);
				fileout << getName() << "  " << getBookISBN() << "  " << getOutDate() << "  " << getInDate()
					<< "  " << getDeadline() << endl;//输入文件
				cout << getName() << "  " << getBookISBN() << "  " << getOutDate() << "  " << getInDate()
					<< "  " << getDeadline() << endl;//输出控制台
				break;
			}

		} while (!filein.eof());//判断是否到文件尾
		if (n == 0) {//不存在这本书
			cout << "未找到要借阅记录！" << endl;
		}
		filein.close();//关闭
	}

	ifstream filei("reborrow.txt");//打开文档
	ofstream fileout("borrow.txt",ios::out);//打开文档并清空内容

	for(string s;getline(filei,s);)//将修改后的内容写到文件中去
	{
		fileout<<s<<endl;
	}
	filei.close();//关闭文件
	fileout.close();//关闭文件
	system("del reborrow.txt");//删除文件副本

}

borrow::~borrow()
{
}
