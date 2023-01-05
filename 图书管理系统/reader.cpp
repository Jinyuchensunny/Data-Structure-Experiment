#include "reader.h"
#include "book.h"
#include "borrow.h"

reader::reader()
    {
	name="δ����";

    }

string reader::getName()const//�������
        {
               return name;
        }

string reader::getNumber()const//���ѧ��
        {
               return number;
        }

string reader::getCode()const//�������
        {
               return code;
        }

void reader::setName(string n)//�趨����
      {
		  name=n;
	  }

void reader::setNumber(string nu)//�趨ѧ��
      {
		  number=nu;
	  }

void reader::setCode(string c)//�趨����
      {
		  code=c;
	  }

int reader::getInformation()//��֤��Ϣ
      {
           cout<<"��ӭ��½ͼ�����ϵͳ��"<<endl;
           string a,b,t;
           cout<<"������������"<<endl;
           cin>>a;
           cout<<"������ѧ�ţ�"<<endl;
           cin>>b;
           cout<<"���������룺(��ʼ����Ϊѧ��)"<<endl;
           cin>>t;

		   string n,nu,c;
           ifstream in("student.txt");//���ļ�
		   int i=0;//��ǩ���ж��˺ŵĴ������
           do
           {
			     
                  //if(in.eof())//�ļ�β�ͽ���
                  //break;
				  string s;//�������
			      getline(in,s);//����ÿһ��
			      istringstream sin(s);//����sin��
                  sin>>n>>nu>>c;
				  if((a==n)&&(b==nu)&&(c==t))//�˺Ŵ���
                  {
					 i=1;
                     cout<<"��½�ɹ���"<<endl;
					 //cout << n << nu << c << endl;
					 system("pause");
					 setName(n);
					 setNumber(nu);
					 setCode(c);
					 return 1;//������ֵ 
					 break;             
                  }
           }
		   while(!in.eof());//�ж��Ƿ��ļ�β

		   if(i==0)//δ�ҵ��˺�
				cout<<"���벻��ȷ��" <<endl;
		        return 0;//���ؼ�ֵ
           in.close();//�ر��ļ�
      }

void reader::reviseCode()//�޸�����
      {    
		  int t=0;//��ǩ���ж��˺��Ƿ����
		  string a,b,c,d,e,f;//�������
		  cout<<"�����������Ϣ��"<<endl;
		  cout<<"����:"<<endl;
		  cin>>d;
		  cout<<"ѧ�ţ�"<<endl;
		  cin>>e;
		  cout<<"���룺(��ʼ����Ϊѧ��)"<<endl;
		  cin>>f;
		  ifstream in("student.txt");//���ļ�
		  string s1;
          while( getline(in,s1))//��������
           {
			 istringstream sin(s1);//����sin1��
             sin>>a>>b>>c;
			 ofstream out("student1.txt",ios::app);//��д���ļ�
             if((a==d)&&(b==e)&&(c==f))//�ж��Ƿ�������ȷ
             {
				t=1;
				string m,p,q;//�������
				cout<<"�������޸ĺ����Ϣ:" <<endl;
				cout<<"������"<<endl;
				cin>>m;
				cout<<"ѧ�ţ�"<<endl;
				cin>>p;
				cout<<"���룺"<<endl;
                cin>>q;
				out<<m<<" "<<p<<" "<<q<<endl; 
				cout<<"�޸ĳɹ�"<<endl;
		      }
		      else
			     out<<a<<" "<<b<<" "<<c<<endl;//д��δ�޸ĵ�����
		         out.close();//�ر��ļ�
			}
		   in.close();//�ر��ļ�

		ifstream filein("student1.txt");//���ĵ�
		ofstream fileout("student.txt",ios::out);//���ĵ����������
		string s;
		while(getline(filein,s))//���޸ĺ������д���ļ���ȥ
		{
			fileout<<s<<endl;
		}
		filein.close();//�ر��ļ�
		fileout.close();//�ر��ļ�

		if(t==0)//�˺��������
        {
	       cout<<"�������"<<endl;
	     }
		 system("del student1.txt");//ɾ���ļ�
      }

