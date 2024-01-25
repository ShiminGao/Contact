#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"

//测试动作：测试顺序表
void ContactTest()
{
	SLT con;
	InitContact(&con);
	int op = -1;
	do {
		menu();

		printf("请选择您的操作：\n");
		scanf("%d", &op);

		switch (op)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			FindContact(&con);
			break;
		case 4:
			ModifyContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 0:
			printf("退出通讯录！\n");
			break;
		default:
			printf("输入有误，请重新输入！\n");
			break;
		}
	} while (op);
}

int main()
{
	ContactTest();
	return 0;
}