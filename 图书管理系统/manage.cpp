#include "manage.h"
#include "book.h"
#include"borrow.h"
#include <string>
using namespace std;//���ռ�
manage::manage()//��������
{

}

int manage::getManage()//��¼����
{
	cout<<"��ӭ��½ͼ�����ϵͳ��"<<endl;
	string a,b;
	cout<<"�������˺ţ�"<<endl;
	cin>>a;
	cout<<"���������룺"<<endl;
	cin>>b;
	string n,c;
    ifstream in("manage.txt");//���ļ�
	int i=0;//��ǩ���ж��˺ŵĴ������
    do
     {
	   if(in.eof())//�ļ�β�ͽ���
       break;
	   
	   string s;
	   getline(in,s);//����ÿһ��
       istringstream sin(s);//����sin��
       sin>>n>>c;
	   if((a==n)&&(c==b))//�ж��Ƿ����
         {
			 i=1;
		     return 1;//������ֵ      
             cout<<"��½�ɹ���"<<endl;
			 break; 
					            
         }
     }
	while(!in.eof());//�ж��Ƿ��ļ�β

    if(i==0)//δ�ҵ��˺�
	cout<<"���벻��ȷ��" <<endl;
    return 0;//���ؼ�ֵ
    in.close();//�ر��ļ�
}

void manage::reviseInformation()//�޸���Ϣ����
{
  int t=0;//��ǩ���Ƿ���ڸ��˺�
  string a,b,c,d;
  cout<<"�����������Ϣ��"<<endl;
  cout<<"�˺ţ�"<<endl;
  cin>>c;
  cout<<"���룺"<<endl;
  cin>>d;
  ifstream in("manage.txt");//���ļ�
  string s1;
  while( getline(in,s1))//��������
     {
		istringstream sin(s1);//����sin��
        sin>>a>>b;
	    ofstream out("manage1.txt",ios::app);//���ļ�
        if((a==c)&&(b==d))//���ڸ��˺�
          {
		    t=1;
		    string m,p;
			cout<<"�������޸ĺ����Ϣ:" <<endl;
			cout<<"������"<<endl;
			cin>>m;
			cout<<"���룺"<<endl;
			cin>>p;
            out<<m<<" "<<p<<endl; 
			cout<<"�޸ĳɹ�"<<endl;
		  }
		  else
			  out<<a<<" "<<b<<endl;//δ�޸�
		      out.close();//�ر��ļ�
	 }
		in.close();//�ر��ļ�

		ifstream filein("manage1.txt");//���ĵ�
		ofstream fileout("manage.txt",ios::out);//���ĵ����������
		string s;
		while(getline(filein,s))//���޸ĺ������д���ļ���ȥ
		{
			fileout<<s<<endl;
		}
		filein.close();//�ر��ļ�
		fileout.close();//�ر��ļ�

		if(t==0)//�����ڸ��˺�
        {
	       cout<<"�������"<<endl;
	    }
		 system("del manage1.txt");
}

void manage::add()//��������鼮����
{
	book book1;//ʵ��������
	ofstream fileout("store.txt",ios::app);//���ļ�
	if(!fileout)
	{
		cout<<"���ܴ��ļ���"<<"store.txt"<<endl;
	}
	else
	{
		if(search(1)==1){
			
		}else{
			cout<<"�������鱾������Ϣ��"<<endl;
			book1.readBookInformation();//������Ϣ
			fileout<<book1.getName()<<" "<<book1.getbookAuthor()<<" "<<book1.getbookISBN()<<" "<<book1.gettype()
			<<" "<<book1.getbookPress()<<" " << book1.getbookPrice()<<" "<<book1.getbookNum()<<" "<<book1.getallbookNum()<<endl;//д����Ϣ
			fileout.close();//�ر��ļ�
			system("del restore.txt");//ɾ���ļ�����
		}
	}

}


bool AllisNum(string str)  
 {  
     for (int i = 0; i <str.size(); i++)
     {
         int tmp = (int)str[i];
         if (tmp >= 48 && tmp <= 57)
         {
             continue;
         }
         else
         {
             return false;
         }
     } 
     return true;
 }


