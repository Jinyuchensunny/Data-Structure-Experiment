#include "reader.h"
#include "book.h"
#include "borrow.h"

reader::reader()
    {
	name="未命名";

    }

string reader::getName()const//获得姓名
        {
               return name;
        }

string reader::getNumber()const//获得学号
        {
               return number;
        }

string reader::getCode()const//获得密码
        {
               return code;
        }

void reader::setName(string n)//设定姓名
      {
		  name=n;
	  }

void reader::setNumber(string nu)//设定学号
      {
		  number=nu;
	  }

void reader::setCode(string c)//设定密码
      {
		  code=c;
	  }

int reader::getInformation()//验证信息
      {
           cout<<"欢迎登陆图书管理系统！"<<endl;
           string a,b,t;
           cout<<"请输入姓名："<<endl;
           cin>>a;
           cout<<"请输入学号："<<endl;
           cin>>b;
           cout<<"请输入密码：(初始密码为学号)"<<endl;
           cin>>t;

		   string n,nu,c;
           ifstream in("student.txt");//打开文件
		   int i=0;//标签，判断账号的存在与否
           do
           {
			     
                  //if(in.eof())//文件尾就结束
                  //break;
				  string s;//定义变量
			      getline(in,s);//读入每一行
			      istringstream sin(s);//定义sin流
                  sin>>n>>nu>>c;
				  if((a==n)&&(b==nu)&&(c==t))//账号存在
                  {
					 i=1;
                     cout<<"登陆成功！"<<endl;
					 //cout << n << nu << c << endl;
					 system("pause");
					 setName(n);
					 setNumber(nu);
					 setCode(c);
					 return 1;//返回真值 
					 break;             
                  }
           }
		   while(!in.eof());//判断是否到文件尾

		   if(i==0)//未找到账号
				cout<<"输入不正确！" <<endl;
		        return 0;//返回假值
           in.close();//关闭文件
      }

void reader::reviseCode()//修改密码
      {    
		  int t=0;//标签，判断账号是否存在
		  string a,b,c,d,e,f;//定义变量
		  cout<<"请输入个人信息："<<endl;
		  cout<<"姓名:"<<endl;
		  cin>>d;
		  cout<<"学号："<<endl;
		  cin>>e;
		  cout<<"密码：(初始密码为学号)"<<endl;
		  cin>>f;
		  ifstream in("student.txt");//打开文件
		  string s1;
          while( getline(in,s1))//读入数据
           {
			 istringstream sin(s1);//定义sin1流
             sin>>a>>b>>c;
			 ofstream out("student1.txt",ios::app);//打开写入文件
             if((a==d)&&(b==e)&&(c==f))//判断是否输入正确
             {
				t=1;
				string m,p,q;//定义变量
				cout<<"请输入修改后的信息:" <<endl;
				cout<<"姓名："<<endl;
				cin>>m;
				cout<<"学号："<<endl;
				cin>>p;
				cout<<"密码："<<endl;
                cin>>q;
				out<<m<<" "<<p<<" "<<q<<endl; 
				cout<<"修改成功"<<endl;
		      }
		      else
			     out<<a<<" "<<b<<" "<<c<<endl;//写入未修改的内容
		         out.close();//关闭文件
			}
		   in.close();//关闭文件

		ifstream filein("student1.txt");//打开文档
		ofstream fileout("student.txt",ios::out);//打开文档并清空内容
		string s;
		while(getline(filein,s))//将修改后的内容写到文件中去
		{
			fileout<<s<<endl;
		}
		filein.close();//关闭文件
		fileout.close();//关闭文件

		if(t==0)//账号输入错误
        {
	       cout<<"输入错误！"<<endl;
	     }
		 system("del student1.txt");//删除文件
      }

