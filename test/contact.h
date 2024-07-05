#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

#define MAX 1000
#define MAX_NAME 8
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

//成员信息
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//通讯录类型
struct Contact
{
	struct PeoInfo data[MAX];//存放1000个人的信息
	int size;//记录当前已经有的元素个数
};

//初始化通讯录
void InitContact(struct Contact* ps);

//添加一个信息到通讯录
void AddContact(struct Contact* ps);

//展示通讯录
void ShowContact(const struct Contact* ps);

//删除通讯录中的元素
void DelContact(struct Contact* ps);

//查找
void SearchContact(const struct Contact* ps);

//修改
void ModifyContact(const struct Contact* ps);

//排序
void SortContact(struct Contact* ps);