bool manage::search(int mode)//�����ѯ���������������飬�Ȳ�ѯ��������
{
	book book1;//ʵ��������
	ifstream filein("store.txt");//���ļ�
	if(!filein)
	{
		cout<<"���ļ�ʧ�ܣ�"<<endl;
		return 0;
	}
	else
	{
		cout<<"��������Ҫ��ӵ���������ţ�"<<endl;
		string t;//�������������
		cin>>t;
		int m=0;//��ǩ���ж��Ƿ����Ȿ��
		for(string s;getline(filein,s);)//�ж϶��������
		{
			int b,c,d;//b���п�棬c�ܿ��
			float i;
			string a,x,y,z,u,w;//�������
			istringstream sin(s);//����sin��
			sin>>x>>y>>z>>u>>w>>i>>b>>c;//��һ���ַ�������
			ofstream fileout("restore.txt",ios::app);//д�����ļ���ȥ
			
			if(AllisNum(t)){//�ж��Ƿ�Ϊ���
				a=z;		//������ţ�����Ÿ�ֵ��a
			}else{
					a=x;//����ÿ�еĿ�ͷ����������ֵ��a
			}
				if(t!=a)//�ж��Ƿ�Ϊ�޸ĵĵط�
				fileout<<s<<endl;//д������
				if(t==a)//�ж��Ƿ��ҵ����ҵ��鼮
				{
					  
						m++;						
						book1.setName(x);//�趨����
						book1.setAuthor(y);//�趨����
						book1.setISBN(z);//�趨ISBN��
						book1.settype(u);//�趨����
						book1.setPress(w);//�趨������
						book1.setPrice(i);//�趨����
						book1.setbookNum(b);//���п��
						book1.setallbookNum(c);//�������
						//book1.printBookInformation();
	
						if(mode == 1){ 
							//book1.addbookNum();
							cout<< "����в鵽���飬���������������Ŀ." <<endl;
							cin>>d;
							book1.setbookNum(b+d);//���п��
							book1.setallbookNum(c+d);//�������
						    fileout<<book1.getName()<<" "<<book1.getbookAuthor()<<" "<<book1.getbookISBN()<<" "<<book1.gettype()
								<<" "<<book1.getbookPress()<<" "<<book1.getbookPrice()<<" "<<book1.getbookNum()<<" "<<book1.getallbookNum()<<endl;//д�뵽�ļ�
							
						}else{
							book1.printBookInformation();//���
						}
						fileout.close();
						//break;
				}
	
		}
			if(m==0){//�ж��Ƿ��д��鼮
			cout<<"�����δ�ҵ�Ҫ���ҵ��鼮��"<<endl;
			return 0;
		}
	}

	filein.close();//�ر��ļ�
	if(mode==1){
		ifstream filei("restore.txt");//���ĵ�
		ofstream fileout("store.txt",ios::out);//���ĵ����������
		for(string s;getline(filei,s);)//���޸ĺ������д���ļ���ȥ
		{	
			fileout<<s<<endl;
		}
	  filei.close();//�ر��ļ�
	  fileout.close();//�ر��ļ�
	
	}
	system("del restore.txt");//ɾ���ļ�����
	return 1;

}

void manage::revise()//�����޸��鼮��Ϣ����
{
	book book1;//ʵ��������
	ifstream filein("store.txt");//���ļ�
	if(!filein)
	{
		cout<<"���ļ�ʧ�ܣ�"<<endl;
	}
	else
	{
		cout<<"�������޸��鼮�ĵ�������"<<endl;
		int n=0;//��ǩ���Ƿ����Ȿ��
		string t;//��������
		cin>>t;
		do
		{   int b,c;//�������
			float i;
			string x,y,z,u,w;
		    string s;
			getline(filein,s);//����ÿһ��
			istringstream sin(s);
			sin>>x>>y>>z>>u>>w>>i>>b>>c;//��һ���ַ�������
            ofstream fileout("restore.txt",ios::app);//д�����ļ���ȥ
			
			if(t!=x)//�ж��Ƿ�Ϊ�޸ĵĵط�
			fileout<<s<<endl;//д������

			if(t==x)//�ж��Ƿ�Ϊ�޸ĵĵط�
			{
				n=1;
				book1.setName(x);//�趨����
				book1.setAuthor(y);//�趨����
				book1.setISBN(z);//�趨ISBN��
				book1.settype(u);//�趨����
				book1.setPress(w);//�趨������
				book1.setPrice(i);//�趨����
				book1.setbookNum(b);//�趨�����
				book1.setallbookNum(c);//�趨�������
				cout<<"ԭ�鼮��ϢΪ:"<<endl;
				book1.printBookInformation();//���

				cout<<"�������޸ĺ���鼮��Ϣ��"<<endl;
				 book1.readBookInformation();//���¶���
				 fileout<<book1.getName()<<" "<<book1.getbookAuthor()<<" "<<book1.getbookISBN()<<" "<<book1.gettype()
				<<" "<<book1.getbookPress()<<" "<<book1.getbookPrice()<<" "<<book1.getbookNum()<<" "<<book1.getallbookNum()<<endl;//д�뵽�ļ�
				 fileout.close();//�ر��ļ�
				 break;
			}
			
		}while(!filein.eof());//�ж��Ƿ��ļ�β
		if(n==0){//�������Ȿ��
		cout<<"δ�ҵ�Ҫ�޸ĵ��鼮��"<<endl;
		filein.close();//�ر�
		}
	}
	filein.close();//�ر�

	ifstream filei("restore.txt");//���ĵ�
	ofstream fileout("store.txt",ios::out);//���ĵ����������

	for(string s;getline(filei,s);)//���޸ĺ������д���ļ���ȥ
	{
		fileout<<s<<endl;
	}
	filei.close();//�ر��ļ�
	fileout.close();//�ر��ļ�
	system("del restore.txt");//ɾ���ļ�����
}