void reader::search()//�����ѯ����
{
	book book1;//ʵ��������
	ifstream filein("store.txt");//���ļ�
	if(!filein)
	{
		cout<<"���ļ�ʧ�ܣ�"<<endl;
	}
	else
	{
		cout<<"�������ѯ��������"<<endl;
		string t;//��������
		cin>>t;
		int m=0;//��ǩ���ж��Ƿ����Ȿ��
		for(string s;getline(filein,s);)//�ж϶��������
		{
			int b, c, d;//b���п�棬c�ܿ��
			float i;
			string a, x, y, z, u, w;//�������
			istringstream sin(s);//����sin��
			sin >> x >> y >> z >> u >> w >> i >> b >> c;//��һ���ַ�������
			a = x;
			if(t==a)//�ж��Ƿ��ҵ����ҵ��鼮
			{
				m++;
				book1.setName(x);//�趨����
				book1.setAuthor(y);//�趨����
				book1.setISBN(z);//�趨ISBN��
				book1.settype(u);//�趨����
				book1.setPress(w);//�趨������
				book1.setPrice(i);//�趨����
				book1.setbookNum(b);//�趨�����
				book1.setallbookNum(c);//�趨�������
				book1.printBookInformation();//���
			    break;
			
	        }
		}
		if(m==0)//�ж��Ƿ��д��鼮
			cout<<"δ�ҵ�Ҫ���ҵ��鼮��"<<endl;
		}
	filein.close();//�ر��ļ�

}
void reader::findAllBooks()//�����ѯ�����鼮����
{
	book book3;//ʵ��������
	ifstream filein("store.txt");//���ļ�
	if (!filein)
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
	}
	else
	{
		cout <<"  ����"<<setw(25)<<"����"<<setw(10)<<"ISBN��"<<setw(10)<<"����"<<setw(20)<<"������"<<setw(10)<<"����"<<setw(10)<<"�����"<<setw(10)<<"�������" << endl;
		for (string s; getline(filein, s);)//�ж϶��������
		{
			int b, c, d;//b���п�棬c�ܿ��
			float i;
			string a, x, y, z, u, w;//�������
			istringstream sin(s);//����sin��
			sin >> x >> y >> z >> u >> w >> i >> b >> c;//��һ���ַ�������	  				
			if (x == "") {

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
				cout << book3.getName() <<setw(20)<< book3.getbookAuthor() <<setw(10)<< book3.getbookISBN() <<setw(10)<< book3.gettype()
					<<setw(15)<< book3.getbookPress() <<setw(10)<< book3.getbookPrice() <<setw(10)<< book3.getbookNum() <<setw(10)<< book3.getallbookNum() << endl;//�������̨
			}
		}

	}
	filein.close();//�ر��ļ�
}

void reader::findAllBorrow()
{
	borrow borrow;
	borrow.searchInfo(number);
}

void reader::findBorrowbyBookId()
{
	borrow borrow;
	string isbn;
	cout<<"��������Ҫ��ѯ�鼮������Ϣ��ISBN�룺"<<endl;//����ISBN��
	cin>>isbn;
	borrow.searchInfobybook(isbn);
}

void reader::borrowBook()//������麯��
  {
	book book2;//ʵ��������
	borrow borrow;
	cout<<"�������鼮���ƣ�"<<endl; 
	ifstream filein("store.txt");//���ļ�
    string t;//��������		
	cin>>t;
	int m=0;
	for(string s;getline(filein,s);)//�ж϶��������
	{
		//string a;//����ÿ�еĿ�ͷ
		int b,c,d;//b���п�棬c�ܿ��
		float i;
		string a,x,y,z,u,w;//�������
		istringstream sin(s);//����sin��
		sin>>x>>y>>z>>u>>w>>i>>b>>c;//��һ���ַ�������
		a=x;
		if(t==a)//�ж��Ƿ��ҵ�����鼮
		{
			m++;
			book2.setName(x);//�趨����
			book2.setAuthor(y);//�趨����
			book2.setISBN(z);//�趨ISBN��
			book2.settype(u);//�趨����
			book2.setPress(w);//�趨������
			book2.setPrice(i);//�趨����
			book2.setbookNum(b);//�趨�����
			book2.setallbookNum(c);//�趨�������
			book2.printBookInformation();//���
			break;
        }   
	 }

	if(m==0){//�ж��Ƿ��д��鼮
		cout<<"δ�ҵ�Ҫ����鼮��"<<endl;
		filein.close();//�ر��ļ�
	}

		if(book2.getbookNum()!=0)//�Ƿ��ڹ�
	{
	cout<<"�Ƿ���飿��Y:��,N:��"<<endl;
	char n;
	cin>>n;
	if(n=='Y')
	{
		cout<<"������"<<t<<endl;
		cout<<"����ɹ���"<<endl;
		ifstream filein("store.txt");//���ļ�
		do
		{   
			int b,c,d;//b���п�棬c�ܿ��
			float i;
			string a,x,y,z,u,w;//�������
		    string s;
			getline(filein,s);//����ÿһ��
			istringstream sin(s);
			sin>>x>>y>>z>>u>>w>>i>>b>>c;//��һ���ַ�������
            ofstream fileout("restore1.txt",ios::app);//д�����ļ���ȥ
			
			if(t!=x)//�ж��Ƿ�Ϊ�޸ĵĵط�
			fileout<<s<<endl;//д������

			if(t==x)//�ж��Ƿ�Ϊ�޸ĵĵط�
			{
				book2.setName(x);//�趨����
				book2.setAuthor(y);//�趨����
				book2.setISBN(z);//�趨ISBN��
				book2.settype(u);//�趨����
				book2.setPress(w);//�趨������
				book2.setPrice(i);//�趨����
				book2.setbookNum(b-1);//�趨�����
				book2.setallbookNum(c);//�趨�������

				borrow.addBorrow(z, number);

				fileout<<book2.getName()<<" "<<book2.getbookAuthor()<<" "<<book2.getbookISBN()<<" "<<book2.gettype()
				<<" "<<book2.getbookPress()<<" "<<book2.getbookPrice()<<" "<<book2.getbookNum()<<" "<<book2.getallbookNum()<<endl;//д�뵽�ļ�
				 fileout.close();//�ر��ļ�
				 break;
			}
			
		}
		while(!filein.eof());//�ж��Ƿ��ļ�β
		filein.close();//�ر�

	ifstream filei("restore1.txt");//���ĵ�
	ofstream fileout("store.txt",ios::out);//���ĵ����������
    for(string s;getline(filei,s);)//���޸ĺ������д���ļ���ȥ
	{
		fileout<<s<<endl;
	}
	filei.close();//�ر��ļ�
	fileout.close();
	system("del restore1.txt");//ɾ���ļ�����
	}

	 else
		 if(n=='N')
	{cout<<"δ���飡"<<endl;}
	else
	{
		cout<<"�������"<<endl;
    }

	}
	else //�ѽ���޷��ٽ�
	{
		cout<<"�����ѽ��!"<<endl;
		system("pause");
	}
    
}