void reader::search()//定义查询函数
{
	book book1;//实例化对象
	ifstream filein("store.txt");//打开文件
	if(!filein)
	{
		cout<<"打开文件失败！"<<endl;
	}
	else
	{
		cout<<"请输入查询的书名："<<endl;
		string t;//输入书名
		cin>>t;
		int m=0;//标签，判断是否有这本书
		for(string s;getline(filein,s);)//判断读入的书名
		{
			int b, c, d;//b现有库存，c总库存
			float i;
			string a, x, y, z, u, w;//定义变量
			istringstream sin(s);//定义sin流
			sin >> x >> y >> z >> u >> w >> i >> b >> c;//将一行字符串读出
			a = x;
			if(t==a)//判断是否找到查找的书籍
			{
				m++;
				book1.setName(x);//设定书名
				book1.setAuthor(y);//设定作者
				book1.setISBN(z);//设定ISBN码
				book1.settype(u);//设定书项
				book1.setPress(w);//设定出版社
				book1.setPrice(i);//设定单价
				book1.setbookNum(b);//设定库存量
				book1.setallbookNum(c);//设定库存总量
				book1.printBookInformation();//输出
			    break;
			
	        }
		}
		if(m==0)//判断是否有此书籍
			cout<<"未找到要查找的书籍！"<<endl;
		}
	filein.close();//关闭文件

}
void reader::findAllBooks()//定义查询所有书籍函数
{
	book book3;//实例化对象
	ifstream filein("store.txt");//打开文件
	if (!filein)
	{
		cout << "打开文件失败！" << endl;
	}
	else
	{
		cout <<"  书名"<<setw(25)<<"作者"<<setw(10)<<"ISBN码"<<setw(10)<<"书项"<<setw(20)<<"出版社"<<setw(10)<<"单价"<<setw(10)<<"库存量"<<setw(10)<<"库存总量" << endl;
		for (string s; getline(filein, s);)//判断读入的书名
		{
			int b, c, d;//b现有库存，c总库存
			float i;
			string a, x, y, z, u, w;//定义变量
			istringstream sin(s);//定义sin流
			sin >> x >> y >> z >> u >> w >> i >> b >> c;//将一行字符串读出	  				
			if (x == "") {

			}
			else {
				book3.setName(x);//设定书名
				book3.setAuthor(y);//设定作者
				book3.setISBN(z);//设定ISBN码
				book3.settype(u);//设定书项
				book3.setPress(w);//设定出版社
				book3.setPrice(i);//设定单价
				book3.setbookNum(b);//设定库存量
				book3.setallbookNum(c);//设定库存总量
				cout << book3.getName() <<setw(20)<< book3.getbookAuthor() <<setw(10)<< book3.getbookISBN() <<setw(10)<< book3.gettype()
					<<setw(15)<< book3.getbookPress() <<setw(10)<< book3.getbookPrice() <<setw(10)<< book3.getbookNum() <<setw(10)<< book3.getallbookNum() << endl;//输出控制台
			}
		}

	}
	filein.close();//关闭文件
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
	cout<<"请输入需要查询书籍借阅信息的ISBN码："<<endl;//读入ISBN码
	cin>>isbn;
	borrow.searchInfobybook(isbn);
}

void reader::borrowBook()//定义借书函数
  {
	book book2;//实例化对象
	borrow borrow;
	cout<<"请输入书籍名称："<<endl; 
	ifstream filein("store.txt");//打开文件
    string t;//输入书名		
	cin>>t;
	int m=0;
	for(string s;getline(filein,s);)//判断读入的书名
	{
		//string a;//读出每行的开头
		int b,c,d;//b现有库存，c总库存
		float i;
		string a,x,y,z,u,w;//定义变量
		istringstream sin(s);//定义sin流
		sin>>x>>y>>z>>u>>w>>i>>b>>c;//将一行字符串读出
		a=x;
		if(t==a)//判断是否找到借的书籍
		{
			m++;
			book2.setName(x);//设定书名
			book2.setAuthor(y);//设定作者
			book2.setISBN(z);//设定ISBN码
			book2.settype(u);//设定书项
			book2.setPress(w);//设定出版社
			book2.setPrice(i);//设定单价
			book2.setbookNum(b);//设定库存量
			book2.setallbookNum(c);//设定库存总量
			book2.printBookInformation();//输出
			break;
        }   
	 }

	if(m==0){//判断是否有此书籍
		cout<<"未找到要借的书籍！"<<endl;
		filein.close();//关闭文件
	}

		if(book2.getbookNum()!=0)//是否在馆
	{
	cout<<"是否借书？（Y:是,N:否）"<<endl;
	char n;
	cin>>n;
	if(n=='Y')
	{
		cout<<"书名："<<t<<endl;
		cout<<"借书成功！"<<endl;
		ifstream filein("store.txt");//打开文件
		do
		{   
			int b,c,d;//b现有库存，c总库存
			float i;
			string a,x,y,z,u,w;//定义变量
		    string s;
			getline(filein,s);//读入每一行
			istringstream sin(s);
			sin>>x>>y>>z>>u>>w>>i>>b>>c;//将一行字符串读出
            ofstream fileout("restore1.txt",ios::app);//写到新文件中去
			
			if(t!=x)//判断是否为修改的地方
			fileout<<s<<endl;//写入数据

			if(t==x)//判断是否为修改的地方
			{
				book2.setName(x);//设定书名
				book2.setAuthor(y);//设定作者
				book2.setISBN(z);//设定ISBN码
				book2.settype(u);//设定书项
				book2.setPress(w);//设定出版社
				book2.setPrice(i);//设定单价
				book2.setbookNum(b-1);//设定库存量
				book2.setallbookNum(c);//设定库存总量

				borrow.addBorrow(z, number);

				fileout<<book2.getName()<<" "<<book2.getbookAuthor()<<" "<<book2.getbookISBN()<<" "<<book2.gettype()
				<<" "<<book2.getbookPress()<<" "<<book2.getbookPrice()<<" "<<book2.getbookNum()<<" "<<book2.getallbookNum()<<endl;//写入到文件
				 fileout.close();//关闭文件
				 break;
			}
			
		}
		while(!filein.eof());//判断是否到文件尾
		filein.close();//关闭

	ifstream filei("restore1.txt");//打开文档
	ofstream fileout("store.txt",ios::out);//打开文档并清空内容
    for(string s;getline(filei,s);)//将修改后的内容写到文件中去
	{
		fileout<<s<<endl;
	}
	filei.close();//关闭文件
	fileout.close();
	system("del restore1.txt");//删除文件副本
	}

	 else
		 if(n=='N')
	{cout<<"未借书！"<<endl;}
	else
	{
		cout<<"输入错误！"<<endl;
    }

	}
	else //已借出无法再借
	{
		cout<<"该书已借出!"<<endl;
		system("pause");
	}
    
}

