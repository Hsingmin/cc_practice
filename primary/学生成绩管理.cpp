#include <iostream> 
using namespace std; 
#include <stdlib.h> 
#include<conio.h> 
double avg=0;//ͳ���ֺܷͼ�ƽ����Ȩ 
const int mathp=4;//��ѧѧ�� 
const int cppp=5;//C++ѧ�� 
const int sum=70;//������ѧ�� 

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
Student* head=new Student;//��ͷ����ͷָ�� 

void Student::Push(Student **refhead,int num,char *name,char *sex,char *phone,char *rphone,double math,double cpp) 
{ 
Student* newnode=new Student;//�����ӽ�� 
newnode->num=num; 
newnode->name=name; 
newnode->sex=sex; 
newnode->phone=phone; 
newnode->rphone=rphone; 
newnode->math=math; 
newnode->cpp=cpp; 
newnode->next=*refhead; 
*refhead=newnode;//���ñ�ͷ 
} 
//���� 
void Student::Display(Student* head) 
{ 
Student* temp; 
temp=head; 
if(temp->next==NULL)//�жϿձ� 
cout<<"û��ѧ����"; 
else 
{while(temp!=NULL)// 
{ 
cout<<"ѧ�ţ�"<<temp->num<<"������"<<temp->name<<"�Ա�"<<temp->sex<<"�ֻ���"<<temp->phone<<"����绰��"<<temp->rphone<<"��ѧ�ɼ���"<<temp->math<<"C++�ɼ�:"<<temp->cpp<<endl; 
temp=temp->next; 
} 
} 
return; 
} 
//���� 
int Student::Length(Student* head) 
{ 
Student* cur; 
cur=head; 
int count=0; 
while(cur!=NULL) 
{ 
count++;//ͨ���ۼ�ͳ������ 
cur=cur->next; 
} 
return count; 
} 
//���� 
Student* Student::Find(Student* head,int data) 
{ 
Student* cur=head; 
bool bo=false; 
while(cur!=NULL) 
{ 
if(cur->num=data) 
{ 
bo=true;//����ҵ���ı�bo��ֵ 
cout<<"ѧ�ţ�"<<cur->num<<"������"<<cur->name<<"�Ա�"<<cur->sex<<"�ֻ���"<<cur->phone<<"����绰��"<<cur->rphone<<"��ѧ�ɼ���"<<cur->math<<"C++�ɼ�:"<<cur->cpp<<endl; 
break; 
} 
cur=cur->next; 
} 
if(bo==false)//ͨ���ж�bo��ֵ�ж��ҵ���� 
cout<<"û������ˣ�"<<endl; 
return cur; 
} 
//ɾ�� 
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
if(cur==head)//�����ͷ�����ɾ��ͷ��� 
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
//�޸� 
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
for(;;) //�ҵ����ṩ���ֶε��޸� 
{ cout<<"1�޸�ѧ��|2�޸�����|3�޸��Ա�|4�޸��ֻ���|5�޸�����绰��|6�޸���ѧ�ɼ�|7�޸�C++�ɼ�|8�˳�\n"; 
cin>>a; 
switch(a) 
{ 
case 1:cout<<"������ѧ�ţ�"; 
cin>>b; 
cur->num=a; 
break; 
case 2:cout<<"������������"; 
cin>>c; 
cur->name=c; 
break; 
case 3:cout<<"�������Ա�"; 
cin>>c; 
cur->sex=c; 
break; 
case 4:cout<<"�������ֻ��ţ�"; 
cin>>c; 
cur->phone=c; 
break; 
case 5:cout<<"����������绰�ţ�"; 
cin>>c; 
cur->rphone=c; 
break; 
case 6:cout<<"��������ѧ�ɼ���"; 
cin>>d; 
cur->math=d; 
break; 
case 7:cout<<"����C++�ɼ���"; 
cin>>d; 
cur->cpp=d; 
break; 
case 8:exit(1); 
break; 
default:cout<<"��������"; 
break; 
} 
} 
break; 
} 
} 
if(bo==false) 
cout<<"û������ˣ�"<<endl; 
return; 
} 
//ͳ�� 
void Student::Math(Student* head,int data) 
{ 
Student* cur=head; 
bool bo=false; 
while(cur!=NULL) 
{ 
if(cur->num=data) 
{ 
bo=true; 
avg=cur->math*(mathp/sum)+cur->cpp*(cppp/sum);//�����ֺܷͼ�ƽ����Ȩ�Ĺ�ʽ 
break; 
} 
cur=cur->next; 
} 
if(bo==false){ 
cout<<"û������ˣ�"<<endl; 
return; 
} 
cout<<"�������ֺܷͼ�ƽ����Ȩ="<<avg<<endl; 
return; 
} 
//¼�� 
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
cout<<"�����������Ϣ��\n"; 
cout<<"ѧ�ţ�"; 
cin>>num; 
cout<<"������"; 
cin>>name; 
cout<<"�Ա�"; 
cin>>sex; 
cout<<"�ֻ��ţ�"; 
cin>>phone; 
cout<<"����绰��"; 
cin>>rphone; 
cout<<"��ѧ�ɼ���"; 
cin>>math; 
cout<<"C++�ɼ���"; 
cin>>cpp; 
Push(&head,num,name,sex,phone,rphone,math,cpp);//���ú���Push������������ 
} 
//���͹���������ͷſռ� 
Student::~Student() 
{ 
while(head!=NULL) 
{ 
delete head; 
head=head->next; 
} 
} 
//��������� 
int main() 
{ 
for(;;) 
{ 
head=NULL; 
Student s; 
int x; 
int data; 
cout<<"|1¼��|2����|3ɾ��|4�޸�|5ͳ��|6�˳�|\n"; 
cout<<"����ѡ��\n"; 
cin>>x; 
switch(x) 
{ 
case 1: 
start: 
s.Insert(); 
cout<<"������[Y/N]"; 
char ch; 
cin>>ch; 
if(ch=='y' || ch=='Y') 
goto start; 
s.Display(head); 
int l; 
l=s.Length(head); 
cout<<"һ����"<<l<<"��ѧ����"<<endl; 
break; 
case 2: 
cout<<"��������Ҫ���ҵ�ѧ����ѧ�ţ�"; 
cin>>data; 
s.Find(head,data); 
break; 
case 3: 
cout<<"��������Ҫɾ����ѧ����ѧ�ţ�"; 
cin>>data; 
s.Delete(head,data); 
break; 
case 4: 
cout<<"��������Ҫ�޸ĵ�ѧ����ѧ�ţ�"; 
cin>>data; 
s.Update(head,data); 
break; 
case 5: 
cout<<"��������Ҫͳ�Ƶ�ѧ����ѧ�ţ�"; 
cin>>data; 
s.Math(head,data); 
break; 
case 6: 
exit(1); 
break; 
default:cout<<"��������"<<endl; 
break; 
} 
}
getch();
}