void reader::returnBook()//���廹�麯��
{
	book book3;//ʵ��������
	borrow borrow;
	cout<<"�������鼮���ƣ�"<<endl;
	ifstream filein("store.txt");//���ļ�
	string t;//��������
	cin>>t;
	int m=0;//��ǩ���Ƿ����Ȿ��
	for(string s;getline(filein,s);)//�ж϶��������
	{
	//	string a;//����ÿ�еĿ�ͷ
		int b,c,d;//b���п�棬c�ܿ��
		float i;
		string a,x,y,z,u,w;//�������
		istringstream sin(s);//����sin��
		sin>>x>>y>>z>>u>>w>>i>>b>>c;//��һ���ַ�������
		a=x;
		if(t==a)//�ж��Ƿ��ҵ�����鼮
		{
			m++;
			book3.setName(x);//�趨����
			book3.setAuthor(y);//�趨����
			book3.setISBN(z);//�趨ISBN��
			book3.settype(u);//�趨����
			book3.setPress(w);//�趨������
			book3.setPrice(i);//�趨����
			book3.setbookNum(b);//�趨�����
			book3.setallbookNum(c);//�趨�������
			book3.printBookInformation();//���
			break;
        }   
	    }
	if(m==0)//�ж��Ƿ��д��鼮
		cout<<"δ�ҵ�Ҫ�����鼮��"<<endl;
        filein.close();//�ر��ļ�
	if(book3.getallbookNum()!=0)//�ж��Ƿ񱻽����
	{
	cout<<"�Ƿ��飿��Y:��,N:��"<<endl;
	char n;
	cin>>n;
	if(n=='Y')
	{
		cout<<"������"<<t<<endl;
		cout<<"����ɹ���"<<endl;
		ifstream filein("store.txt");
		do
		{   
			int b,c,d;//b���п�棬c�ܿ��
			float i;
			string a,x,y,z,u,w;//�������

		    string s;
			getline(filein,s);//����ÿһ��
			istringstream sin(s);
			sin>>x>>y>>z>>u>>w>>i>>b>>c;//��һ���ַ�������
            ofstream fileout("restore2.txt",ios::app);//д�����ļ���ȥ
			if(t!=x)//�ж��Ƿ�Ϊ�޸ĵĵط�
			fileout<<s<<endl;//д������
            if(t==x)//�ж��Ƿ�Ϊ�޸ĵĵط�
			{
				book3.setName(x);//�趨����
				book3.setAuthor(y);//�趨����
				book3.setISBN(z);//�趨ISBN��
				book3.settype(u);//�趨����
				book3.setPress(w);//�趨������
				book3.setPrice(i);//�趨����
				book3.setbookNum(b+1);//�趨�����
				book3.setallbookNum(c);//�趨�������
				borrow.updateInfo(z,number);


				fileout<<book3.getName()<<" "<<book3.getbookAuthor()<<" "<<book3.getbookISBN()<<" "<<book3.gettype()
				<<" "<<book3.getbookPress()<<" "<<book3.getbookPrice()<<" "<<book3.getbookNum()<<" "<<book3.getallbookNum()<<endl;//д�뵽�ļ�
				 fileout.close();
			}
			
		}
		while(!filein.eof());//�ж��Ƿ��ļ�β
		filein.close();//�ر�

	ifstream filei("restore2.txt");//���ĵ�
	ofstream fileout("store.txt",ios::out);//���ĵ����������
    for(string s;getline(filei,s);)//���޸ĺ������д���ļ���ȥ
	{
		fileout<<s<<endl;
	}
	filei.close();//�ر��ļ�
	fileout.close();//�ر��ļ�
	system("del restore2.txt");//ɾ���ļ�����
	}
    else
	if(n=='N')
	{
		cout<<"δ���飡"<<endl;
	}
	else
	{
		cout<<"�������"<<endl;}
	}
	else 
	{
		cout<<"����δ�����"<<endl;
		system("pause");
	}
	}

reader::~reader()
{
}