void reader::returnBook()//定义还书函数
{
	book book3;//实例化对象
	borrow borrow;
	cout<<"请输入书籍名称："<<endl;
	ifstream filein("store.txt");//打开文件
	string t;//输入书名
	cin>>t;
	int m=0;//标签，是否有这本书
	for(string s;getline(filein,s);)//判断读入的书名
	{
	//	string a;//读出每行的开头
		int b,c,d;//b现有库存，c总库存
		float i;
		string a,x,y,z,u,w;//定义变量
		istringstream sin(s);//定义sin流
		sin>>x>>y>>z>>u>>w>>i>>b>>c;//将一行字符串读出
		a=x;
		if(t==a)//判断是否找到借的书籍
		{
			m++;
			book3.setName(x);//设定书名
			book3.setAuthor(y);//设定作者
			book3.setISBN(z);//设定ISBN码
			book3.settype(u);//设定书项
			book3.setPress(w);//设定出版社
			book3.setPrice(i);//设定单价
			book3.setbookNum(b);//设定库存量
			book3.setallbookNum(c);//设定库存总量
			book3.printBookInformation();//输出
			break;
        }   
	    }
	if(m==0)//判断是否有此书籍
		cout<<"未找到要还的书籍！"<<endl;
        filein.close();//关闭文件
	if(book3.getallbookNum()!=0)//判断是否被借出过
	{
	cout<<"是否还书？（Y:是,N:否）"<<endl;
	char n;
	cin>>n;
	if(n=='Y')
	{
		cout<<"书名："<<t<<endl;
		cout<<"还书成功！"<<endl;
		ifstream filein("store.txt");
		do
		{   
			int b,c,d;//b现有库存，c总库存
			float i;
			string a,x,y,z,u,w;//定义变量

		    string s;
			getline(filein,s);//读入每一行
			istringstream sin(s);
			sin>>x>>y>>z>>u>>w>>i>>b>>c;//将一行字符串读出
            ofstream fileout("restore2.txt",ios::app);//写到新文件中去
			if(t!=x)//判断是否为修改的地方
			fileout<<s<<endl;//写入数据
            if(t==x)//判断是否为修改的地方
			{
				book3.setName(x);//设定书名
				book3.setAuthor(y);//设定作者
				book3.setISBN(z);//设定ISBN码
				book3.settype(u);//设定书项
				book3.setPress(w);//设定出版社
				book3.setPrice(i);//设定单价
				book3.setbookNum(b+1);//设定库存量
				book3.setallbookNum(c);//设定库存总量
				borrow.updateInfo(z,number);


				fileout<<book3.getName()<<" "<<book3.getbookAuthor()<<" "<<book3.getbookISBN()<<" "<<book3.gettype()
				<<" "<<book3.getbookPress()<<" "<<book3.getbookPrice()<<" "<<book3.getbookNum()<<" "<<book3.getallbookNum()<<endl;//写入到文件
				 fileout.close();
			}
			
		}
		while(!filein.eof());//判断是否到文件尾
		filein.close();//关闭

	ifstream filei("restore2.txt");//打开文档
	ofstream fileout("store.txt",ios::out);//打开文档并清空内容
    for(string s;getline(filei,s);)//将修改后的内容写到文件中去
	{
		fileout<<s<<endl;
	}
	filei.close();//关闭文件
	fileout.close();//关闭文件
	system("del restore2.txt");//删除文件副本
	}
    else
	if(n=='N')
	{
		cout<<"未还书！"<<endl;
	}
	else
	{
		cout<<"输入错误！"<<endl;}
	}
	else 
	{
		cout<<"该书未被借出"<<endl;
		system("pause");
	}
	}

reader::~reader()
{
}