void manage::deleteBook()
{
	book book2;//ʵ��������
	ifstream filein("store.txt");//���ļ�
	if(!filein)
	{
		cout<<"���ļ�ʧ�ܣ�"<<endl;
	}
	else
	{
		cout<<"������ɾ���鼮�ĵ�������"<<endl;
		int n=0;//��ǩ���Ƿ����Ȿ��
		string t;//��������
		cin>>t;
		do
		{   int a,b,c;//�������
			float i;
			string x,y,z,u,w;
		    string s;
			getline(filein,s);//����ÿһ��
			istringstream sin(s);
			sin>>x>>y>>z>>u>>w>>i>>b>>c;//��һ���ַ�������
            ofstream fileout("restore.txt",ios::app);//д�����ļ���ȥ
			
			if(t!=x)//�ж��Ƿ�Ϊɾ���ĵط�
			fileout<<s<<endl;//д������

			if(t==x)//�ж��Ƿ�Ϊɾ���ĵط�
			{
				n=1;
				book2.setName(x);//�趨����
				book2.setAuthor(y);//�趨����
				book2.setISBN(z);//�趨ISBN��
				book2.settype(u);//�趨����
				book2.setPress(w);//�趨������
				book2.setPrice(i);//�趨����
				book2.setbookNum(b);//�趨�����
			    book2.setallbookNum(c);//�趨�������
				cout<<"ԭ�鼮��ϢΪ:"<<endl;
				book2.printBookInformation();//���

				cout<<"�Ƿ�ɾ������Y���ǣ�N����"<<endl;
				char a;//�������
				cin>>a;
				if(a=='Y')
				{
					cout<<"ɾ���ɹ���"<<endl;
				}
			    if(a=='N')
				{
					cout<<"δɾ����"<<endl;
				    fileout<<book2.getName()<<" "<<book2.getbookAuthor()<<" "<<book2.getbookISBN()<<" "<<book2.gettype()
					<<" "<<book2.getbookPress()<<" "<<book2.getbookPrice()<<" "<<book2.getbookNum()<<" "<<book2.getallbookNum()<<endl;//д�뵽�ļ�
				}
				if(a!='Y'||a!='N')
				{
					system("pause");
				}
				fileout.close();//�ر��ļ�
			}
			
		}while(!filein.eof());//�ж��Ƿ��ļ�β
		if(n==0){//�������Ȿ��
		cout<<"δ�ҵ�Ҫɾ�����鼮��"<<endl;	
		}
		filein.close();//�ر�
	}
	
	ifstream filei("restore.txt");//���ĵ�
	ofstream fileout("store.txt",ios::out);//���ĵ����������

	for(string s;getline(filei,s);)//���޸ĺ������д���ļ���ȥ
	{
		fileout<<s<<endl;
	}
	filei.close();//�ر��ļ�
	fileout.close();//�ر��ļ�
	system("del restore.txt");//ɾ���ļ�����
}

void manage::addReader()//���Ӷ��ߺ���
{
	ofstream fout("student.txt",ios::app);//���ļ�
	string a,b,c;
	cout<<"��������Ӧ��Ϣ��"<<endl;
	cout<<"������"<<endl;
	cin>>a;
	cout<<"ѧ�ţ�"<<endl;
	cin>>b;
	cout<<"���룺"<<endl;
	cin >>c;
	fout<<a<<" "<<b<<" "<<c<<" "<<endl;
    fout.close();//�ر��ļ�
}

