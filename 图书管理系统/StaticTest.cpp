#include"book.h"//ͷ�ļ�
#include"manage.h"
#include"reader.h"
#include<iostream>
using namespace std;//���ռ�

//����Ա��غ���
void addbook()//��������鼮
{
	manage manage1;//ʵ��������
	for (int temp=1;temp;)//ѭ������鼮
	{
	manage1.add();//����manage���е�add��������
	cout<<"�Ƿ��������鼮��Y���ǣ�N����"<<endl;//�ж��Ƿ�ѭ��
	char a;//�������
	cin>>a;
	if(a=='Y') temp=1;
	else if(a=='N') temp=0;
	else 
	{ 
		cout<<"�������!"<<endl; temp=1;//���������ʾ
	}

    }
}

void deletebook()//����ɾ���鼮
{
	manage manage6;//ʵ��������
	for (int temp=1;temp;)//ѭ��ɾ���鼮
	{
	manage6.deleteBook();//����manage���е�deleteBook()����
	cout<<"�Ƿ����ɾ���鼮��Y���ǣ�N����"<<endl;//�ж��Ƿ�ѭ��
	char a;//�������
	cin>>a;
	if(a=='Y') temp=1;
	else if(a=='N') temp=0;
	else 
	{ 
		cout<<"�������!"<<endl; temp=1;//���������ʾ
	}

    }
}

void changebook()//�޸��鼮��Ϣ
{
	manage manage2;//ʵ��������
    for (int temp=1;temp;)//ѭ���޸��鼮
    {
	manage2.revise();//����manage����revise��������
	cout<<"�Ƿ�����޸ģ�Y���ǣ�N����"<<endl;//ѭ���ж�
	char a;//�������
	cin>>a;
	if(a=='Y') temp=1;
	else if(a=='N') temp=0;
	else 
	{
		cout<<"�������!"<<endl; temp=1;//���������ʾ
	}
	}
}


void addReader()//���Ӷ��ߺ���
{
	manage manage3;//ʵ��������
	for (int temp=1;temp;)//ѭ������
	{
	manage3.addReader();//����manage����addReader��������
	cout<<"�Ƿ������Ӷ��ߣ�Y���ǣ�N����"<<endl;//ѭ���ж�
	char a;//�������
	cin>>a;
	if(a=='Y') temp=1;
	else if(a=='N') temp=0;
	else 
	{
		cout<<"�������!"<<endl; temp=1;//���������ʾ
	}
	}
}

void deleteReader()//ɾ�����ߺ���
{
	manage manage7;//ʵ��������
	for (int temp=1;temp;)//ѭ��ɾ��
	{
	manage7.deleteReader();//����manage����deleteReader��������
	cout<<"�Ƿ����ɾ�����ߣ�Y���ǣ�N����"<<endl;//ѭ���ж�
	char a;//�������
	cin>>a;
	if(a=='Y') temp=1;
	else if(a=='N') temp=0;
	else 
	{
		cout<<"�������!"<<endl; temp=1;//���������ʾ
	}
	}
}

void findebook(){
	manage manage8;
	manage8.findAllBooks();;//����manage����findAllBooks��������
	system("pause");
	
}
void searchAllBorrow() {
	manage manage9;
	manage9.findAllBorrow();//����reader���е�findAllBooks()����
	system("pause");
}

void getManage()//����Ա��½����
{
	manage manage4;//ʵ��������
	for(int temp=1;temp;)//ѭ����½
	{
	int b;//����getManage()�ķ���ֵ
	b=manage4.getManage();//����manage���е�getManage()����
	if(b==1)//��½�ɹ�
	{
		while(true)
		{
		system("cls");//�����Ļ����
		cout<<"***************************"<<endl;
		cout<<"��ӭ����ͼ�����ϵͳ��"<<endl;
		cout<<"��ѡ����Ӧ���ܣ�"<<endl;
		cout<<"1.���Ӷ���"<<endl;
		cout<<"2.ɾ������"<<endl;
		cout<<"3.�����鼮��Ϣ"<<endl;
		cout<<"4.ɾ���鼮��Ϣ"<<endl;
		cout<<"5.�޸��鼮��Ϣ"<<endl;
		cout<<"6.��ѯ�����鼮��Ϣ"<<endl;
		cout<<"7.��ѯ���н�����Ϣ" << endl;
		cout<<"8.�˳�"<<endl;
		int t;
		cin>>t;
		switch(t)
			{
			case 1:addReader();break;//����addReader()����
			case 2:deleteReader();break;//����deleteReader()����
			case 3:addbook();break;//����addbook()����
			case 4:deletebook();break;//����deletebook()����
			case 5:changebook();break;//����changebook()����
			case 6:findebook();break;//����findbook()����
			case 7:searchAllBorrow(); break;//����searchAllBorrow()����
			case 8:
				cout<<"��л����ʹ�ã�"<<endl;//�˳�
				system("pause");
				exit(0);
			
			default:
				cout<<"�������"<<endl;//�������
			}

		}

	}

	else//��¼ʧ���ж��Ƿ��ٴε�½
	{
	cout<<"�Ƿ������½��Y���ǣ�N����"<<endl;//ѭ���ж�
	char a;//�������
	cin>>a;
	if(a=='Y') temp=1;
	else if(a=='N') temp=0;
	else 
	{
		cout<<"�������!"<<endl; temp=1;//���������ʾ
	}
	}
	}

}

