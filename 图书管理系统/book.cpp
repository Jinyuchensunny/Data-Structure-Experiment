#include "book.h"
book::book()//���캯��
	{ 
	    bookName="δ��ֵ";
	    bookISBN=NULLID;
	}

string book::getName()const//�������
{
	return bookName;
}

string book::getbookAuthor()const//�������
	{
		return bookAuthor;
    }

string book::getbookISBN()const//���ISBN
	{
		return bookISBN;
	}

string book::gettype()const//�������
	{
		return type;
	}

string book::getbookPress()const//��ó�����
	{
		return bookPress;
	}

float book::getbookPrice()const//��õ���
	{
		return bookPrice;
	}

int book::getbookNum()const//������п��
	{
		return bookNum;
	}

int book::getallbookNum()const//����ܿ��
	{
		return allbookNum;
	}

void book::setName(string a)//�趨����
	{
		bookName=a;
	}



void book::setAuthor(string b)//�趨����
	{
		bookAuthor=b;
	}

void book::setISBN(string c)//�趨ISBN��
	{
		bookISBN=c;
    }

void book::settype(string d)//�趨����
	{
		type=d;
	}

void book::setPress(string e)//�趨������
	{
		bookPress=e;
	}

void book::setPrice(float i)//�趨������
	{
		bookPrice=i;
	}

void book::setbookNum(int g=0)//�趨���п��
	{
		bookNum=g;
	}

void book::setallbookNum(int h=0)//�趨�ܿ��
	{
		allbookNum=h;
	}
	
void book::readBookInformation()//�����鼮��Ϣ����
	{
    cout<<"������������"<<endl;//��������
	cin>>bookName;
	
    cout<<"��������������"<<endl;//����������
    cin>>bookAuthor;

	cout<<"������ISBN�룺"<<endl;//����ISBN��
	cin>>bookISBN;

	cout<<"���������"<<endl;//�������
	cin>>type;

	cout<<"����������磺"<<endl;//���������
	cin>>bookPress;

	cout<<"�����뵥�ۣ�"<<endl;//���뵥��
	cin>>bookPrice;

	cout<<"����������������"<<endl;//����������
	cin>>allbookNum;

	bookNum=allbookNum;
	}

void book::printBookInformation()//����鼮��Ϣ����
	{
		cout<<"������"<<bookName<<endl;//�������
		cout<<"���ߣ�"<<bookAuthor<<endl;//�������
		cout<<"ISBN�룺"<<bookISBN<<endl;//���ISBN��
		cout<<"���"<<type<<endl;//������
		cout<<"�����磺"<<bookPress<<endl;//���������
		cout<<"���ۣ�"<<bookPrice<<endl;//�������
		cout<<"�ֿ��������"<<bookNum<<endl;//����ֿ������
		cout<<"�ܿ������"<<allbookNum<<endl;//��������
	}

void book::addbookNum()//�ж�״̬
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