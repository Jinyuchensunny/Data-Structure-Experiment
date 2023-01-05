#pragma once
#ifndef BORROW_H
#define BORROW_H
#include<iostream>//ʹ�ñ�׼���������
#include<sstream>//ʹ��string��
#include<iomanip>//��ʽ���
#include <fstream>
#define NULLID "0"//�궨��
using namespace std;//ʹ�����ռ�
class borrow
{
private:
	string outDate;//����ʱ��
	string inDate;//����ʱ��
	int deadline;//��������
	string number;//���ߺ�
	string bookISBN;//ͼ��ISBN��

public:
	borrow();//���캯��
	string getName()const;//��ö��ߺ�
    string getBookISBN()const;//���ISBN
	string getOutDate()const;//��ý���ʱ��
	string getInDate()const;//��û���ʱ��
	int getDeadline()const;//��ý�������
	
	void setName(string a);//�趨����
	void setISBN(string b);//�趨ISBN��
	void setOutDate(string c);//�趨����ʱ��
	void setInDate(string d);//�趨����ʱ��
	void setDeadline(int e);//�趨��������

	void addBorrow(string isbn, string number);//����ĵǼǱ����������ļ�¼
	void printBorrowInfo();//���������Ϣ����
	void searchInfo(string number);//���Ҷ��ߵ����н�����Ϣ
	void updateInfo(string isbn,string number);//�޸Ľ�����Ϣ
	void searchInfobybook(string isbn);//������Ų�ѯ�鼮������Ϣ

	~borrow();//��������
	
};
#endif