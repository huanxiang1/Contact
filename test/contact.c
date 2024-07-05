#define  _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//初始化
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));//将数组初始化成0
	ps->size = 0;//设置通讯录最初只有0个元素
}

//增
void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录满了，无法增加");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[ps->size].name);//name本身就是字符数组的数组名，就是字符数组的首地址，所以不需要使用取地址符
		printf("请输年龄:>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("添加成功\n");
	}
}


//显示
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空");
	}
	else
	{
		int i = 0;
		//标题
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		//数据
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n", 
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

//删除
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除的人的名字\n");
	scanf("%s", name);
	//1.查找要删除的人在什么位置
	int pos = FindByName(ps, name);
	//2.删除
	if (pos == -1)
	{
		printf("没有这个人\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}


//找到了返回下标，找不到返回-1
static int FindByName(const struct Contact* ps,char name[MAX_NAME])//static修饰函数只能在这个文件内contact.c使用
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == (strcmp(ps->data[i].name, name)))
			return i;
	}
	if (i == ps->size)
		return -1;
}

//查找
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入你要查找的人的姓名");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
		printf("没有这个人\n");
	else
	{
		printf("找到了\n");
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}	
}

//修改
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入你要修改的人的姓名");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
		printf("没有这个人\n");
	else 
	{
		printf("请开始修改\n");
		printf("请输入名字:>");
		scanf("%s", ps->data[pos].name);
		printf("请输年龄:>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[pos].addr);
		printf("修改成功\n");
	}
}

//排序

cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}

void SortContact(struct Contact* ps)
{
	qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_by_name);
}