void reviseInformation()//����Ա�޸���Ϣ����
{
	manage manage5;//ʵ��������
	for (int temp=1;temp;)//ѭ���޸�
	{
	manage5.reviseInformation();//����manage���е�reviseInformation()����
	cout<<"�Ƿ�����޸ģ�Y���ǣ�N����"<<endl;//ѭ���ж�
	char a;//�������
	cin>>a;
	if(a=='Y') temp=1;
	else if(a=='N') temp=0;
	else 
	{
		cout<<"�������!"<<endl; temp=1;//���������ʾ
	}
	}
}



//������غ���
void search(reader &reader3)//��ѯ����
{
	//reader reader3;//ʵ��������
	for (int temp=1;temp;)//ѭ����ѯ
	{
	reader3.search();//����reader���е�search()����
	cout<<"�Ƿ������ѯ��Y���ǣ�N����"<<endl;//ѭ���ж�
	char a;//�������
	cin>>a;
	if(a=='Y') temp=1;
	else if(a=='N') temp=0;
	else
	{
		cout<<"�������!"<<endl; temp=1;//���������ʾ
	}
    }
}

void borrowBook(reader* reader4)//���麯��
{
	//reader reader4;//ʵ��������
	for (int temp=1;temp;)//ѭ������
	{
	reader4->borrowBook();//����reader���е�borrowBook()����
//	cout << reader4->getNumber() << endl;
	cout << "�Ƿ�������飨Y���ǣ�N����"<<endl;//ѭ���ж�
	char a;//�������
	cin>>a;
	if(a=='Y') temp=1;
	else if(a=='N') temp=0;
	else 
	{
		cout<<"�������!"<<endl; temp=1;//���������ʾ
	}
	}
}
void searchAllBook(reader &reader7)//���麯��
{
	//reader reader7;//ʵ��������
	reader7.findAllBooks();//����reader���е�findAllBooks()����
	system("pause");
}

void reviseCode()//�޸����뺯��
{
	reader reader6;//ʵ��������
	for (int temp=1;temp;)//ѭ���޸�����
	{
	reader6.reviseCode();//����reader���е�reviseCode()����
	cout<<"�Ƿ�����޸ģ�Y���ǣ�N����"<<endl;//ѭ���ж�
	char a;//�������
	cin>>a;
	if(a=='Y') temp=1;
	else if(a=='N') temp=0;
	else
	{
		cout<<"�������!"<<endl; temp=1;//���������ʾ
	}
	}
}

void searchAllBorrow(reader &reader8) {
	reader8.findAllBorrow();//����reader���е�findAllBooks()����
	system("pause");
}

void searchBookBorrow(reader &reader9) {
	reader9.findBorrowbyBookId();//����reader���е�findAllBooks()����
	system("pause");
}

void returnBook(reader &reader5)//���麯��
{
	//reader reader5;//ʵ��������
	for (int temp=1;temp;)//ѭ������
	{
	reader5.returnBook();//����reader���е�returnBook()����
	cout<<"�Ƿ�������飨Y���ǣ�N����"<<endl;//ѭ���ж�
	char a;//�������
	cin>>a;
	if(a=='Y') temp=1;
	else if(a=='N') temp=0;
	else 
	{
		cout<<"�������"<<endl; temp=1;//���������ʾ
	}
	}
}

