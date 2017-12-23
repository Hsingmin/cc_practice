#include <iostream> 
using namespace std; 
#include <stdlib.h> 
#include<conio.h> 
double avg=0;//统计总分和加平均分权 
const int mathp=4;//数学学分 
const int cppp=5;//C++学分 
const int sum=70;//设置总学分 

class Student 
{ 
private: 
int num; 
char *name; 
char *sex; 
char *phone; 
char *rphone; 
double math; 
double cpp; 
Student* next; 
public: 
Student() 
{next=NULL;} 
~Student(); 
void Push(Student **refhead,int num,char *name,char *sex,char *phone,char *rphone,double math,double cpp); 
void Delete(Student *head,int data); 
Student* Find(Student* head,int data); 
void Display(Student* head); 
int Length(Student* head); 
void Math(Student* head,int data); 
void Update(Student* head,int data); 
void Insert(); 
}; 
Student* head=new Student;//带头结点的头指针 

void Student::Push(Student **refhead,int num,char *name,char *sex,char *phone,char *rphone,double math,double cpp) 
{ 
Student* newnode=new Student;//新增加结点 
newnode->num=num; 
newnode->name=name; 
newnode->sex=sex; 
newnode->phone=phone; 
newnode->rphone=rphone; 
newnode->math=math; 
newnode->cpp=cpp; 
newnode->next=*refhead; 
*refhead=newnode;//重置表头 
} 
//遍历 
void Student::Display(Student* head) 
{ 
Student* temp; 
temp=head; 
if(temp->next==NULL)//判断空表 
cout<<"没有学生！"; 
else 
{while(temp!=NULL)// 
{ 
cout<<"学号："<<temp->num<<"姓名："<<temp->name<<"性别："<<temp->sex<<"手机："<<temp->phone<<"宿舍电话："<<temp->rphone<<"数学成绩："<<temp->math<<"C++成绩:"<<temp->cpp<<endl; 
temp=temp->next; 
} 
} 
return; 
} 
//人数 
int Student::Length(Student* head) 
{ 
Student* cur; 
cur=head; 
int count=0; 
while(cur!=NULL) 
{ 
count++;//通过累加统计人数 
cur=cur->next; 
} 
return count; 
} 
//查找 
Student* Student::Find(Student* head,int data) 
{ 
Student* cur=head; 
bool bo=false; 
while(cur!=NULL) 
{ 
if(cur->num=data) 
{ 
bo=true;//如果找到则改变bo的值 
cout<<"学号："<<cur->num<<"姓名："<<cur->name<<"性别："<<cur->sex<<"手机："<<cur->phone<<"宿舍电话："<<cur->rphone<<"数学成绩："<<cur->math<<"C++成绩:"<<cur->cpp<<endl; 
break; 
} 
cur=cur->next; 
} 
if(bo==false)//通过判断bo的值判断找到与否 
cout<<"没有这个人！"<<endl; 
return cur; 
} 
//删除 
void Student::Delete(Student* head,int data) 
{ 
Student *bef,*cur; 
bef=cur=head; 
while(cur!=NULL) 
{ 
if(cur->num==data) 
break; 
else 
{bef=cur;cur=cur->next;} 
} 
if(cur==head)//如果是头结点则删除头结点 
{ 
head=cur->next; 
delete cur; 
} 
else 
{ 
bef->next=cur->next; 
delete cur; 
} 
} 
//修改 
void Student::Update(Student* head,int data) 
{ 
Student* cur=head; 
bool bo=false; 
while(cur!=NULL) 
{ 
if(cur->num==data) 
{ 
bo=true; 
int a,b; 
char *c; 
double d; 
for(;;) //找到后提供各字段的修改 
{ cout<<"1修改学号|2修改姓名|3修改性别|4修改手机号|5修改宿舍电话号|6修改数学成绩|7修改C++成绩|8退出\n"; 
cin>>a; 
switch(a) 
{ 
case 1:cout<<"输入新学号："; 
cin>>b; 
cur->num=a; 
break; 
case 2:cout<<"输入新姓名："; 
cin>>c; 
cur->name=c; 
break; 
case 3:cout<<"输入新性别："; 
cin>>c; 
cur->sex=c; 
break; 
case 4:cout<<"输入新手机号："; 
cin>>c; 
cur->phone=c; 
break; 
case 5:cout<<"输入新宿舍电话号："; 
cin>>c; 
cur->rphone=c; 
break; 
case 6:cout<<"输入新数学成绩："; 
cin>>d; 
cur->math=d; 
break; 
case 7:cout<<"输入C++成绩："; 
cin>>d; 
cur->cpp=d; 
break; 
case 8:exit(1); 
break; 
default:cout<<"操作错误"; 
break; 
} 
} 
break; 
} 
} 
if(bo==false) 
cout<<"没有这个人！"<<endl; 
return; 
} 
//统计 
void Student::Math(Student* head,int data) 
{ 
Student* cur=head; 
bool bo=false; 
while(cur!=NULL) 
{ 
if(cur->num=data) 
{ 
bo=true; 
avg=cur->math*(mathp/sum)+cur->cpp*(cppp/sum);//计算总分和加平均分权的公式 
break; 
} 
cur=cur->next; 
} 
if(bo==false){ 
cout<<"没有这个人！"<<endl; 
return; 
} 
cout<<"该生的总分和加平均分权="<<avg<<endl; 
return; 
} 
//录入 
void Student::Insert() 
{ 
head=NULL; 
int num; 
char name[8]; 
char sex[4]; 
char phone[11]; 
char rphone[7]; 
double math; 
double cpp; 
cout<<"请输入基本信息：\n"; 
cout<<"学号："; 
cin>>num; 
cout<<"姓名："; 
cin>>name; 
cout<<"性别："; 
cin>>sex; 
cout<<"手机号："; 
cin>>phone; 
cout<<"宿舍电话："; 
cin>>rphone; 
cout<<"数学成绩："; 
cin>>math; 
cout<<"C++成绩："; 
cin>>cpp; 
Push(&head,num,name,sex,phone,rphone,math,cpp);//调用函数Push建立有序链表 
} 
//用释构函数逐个释放空间 
Student::~Student() 
{ 
while(head!=NULL) 
{ 
delete head; 
head=head->next; 
} 
} 
//程序主入口 
int main() 
{ 
for(;;) 
{ 
head=NULL; 
Student s; 
int x; 
int data; 
cout<<"|1录入|2查找|3删除|4修改|5统计|6退出|\n"; 
cout<<"请作选择：\n"; 
cin>>x; 
switch(x) 
{ 
case 1: 
start: 
s.Insert(); 
cout<<"继续吗？[Y/N]"; 
char ch; 
cin>>ch; 
if(ch=='y' || ch=='Y') 
goto start; 
s.Display(head); 
int l; 
l=s.Length(head); 
cout<<"一共有"<<l<<"个学生。"<<endl; 
break; 
case 2: 
cout<<"请输入你要查找的学生的学号："; 
cin>>data; 
s.Find(head,data); 
break; 
case 3: 
cout<<"请输入你要删除的学生的学号："; 
cin>>data; 
s.Delete(head,data); 
break; 
case 4: 
cout<<"请输入你要修改的学生的学号："; 
cin>>data; 
s.Update(head,data); 
break; 
case 5: 
cout<<"请输入你要统计的学生的学号："; 
cin>>data; 
s.Math(head,data); 
break; 
case 6: 
exit(1); 
break; 
default:cout<<"操作错误！"<<endl; 
break; 
} 
}
getch();
}
