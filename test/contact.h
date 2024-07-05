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

//��Ա��Ϣ
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//ͨѶ¼����
struct Contact
{
	struct PeoInfo data[MAX];//���1000���˵���Ϣ
	int size;//��¼��ǰ�Ѿ��е�Ԫ�ظ���
};

//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps);

//���һ����Ϣ��ͨѶ¼
void AddContact(struct Contact* ps);

//չʾͨѶ¼
void ShowContact(const struct Contact* ps);

//ɾ��ͨѶ¼�е�Ԫ��
void DelContact(struct Contact* ps);

//����
void SearchContact(const struct Contact* ps);

//�޸�
void ModifyContact(const struct Contact* ps);

//����
void SortContact(struct Contact* ps);