void manage::deleteReader()
{
	
	ifstream filein("student.txt");//���ļ�
	if(!filein)
	{
		cout<<"���ļ�ʧ�ܣ�"<<endl;
	}
	else
	{
		string t,m;
		int n=0;//��ǩ���Ƿ����������
		cout<<"������ɾ��ѧ���ĵ�������"<<endl;
		cin>>m;
        cout<<"������ɾ��ѧ���ĵ�ѧ�ţ�"<<endl;
		cin>>t;
		do
		{   
			string x,y,z;//�������
		    string s;
			getline(filein,s);//����ÿһ��
			istringstream sin(s);
			sin>>x>>y>>z;//��s�е�һ���ַ�����a
            ofstream fileout("student1.txt",ios::app);//д�����ļ���ȥ
			
			if(m!=x||t!=y)//�ж��Ƿ�Ϊɾ���ĵط�
			fileout<<s<<endl;//д������

			if(m==x&&t==y)//�ж��Ƿ�Ϊɾ���ĵط�
			{
				n=1;
				cout<<"ԭѧ����ϢΪ:"<<endl;
				cout<<"������"<<x<<endl;
				cout<<"ѧ�ţ�"<<y<<endl;
				cout<<"���룺"<<z<<endl;
				cout<<"�Ƿ�ɾ������Y���ǣ�N����"<<endl;
				char a;//�������
				cin>>a;
				if(a=='Y')
				{
					cout<<"ɾ���ɹ���"<<endl;
				}
			    if(a=='N')
				{
					cout<<"δɾ����"<<endl;
				    fileout<<x<<" "<<y<<" "<<z<<endl;//д�뵽�ļ�
				}
				if(a!='Y'||a!='N')
				{
					system("pause");
				}
				fileout.close();//�ر��ļ�
			}
			
		}
		while(!filein.eof());//�ж��Ƿ��ļ�β
		if(n==0)//���������ѧ��
		cout<<"δ�ҵ�Ҫɾ����ѧ����"<<endl;
	}
	filein.close();//�ر�

	ifstream filei("student1.txt");//���ĵ�
	ofstream fileout("student.txt",ios::out);//���ĵ����������

	for(string s;getline(filei,s);)//���޸ĺ������д���ļ���ȥ
	{
		fileout<<s<<endl;
	}
	filei.close();//�ر��ļ�
	fileout.close();//�ر��ļ�
	system("del student1.txt");//ɾ���ļ�����
}

void manage::findAllBooks()//�����ѯ�����鼮����
{
	book book3;//ʵ��������
	ifstream filein("store.txt");//���ļ�
	if(!filein)
	{
		cout<<"���ļ�ʧ�ܣ�"<<endl;
	}
	else
	{
		cout <<"  ����"<<setw(25)<<"����"<<setw(10)<<"ISBN��"<<setw(10)<<"����"<<setw(20)<<"������"<<setw(10)<<"����"<<setw(10)<<"�����"<<setw(10)<<"�������" << endl;
		for(string s;getline(filein,s);)//�ж϶��������
		{
			int b,c,d;//b���п�棬c�ܿ��
			float i;
			string a,x,y,z,u,w;//�������
			istringstream sin(s);//����sin��
			sin>>x>>y>>z>>u>>w>>i>>b>>c;//��һ���ַ�������	  				
			if (x=="") {
				
			}
			else {
				book3.setName(x);//�趨����
				book3.setAuthor(y);//�趨����
				book3.setISBN(z);//�趨ISBN��
				book3.settype(u);//�趨����
				book3.setPress(w);//�趨������
				book3.setPrice(i);//�趨����
				book3.setbookNum(b);//�趨�����
				book3.setallbookNum(c);//�趨�������
				cout << book3.getName() << setw(15) << book3.getbookAuthor() << setw(10) << book3.getbookISBN() << setw(10) << book3.gettype()
					<< setw(20) << book3.getbookPress() << setw(10) << book3.getbookPrice() << setw(10) << book3.getbookNum() << setw(10) << book3.getallbookNum() << endl;//�������̨
			}
		}
	
	}
			filein.close();//�ر��ļ�
}

void manage::findAllBorrow()
{
	borrow borrow;
	borrow.printBorrowInfo();
}

manage::~manage()//��������
{
}
