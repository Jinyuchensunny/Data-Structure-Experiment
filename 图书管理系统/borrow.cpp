#include "borrow.h"
#include <string>
#include <stdio.h>
#include <time.h>
using namespace std;//���ռ�

#define _CRT_SECURE_NO_WARNINGS 1

borrow::borrow()//���캯��
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


void borrow::addBorrow(string isbn,string number)//����ĵǼǱ����������ļ�¼
{
	ofstream fileout("borrow.txt", ios::app);//���ļ�
	if (!fileout)
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
	}
	else
	{
		int i;
		time_t t = time(NULL);
		char ch[64] = { 0 };
		strftime(ch, sizeof(ch) - 1, "%Y-%m-%d", localtime(&t));     //��-��-�� ʱ-��-��
		string s(ch);
		if (isbn != " "&& number != " ") {
			setISBN(isbn);
			setName(number);
			setOutDate(s);
			setInDate("1");
			cout << "���������ʱ��" << endl;
			cin >> i;
			setDeadline(i);
			fileout << getName() << "  " << getBookISBN() << "  " << getOutDate() << "  "
				<< getInDate()<< "  " << getDeadline() << endl;//�������̨
			cout << getName() << "  " << getBookISBN() << "  " << getOutDate() << "  " << getInDate()
				<< "  " << getDeadline() << endl;//�������̨
			fileout.close();//�ر��ļ�
		}
	}

}

void borrow::printBorrowInfo()//���������Ϣ����
{
	ifstream filein("borrow.txt");//���ļ�
	if (!filein)
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
	}
	else
	{
		cout << "���ߺ�"<<setw(10)<<"ISBN��"<<setw(16)<<"����ʱ��"<<setw(20)<<"����ʱ��"<<setw(20)<<"����ʱ��" << endl;
		for (string s; getline(filein, s);)//�ж϶��������
		{
			int w;
			string a, x, y,z, u;//�������
			istringstream sin(s);//����sin��
			sin >> x >> y >> z >> u >> w ;//��һ���ַ�������	  				
			if (x != "") {
				setName(x);
				setISBN(y);
				setOutDate(z);
				setInDate(u);
				setDeadline(w);
				cout << getName() << setw(10) << getBookISBN() << setw(20) << getOutDate() << setw(20) << getInDate()
				<< setw(15) << getDeadline() << endl;//�������̨
			}
		}

	}
	filein.close();//�ر��ļ�
}

void borrow::searchInfo(string number)//���Ҷ��ߵ����н�����Ϣ
{
	ifstream filein("borrow.txt");//���ļ�
	if (!filein)
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
	}
	else
	{
		cout << "���ߺ�"<<setw(10)<<"ISBN��"<<setw(16)<<"����ʱ��"<<setw(20)<<"����ʱ��"<<setw(20)<<"����ʱ��" << endl;
		for (string s; getline(filein, s);)//�ж϶��������
		{
			int w;
			string a, x, y, z, u;//�������
			istringstream sin(s);//����sin��
			sin >> x >> y >> z >> u >> w;//��һ���ַ�������	  				
			if (x != "") {
				if (x==number) {
					setName(x);
					setISBN(y);
					setOutDate(z);
					setInDate(u);
					setDeadline(w);
					cout << getName() << setw(10) << getBookISBN() << setw(20) << getOutDate() << setw(20) << getInDate()
					<< setw(15) << getDeadline() << endl;//�������̨
				}
			}
		}

	}
	filein.close();//�ر��ļ�

}

void borrow::searchInfobybook(string isbn)//���Ҷ��ߵ����н�����Ϣ
{
	ifstream filein("borrow.txt");//���ļ�
	if (!filein)
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
	}
	else
	{
		cout << "���ߺ�"<<setw(10)<<"ISBN��"<<setw(16)<<"����ʱ��"<<setw(20)<<"����ʱ��"<<setw(20)<<"����ʱ��" << endl;
		for (string s; getline(filein, s);)//�ж϶��������
		{
			int w;
			string a, x, y, z, u;//�������
			istringstream sin(s);//����sin��
			sin >> x >> y >> z >> u >> w;//��һ���ַ�������	  				
			if (x != "") {
				if (y==isbn) {
					setName(x);
					setISBN(y);
					setOutDate(z);
					setInDate(u);
					setDeadline(w);
					cout << getName() << setw(10) << getBookISBN() << setw(20) << getOutDate() << setw(20) << getInDate()
					<< setw(15) << getDeadline() << endl;//�������̨
				}
			}
		}

	}
	filein.close();//�ر��ļ�

}


void borrow::updateInfo(string isbn,string number)//�޸Ľ�����Ϣ�����飩
{
	ifstream filein("borrow.txt");//���ļ�
	if (!filein)
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
	}
	else
	{
		int n = 0;
		time_t t = time(NULL);
		char ch[64] = { 0 };
		strftime(ch, sizeof(ch) - 1, "%Y-%m-%d", localtime(&t));     //��-��-�� ʱ-��-��
		string str(ch);
		
		do
		{
			int w;
			string a, x, y, z, u;//�������
			string s;
			getline(filein, s);//����ÿһ��
			istringstream sin(s);//����sin��
			sin >> x >> y >> z >> u >> w;//��һ���ַ�������	 
			ofstream fileout("reborrow.txt", ios::app);//д�����ļ���ȥ

			if (y != isbn)//�ж��Ƿ�Ϊ�޸ĵĵط�
				fileout << s << endl;//д������

			if (y == isbn&&x==number) {
				n = n + 1;
				setName(x);
				setISBN(y);
				setOutDate(z);
				setInDate(str);
				setDeadline(w);
				fileout << getName() << "  " << getBookISBN() << "  " << getOutDate() << "  " << getInDate()
					<< "  " << getDeadline() << endl;//�����ļ�
				cout << getName() << "  " << getBookISBN() << "  " << getOutDate() << "  " << getInDate()
					<< "  " << getDeadline() << endl;//�������̨
				break;
			}

		} while (!filein.eof());//�ж��Ƿ��ļ�β
		if (n == 0) {//�������Ȿ��
			cout << "δ�ҵ�Ҫ���ļ�¼��" << endl;
		}
		filein.close();//�ر�
	}

	ifstream filei("reborrow.txt");//���ĵ�
	ofstream fileout("borrow.txt",ios::out);//���ĵ����������

	for(string s;getline(filei,s);)//���޸ĺ������д���ļ���ȥ
	{
		fileout<<s<<endl;
	}
	filei.close();//�ر��ļ�
	fileout.close();//�ر��ļ�
	system("del reborrow.txt");//ɾ���ļ�����

}

borrow::~borrow()
{
}
