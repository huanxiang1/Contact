#define  _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"



void memu()
{
	printf("*************************************\n");
	printf("*****    1.add        2.del      ****\n");
	printf("*****    3.search     4.modify   ****\n");
	printf("*****    5.show       6.sort     ****\n");
	printf("*****            0.exit          ****\n");
	printf("*************************************\n");
}

int main()
{
	int input = 0;
	//创建通讯录
	struct Contact con;//con是通讯录里面包含：可存放1000个元素的数组和size
	//初始化通讯录
	InitContact(&con);
	do 
	{ 
		memu();//菜单
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			ShowContact(&con);
			break;
		case EXIT:
			printf("bye bye\n");
			break;
		default:
			printf("输入错误，请重新选择\n");
			break;
		}

	} while (input);
	return 0;
}

