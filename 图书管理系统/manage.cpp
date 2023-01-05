#include "manage.h"
#include "book.h"
#include"borrow.h"
#include <string>
using namespace std;//名空间
manage::manage()//析构函数
{

}

int manage::getManage()//登录函数
{
	cout<<"欢迎登陆图书管理系统！"<<endl;
	string a,b;
	cout<<"请输入账号："<<endl;
	cin>>a;
	cout<<"请输入密码："<<endl;
	cin>>b;
	string n,c;
    ifstream in("manage.txt");//打开文件
	int i=0;//标签，判断账号的存在与否
    do
     {
	   if(in.eof())//文件尾就结束
       break;
	   
	   string s;
	   getline(in,s);//读入每一行
       istringstream sin(s);//定义sin流
       sin>>n>>c;
	   if((a==n)&&(c==b))//判断是否存在
         {
			 i=1;
		     return 1;//返回真值      
             cout<<"登陆成功！"<<endl;
			 break; 
					            
         }
     }
	while(!in.eof());//判断是否到文件尾

    if(i==0)//未找到账号
	cout<<"输入不正确！" <<endl;
    return 0;//返回假值
    in.close();//关闭文件
}

void manage::reviseInformation()//修改信息函数
{
  int t=0;//标签，是否存在该账号
  string a,b,c,d;
  cout<<"请输入个人信息："<<endl;
  cout<<"账号："<<endl;
  cin>>c;
  cout<<"密码："<<endl;
  cin>>d;
  ifstream in("manage.txt");//打开文件
  string s1;
  while( getline(in,s1))//读入数据
     {
		istringstream sin(s1);//定义sin流
        sin>>a>>b;
	    ofstream out("manage1.txt",ios::app);//打开文件
        if((a==c)&&(b==d))//存在该账号
          {
		    t=1;
		    string m,p;
			cout<<"请输入修改后的信息:" <<endl;
			cout<<"姓名："<<endl;
			cin>>m;
			cout<<"密码："<<endl;
			cin>>p;
            out<<m<<" "<<p<<endl; 
			cout<<"修改成功"<<endl;
		  }
		  else
			  out<<a<<" "<<b<<endl;//未修改
		      out.close();//关闭文件
	 }
		in.close();//关闭文件

		ifstream filein("manage1.txt");//打开文档
		ofstream fileout("manage.txt",ios::out);//打开文档并清空内容
		string s;
		while(getline(filein,s))//将修改后的内容写到文件中去
		{
			fileout<<s<<endl;
		}
		filein.close();//关闭文件
		fileout.close();//关闭文件

		if(t==0)//不存在该账号
        {
	       cout<<"输入错误！"<<endl;
	    }
		 system("del manage1.txt");
}

