#pragma once
#ifndef BOOK_H
#define BOOK_H
#include<iostream>//ʹ�ñ�׼���������
#include<sstream>//ʹ��string��
#include<iomanip>//��ʽ���
#define NULLID "0"//�궨��
using namespace std;//ʹ�����ռ�
class book
{
private:
	string bookName;//����
	string bookAuthor;//����
	string bookISBN;//ISBN��
	string type;//���
	int bookStatue;//�鼮״̬
	string bookPress;//������
	float bookPrice;//�۸�
	int bookNum;//���п��
	int allbookNum;//�ܿ��

public:
	book();//���캯��
	string getName()const;//�������
	string getbookAuthor()const;//�������  
    string getbookISBN()const;//���ISBN
	string gettype()const;//�������
	string getbookPress()const;//��ó�����
	float getbookPrice()const;//��ü۸�
	int getbookNum()const;//��ȡ���п����
	int getallbookNum()const;//��ȡ�ܿ����
	
	void setName(string a);//�趨����
	void setAuthor(string b);//�趨����
	void setISBN(string c);//�趨ISBN��
	void settype(string d);//�趨����
	void setPress(string e);//�趨������
	void setPrice(float i);//�趨�۸�
	void setbookNum(int g);//��ȡ���п����
	void setallbookNum(int h);//��ȡ�ܿ����

	void readBookInformation();//�����鼮��Ϣ����	
	void printBookInformation();//����鼮��Ϣ����
	void addbookNum();//�����������(���п����ܿ��)
	void addrbookNum();//�û����飬�����п��
	void subrbookNum();//�û����飬�����п��
	
	~book();//��������
	
};
#endif