void getStudent()//��¼����
{
	reader reader5;//ʵ��������
	for (int temp=1;temp;)//ѭ����½
	{
	int a;//����getInformation()�ķ���ֵ
	a=reader5.getInformation();//����reader���е�getInformation()����
	if(a==1)//��½�ɹ�
	{
		while(true)
		{
		system("cls");//�����Ļ����
		cout<<"***************************"<<endl;
		cout<<"��ӭ����ͼ�����ϵͳ��"<<endl;
		cout<<"��ѡ����Ӧ���ܣ�"<<endl;
		cout<<"1.��ѯ�鼮��Ϣ"<<endl;
		cout<< "2.��ѯ�����鼮��Ϣ" << endl;
		cout<<"3.�����鼮"<<endl;
		cout<<"4.�����鼮"<<endl;
		cout<<"5.��ѯ���߽�����Ϣ" << endl;
		cout<<"6.��ѯ�鼮������Ϣ" << endl;
		cout<<"7.�˳�"<<endl;
		int t;
		cin>>t;
		switch(t)
			{
			case 1:search(reader5);break;//����search()����
			case 2:searchAllBook(reader5); break;//����searchAllBook()����
			case 3:borrowBook(&reader5);break;//����borrowBook()����
			case 4:returnBook(reader5);break;//����returnBook()����
			case 5:searchAllBorrow(reader5); break;//����searchAllBorrow()����
			case 6:searchBookBorrow(reader5);break;//����searchBookBorrow()����
			case 7:
				cout<<"��л����ʹ�ã�"<<endl;//�˳�
				system("pause");
				exit(0);
			default:
				cout<<"�������"<<endl;//�������
			}

		}

	}
	else
	{
	cout<<"�Ƿ�������루Y���ǣ�N����"<<endl;//ѭ���ж�
	char a;
	cin>>a;
	if(a=='Y') temp=1;
	else if(a=='N') temp=0;
	else 
	{
		cout<<"�������!"<<endl; temp=1;//���������ʾ
	}
	}
	}
}


//�˵���ʾ����
void display_2()
{   
   
	while(true)
	{
        system("cls");//�����Ļ����
		cout<<"***************************"<<endl;
		cout<<"��ӭ����ͼ�����ϵͳ��"<<endl;
		cout<<"1.��½�˺�"<<endl;
		cout<<"2.�޸Ĺ���Ա��Ϣ"<<endl;
		cout<<"3.�˳�"<<endl;
		int t;
	    cin>>t;
	    switch(t)
	    {
	     case 1:getManage();break;//����getManage()����
	     case 2:reviseInformation();break;//����reviseInformation()����
	     case 3:
			 cout<<"��л����ʹ�ã�"<<endl;//�˳�
			 system("pause");
			 exit(0);
		 default :
		     cout<<"�������"<<endl;//�������
	     }
	}
}




void display_3()
{
	while(true)
	{
		system("cls");//�����Ļ����
		cout<<"***************************"<<endl;
		cout<<"��ӭ����ͼ�����ϵͳ��"<<endl;
		cout<<"1.��½�˺�"<<endl;
		cout<<"2.�޸Ķ�����Ϣ"<<endl;
		cout<<"3.�˳�"<<endl;
		int t;
	    cin>>t;
	    switch(t)
	    {
	     case 1:getStudent();break;//����getStudent()����
	     case 2:reviseCode();break;//����reviseCode()����
		 case 3:
			 cout<<"��л����ʹ�ã�"<<endl;//�˳�
	         system("pause");
			 exit(0);
	     default :
		      cout<<"�������"<<endl;//������ʾ
	    }

	}

}
	


void display_1()
{
	while(true)
	{
	system("cls");//�����Ļ����
	cout<<"***************************"<<endl;
	cout<<"��ӭ����ͼ�����ϵͳ��"<<endl;
	cout<<"��ѡ���Ժ�����ݵ�¼��"<<endl;
	cout<<"1.����Ա"<<endl;
	cout<<"2.����"<<endl;
	cout<<"3.�˳�"<<endl;
	int t;
	cin>>t;
	switch(t)
	{
	case 1:display_2();break;//����display_2()����
	case 2:display_3();break;//����display_3()����
	case 3:
		cout<<"��л����ʹ�ã�"<<endl;//�˳�
		system("pause");
		exit(0);
	default :
		cout<<"�������"<<endl;//������ʾ
	}

	}

}



//������
int main()
{

	while(1)
	{
		display_1();//����display_1()����
		system("pause");
	}
	return 0;
}