void manage::add()//定义添加书籍函数
{
	book book1;//实例化对象
	ofstream fileout("store.txt",ios::app);//打开文件
	if(!fileout)
	{
		cout<<"不能打开文件！"<<"store.txt"<<endl;
	}
	else
	{
		if(search(1)==1){
			
		}else{
			cout<<"请输入书本基本信息："<<endl;
			book1.readBookInformation();//读入信息
			fileout<<book1.getName()<<" "<<book1.getbookAuthor()<<" "<<book1.getbookISBN()<<" "<<book1.gettype()
			<<" "<<book1.getbookPress()<<" " << book1.getbookPrice()<<" "<<book1.getbookNum()<<" "<<book1.getallbookNum()<<endl;//写入信息
			fileout.close();//关闭文件
			system("del restore.txt");//删除文件副本
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


bool manage::search(int mode)//定义查询函数（新增现有书，先查询后新增）
{
	book book1;//实例化对象
	ifstream filein("store.txt");//打开文件
	if(!filein)
	{
		cout<<"打开文件失败！"<<endl;
		return 0;
	}
	else
	{
		cout<<"请输入需要添加的书名或书号："<<endl;
		string t;//输入书名或书号
		cin>>t;
		int m=0;//标签，判断是否有这本书
		for(string s;getline(filein,s);)//判断读入的书名
		{
			int b,c,d;//b现有库存，c总库存
			float i;
			string a,x,y,z,u,w;//定义变量
			istringstream sin(s);//定义sin流
			sin>>x>>y>>z>>u>>w>>i>>b>>c;//将一行字符串读出
			ofstream fileout("restore.txt",ios::app);//写到新文件中去
			
			if(AllisNum(t)){//判断是否为书号
				a=z;		//读出书号，把书号赋值给a
			}else{
					a=x;//读出每行的开头，把书名赋值给a
			}
				if(t!=a)//判断是否为修改的地方
				fileout<<s<<endl;//写入数据
				if(t==a)//判断是否找到查找的书籍
				{
					  
						m++;						
						book1.setName(x);//设定书名
						book1.setAuthor(y);//设定作者
						book1.setISBN(z);//设定ISBN码
						book1.settype(u);//设定书项
						book1.setPress(w);//设定出版社
						book1.setPrice(i);//设定单价
						book1.setbookNum(b);//现有库存
						book1.setallbookNum(c);//库存总量
						//book1.printBookInformation();
	
						if(mode == 1){ 
							//book1.addbookNum();
							cout<< "库存中查到此书，请输入新增库存数目." <<endl;
							cin>>d;
							book1.setbookNum(b+d);//现有库存
							book1.setallbookNum(c+d);//库存总量
						    fileout<<book1.getName()<<" "<<book1.getbookAuthor()<<" "<<book1.getbookISBN()<<" "<<book1.gettype()
								<<" "<<book1.getbookPress()<<" "<<book1.getbookPrice()<<" "<<book1.getbookNum()<<" "<<book1.getallbookNum()<<endl;//写入到文件
							
						}else{
							book1.printBookInformation();//输出
						}
						fileout.close();
						//break;
				}
	
		}
			if(m==0){//判断是否有此书籍
			cout<<"库存中未找到要查找的书籍！"<<endl;
			return 0;
		}
	}

	filein.close();//关闭文件
	if(mode==1){
		ifstream filei("restore.txt");//打开文档
		ofstream fileout("store.txt",ios::out);//打开文档并清空内容
		for(string s;getline(filei,s);)//将修改后的内容写到文件中去
		{	
			fileout<<s<<endl;
		}
	  filei.close();//关闭文件
	  fileout.close();//关闭文件
	
	}
	system("del restore.txt");//删除文件副本
	return 1;

}

void manage::revise()//定义修改书籍信息函数
{
	book book1;//实例化对象
	ifstream filein("store.txt");//打开文件
	if(!filein)
	{
		cout<<"打开文件失败！"<<endl;
	}
	else
	{
		cout<<"请输入修改书籍的的书名："<<endl;
		int n=0;//标签，是否有这本书
		string t;//输入书名
		cin>>t;
		do
		{   int b,c;//定义变量
			float i;
			string x,y,z,u,w;
		    string s;
			getline(filein,s);//读入每一行
			istringstream sin(s);
			sin>>x>>y>>z>>u>>w>>i>>b>>c;//将一行字符串读出
            ofstream fileout("restore.txt",ios::app);//写到新文件中去
			
			if(t!=x)//判断是否为修改的地方
			fileout<<s<<endl;//写入数据

			if(t==x)//判断是否为修改的地方
			{
				n=1;
				book1.setName(x);//设定书名
				book1.setAuthor(y);//设定作者
				book1.setISBN(z);//设定ISBN码
				book1.settype(u);//设定书项
				book1.setPress(w);//设定出版社
				book1.setPrice(i);//设定单价
				book1.setbookNum(b);//设定库存量
				book1.setallbookNum(c);//设定库存总量
				cout<<"原书籍信息为:"<<endl;
				book1.printBookInformation();//输出

				cout<<"请输入修改后的书籍信息："<<endl;
				 book1.readBookInformation();//重新读入
				 fileout<<book1.getName()<<" "<<book1.getbookAuthor()<<" "<<book1.getbookISBN()<<" "<<book1.gettype()
				<<" "<<book1.getbookPress()<<" "<<book1.getbookPrice()<<" "<<book1.getbookNum()<<" "<<book1.getallbookNum()<<endl;//写入到文件
				 fileout.close();//关闭文件
				 break;
			}
			
		}while(!filein.eof());//判断是否到文件尾
		if(n==0){//不存在这本书
		cout<<"未找到要修改的书籍！"<<endl;
		filein.close();//关闭
		}
	}
	filein.close();//关闭

	ifstream filei("restore.txt");//打开文档
	ofstream fileout("store.txt",ios::out);//打开文档并清空内容

	for(string s;getline(filei,s);)//将修改后的内容写到文件中去
	{
		fileout<<s<<endl;
	}
	filei.close();//关闭文件
	fileout.close();//关闭文件
	system("del restore.txt");//删除文件副本
}


void manage::deleteBook()
{
	book book2;//实例化对象
	ifstream filein("store.txt");//打开文件
	if(!filein)
	{
		cout<<"打开文件失败！"<<endl;
	}
	else
	{
		cout<<"请输入删除书籍的的书名："<<endl;
		int n=0;//标签，是否有这本书
		string t;//输入书名
		cin>>t;
		do
		{   int a,b,c;//定义变量
			float i;
			string x,y,z,u,w;
		    string s;
			getline(filein,s);//读入每一行
			istringstream sin(s);
			sin>>x>>y>>z>>u>>w>>i>>b>>c;//将一行字符串读出
            ofstream fileout("restore.txt",ios::app);//写到新文件中去
			
			if(t!=x)//判断是否为删除的地方
			fileout<<s<<endl;//写入数据

			if(t==x)//判断是否为删除的地方
			{
				n=1;
				book2.setName(x);//设定书名
				book2.setAuthor(y);//设定作者
				book2.setISBN(z);//设定ISBN码
				book2.settype(u);//设定书项
				book2.setPress(w);//设定出版社
				book2.setPrice(i);//设定单价
				book2.setbookNum(b);//设定库存量
			    book2.setallbookNum(c);//设定库存总量
				cout<<"原书籍信息为:"<<endl;
				book2.printBookInformation();//输出

				cout<<"是否删除？（Y：是，N：否）"<<endl;
				char a;//定义变量
				cin>>a;
				if(a=='Y')
				{
					cout<<"删除成功！"<<endl;
				}
			    if(a=='N')
				{
					cout<<"未删除！"<<endl;
				    fileout<<book2.getName()<<" "<<book2.getbookAuthor()<<" "<<book2.getbookISBN()<<" "<<book2.gettype()
					<<" "<<book2.getbookPress()<<" "<<book2.getbookPrice()<<" "<<book2.getbookNum()<<" "<<book2.getallbookNum()<<endl;//写入到文件
				}
				if(a!='Y'||a!='N')
				{
					system("pause");
				}
				fileout.close();//关闭文件
			}
			
		}while(!filein.eof());//判断是否到文件尾
		if(n==0){//不存在这本书
		cout<<"未找到要删除的书籍！"<<endl;	
		}
		filein.close();//关闭
	}
	
	ifstream filei("restore.txt");//打开文档
	ofstream fileout("store.txt",ios::out);//打开文档并清空内容

	for(string s;getline(filei,s);)//将修改后的内容写到文件中去
	{
		fileout<<s<<endl;
	}
	filei.close();//关闭文件
	fileout.close();//关闭文件
	system("del restore.txt");//删除文件副本
}

void manage::addReader()//增加读者函数
{
	ofstream fout("student.txt",ios::app);//打开文件
	string a,b,c;
	cout<<"请输入相应信息！"<<endl;
	cout<<"姓名："<<endl;
	cin>>a;
	cout<<"学号："<<endl;
	cin>>b;
	cout<<"密码："<<endl;
	cin >>c;
	fout<<a<<" "<<b<<" "<<c<<" "<<endl;
    fout.close();//关闭文件
}

void manage::deleteReader()
{
	
	ifstream filein("student.txt");//打开文件
	if(!filein)
	{
		cout<<"打开文件失败！"<<endl;
	}
	else
	{
		string t,m;
		int n=0;//标签，是否有这个读者
		cout<<"请输入删除学生的的姓名："<<endl;
		cin>>m;
        cout<<"请输入删除学生的的学号："<<endl;
		cin>>t;
		do
		{   
			string x,y,z;//定义变量
		    string s;
			getline(filein,s);//读入每一行
			istringstream sin(s);
			sin>>x>>y>>z;//把s中第一个字符串给a
            ofstream fileout("student1.txt",ios::app);//写到新文件中去
			
			if(m!=x||t!=y)//判断是否为删除的地方
			fileout<<s<<endl;//写入数据

			if(m==x&&t==y)//判断是否为删除的地方
			{
				n=1;
				cout<<"原学生信息为:"<<endl;
				cout<<"姓名："<<x<<endl;
				cout<<"学号："<<y<<endl;
				cout<<"密码："<<z<<endl;
				cout<<"是否删除？（Y：是，N：否）"<<endl;
				char a;//定义变量
				cin>>a;
				if(a=='Y')
				{
					cout<<"删除成功！"<<endl;
				}
			    if(a=='N')
				{
					cout<<"未删除！"<<endl;
				    fileout<<x<<" "<<y<<" "<<z<<endl;//写入到文件
				}
				if(a!='Y'||a!='N')
				{
					system("pause");
				}
				fileout.close();//关闭文件
			}
			
		}
		while(!filein.eof());//判断是否到文件尾
		if(n==0)//不存在这个学生
		cout<<"未找到要删除的学生！"<<endl;
	}
	filein.close();//关闭

	ifstream filei("student1.txt");//打开文档
	ofstream fileout("student.txt",ios::out);//打开文档并清空内容

	for(string s;getline(filei,s);)//将修改后的内容写到文件中去
	{
		fileout<<s<<endl;
	}
	filei.close();//关闭文件
	fileout.close();//关闭文件
	system("del student1.txt");//删除文件副本
}

void manage::findAllBooks()//定义查询所有书籍函数
{
	book book3;//实例化对象
	ifstream filein("store.txt");//打开文件
	if(!filein)
	{
		cout<<"打开文件失败！"<<endl;
	}
	else
	{
		cout <<"  书名"<<setw(25)<<"作者"<<setw(10)<<"ISBN码"<<setw(10)<<"书项"<<setw(20)<<"出版社"<<setw(10)<<"单价"<<setw(10)<<"库存量"<<setw(10)<<"库存总量" << endl;
		for(string s;getline(filein,s);)//判断读入的书名
		{
			int b,c,d;//b现有库存，c总库存
			float i;
			string a,x,y,z,u,w;//定义变量
			istringstream sin(s);//定义sin流
			sin>>x>>y>>z>>u>>w>>i>>b>>c;//将一行字符串读出	  				
			if (x=="") {
				
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
				cout << book3.getName() << setw(15) << book3.getbookAuthor() << setw(10) << book3.getbookISBN() << setw(10) << book3.gettype()
					<< setw(20) << book3.getbookPress() << setw(10) << book3.getbookPrice() << setw(10) << book3.getbookNum() << setw(10) << book3.getallbookNum() << endl;//输出控制台
			}
		}
	
	}
			filein.close();//关闭文件
}

void manage::findAllBorrow()
{
	borrow borrow;
	borrow.printBorrowInfo();
}

manage::~manage()//析构函数
{
}
