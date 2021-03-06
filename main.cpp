//Books library using linked list and file handling
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
fstream myfile;
string s[100];
struct books
{
 //parts of a node.
 string name,authur,type;
 books*link;
  books()
  {
   link=NULL;
  }
};
class records
{
 //pointers to handle the linklist
 books *start,*cur,*temp;
 public:

 records()
 {
  start=NULL;
 }
 //function to create nodes
 creat_file (string n,string a,string t)
 {
  //create first node...
   if(start==NULL)
   {
    start=new books;
    start->link=NULL;
    start->name=n;
    start->authur=a;
    start->type=t;
    myfile.open ("books library.txt",ios::out | ios::app);
	myfile<<"Name:"<<start->name<<"Authur:"<<start->authur<<"Type:"<<start->type<<endl;
	myfile.close();
   }
   //to create new node..
   else
   {
    cur=start;
    while(cur->link!=NULL)
    {
     cur=cur->link;
    }
    temp=new books;
    temp->name=n;
	temp->authur=a;
    temp->type=t;
    temp->link=NULL;
    cur->link=temp;
   myfile.open ("books library.txt",ios::out | ios::app);
	myfile<<"Name:"<<temp->name<<"Authur:"<<temp->authur<<"Type:"<<temp->type<<endl;
	myfile.close();
   }

    }

    //print data of the linklist.
    void print_now()
    {
     cur=start;
     int c;
     cout<<"Book #"<<"Name\tAuthur\tType"<<endl;
     for(c=1;cur->link!=NULL;c++)
     {
      cout<<"   "<<c<<" "<<cur->name<<"\t"<<cur->authur<<"\t"<<cur->type<<endl;
      cur=cur->link;
     }
      cout<<"   "<<c<<" "<<cur->name<<"\t"<<cur->authur<<"\t"<<cur->type<<endl;
 }
 void search(string n)
 {
 	int i,k=0;string ss;
 	myfile.open("books library.txt",ios::in);
 	while(!myfile.eof())
 	{
 		myfile>>s[k];
 		k++;
	 }
	 k--;
	 myfile.close();
for( i=0;i<k;i++)
{		
		if(s[i].find(n)>0 && s[i].find(n)<s[i].length())
		{
			break;	
		}
}
if(i!=k)
{
char mod;
	cout<<"\nWant to modify Book Data ..?? (y/n) ";
	cin>>mod;
	if(mod=='y'|| mod=='Y')
	{
		string n,an,tp;
		cout<<"Enter book name ";
		cin>>n;
		cout<<"Enter Authur Name ";
		cin>>an;
		cout<<"Enter Book Type :";
		cin>>tp;
		s[i]="Name:"+n+"Authur:"+an+"Type:"+tp;
	
	 myfile.open("books library.txt",ios::out);
	 for(  int j=0;j<k;j++)
	 myfile<<s[j]<<endl;
	 myfile.close();
}
 }
 else
 {
 	cout<<"\nNot found "<<endl;
 }
}
 void print()
 {
 	//this function reads the data from file
 	myfile.open("books library.txt",ios::in);
 	int i=0;
 	while(!(myfile.eof()))
 	{
 		myfile>>s[i];
 		cout<<s[i]<<endl;
 		i++;
	 }
	 myfile.close();
 }
};
int main()
{
 records l1;
 int nooffiles,i,p,ch,k,j;
 string n,an,t;
 
 cout<<"\t\t\t BOOKS LIBRARY\n";
 
 
 cout<<"\n\t1-ENTER NEW BOOK\n";
 cout<<"\n\t2-SEARCH AND UPDATE THE BOOKS DATA\n";
 cout<<"\n\t3-DELETE A B00O FROM LIBRARY\n";
 cout<<"\n\t4-SEE ALL THE LIST ANY TIME\n";
 

 cout<<"\n\t=SAVE BOOKS=\n"<<endl;
 //no. of files.
 cout<<"\thow many Book's data you want to save"<<endl;
 cin>>nooffiles;
 //create/save data of each book....function call pass data..
 for(i=1;i<=nooffiles;i++)
 {
  cout<<"\n\tEnter Name \t";
  //getline(cin,n);
  cin>>n;
  cout<<"\n\tEnter Authur Name \t";
  cin>>an;
  cout<<"\n\tEnter TYPE \t";
  cin>>t;
  l1.creat_file(n,an,t);
 }
	system("CLS");
 do
 {
 cout<<"\n\nWhat You want to do with your Books now"<<endl;
 cout<<"\n1-Save new Book\n";
 cout<<"2-Delete any book"<<endl;
 cout<<"3-Search and Modify"<<endl;
 cout<<"4-See All list"<<endl;
cout<<"5-Read online books "<<endl;
 cout<<"6-Exit\n"<<endl;

 cin>>ch;
 	system("CLS");
 switch(ch)
 {
  case 1:
   cout<<"\n\tADD NEW BOOK\n\n";
   cout<<"Enter Book Data to insert in your library"<<endl;

  cout<<"\nEnter Name \t";
  //getline(cin,n);
  cin>>n;
  cout<<"\nEnter Authur name \t";
  cin>>an;
  cout<<"Enter Type \t";
  cin>>t;
  l1.creat_file(n,an,t);
   cout<<"Book "<<n<<" has been Saved in your Library "<<endl;
   break;
  case 2:
   cout<<"\n\tDELETE Book\n\n";

 	myfile.open("books library.txt",ios::in);
 	  k=0;
 	int del;
 	while(myfile.good())
 	{
 		myfile>>s[k];
 		cout<<k+1<<"-"<<s[k]<<endl;
 		k++;
	 }
	 myfile.close();
	 cout<<"Which Book data you want to delete ..? ";
	 cin>>del;
	 s[del-1]="";

	 cout<<"\nBook record has been deleted "<<endl;
	 myfile.open("books library.txt",ios::out);
	 for(  j=0;j<k;j++)
	 myfile<<s[j]<<endl;
	 myfile<<endl;
	 myfile.close();
     break;
   case 3:
   	cout<<"\n\tSEARCH AND UPDATE BOOK data\n\n";
   	cout<<"Enter NAME of Book to search it from Library\t";
   	cin>>n;
   	l1.search(n);
   	break;
	case 4:
	cout<<"\n\tPRINTING ALL LIST\n\n";
   	l1.print();
   	break;
   	case 5:
   	cout<<"\n\t=SEARCH BOOK ONLINE=\n\n";
   system("cmd/c start https://books.google.com/");
   		break;
  case 6:
   cout<<"\n\t=\LIST OF Books added Now=\n\n";
   l1.print_now();
   break;
  default:
   cout<<"\t----------Invalid----------"<<endl;
 }
}
 while(ch>0 && ch<6);
 cout<<"\n"<<endl;
 getch();
}
